/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/debug.h>
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
#include <ewol/widget/Manager.h>


static const char * l_eventChangeExpendX     = "event-change-expend-X";
static const char * l_eventChangeExpendY     = "event-change-expend-Y";
static const char * l_eventChangeFillX       = "event-change-fill-X";
static const char * l_eventChangeFillY       = "event-change-fill-Y";

#undef __class__
#define __class__ "TestButton"

TestButtonColor::TestButtonColor() :
  ewol::widget::Sizer(ewol::widget::Sizer::modeVert),
  m_testWidget(nullptr) {
	APPL_INFO("CREATE " __class__ " ... ");
	addObjectType("appl::TestButtonColor");
	ewol::object::Shared<ewol::widget::Sizer> mySizerVert2;
	ewol::object::Shared<ewol::widget::Sizer> mySizerHori;
	ewol::object::Shared<ewol::widget::Button> myButton;
	
	mySizerHori = ewol::object::makeShared(new ewol::widget::Sizer(ewol::widget::Sizer::modeHori));
	if (nullptr == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
		myButton = ewol::object::makeShared(new ewol::widget::Button());
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::object::makeShared(new ewol::widget::Label("Expand X (false)")));
			myButton->setSubWidgetToggle(ewol::object::makeShared(new ewol::widget::Label("Expand X (true)")));
			myButton->registerOnEvent(this, "value", l_eventChangeExpendX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::object::makeShared(new ewol::widget::Button());
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::object::makeShared(new ewol::widget::Label("Expand Y (false)")));
			myButton->setSubWidgetToggle(ewol::object::makeShared(new ewol::widget::Label("Expand Y (true)")));
			myButton->registerOnEvent(this, "value", l_eventChangeExpendY);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::object::makeShared(new ewol::widget::Button());
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::object::makeShared(new ewol::widget::Label("Fill X (false)")));
			myButton->setSubWidgetToggle(ewol::object::makeShared(new ewol::widget::Label("Fill X (true)")));
			myButton->registerOnEvent(this, "value", l_eventChangeFillX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::object::makeShared(new ewol::widget::Button());
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::object::makeShared(new ewol::widget::Label("Fill Y (false)")));
			myButton->setSubWidgetToggle(ewol::object::makeShared(new ewol::widget::Label("Fill Y (true)")));
			myButton->registerOnEvent(this, "value", l_eventChangeFillY);
			mySizerHori->subWidgetAdd(myButton);
		}
		
	ewol::object::Shared<ewol::widget::Spacer> mySpacer = ewol::object::makeShared(new ewol::widget::Spacer());
	if (nullptr != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(0xFF000080);
		subWidgetAdd(mySpacer);
	}
	
	mySizerHori = ewol::object::makeShared(new ewol::widget::Sizer(ewol::widget::Sizer::modeHori));
	if (nullptr == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
	
		mySpacer = ewol::object::makeShared(new ewol::widget::Spacer());
		if (nullptr != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(0x00FF0080);
			mySizerHori->subWidgetAdd(mySpacer);
		}
		m_testWidget = ewol::object::makeShared(new ewol::widget::ButtonColor(etk::color::olive));
		if (nullptr != m_testWidget) {
			m_testWidget->setExpand(bvec2(false,false));
			m_testWidget->setFill(bvec2(false,false));
			m_testWidget->registerOnEvent(this, "*");
			mySizerHori->subWidgetAdd(m_testWidget);
		}
		mySpacer = ewol::object::makeShared(new ewol::widget::Spacer());
		if (nullptr != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(0x0000FF80);
			mySizerHori->subWidgetAdd(mySpacer);
		}
		
	mySpacer = ewol::object::makeShared(new ewol::widget::Spacer());
	if (nullptr != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(0x00FFFF80);
		subWidgetAdd(mySpacer);
	}
}

TestButtonColor::~TestButtonColor() {
	
}

void TestButtonColor::onReceiveMessage(const ewol::object::Message& _msg) {
	ewol::widget::Sizer::onReceiveMessage(_msg);
	//APPL_INFO("Receive Event from the main windows : " << _msg);
	if (m_testWidget == _msg.getCaller()) {
		APPL_WARNING("Receive Event from tested Button ... : " << _msg );
	}
	if (_msg.getMessage() == l_eventChangeExpendX) {
		if (nullptr!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setExpand(bvec2(true,m_testWidget->getExpand().y()));
			} else {
				m_testWidget->setExpand(bvec2(true,m_testWidget->getExpand().y()));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeExpendY) {
		if (nullptr!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setExpand(bvec2(m_testWidget->getExpand().x(),true));
			} else {
				m_testWidget->setExpand(bvec2(m_testWidget->getExpand().x(),false));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeFillX) {
		if (nullptr!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setFill(bvec2(true,m_testWidget->getFill().y()));
			} else {
				m_testWidget->setFill(bvec2(false,m_testWidget->getFill().y()));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeFillY) {
		if (nullptr!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setFill(bvec2(m_testWidget->getFill().x(),true));
			} else {
				m_testWidget->setFill(bvec2(m_testWidget->getFill().x(),false));
			}
		}
	}
	
	return;
}

