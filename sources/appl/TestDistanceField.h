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
#include <ewol/compositing/Text.h>
#include <ewol/compositing/TextDF.h>
#include <ewol/resource/Program.h>
#include <ewol/resource/DistanceFieldFont.h>

class TestDistanceField : public ewol::Widget {
		ewol::compositing::Text   m_text1;
		ewol::compositing::TextDF m_text2;
	public:
		// Constructeur
		TestDistanceField(void);
		virtual ~TestDistanceField(void);
	public: // Derived function
		virtual void onDraw(void);
		virtual void calculateMinMaxSize(void);
		virtual void calculateSize(const vec2& _availlable);
		virtual void onRegenerateDisplay(void);
		virtual bool onEventInput(const ewol::event::Input& _event);
};

#endif
