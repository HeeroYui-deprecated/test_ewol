/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/debug.h>
#include <appl/MainWindows.h>

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
#include <ewol/context/Context.h>
#include <appl/TestButton.h>
#include <appl/TestCheckBox.h>
#include <appl/TestButtonColor.h>
#include <appl/TestLabel.h>
#include <appl/TestImage.h>
#include <appl/TestDistanceField.h>
#include <etk/os/FSNode.h>


static const char * l_eventChangeTheme           = "event-change-theme";
static const char * l_eventChangeWidgetNext      = "event-change-widget-test-next";
static const char * l_eventChangeWidgetPrevious  = "event-change-widget-test-previous";


#undef __class__
#define __class__ "MainWindows"

MainWindows::MainWindows(void) :
  m_idWidget(0),
  m_subWidget(NULL),
  m_testName(NULL) {
	APPL_DEBUG("CREATE WINDOWS ... ");
	ewol::widget::Sizer* mySizerHori = NULL;
	ewol::widget::Button* myButton = NULL;
	
	m_sizerVert = new ewol::widget::Sizer(ewol::widget::Sizer::modeVert);
	if (NULL == m_sizerVert) {
		APPL_DEBUG("Allocation error mySizerVert");
		return;
	}
	setSubWidget(m_sizerVert);
		
		mySizerHori = new ewol::widget::Sizer(ewol::widget::Sizer::modeHori);
		if (NULL == mySizerHori) {
			APPL_DEBUG("Allocation error mySizerHori");
			return;
		}
		m_sizerVert->subWidgetAdd(mySizerHori);
			myButton = new ewol::widget::Button();
			if (NULL != myButton) {
				myButton->setSubWidget(new ewol::widget::Label("default theme (cube)"));
				myButton->setSubWidgetToggle(new ewol::widget::Label("rounded theme"));
				myButton->setToggleMode(true);
				myButton->registerOnEvent(this, "value", l_eventChangeTheme);
				mySizerHori->subWidgetAdd(myButton);
			}
			myButton = new ewol::widget::Button();
			if (NULL != myButton) {
				myButton->setSubWidget(new ewol::widget::Label("Previous Widget test"));
				myButton->registerOnEvent(this, "pressed", l_eventChangeWidgetPrevious);
				mySizerHori->subWidgetAdd(myButton);
			}
			myButton = new ewol::widget::Button();
			if (NULL != myButton) {
				myButton->setSubWidget(new ewol::widget::Label("Next Widget test"));
				myButton->registerOnEvent(this, "pressed", l_eventChangeWidgetNext);
				mySizerHori->subWidgetAdd(myButton);
			}
			m_testName = new ewol::widget::Label("none");
			if (NULL != m_testName) {
				mySizerHori->subWidgetAdd(m_testName);
			}
		ewol::widget::Spacer* mySpacer = new ewol::widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(true,false));
			mySpacer->setMinSize(vec2(3,3));
			mySpacer->setColor(0x000000FF);
			m_sizerVert->subWidgetAdd(mySpacer);
		}
		// add the basic widget with a strange methode ...
		ewol::object::Message msg(NULL, NULL, "");
		onReceiveMessage(msg);
}

MainWindows::~MainWindows(void) {
	
}

void MainWindows::onReceiveMessage(const ewol::object::Message& _msg) {
	if(    _msg.getCaller() != this
	    && _msg.getCaller() != NULL) {
		ewol::widget::Windows::onReceiveMessage(_msg);
	}
	APPL_INFO("Receive Event from the main windows ... : " << _msg );
	if (_msg.getMessage() == l_eventChangeTheme) {
		if (_msg.getData()=="true") {
			etk::theme::setName("GUI", "shape/round/");
		} else {
			etk::theme::setName("GUI", "shape/square/");
		}
		// Reload shaders and graphic system ...
		ewol::getContext().getResourcesManager().reLoadResources();
		ewol::getContext().forceRedrawAll();
		return;
	} else if (_msg.getMessage() == l_eventChangeWidgetPrevious) {
		m_idWidget--;
	} else if (_msg.getMessage() == l_eventChangeWidgetNext) {
		m_idWidget++;
	}
	
	if (m_subWidget != NULL) {
		m_subWidget->removeObject();
		// in theory it must be removed ...
		m_subWidget = NULL;
	}
	// special init forcing ...
	if(_msg.getCaller() == NULL) {
		m_idWidget = 0;
	}
	switch(m_idWidget) {
		case 0:
			m_subWidget = (ewol::Widget*)new appl::TestButton();
			if (NULL != m_subWidget) {
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("TestButton");
			};
			break;
		case 1:
			m_subWidget = (ewol::Widget*)new TestDistanceField();
			if (NULL != m_subWidget) {
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("Test Distance Field");
			};
			break;
		case 2:
			m_subWidget = (ewol::Widget*)new TestButtonColor();
			if (NULL != m_subWidget) {
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("TestButtonColor");
			};
			break;
		case 3:
			m_subWidget = (ewol::Widget*)new TestLabel();
			if (NULL != m_subWidget) {
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("TestLabel");
			};
			break;
		case 4:
			m_subWidget = (ewol::Widget*)new TestImage();
			if (NULL != m_subWidget) {
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("TestImage");
			};
			break;
		case 5:
			m_subWidget = (ewol::Widget*)new appl::TestCheckBox();
			if (NULL != m_subWidget) {
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("TestButton");
			};
			break;
		default:
			m_subWidget = (ewol::Widget*)new ewol::widget::Label("Test software for EWOL");
			if (NULL != m_subWidget) {
				m_subWidget->setExpand(bvec2(true,true));
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("Label");
			};
			m_idWidget = 0;
			break;
		/*case 5:
			m_subWidget = (ewol::Widget*)new TestScene();
			if (NULL != m_subWidget) {
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("TestScene");
			};
			break;
		*/
	}
}

void MainWindows::onObjectRemove(ewol::Object* _removeObject) {
	ewol::widget::Windows::onObjectRemove(_removeObject);
	if (m_subWidget == _removeObject) {
		m_subWidget = NULL;
	} else if (m_sizerVert == _removeObject) {
		m_sizerVert = NULL;
	} else if (m_testName == _removeObject) {
		m_testName = NULL;
	}
}
