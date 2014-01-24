/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_BUTTON_H__
#define __TEST_BUTTON_H__

#include <appl/debug.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/Composer.h>
namespace appl {
	class TestButton : public ewol::widget::Composer {
		private:
			ewol::widget::Button* m_testWidget;
		public:
			// Constructeur
			TestButton(void);
		public: // Derived function
			virtual void onReceiveMessage(const ewol::object::Message& _msg);
			virtual void onObjectRemove(ewol::Object* _removeObject);
	};
};

#endif
