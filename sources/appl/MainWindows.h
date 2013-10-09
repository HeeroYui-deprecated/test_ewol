/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __MAIN_WINDOWS_H__
#define __MAIN_WINDOWS_H__

#include <appl/Debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Windows.h>
#include <ewol/widget/Sizer.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Spacer.h>

class MainWindows : public ewol::Windows {
	private:
		widget::Sizer* m_sizerVert;
		ewol::Widget* m_subWidget;
		widget::Label* m_testName;
		int32_t m_idWidget;
	public:
		// Constructeur
		MainWindows(void);
		~MainWindows(void);
	public: // derived fuction
		const char * const getObjectType(void) {
			return "MainWindows";
		};
		virtual void onReceiveMessage(const ewol::EMessage& _msg);
		virtual void onObjectRemove(ewol::EObject* _removeObject);
};

#endif


