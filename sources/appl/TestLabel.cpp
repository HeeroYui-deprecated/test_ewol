/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */


#include <appl/Debug.h>
#include <appl/TestLabel.h>

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
static const char * l_eventChangeMaxSize     = "event-change-maxSize";
static const char * l_eventChangeLabel       = "event-change-label";

#undef __class__
#define __class__	"TestButton"

TestLabel::TestLabel(void) :
	widget::Sizer(widget::Sizer::modeVert),
	m_labelId(0)
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
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetToggleMode(true);
			myButton->SetSubWidget(      new widget::Label("no Max size"));
			myButton->SetSubWidgetToggle(new widget::Label("maxSize (400,99999999)"));
			myButton->RegisterOnEvent(this, ewolEventButtonValue, l_eventChangeMaxSize);
			mySizerHori->SubWidgetAdd(myButton);
		}
		myButton = new widget::Button();
		if (NULL != myButton) {
			myButton->SetSubWidget(new widget::Label("Next Label"));
			myButton->RegisterOnEvent(this, ewolEventButtonPressed, l_eventChangeLabel);
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
		
		m_testWidget = new widget::Label("Basic label");
		if (NULL != m_testWidget) {
			m_testWidget->SetExpand(bvec2(false,false));
			m_testWidget->SetFill(bvec2(false,false));
			//m_testWidget->RegisterOnEvent(this, ewolEventButtonColorChange);
			mySizerHori->SubWidgetAdd(m_testWidget);
		}
		
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


TestLabel::~TestLabel(void)
{
	
}


void TestLabel::OnReceiveMessage(ewol::EObject * CallerObject, const char * eventId, const etk::UString& data)
{
	widget::Sizer::OnReceiveMessage(CallerObject, eventId, data);
	
	//APPL_INFO("Receive Event from the main windows ... : \"" << eventId << "\" ==> data=\"" << data << "\"" );
	if (m_testWidget == CallerObject) {
		APPL_WARNING("Receive Event from tested Button ... : \"" << eventId << "\" ==> data=\"" << data << "\"" );
	}
	
	if (eventId == l_eventChangeExpendX) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetExpand(bvec2(true,m_testWidget->GetExpand().y()));
			} else {
				m_testWidget->SetExpand(bvec2(true,m_testWidget->GetExpand().y()));
			}
		}
	} else if (eventId == l_eventChangeExpendY) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetExpand(bvec2(m_testWidget->GetExpand().x(),true));
			} else {
				m_testWidget->SetExpand(bvec2(m_testWidget->GetExpand().x(),false));
			}
		}
	} else if (eventId == l_eventChangeFillX) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetFill(bvec2(true,m_testWidget->GetFill().y()));
			} else {
				m_testWidget->SetFill(bvec2(false,m_testWidget->GetFill().y()));
			}
		}
	} else if (eventId == l_eventChangeFillY) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetFill(bvec2(m_testWidget->GetFill().x(),true));
			} else {
				m_testWidget->SetFill(bvec2(m_testWidget->GetFill().x(),false));
			}
		}
	} else if (eventId == l_eventChangeMaxSize) {
		if (NULL!=m_testWidget) {
			if (data=="1") {
				m_testWidget->SetMaxSize(vec2(400,9999999999));
			} else {
				m_testWidget->SetNoMaxSize();
			}
		}
	} else if (eventId == l_eventChangeLabel) {
		if (NULL!=m_testWidget) {
			m_labelId++;
			switch(m_labelId)
			{
				default:
					m_labelId=0;
				case 0:
					m_testWidget->SetLabel("Basic label");
					break;
				case 1:
					m_testWidget->SetLabel("Basic <bold>label</bold>");
					break;
				case 2:
					m_testWidget->SetLabel("<center>\n"
					                       "	Un jour Cosette se <b>regarda</b> par hasard dans son miroir et se dit: Tiens! <b>Il lui semblait presque <i>qu'elle était jolie.</i></b> Ceci la jeta dans un trouble singulier. <font color=\"#FF0000\">Jusqu'à ce moment elle <b>n'avait</b> point <i>songé</i> à sa figure.</font> Elle se voyait dans son miroir, mais elle ne s'y regardait pas. Et puis, on lui avait souvent dit qu'elle était laide;<br/> Jean Valjean seul disait doucement : <br/> Mais non!<br/>  mais non!<br/>  Quoi qu'il en fut, Cosette s'était toujours crue laide, et avait grandi dans cette idée avec la résignation facile de l'enfance. Voici que tout d'un coup son miroir lui disait comme Jean Valjean : Mais non! Elle ne dormit pas de la nuit. Si j'étais jolie ? pensait-elle, comme cela serait drole que je fusse jolie! Et elle se rappelait celles de ses compagnes dont la beauté faisait effet dans le couvent, et elle se disait : Comment! je serais comme mademoiselle une telle!\n"
					                       "</center>\n");
					break;
				case 3:
					m_testWidget->SetLabel("<left>\n"
					                       "	Un jour Cosette se <b>regarda</b> par hasard dans son miroir et se dit: Tiens! <b>Il lui semblait presque <i>qu'elle était jolie.</i></b> Ceci la jeta dans un trouble singulier. <font color=\"#0F0\">Jusqu'à ce moment elle <b>n'avait</b> point <i>songé</i> à sa figure.</font> Elle se voyait dans son miroir, mais elle ne s'y regardait pas. Et puis, on lui avait souvent dit qu'elle était laide;<br/> Jean Valjean seul disait doucement :<br/>  Mais non!<br/>  mais non!<br/>  Quoi qu'il en fut, Cosette s'était toujours crue laide, et avait grandi dans cette idée avec la résignation facile de l'enfance. Voici que tout d'un coup son miroir lui disait comme Jean Valjean : Mais non! Elle ne dormit pas de la nuit. Si j'étais jolie ? pensait-elle, comme cela serait drole que je fusse jolie! Et elle se rappelait celles de ses compagnes dont la beauté faisait effet dans le couvent, et elle se disait : Comment! je serais comme mademoiselle une telle!\n"
					                       "</left>\n");
					break;
				case 4:
					m_testWidget->SetLabel("<right>\n"
					                       "	Un jour Cosette se <b>regarda</b> par hasard dans son miroir et se dit: Tiens! <b>Il lui semblait presque <i>qu'elle était jolie.</i></b> Ceci la jeta dans un trouble singulier. <font color=\"#00F\">Jusqu'à ce moment elle<b> n'avait</b> point <i>songé</i> à sa figure.</font> Elle se voyait dans son miroir, mais elle ne s'y regardait pas. Et puis, on lui avait souvent dit qu'elle était laide;<br/> Jean Valjean seul disait doucement :<br/>  Mais non! <br/> mais non!<br/>  Quoi qu'il en fut, Cosette s'était toujours crue laide, et avait grandi dans cette idée avec la résignation facile de l'enfance. Voici que tout d'un coup son miroir lui disait comme Jean Valjean : Mais non! Elle ne dormit pas de la nuit. Si j'étais jolie ? pensait-elle, comme cela serait drole que je fusse jolie! Et elle se rappelait celles de ses compagnes dont la beauté faisait effet dans le couvent, et elle se disait : Comment! je serais comme mademoiselle une telle!\n"
					                       "</right>\n");
					break;
				case 5:
					m_testWidget->SetLabel("<justify>\n"
					                       "	Un jour Cosette se <b>regarda</b> par hasard dans son miroir et se dit: Tiens! <b>Il lui semblait presque <i>qu'elle était jolie.</i></b> Ceci la jeta dans un trouble singulier. <font color=\"#FF0\">Jusqu'à ce moment elle <b>n'avait</b> point <i>songé</i> à sa figure.</font> Elle se voyait dans son miroir, mais elle ne s'y regardait pas. Et puis, on lui avait souvent dit qu'elle était laide;<br/> Jean Valjean seul disait doucement :<br/>  Mais non!<br/>  mais non!<br/>  Quoi qu'il en fut, Cosette s'était toujours crue laide, et avait grandi dans cette idée avec la résignation facile de l'enfance. Voici que tout d'un coup son miroir lui disait comme Jean Valjean : Mais non! Elle ne dormit pas de la nuit. Si j'étais jolie ? pensait-elle, comme cela serait drole que je fusse jolie! Et elle se rappelait celles de ses compagnes dont la beauté faisait effet dans le couvent, et elle se disait : Comment! je serais comme mademoiselle une telle!\n"
					                       "</justify>\n");
					break;
			}
		}
	}
	
	return;
}

void TestLabel::OnObjectRemove(ewol::EObject * removeObject)
{
	widget::Sizer::OnObjectRemove(removeObject);
	if (m_testWidget == removeObject) {
		m_testWidget = NULL;
	}
}
