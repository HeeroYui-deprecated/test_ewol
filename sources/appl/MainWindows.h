/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __MAIN_WINDOWS_H__
#define __MAIN_WINDOWS_H__

#include <appl/debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Windows.h>
#include <ewol/widget/Sizer.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Spacer.h>

class MainWindows : public ewol::widget::Windows {
	private:
		ewol::object::Shared<ewol::widget::Sizer> m_sizerVert;
		ewol::object::Shared<ewol::Widget> m_subWidget;
		ewol::object::Shared<ewol::widget::Label> m_testName;
		int32_t m_idWidget;
	public:
		// Constructeur
		MainWindows();
		~MainWindows();
	public: // derived fuction
		virtual void onReceiveMessage(const ewol::object::Message& _msg);
};

#endif


