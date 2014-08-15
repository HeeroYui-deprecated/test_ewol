/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_IMAGE_H__
#define __TEST_IMAGE_H__

#include <appl/debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/Image.h>
#include <ewol/widget/Spacer.h>
#include <ewol/widget/Sizer.h>

class TestImage : public ewol::widget::Sizer {
	private:
		ewol::object::Shared<ewol::widget::Image> m_testWidget;
	public:
		// Constructeur
		TestImage();
		virtual ~TestImage();
	public: // Derived function
		virtual void onReceiveMessage(const ewol::object::Message& _msg);
};

#endif
