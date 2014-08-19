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

appl::TestButtonColor::TestButtonColor() {
	addObjectType("appl::TestButtonColor");
}

void appl::TestButtonColor::init() {
	ewol::widget::Sizer::init(ewol::widget::Sizer::modeVert);
	APPL_INFO("CREATE " __class__ " ... ");
	
	std::shared_ptr<ewol::widget::Sizer> mySizerVert2;
	std::shared_ptr<ewol::widget::Sizer> mySizerHori;
	std::shared_ptr<ewol::widget::Button> myButton;
	
	mySizerHori = ewol::widget::Sizer::create(ewol::widget::Sizer::modeHori);
	if (nullptr == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::widget::Label::create("Expand X (false)"));
			myButton->setSubWidgetToggle(ewol::widget::Label::create("Expand X (true)"));
			myButton->registerOnEvent(shared_from_this(), "value", l_eventChangeExpendX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::widget::Label::create("Expand Y (false)"));
			myButton->setSubWidgetToggle(ewol::widget::Label::create("Expand Y (true)"));
			myButton->registerOnEvent(shared_from_this(), "value", l_eventChangeExpendY);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::widget::Label::create("Fill X (false)"));
			myButton->setSubWidgetToggle(ewol::widget::Label::create("Fill X (true)"));
			myButton->registerOnEvent(shared_from_this(), "value", l_eventChangeFillX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = ewol::widget::Button::create();
		if (nullptr != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      ewol::widget::Label::create("Fill Y (false)"));
			myButton->setSubWidgetToggle(ewol::widget::Label::create("Fill Y (true)"));
			myButton->registerOnEvent(shared_from_this(), "value", l_eventChangeFillY);
			mySizerHori->subWidgetAdd(myButton);
		}
		
	std::shared_ptr<ewol::widget::Spacer> mySpacer = ewol::widget::Spacer::create();
	if (nullptr != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(etk::Color<>(0xFF, 0x00, 0x00, 0x80));
		subWidgetAdd(mySpacer);
	}
	
	mySizerHori = ewol::widget::Sizer::create(ewol::widget::Sizer::modeHori);
	if (nullptr == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
	
		mySpacer = ewol::widget::Spacer::create();
		if (nullptr != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(etk::Color<>(0x00, 0xFF, 0x00, 0x80));
			mySizerHori->subWidgetAdd(mySpacer);
		}
		m_testWidget = ewol::widget::ButtonColor::create(etk::color::olive);
		if (nullptr != m_testWidget) {
			m_testWidget->setExpand(bvec2(false,false));
			m_testWidget->setFill(bvec2(false,false));
			m_testWidget->registerOnEvent(shared_from_this(), "*");
			mySizerHori->subWidgetAdd(m_testWidget);
		}
		mySpacer = ewol::widget::Spacer::create();
		if (nullptr != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(etk::Color<>(0x00, 0x00, 0xFF, 0x80));
			mySizerHori->subWidgetAdd(mySpacer);
		}
		
	mySpacer = ewol::widget::Spacer::create();
	if (nullptr != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(etk::Color<>(0x00, 0xFF, 0xFF, 0x80));
		subWidgetAdd(mySpacer);
	}
}

void appl::TestButtonColor::onReceiveMessage(const ewol::object::Message& _msg) {
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

