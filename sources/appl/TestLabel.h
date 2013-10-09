/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_LABEL_H__
#define __TEST_LABEL_H__

#include <appl/Debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Spacer.h>
#include <ewol/widget/Sizer.h>

class TestLabel : public widget::Sizer {
	private:
		widget::Label* m_testWidget;
		int32_t m_labelId;
	public:
		/**
		 * @brief Constructeur
		 */
		TestLabel(void);
		/**
		 * @brief Destructor
		 */
		virtual ~TestLabel(void);
	public: // Derived function
		virtual const char * const getObjectType(void) {
			return "TestButton";
		};
		virtual void onReceiveMessage(const ewol::EMessage& _msg);
		virtual void onObjectRemove(ewol::EObject* _removeObject);
};

#endif
