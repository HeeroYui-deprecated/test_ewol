/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#include <etk/types.h>
#include <etk/UString.h>
#include <etk/os/FSNode.h>
#include <ewol/ewol.h>
#include <ewol/Dimension.h>
//#include <ewol/config.h>
#include <ewol/commandLine.h>
#include <ewol/renderer/EObject.h>
#include <ewol/renderer/eContext.h>
#include <ewol/widget/WidgetManager.h>

#include <appl/Debug.h>
#include <appl/MainWindows.h>



/**
 * @brief Main of the program (This can be set in every case, but it is not used in Andoid...).
 * @param std IO
 * @return std IO
 */
int main(int argc, const char *argv[])
{
	// only one things to do : 
	return ewol::Run(argc, argv);
}

void tmpTestOfTheFSNode(void)
{
	APPL_INFO("==> Start test of FSNode");
	etk::UString fileName("USERDATA:myFileTest.txt");
	etk::FSNode myNodeTest1(fileName);
	APPL_INFO("********************************************");
	APPL_INFO("** Filename=\"" << fileName << "\"");
	APPL_INFO("********************************************");
	APPL_INFO("      GetNameFolder()      =\"" <<myNodeTest1.GetNameFolder() << "\"");
	APPL_INFO("      GetName()            =\"" <<myNodeTest1.GetName() << "\"");
	APPL_INFO("      GetNameFile()        =\"" <<myNodeTest1.GetNameFile() << "\"");
	APPL_INFO("      GetRelativeFolder()  =\"" <<myNodeTest1.GetRelativeFolder() << "\"");
	APPL_INFO("      exist                =" <<myNodeTest1.Exist());
	if (true==myNodeTest1.Exist()) {
		APPL_ERROR(" ==> remove the file ==> bad for the test");
	} else {
		APPL_INFO("      Display time when file does not exist :");
		APPL_INFO("          TimeCreatedString()  =\"" <<myNodeTest1.TimeCreatedString() << "\"");
		APPL_INFO("          TimeModifiedString() =\"" <<myNodeTest1.TimeModifiedString() << "\"");
		APPL_INFO("          TimeAccessedString() =\"" <<myNodeTest1.TimeAccessedString() << "\"");
	}
	myNodeTest1.Touch();
	if (false==myNodeTest1.Exist()) {
		APPL_ERROR(" ==> Error, can not create the file ....");
	} else {
		APPL_INFO("      Display time when file does exist :");
		APPL_INFO("          TimeCreatedString()  =\"" <<myNodeTest1.TimeCreatedString() << "\"");
		APPL_INFO("          TimeModifiedString() =\"" <<myNodeTest1.TimeModifiedString() << "\"");
		APPL_INFO("          TimeAccessedString() =\"" <<myNodeTest1.TimeAccessedString() << "\"");
	}
	// Try remove the file : 
	myNodeTest1.Remove();
	if (true==myNodeTest1.Exist()) {
		APPL_ERROR(" ==> The file might be removed ==> but it is not the case ...");
	} else {
		APPL_INFO(" ==> The file is removed");
	}
	APPL_INFO("********************************************");
	
	
	APPL_INFO("==> Stop test of FSNode");
	
	exit(0);
}

void tmpTestOfTheDimension(void)
{
	APPL_INFO("==> test of Dimension (START)");
	
	ewol::Dimension myDimention(vec2(5,5), ewol::Dimension::Centimeter);
	APPL_INFO("    set dimension at : " << myDimention);
	APPL_INFO("    set dimension at : " << myDimention.GetCentimeter() << " cm");
	APPL_INFO("    set dimension at : " << myDimention.GetMillimeter() << " mm");
	APPL_INFO("    set dimension at : " << myDimention.GetKilometer() << " km");
	APPL_INFO("    set dimension at : " << myDimention.GetMeter() << " m");
	APPL_INFO("    set dimension at : " << myDimention.GetInch() << " Inch");
	APPL_INFO("    set dimension at : " << myDimention.GetFoot() << " ft");
	APPL_INFO("    set dimension at : " << myDimention.GetPourcent() << " %");
	APPL_INFO("    set dimension at : " << myDimention.GetPixel() << " px");
	
	APPL_INFO("==> test of Dimension (STOP)");
	exit(0);
}

/**
 * @brief main application function Initialisation
 */
bool APP_Init(ewol::eContext& _context)
{
	APPL_INFO("==> Init "PROJECT_NAME" (START) [" << ewol::GetBoardType() << "] (" << ewol::GetCompilationMode() << ")");
	
	etk::InitDefaultFolder(PROJECT_NAME);
	
	_context.SetSize(vec2(800, 600));
	
	// select internal data for font ...
	_context.GetFontDefault().SetUseExternal(false);
	#ifdef __TARGET_OS__Android
		_context.GetFontDefault().Set("FreeSerif;DejaVuSansMono", 19);
	#else
		_context.GetFontDefault().Set("FreeSerif;DejaVuSansMono", 14);
	#endif
	// set the application icon ...
	_context.SetIcon("DATA:icon.png");
	
	MainWindows* basicWindows = new MainWindows();
	if (NULL == basicWindows) {
		APPL_ERROR("Can not allocate the basic windows");
		return false;
	}
	// create the specific windows
	_context.SetWindows(basicWindows);
	
	//tmpTestOfTheFSNode();
	//tmpTestOfTheDimension();
	
	// add files
	APPL_INFO("show list of command line input : ");
	for( int32_t iii=0 ; iii<_context.GetCmd().Size(); iii++) {
		APPL_INFO("parameter [" << iii << "] is \"" << _context.GetCmd().Get(iii) << "\"");
	}
	APPL_INFO("==> Init "PROJECT_NAME" (END)");
	return true;
}




/**
 * @brief main application function Un-Initialisation
 */
void APP_UnInit(ewol::eContext& _context)
{
	APPL_INFO("==> Un-Init "PROJECT_NAME" (START)");
	// Get the curent windows
	ewol::Windows* tmpWindows = _context.GetWindows();
	// Remove windows :
	_context.SetWindows(NULL);
	
	if (NULL != tmpWindows) {
		delete(tmpWindows);
		tmpWindows = NULL;
	}
	APPL_INFO("==> Un-Init "PROJECT_NAME" (END)");
}

