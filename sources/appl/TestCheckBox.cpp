/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/debug.h>
#include <appl/TestCheckBox.h>

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
#define __class__	"TestCheckBox"

appl::TestCheckBox::TestCheckBox(void) :
  m_testWidget(NULL) {
	APPL_INFO("Create " __class__ " (start)");
	
	std::string myDescription = std::string("")
	      + "<sizer mode='vert' fill='true' expand='true'>\n"
	      + "	<sizer mode='hori'>\n"
	      + "		<button name='[TEST]Button:Expand-x' toggle='true'>\n"
	      + "			<label>Expend X <br/> (false)</label>\n"
	      + "			<label>Expend X <br/> <b>(true)</b></label>\n"
	      + "		</button>\n"
	      + "		<button name='[TEST]Button:Expand-y' toggle='true'>\n"
	      + "			<label>Expend Y <br/> (false)</label>\n"
	      + "			<label>Expend Y <br/> <b>(true)</b></label>\n"
	      + "		</button>\n"
	      + "		<button name='[TEST]Button:Toggle' toggle='true'>\n"
	      + "			<label>Toggle <br/> (false)</label>\n"
	      + "			<label>Toggle <br/> <b>(true)</b></label>\n"
	      + "		</button>\n"
	      + "		<button name='[TEST]Button:TextToggle' toggle='true'>\n"
	      + "			<label>Text On toggle state <br/> (false)</label>\n"
	      + "			<label>Text On toggle state <br/> <b>(true)</b></label>\n"
	      + "		</button>\n"
	      + "	</sizer>\n"
	      + "	<sizer mode='hori'>\n"
	      + "		<button name='[TEST]Button:Fill-x' toggle='true'>\n"
	      + "			<label>Fill X <br/> (false)</label>\n"
	      + "			<label>Fill X <br/> <b>(true)</b></label>\n"
	      + "		</button>\n"
	      + "		<button name='[TEST]Button:Fill-y' toggle='true'>\n"
	      + "			<label>Fill Y <br/> (false)</label>\n"
	      + "			<label>Fill Y <br/> <b>(true)</b></label>\n"
	      + "		</button>\n"
	      + "		<button name='[TEST]Button:ChangeText'>\n"
	      + "			<label>Change Text<br/> and other ...</label>\n"
	      + "		</button>\n"
	      + "	</sizer>\n"
	      + "	<sizer mode='hori'>\n"
	      + "		<spacer expand='false,false' fill='true,false' min-size='10,10px' color='#F008'/>\n"
	      + "		<sizer mode='vert'>\n"
	      + "			<spacer expand='false,false' fill='false,true' min-size='10,10px' color='#FF08'/>\n"
	      + "			<CheckBox name='[TEST]TO-TEST' expand='false,false' fill='false,false' >\n"
	      + "				<label>My <font color='#FF0000'>CheckBox</font> <br/> And Some under line<br/> plop <br/> and an other super long line ...</label>\n"
	      + "			</CheckBox>\n"
	      + "			<spacer expand='false,false' fill='false,true' min-size='10,10px' color='#0FF8'/>\n"
	      + "		</sizer>\n"
	      + "		<spacer expand='false,false' fill='true,false' min-size='10,10px' color='#0F08'/>\n"
	      + "	</sizer>\n"
	      + "</sizer>";
	loadFromString(myDescription);
	setExpand(bvec2(true,true));
	setFill(bvec2(true,true));
	registerOnEventNameWidget("[TEST]Button:Expand-x", "value", l_eventChangeExpendX);
	registerOnEventNameWidget("[TEST]Button:Expand-y", "value", l_eventChangeExpendY);
	registerOnEventNameWidget("[TEST]Button:Toggle", "value", l_eventChangeToggle);
	registerOnEventNameWidget("[TEST]Button:TextToggle", "value", l_eventChangeTextToggle);
	registerOnEventNameWidget("[TEST]Button:Fill-x", "value", l_eventChangeFillX);
	registerOnEventNameWidget("[TEST]Button:Fill-y", "value", l_eventChangeFillY);
	registerOnEventNameWidget("[TEST]Button:ChangeText", "pressed", l_eventChangeText);
	// show all event from a button :
	registerOnEventNameWidget("[TEST]TO-TEST", "*");
	m_testWidget = dynamic_cast<ewol::widget::CheckBox*>(getWidgetNamed("[TEST]TO-TEST"));
	if (m_testWidget == NULL) {
		APPL_CRITICAL("Can not get the pointer of the widget button pointer");
	}
	APPL_INFO("Create " __class__ " (end)");
}

void appl::TestCheckBox::onReceiveMessage(const ewol::object::Message& _msg) {
	ewol::widget::Composer::onReceiveMessage(_msg);
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
	} else if (_msg.getMessage() == l_eventChangeTextToggle) {
		if (NULL!=m_testWidget) {
			if (_msg.getData()=="true") {
				m_testWidget->setSubWidgetToggle(new ewol::widget::Label("A stupid very long text on toggle <br/><br/> and on multiple lines"));
			} else {
				m_testWidget->setSubWidgetToggle(NULL);
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

void appl::TestCheckBox::onObjectRemove(ewol::Object* _removeObject) {
	ewol::widget::Composer::onObjectRemove(_removeObject);
	if (m_testWidget == _removeObject) {
		m_testWidget = NULL;
	}
}
