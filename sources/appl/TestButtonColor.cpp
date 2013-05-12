/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/Debug.h>
#include <appl/TestButtonColor.h>

#include <ewol/widget/Button.h>
#include <ewol/widget/CheckBox.h>
#include <ewol/widget/Sizer.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Entry.h>
#include <ewol/widget/List.h>
#include <ewol/widget/ContextMenu.h>
#include <ewol/widget/PopUp.h>
#include <ewol/widget/Slider.h>
#include <ewol/widget/Menu.h>
#include <ewol/widget/meta/FileChooser.h>
#include <ewol/widget/meta/Parameter.h>
#include <ewol/widget/WidgetManager.h>


static const char * l_eventChangeExpendX     = "event-change-expend-X";
static const char * l_eventChangeExpendY     = "event-change-expend-Y";
static const char * l_eventChangeFillX       = "event-change-fill-X";
static const char * l_eventChangeFillY       = "event-change-fill-Y";

#undef __class__
#define __class__	"TestButton"

TestButtonColor::TestButtonColor(void) : 
	widget::Sizer(widget::Sizer::modeVert),
	m_testWidget(NULL)
{
	APPL_DEBUG("CREATE "__class__" ... ");
	widget::Sizer* mySizerVert2 = NULL;
	widget::Sizer* mySizerHori = NULL;
	widget::Button*    myButton = NULL;
	
	mySizerHori = new widget::Sizer(widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	SubWidgetAdd(mySizerHori);
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Expand X (false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Expand X (true)"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeExpendX);
			mySizerHori->SubWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Expand Y (false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Expand Y (true)"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeExpendY);
			mySizerHori->SubWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Fill X (false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Fill X (true)"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeFillX);
			mySizerHori->SubWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("Fill Y (false)"));
			myButton->SetSubWidgetToggle(new widget::Label("Fill Y (true)"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeFillY);
			mySizerHori->SubWidgetAdd(myButton);
		}
		
	widget::Spacer* mySpacer = new widget::Spacer();
	if (NULL != mySpacer) {
		mySpacer->SetExpand(bvec2(false,false));
		mySpacer->SetFill(bvec2(true,false));
		mySpacer->SetMinSize(vec2(10,10));
		mySpacer->SetColor(0xFF000080);
		SubWidgetAdd(mySpacer);
	}
	
	mySizerHori = new widget::Sizer(widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	SubWidgetAdd(mySizerHori);
	
		mySpacer = new widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->SetExpand(bvec2(false,false));
			mySpacer->SetFill(bvec2(false,true));
			mySpacer->SetMinSize(vec2(10,10));
			mySpacer->SetColor(0x00FF0080);
			mySizerHori->SubWidgetAdd(mySpacer);
		}
		/*
		m_testWidget = new widget::ButtonColor(draw::color::olive);
		if (NULL != m_testWidget) {
			m_testWidget->SetExpand(bvec2(false,false));
			m_testWidget->SetFill(bvec2(false,false));
			m_testWidget->RegisterOnEvent(this, ewolEventButtonColorChange);
			mySizerHori->SubWidgetAdd(m_testWidget);
		}
		*/
		mySpacer = new widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->SetExpand(bvec2(false,false));
			mySpacer->SetFill(bvec2(false,true));
			mySpacer->SetMinSize(vec2(10,10));
			mySpacer->SetColor(0x0000FF80);
			mySizerHori->SubWidgetAdd(mySpacer);
		}
		
	mySpacer = new widget::Spacer();
	if (NULL != mySpacer) {
		mySpacer->SetExpand(bvec2(false,false));
		mySpacer->SetFill(bvec2(true,false));
		mySpacer->SetMinSize(vec2(10,10));
		mySpacer->SetColor(0x00FFFF80);
		SubWidgetAdd(mySpacer);
	}
}


TestButtonColor::~TestButtonColor(void)
{
	
}


void TestButtonColor::OnReceiveMessage(const ewol::EMessage& _msg)
{
	widget::Sizer::OnReceiveMessage(_msg);
	
	//APPL_INFO("Receive Event from the main windows ... : \"" << eventId << "\" ==> data=\"" << data << "\"" );
	if (m_testWidget == _msg.GetCaller()) {
		APPL_WARNING("Receive Event from tested Button ... : " << _msg );
	}
	if (_msg.GetMessage() == l_eventChangeExpendX) {
		if (NULL!=m_testWidget) {
			if (_msg.GetData()=="1") {
				m_testWidget->SetExpand(bvec2(true,m_testWidget->GetExpand().y()));
			} else {
				m_testWidget->SetExpand(bvec2(true,m_testWidget->GetExpand().y()));
			}
		}
	} else if (_msg.GetMessage() == l_eventChangeExpendY) {
		if (NULL!=m_testWidget) {
			if (_msg.GetData()=="1") {
				m_testWidget->SetExpand(bvec2(m_testWidget->GetExpand().x(),true));
			} else {
				m_testWidget->SetExpand(bvec2(m_testWidget->GetExpand().x(),false));
			}
		}
	} else if (_msg.GetMessage() == l_eventChangeFillX) {
		if (NULL!=m_testWidget) {
			if (_msg.GetData()=="1") {
				m_testWidget->SetFill(bvec2(true,m_testWidget->GetFill().y()));
			} else {
				m_testWidget->SetFill(bvec2(false,m_testWidget->GetFill().y()));
			}
		}
	} else if (_msg.GetMessage() == l_eventChangeFillY) {
		if (NULL!=m_testWidget) {
			if (_msg.GetData()=="1") {
				m_testWidget->SetFill(bvec2(m_testWidget->GetFill().x(),true));
			} else {
				m_testWidget->SetFill(bvec2(m_testWidget->GetFill().x(),false));
			}
		}
	}
	
	return;
}

void TestButtonColor::OnObjectRemove(ewol::EObject * removeObject)
{
	widget::Sizer::OnObjectRemove(removeObject);
	if (m_testWidget == removeObject) {
		m_testWidget = NULL;
	}
}
