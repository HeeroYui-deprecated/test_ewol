/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/Debug.h>
#include <appl/TestImage.h>

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
#include <ewol/widget/WidgetManager.h>


static const char * l_eventChangeExpendX     = "event-change-expend-X";
static const char * l_eventChangeExpendY     = "event-change-expend-Y";
static const char * l_eventChangeFillX       = "event-change-fill-X";
static const char * l_eventChangeFillY       = "event-change-fill-Y";
static const char * l_eventChangeImage      = "event-change-image";

#undef __class__
#define __class__ "TestImage"

TestImage::TestImage(void) :
  widget::Sizer(widget::Sizer::modeVert),
  m_testWidget(NULL) {
	APPL_CRITICAL("Create "__class__" (start)");
	widget::Sizer* mySizerVert2 = NULL;
	widget::Sizer* mySizerHori = NULL;
	widget::Button*    myButton = NULL;
	
	mySizerHori = new widget::Sizer(widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new widget::Label("Expend X <br/> (false)"));
			myButton->setSubWidgetToggle(new widget::Label("Expend X <br/><b>(true)</b>"));
			myButton->registerOnEvent(this, widget::Button::eventValue, l_eventChangeExpendX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new widget::Label("Expend Y <br/> (false)"));
			myButton->setSubWidgetToggle(new widget::Label("Expend Y <br/><b>(true)</b>"));
			myButton->registerOnEvent(this, widget::Button::eventValue, l_eventChangeExpendY);
			mySizerHori->subWidgetAdd(myButton);
		}
	
	mySizerHori = new widget::Sizer(widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
		
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new widget::Label("Fill X <br/> (false)"));
			myButton->setSubWidgetToggle(new widget::Label("Fill X <br/> (true)"));
			myButton->registerOnEvent(this, widget::Button::eventValue, l_eventChangeFillX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new widget::Label("Fill Y <br/> (false)"));
			myButton->setSubWidgetToggle(new widget::Label("Fill Y <br/> (true)"));
			myButton->registerOnEvent(this, widget::Button::eventValue, l_eventChangeFillY);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->setSubWidget(new widget::Label("Change Image"));
			myButton->registerOnEvent(this, widget::Button::eventValue, l_eventChangeImage);
			mySizerHori->subWidgetAdd(myButton);
		}
	widget::Spacer* mySpacer = new widget::Spacer();
	if (NULL != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(0xFF000080);
		subWidgetAdd(mySpacer);
	}
	
	mySizerHori = new widget::Sizer(widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
	
		mySpacer = new widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(0x00FF0080);
			mySizerHori->subWidgetAdd(mySpacer);
		}
		
		m_testWidget = new widget::Image("DATA:sphere.png");
		if (NULL != m_testWidget) {
			m_testWidget->setExpand(bvec2(false,false));
			m_testWidget->setFill(bvec2(false,false));
			//m_testWidget->registerOnEvent(this, ewolEventButtonValue);
			mySizerHori->subWidgetAdd(m_testWidget);
		}
		
		mySpacer = new widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(0x0000FF80);
			mySizerHori->subWidgetAdd(mySpacer);
		}
		
	mySpacer = new widget::Spacer();
	if (NULL != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(0x00FFFF80);
		subWidgetAdd(mySpacer);
	}
	APPL_INFO("Create "__class__" (end)");
}


TestImage::~TestImage(void) {
	APPL_INFO("Remove "__class__" ...");
}


void TestImage::onReceiveMessage(const ewol::EMessage& _msg) {
	widget::Sizer::onReceiveMessage(_msg);
	//APPL_INFO("Receive Event from the main windows ... : \"" << eventId << "\" ==> data=\"" << data << "\"" );
	if (m_testWidget == _msg.getCaller()) {
		APPL_WARNING("Receive Event from tested Button ... : " << _msg);
	}
	if (_msg.getMessage() == l_eventChangeExpendX) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="1") {
				m_testWidget->setExpand(bvec2(true,m_testWidget->getExpand().y()));
			} else {
				m_testWidget->setExpand(bvec2(false,m_testWidget->getExpand().y()));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeExpendY) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="1") {
				m_testWidget->setExpand(bvec2(m_testWidget->getExpand().x(),true));
			} else {
				m_testWidget->setExpand(bvec2(m_testWidget->getExpand().x(),false));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeFillX) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="1") {
				m_testWidget->setFill(bvec2(true,m_testWidget->getFill().y()));
			} else {
				m_testWidget->setFill(bvec2(false,m_testWidget->getFill().y()));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeFillY) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="1") {
				m_testWidget->setFill(bvec2(m_testWidget->getFill().x(),true));
			} else {
				m_testWidget->setFill(bvec2(m_testWidget->getFill().x(),false));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeImage) {
		if (NULL!=m_testWidget) {
			static int32_t countID = 1;
			switch (countID)
			{
				case 0:
					m_testWidget->setFile("DATA:stone.png");
					break;
				case 1:
					m_testWidget->setFile("DATA:grass.png");
					break;
				default:
					m_testWidget->setFile("DATA:sphere.png");
					countID=-1;
					break;
			}
			countID++;
		}
	}
	return;
}

void TestImage::onObjectRemove(ewol::EObject * _removeObject) {
	widget::Sizer::onObjectRemove(_removeObject);
	if (m_testWidget == _removeObject) {
		m_testWidget = NULL;
	}
}
