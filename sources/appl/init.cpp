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
#include <ewol/config.h>
#include <ewol/commandLine.h>
#include <ewol/eObject/EObject.h>
#include <ewol/widget/WidgetManager.h>

#include <appl/Debug.h>
#include <appl/MainWindows.h>

MainWindows * basicWindows = NULL;


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
void APP_Init(void)
{
	#ifdef MODE_RELEASE
		const char * debugMode = "Release";
	#else
		const char * debugMode = "Debug";
	#endif
	#ifdef __TARGET_OS__Linux
		const char * osMode = "Linux";
	#elif defined(__TARGET_OS__Android)
		const char * osMode = "Android";
	#elif defined(__TARGET_OS__Windows)
		const char * osMode = "Windows";
	#elif defined(__TARGET_OS__IOs)
		const char * osMode = "IOs";
	#elif defined(__TARGET_OS__MacOs)
		const char * osMode = "MacOs";
	#else
		const char * osMode = "Unknown";
	#endif
	APPL_INFO("==> Init "PROJECT_NAME" (START) [" << osMode << "] (" << debugMode << ")");
	
	etk::InitDefaultFolder(PROJECT_NAME);
	ewol::ChangeSize(ivec2(800, 300));
	#ifdef __TARGET_OS__Android
		ewol::config::FontSetDefault("FreeSerif", 19);
	#else
		ewol::config::FontSetDefault("FreeSerif", 14);
	#endif
	// set the application icon ...
	ewol::SetIcon("DATA:icon.png");
	
	basicWindows = new MainWindows();
	
	if (NULL == basicWindows) {
		APPL_ERROR("Can not allocate the basic windows");
		ewol::Stop();
		return;
	}
	// create the specific windows
	ewol::WindowsSet(basicWindows);
	
	//tmpTestOfTheFSNode();
	//tmpTestOfTheDimension();
	
	// add files
	APPL_INFO("show list of command line input : ");
	for( int32_t iii=0 ; iii<ewol::commandLine::Size(); iii++) {
		APPL_INFO("parameter [" << iii << "] is \"" << ewol::commandLine::Get(iii) << "\"");
	}
	
	APPL_INFO("==> Init "PROJECT_NAME" (END)");
}




/**
 * @brief main application function Un-Initialisation
 */
void APP_UnInit(void)
{
	APPL_INFO("==> Un-Init "PROJECT_NAME" (START)");
	// Remove windows :
	ewol::WindowsSet(NULL);
	
	if (NULL != basicWindows) {
		delete(basicWindows);
		basicWindows = NULL;
	}
	APPL_INFO("==> Un-Init "PROJECT_NAME" (END)");
}

