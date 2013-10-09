/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_BUTTON_H__
#define __TEST_BUTTON_H__

#include <appl/Debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/Spacer.h>
#include <ewol/widget/Sizer.h>

class TestButton : public widget::Sizer {
	private:
		widget::Button* m_testWidget;
	public:
		// Constructeur
		TestButton(void);
		virtual ~TestButton(void);
	public: // Derived function
		virtual const char * const getObjectType(void) {
			return "TestButton";
		};
		virtual void onReceiveMessage(const ewol::EMessage& _msg);
		virtual void onObjectRemove(ewol::EObject* _removeObject);
};

#endif
