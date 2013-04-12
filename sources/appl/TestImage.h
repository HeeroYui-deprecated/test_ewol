/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#ifndef __TEST_IMAGE_H__
#define __TEST_IMAGE_H__

#include <appl/Debug.h>
#include <ewol/widget/Widget.h>
#include <ewol/widget/Button.h>
#include <ewol/widget/Image.h>
#include <ewol/widget/Spacer.h>
#include <ewol/widget/Sizer.h>

class TestImage : public widget::Sizer
{
	private:
		widget::Image* m_testWidget;
	public:
		// Constructeur
		TestImage(void);
		virtual ~TestImage(void);
	public:
		// Derived function
		virtual const char * const GetObjectType(void) { return "appl::TestImage"; };
		virtual void OnReceiveMessage(ewol::EObject * CallerObject, const char * eventId, const etk::UString& data);
		virtual void OnObjectRemove(ewol::EObject * removeObject);
};

#endif
