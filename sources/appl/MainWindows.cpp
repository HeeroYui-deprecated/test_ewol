/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/Debug.h>
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
#include <ewol/widget/WidgetManager.h>
#include <ewol/renderer/eContext.h>
#include <appl/TestButton.h>
#include <appl/TestButtonColor.h>
#include <appl/TestLabel.h>
#include <appl/TestImage.h>
//#include <appl/TestScene.h>


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
	widget::Sizer* mySizerHori = NULL;
	widget::Button* myButton = NULL;
	
	m_sizerVert = new widget::Sizer(widget::Sizer::modeVert);
	if (NULL == m_sizerVert) {
		APPL_DEBUG("Allocation error mySizerVert");
		return;
	}
	setSubWidget(m_sizerVert);
		
		mySizerHori = new widget::Sizer(widget::Sizer::modeHori);
		if (NULL == mySizerHori) {
			APPL_DEBUG("Allocation error mySizerHori");
			return;
		}
		m_sizerVert->subWidgetAdd(mySizerHori);
			myButton = new widget::Button();
			if (NULL != myButton) {
				myButton->setSubWidget(new widget::Label("default theme (cube)"));
				myButton->setSubWidgetToggle(new widget::Label("rounded theme"));
				myButton->setToggleMode(true);
				myButton->registerOnEvent(this, widget::Button::eventValue, l_eventChangeTheme);
				mySizerHori->subWidgetAdd(myButton);
			}
			myButton = new widget::Button();
			if (NULL != myButton) {
				myButton->setSubWidget(new widget::Label("Previous Widget test"));
				myButton->registerOnEvent(this, widget::Button::eventPressed, l_eventChangeWidgetPrevious);
				mySizerHori->subWidgetAdd(myButton);
			}
			myButton = new widget::Button();
			if (NULL != myButton) {
				myButton->setSubWidget(new widget::Label("Next Widget test"));
				myButton->registerOnEvent(this, widget::Button::eventPressed, l_eventChangeWidgetNext);
				mySizerHori->subWidgetAdd(myButton);
			}
			m_testName = new widget::Label("none");
			if (NULL != m_testName) {
				mySizerHori->subWidgetAdd(m_testName);
			}
		widget::Spacer* mySpacer = new widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(true,false));
			mySpacer->setMinSize(vec2(3,3));
			mySpacer->setColor(0x000000FF);
			m_sizerVert->subWidgetAdd(mySpacer);
		}
		// add the basic widget with a strange methode ...
		ewol::EMessage msg(NULL, NULL, "");
		onReceiveMessage(msg);
}

MainWindows::~MainWindows(void) {
	
}

void MainWindows::onReceiveMessage(const ewol::EMessage& _msg) {
	if(    _msg.getCaller() != this
	    && _msg.getCaller() != NULL) {
		ewol::Windows::onReceiveMessage(_msg);
	}
	APPL_INFO("Receive Event from the main windows ... : " << _msg );
	if (_msg.getMessage() == l_eventChangeTheme) {
		if (_msg.getData()=="1") {
			etk::theme::setName("GUI", "rounded");
		} else {
			etk::theme::setName("GUI", "default");
		}
		// Reload shaders and graphic system ...
		ewol::getContext().getResourcesManager().reLoadResources();
		return;
	} else if (_msg.getMessage() == l_eventChangeWidgetPrevious) {
		m_idWidget--;
	} else if (_msg.getMessage() == l_eventChangeWidgetNext) {
		m_idWidget++;
	}
	
	if (m_subWidget != NULL) {
		delete (m_subWidget);
		// inn theory it must be removed ...
		m_subWidget = NULL;
	}
	// special init forcing ...
	if(_msg.getCaller() == NULL) {
		m_idWidget = 1;
	}
	switch(m_idWidget)
	{
		default:
			m_idWidget = 0;
		case 0:
			m_subWidget = (ewol::Widget*)new widget::Label("Test software for EWOL");
			if (NULL != m_subWidget) {
				m_subWidget->setExpand(bvec2(true,true));
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("Label");
			};
			break;
		case 1:
			m_subWidget = (ewol::Widget*)new TestButton();
			if (NULL != m_subWidget) {
				m_sizerVert->subWidgetAdd(m_subWidget);
			}
			if (m_testName!=NULL) {
				m_testName->setLabel("TestButton");
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

void MainWindows::onObjectRemove(ewol::EObject* _removeObject) {
	ewol::Windows::onObjectRemove(_removeObject);
	if (m_subWidget == _removeObject) {
		m_subWidget = NULL;
	} else if (m_sizerVert == _removeObject) {
		m_sizerVert = NULL;
	} else if (m_testName == _removeObject) {
		m_testName = NULL;
	}
}
