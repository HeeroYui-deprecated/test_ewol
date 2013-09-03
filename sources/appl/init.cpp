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

