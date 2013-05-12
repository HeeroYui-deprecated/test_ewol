/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_SCENE_H__
#define __TEST_SCENE_H__

#include <appl/Debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Scene.h>
#include <ewol/widget/Sizer.h>

class TestScene : public widget::Sizer
{
	private:
		widget::Scene* m_testWidget;
	public:
		// Constructeur
		TestScene(void);
		virtual ~TestScene(void);
		// Derived function
		virtual const char * const GetObjectType(void) { return "TestButton"; };
		// Derived function
		virtual void OnReceiveMessage(const ewol::EMessage& _msg);
		// Derived function
		virtual void OnObjectRemove(ewol::EObject * removeObject);
};

#endif
