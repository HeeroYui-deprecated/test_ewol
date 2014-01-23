/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/debug.h>
#include <appl/TestButton.h>

#include <ewol/widget/Button.h>
#include <ewol/widget/CheckBox.h>
#include <ewol/widget/Sizer.h>
#include <ewol/widget/Label.h>
#include <ewol/widget/Entry.h>
#include <ewol/widget/List.h>
#include <ewol/widget/ContextMenu.h>
#include <ewol/widget/PopUp.h>
#include <ewol/widget/Slider.h>
#include <ewol/widget/Composer.h>
#include <ewol/widget/Menu.h>
#include <ewol/widget/meta/FileChooser.h>
#include <ewol/widget/meta/Parameter.h>
#include <ewol/widget/Manager.h>


static const char * l_eventChangeExpendX     = "event-change-expend-X";
static const char * l_eventChangeExpendY     = "event-change-expend-Y";
static const char * l_eventChangeFillX       = "event-change-fill-X";
static const char * l_eventChangeFillY       = "event-change-fill-Y";
static const char * l_eventChangeToggle      = "event-change-toggle-mode";
static const char * l_eventChangeText        = "event-change-text";
static const char * l_eventChangeTextToggle  = "event-change-text-toggle";
static const char * l_eventChangeImage       = "event-change-image";
static const char * l_eventChangeImageToggle = "event-change-image-toggle";

#undef __class__
#define __class__	"TestButton"

TestButton::TestButton(void) :
  ewol::widget::Sizer(ewol::widget::Sizer::modeVert),
  m_testWidget(NULL) {
	APPL_INFO("Create " __class__ " (start)");
	ewol::widget::Sizer* mySizerVert2 = NULL;
	ewol::widget::Sizer* mySizerHori = NULL;
	ewol::widget::Button*    myButton = NULL;
	
	mySizerHori = new ewol::widget::Sizer(ewol::widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
		myButton = new ewol::widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new ewol::widget::Label("Expend X <br/> (false)"));
			myButton->setSubWidgetToggle(new ewol::widget::Label("Expend X <br/><b>(true)</b>"));
			myButton->registerOnEvent(this, "value", l_eventChangeExpendX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = new ewol::widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new ewol::widget::Label("Expend Y <br/> (false)"));
			myButton->setSubWidgetToggle(new ewol::widget::Label("Expend Y <br/><b>(true)</b>"));
			myButton->registerOnEvent(this, "value", l_eventChangeExpendY);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = new ewol::widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new ewol::widget::Label("Toggle<br/>(false)"));
			myButton->setSubWidgetToggle(new ewol::widget::Label("Toggle<br/><b>(true)</b>"));
			myButton->registerOnEvent(this, "value", l_eventChangeToggle);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = new ewol::widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new ewol::widget::Label("Text On toggle state<br/>(false)"));
			myButton->setSubWidgetToggle(new ewol::widget::Label("Text On toggle state<br/><b>(true)</b>"));
			myButton->registerOnEvent(this, "value", l_eventChangeTextToggle);
			mySizerHori->subWidgetAdd(myButton);
		}
	
	mySizerHori = new ewol::widget::Sizer(ewol::widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
		
		myButton = new ewol::widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new ewol::widget::Label("Fill X <br/> (false)"));
			myButton->setSubWidgetToggle(new ewol::widget::Label("Fill X <br/> (true)"));
			myButton->registerOnEvent(this, "value", l_eventChangeFillX);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = new ewol::widget::Button();
		if (NULL != myButton) {
			myButton->setToggleMode(true);
			myButton->setSubWidget(      new ewol::widget::Label("Fill Y <br/> (false)"));
			myButton->setSubWidgetToggle(new ewol::widget::Label("Fill Y <br/> (true)"));
			myButton->registerOnEvent(this, "value", l_eventChangeFillY);
			mySizerHori->subWidgetAdd(myButton);
		}
		myButton = new ewol::widget::Button();
		if (NULL != myButton) {
			myButton->setSubWidget(new ewol::widget::Label("Change Text<br/> and other ..."));
			myButton->registerOnEvent(this, "pressed", l_eventChangeText);
			mySizerHori->subWidgetAdd(myButton);
		}
	ewol::widget::Spacer* mySpacer = new ewol::widget::Spacer();
	if (NULL != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(0xFF000080);
		subWidgetAdd(mySpacer);
	}
	
	mySizerHori = new ewol::widget::Sizer(ewol::widget::Sizer::modeHori);
	if (NULL == mySizerHori) {
		APPL_DEBUG("Allocation error mySizerHori");
		return;
	}
	subWidgetAdd(mySizerHori);
	
		mySpacer = new ewol::widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(0x00FF0080);
			mySizerHori->subWidgetAdd(mySpacer);
		}
		
		m_testWidget = new ewol::widget::Button();
		if (NULL != m_testWidget) {
			m_testWidget->setSubWidget(new ewol::widget::Label("My <font color=\"#FF0000\">Button</font> <br/> And Some under line<br/> plop <br/> and an other super long line ..."));
			m_testWidget->setExpand(bvec2(false,false));
			m_testWidget->setFill(bvec2(false,false));
			m_testWidget->registerOnEvent(this, "*");
			mySizerHori->subWidgetAdd(m_testWidget);
		}
		
		mySpacer = new ewol::widget::Spacer();
		if (NULL != mySpacer) {
			mySpacer->setExpand(bvec2(false,false));
			mySpacer->setFill(bvec2(false,true));
			mySpacer->setMinSize(vec2(10,10));
			mySpacer->setColor(0x0000FF80);
			mySizerHori->subWidgetAdd(mySpacer);
		}
		
	mySpacer = new ewol::widget::Spacer();
	if (NULL != mySpacer) {
		mySpacer->setExpand(bvec2(false,false));
		mySpacer->setFill(bvec2(true,false));
		mySpacer->setMinSize(vec2(10,10));
		mySpacer->setColor(0x00FFFF80);
		subWidgetAdd(mySpacer);
	}
	APPL_INFO("Create " __class__ " (end)");
}


