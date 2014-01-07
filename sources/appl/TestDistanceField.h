/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_DISTANCE_FIELD_H__
#define __TEST_DISTANCE_FIELD_H__

#include <appl/debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/compositing/Compositing.h>
#include <ewol/resource/Program.h>
#include <ewol/resource/DistanceFieldFont.h>

class TestDistanceField : public ewol::Widget {
	public:
		// Constructeur
		TestDistanceField(void);
		virtual ~TestDistanceField(void);
	public: // Derived function
		virtual void onDraw(void);
		virtual void calculateMinMaxSize(void);
		virtual void calculateSize(const vec2& _availlable);
		virtual void onRegenerateDisplay(void);
		void clear(void);
		void print(const ivec2& _size);
	private:
		vec3 m_position; //!< The current position to draw
		etk::Color<> m_color; //!< The text foreground color
	private:
		ewol::resource::Program* m_GLprogram;  //!< pointer on the opengl display program
		int32_t m_GLPosition; //!< openGL id on the element (vertex buffer)
		int32_t m_GLMatrix;   //!< openGL id on the element (transformation matrix)
		int32_t m_GLColor;    //!< openGL id on the element (color buffer)
		int32_t m_GLtexture;  //!< openGL id on the element (Texture position)
		int32_t m_GLtexID;    //!< openGL id on the element (texture ID)
	private:
		ewol::resource::DistanceFieldFont* m_DFFont; //!< texture resources
		std::vector<vec3 > m_coord; //!< internal coord of the object
		std::vector<vec2 > m_coordTex; //!< internal texture coordinate for every point
		std::vector<etk::Color<float> > m_coordColor; //!< internal color of the different point
	protected:
		mat4 m_matrixApply;
				/**
				 * @brief set position for the next text writen
				 * @param[in] _pos Position of the text (in 3D)
				 */
				void setPos(const vec3& _pos) {
					m_position = _pos;
				};
};

#endif
