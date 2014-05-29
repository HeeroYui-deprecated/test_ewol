/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_LABEL_H__
#define __TEST_LABEL_H__

#include <appl/debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Spacer.h>
#include <ewol/widget/Sizer.h>

class TestLabel : public ewol::widget::Sizer {
	private:
		ewol::object::Shared<ewol::widget::Label> m_testWidget;
		int32_t m_labelId;
	public:
		/**
		 * @brief Constructeur
		 */
		TestLabel();
		/**
		 * @brief Destructor
		 */
		virtual ~TestLabel();
	public: // Derived function
		virtual void onReceiveMessage(const ewol::object::Message& _msg);
		virtual void onObjectRemove(const ewol::object::Shared<ewol::Object>& _object);
};

#endif
