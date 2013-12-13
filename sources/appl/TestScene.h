/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

#include <appl/debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Scene.h>
#include <ewol/widget/Sizer.h>

class TestScene : public ewol::widget::Sizer {
	private:
		ewol::widget::Scene* m_testWidget;
	public:
		// Constructeur
		TestScene(void);
		virtual ~TestScene(void);
	public: // Derived function
		virtual const char * const getObjectType(void) {
			return "TestButton";
		};
		virtual void onReceiveMessage(const ewol::object::Message& _msg);
		virtual void onObjectRemove(ewol::Object* _removeObject);
};

#endif
