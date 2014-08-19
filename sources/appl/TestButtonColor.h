/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_BUTTON_COLOR_H__
#define __TEST_BUTTON_COLOR_H__

#include <appl/debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/ButtonColor.h>
#include <ewol/widget/Spacer.h>
#include <ewol/widget/Sizer.h>

namespace appl {
	class TestButtonColor : public ewol::widget::Sizer {
		private:
			std::shared_ptr<ewol::widget::ButtonColor> m_testWidget;
		public:
			// Constructeur
			TestButtonColor();
			void init();
		public:
			DECLARE_FACTORY(TestButtonColor);
			virtual ~TestButtonColor() {};
		public: // Derived function
			virtual void onReceiveMessage(const ewol::object::Message& _msg);
	};
};

#endif
