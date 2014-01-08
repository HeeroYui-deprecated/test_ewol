/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/debug.h>
#include <appl/TestDistanceField.h>

#include <ewol/widget/Button.h>
#include <ewol/widget/CheckBox.h>
#include <ewol/widget/Sizer.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Entry.h>
#include <ewol/widget/List.h>
#include <ewol/widget/ContextMenu.h>
#include <ewol/widget/PopUp.h>
#include <ewol/widget/Slider.h>
#include <ewol/widget/Composer.h>
#include <ewol/widget/Menu.h>
#include <ewol/widget/meta/FileChooser.h>
#include <ewol/widget/meta/Parameter.h>
#include <ewol/widget/Manager.h>

#undef __class__
#define __class__	"TestDistanceField"

TestDistanceField::TestDistanceField(void){
	addObjectType("appl::TestDistanceField");
	APPL_INFO("Create " __class__ " (start)");
	
	// get the shader resource :
	m_GLPosition = 0;
	//m_GLprogram = ewol::resource::Program::keep("DATA:textured3D.prog");
	m_GLprogram = ewol::resource::Program::keep("DATA:fontDistanceField/font1.prog");
	if (NULL != m_GLprogram) {
		m_GLPosition = m_GLprogram->getAttribute("EW_coord3d");
		m_GLColor    = m_GLprogram->getAttribute("EW_color");
		m_GLtexture  = m_GLprogram->getAttribute("EW_texture2d");
		m_GLMatrix   = m_GLprogram->getUniform("EW_MatrixTransformation");
		m_GLtexID    = m_GLprogram->getUniform("EW_texID");
	}
	m_DFFont = ewol::resource::DistanceFieldFont::keep("FreeMono;DejaVuSansMono;FreeSerif");
	clear();
	setExpand(bvec2(true, true));
	setFill(bvec2(true, true));
	APPL_INFO("Create " __class__ " (end)");
}


TestDistanceField::~TestDistanceField(void) {
	APPL_INFO("Remove " __class__ " ...");
	ewol::resource::DistanceFieldFont::release(m_DFFont);
	ewol::resource::Program::release(m_GLprogram);
}


void TestDistanceField::calculateSize(const vec2& _availlable) {
	// set minimal size
	m_size = _availlable;
}


void TestDistanceField::calculateMinMaxSize(void) {
	m_minSize = vec2(256,256);
	markToRedraw();
}


void TestDistanceField::onDraw(void) {
	if (m_coord.size() <= 0) {
		APPL_WARNING("Nothink to draw...");
		return;
	}
	if (m_DFFont == NULL) {
		// this is a normale case ... the user can choice to have no image ...
		APPL_ERROR("No FONT ...");
		return;
	}
	if (m_GLprogram == NULL) {
		APPL_ERROR("No shader ...");
		return;
	}
	// set Matrix : translation/positionMatrix
	mat4 tmpMatrix = ewol::openGL::getMatrix()*m_matrixApply;
	
	m_GLprogram->use();
	m_GLprogram->uniformMatrix4fv(m_GLMatrix, 1, tmpMatrix.m_mat);
	// TextureID
	m_GLprogram->setTexture0(m_GLtexID, m_DFFont->getId());
	// position :
	m_GLprogram->sendAttribute(m_GLPosition, 3/*x,y,z,unused*/, &m_coord[0], 4*sizeof(btScalar));
	// Texture :
	m_GLprogram->sendAttribute(m_GLtexture, 2/*u,v*/, &m_coordTex[0]);
	// color :
	m_GLprogram->sendAttribute(m_GLColor, 4/*r,g,b,a*/, &m_coordColor[0]);
	// Request the draw od the elements : 
	ewol::openGL::drawArrays(GL_TRIANGLES, 0, m_coord.size());
	m_GLprogram->unUse();
}



void TestDistanceField::onRegenerateDisplay(void) {
	if (false == needRedraw()) {
		return;
	}
	clear();
	APPL_WARNING("Regenerate...");
	setPos(vec3(-200,-500,0));
	print(ivec2(2048,2048));
}


void TestDistanceField::clear(void) {
	// reset Buffer :
	m_coord.clear();
	m_coordTex.clear();
	m_coordColor.clear();
	// reset temporal variables :
	m_position = vec3(0.0, 0.0, 0.0);
	m_matrixApply.identity();
	m_color = etk::Color<>(0xFFFFFFFF);
}

void TestDistanceField::print(const ivec2& _size) {
	vec3 point(0,0,0);
	vec2 tex(0,1);
	point.setX(m_position.x());
	point.setY(m_position.y());
	m_coord.push_back(point);
	m_coordTex.push_back(tex);
	m_coordColor.push_back(m_color);
	
	tex.setValue(1,1);
	point.setX(m_position.x() + _size.x());
	point.setY(m_position.y());
	m_coord.push_back(point);
	m_coordTex.push_back(tex);
	m_coordColor.push_back(m_color);
	
	tex.setValue(1,0);
	point.setX(m_position.x() + _size.x());
	point.setY(m_position.y() + _size.y());
	m_coord.push_back(point);
	m_coordTex.push_back(tex);
	m_coordColor.push_back(m_color);
	
	m_coord.push_back(point);
	m_coordTex.push_back(tex);
	m_coordColor.push_back(m_color);
	
	tex.setValue(0,0);
	point.setX(m_position.x());
	point.setY(m_position.y() + _size.y());
	m_coord.push_back(point);
	m_coordTex.push_back(tex);
	m_coordColor.push_back(m_color);
	
	tex.setValue(0,1);
	point.setX(m_position.x());
	point.setY(m_position.y());
	m_coord.push_back(point);
	m_coordTex.push_back(tex);
	m_coordColor.push_back(m_color);
}

bool TestDistanceField::onEventInput(const ewol::event::Input& _event) {
	
	if (_event.getId() == 4) {
		setZoom(getZoom() + 0.01f);
	} else if (_event.getId() == 5) {
		setZoom(getZoom() - 0.01f);
	} 
	return true;
}

