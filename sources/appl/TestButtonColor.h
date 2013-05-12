/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_BUTTON_COLOR_H__
#define __TEST_BUTTON_COLOR_H__

#include <appl/Debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/ButtonColor.h>
#include <ewol/widget/Spacer.h>
#include <ewol/widget/Sizer.h>

class TestButtonColor : public widget::Sizer
{
	private:
		widget::ButtonColor* m_testWidget;
	public:
		// Constructeur
		TestButtonColor(void);
		virtual ~TestButtonColor(void);
	public:
		// Derived function
		virtual const char * const GetObjectType(void) { return "TestButton"; };
		virtual void OnReceiveMessage(const ewol::EMessage& _msg);
		virtual void OnObjectRemove(ewol::EObject * removeObject);
};

#endif