TestButton::~TestButton(void) {
	APPL_INFO("Remove " __class__ " ...");
}


void TestButton::onReceiveMessage(const ewol::object::Message& _msg) {
	ewol::widget::Sizer::onReceiveMessage(_msg);
	APPL_VERBOSE("Receive Event from the main windows ... : " << _msg );
	if (m_testWidget == _msg.getCaller()) {
		APPL_WARNING("Receive Event from tested Button ... : " << _msg );
	}
	if (_msg.getMessage() == l_eventChangeExpendX) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setExpand(bvec2(true,m_testWidget->getExpand().y()));
			} else {
				m_testWidget->setExpand(bvec2(false,m_testWidget->getExpand().y()));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeExpendY) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setExpand(bvec2(m_testWidget->getExpand().x(),true));
			} else {
				m_testWidget->setExpand(bvec2(m_testWidget->getExpand().x(),false));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeFillX) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setFill(bvec2(true,m_testWidget->getFill().y()));
			} else {
				m_testWidget->setFill(bvec2(false,m_testWidget->getFill().y()));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeFillY) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setFill(bvec2(m_testWidget->getFill().x(),true));
			} else {
				m_testWidget->setFill(bvec2(m_testWidget->getFill().x(),false));
			}
		}
	} else if (_msg.getMessage() == l_eventChangeToggle) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setToggleMode(true);
			} else {
				m_testWidget->setToggleMode(false);
			}
		}
	} else if (_msg.getMessage() == l_eventChangeTextToggle) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setSubWidgetToggle(new ewol::widget::Label("A stupid very long text on toggle <br/><br/> and on multiple lines"));
			} else {
				m_testWidget->setSubWidgetToggle(NULL);
			}
		}
	} else if (_msg.getMessage() == l_eventChangeImage) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="true") {
				//m_testWidget->SetImage("THEME:GUI:icon.png");
				//m_testWidget->SetImageSize(50);
			} else {
				//m_testWidget->SetImage("");
			}
		}
	} else if (_msg.getMessage() == l_eventChangeImageToggle) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="true") {
				//m_testWidget->SetImageToggle("THEME:GUI:icon.png");
			} else {
				//m_testWidget->SetImageToggle("");
			}
		}
	} else if (_msg.getMessage() == l_eventChangeText) {
		if (NULL!=m_testWidget) {
			static int32_t countTextID = 1;
			switch (countTextID) {
				case 0:
					m_testWidget->setSubWidget(new ewol::widget::Label("simple Text"));
					break;
				case 1:
					m_testWidget->setSubWidget(new ewol::widget::Label("<left>Align Left</left>"));
					break;
				case 2:
					m_testWidget->setSubWidget(new ewol::widget::Label("<right>Align right</right>"));
					break;
				case 3:
					m_testWidget->setSubWidget(new ewol::widget::Label("<center>Align center</center>"));
					break;
				case 4:
					m_testWidget->setSubWidget(new ewol::widget::Label("simple Text<br/> With Some Other Lines<br/> and more if you want ...<br/> plop"));
					break;
				case 5:
					m_testWidget->setSubWidget(new ewol::widget::Label("simple <bold>Text</bold> with bold"));
					break;
				case 6:
					m_testWidget->setSubWidget(new ewol::widget::Label("simple <italic>Text</italic> with italic"));
					break;
				case 7:
					m_testWidget->setSubWidget(new ewol::widget::Label("simple <italic><bold>Text</bold></italic> with italic bold"));
					break;
				case 8:
					m_testWidget->setSubWidget(NULL);
					break;
				case 9:
					m_testWidget->setSubWidget(new ewol::widget::Label("simple <font color=\"#FFFF0088\">Text</font> with colored text"));
					break;
				case 10:
					m_testWidget->setSubWidget(
					    new ewol::widget::Composer(ewol::widget::Composer::String,
					        "<composer>\n"
					        "	<label>ploppp</label>\n"
					        "</composer>\n"));
					break;
				case 11:
					m_testWidget->setSubWidget(
					    new ewol::widget::Composer(ewol::widget::Composer::String,
					        "<composer>\n"
					        "	<sizer mode=\"vert\" addmode=\"invert\">\n"
					        "		<label>ploppp</label>\n"
					        "		<label expand=\"true,true\"><center>** ** * *<br/>** * * * *</center></label>\n"
					        "	</sizer>\n"
					        "	\n"
					        "	\n"
					        "</composer>\n"));
					break;
				default:
					m_testWidget->setSubWidget(new ewol::widget::Label("My <font color=\"#FF0000\">Button</font> <br/> And Some under line<br/> plop <br/> and an other super long line ..."));
					countTextID=-1;
					break;
			}
			// set at the subWidget all the space they can ...
			if (NULL != m_testWidget->getSubWidget()){
				m_testWidget->getSubWidget()->setFill(bvec2(true,true));
				m_testWidget->getSubWidget()->setExpand(bvec2(true,true));
			}
			countTextID++;
		}
	}
	
	return;
}

void TestButton::onObjectRemove(ewol::Object* _removeObject) {
	ewol::widget::Sizer::onObjectRemove(_removeObject);
	if (m_testWidget == _removeObject) {
		m_testWidget = NULL;
	}
}
