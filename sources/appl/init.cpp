/**
 * @author Edouard DUPIN
 * 
 * @copyright 2010, Edouard DUPIN, all right reserved
 * 
 * @license BSD v3 (see license file)
 */

#include <etk/types.h>
#include <etk/types.h>
#include <etk/os/FSNode.h>
#include <ewol/ewol.h>
#include <ewol/Dimension.h>
//#include <ewol/config.h>
#include <ewol/context/commandLine.h>
#include <ewol/object/Object.h>
#include <ewol/context/Context.h>
#include <ewol/widget/Manager.h>

#include <appl/debug.h>
#include <appl/MainWindows.h>



/**
 * @brief Main of the program (This can be set in every case, but it is not used in Andoid...).
 * @param std IO
 * @return std IO
 */
int main(int argc, const char *argv[]) {
	// only one things to do : 
	return ewol::run(argc, argv);
}


/**
 * @brief main application function Initialisation
 */
bool APP_Init(ewol::Context& _context) {
	APPL_INFO("==> Init " PROJECT_NAME " (START) [" << ewol::getBoardType() << "] (" << ewol::getCompilationMode() << ")");
	
	etk::initDefaultFolder(PROJECT_NAME);
	
	_context.setSize(vec2(800, 600));
	
	// select internal data for font ...
	_context.getFontDefault().setUseExternal(false);
	#ifdef __TARGET_OS__Android
		_context.getFontDefault().set("FreeSerif;DejaVuSansMono", 19);
	#else
		_context.getFontDefault().set("FreeSerif;DejaVuSansMono", 14);
	#endif
	// set the application icon ...
	_context.setIcon("DATA:icon.png");
	
	MainWindows* basicWindows = new MainWindows();
	if (NULL == basicWindows) {
		APPL_ERROR("Can not allocate the basic windows");
		return false;
	}
	// create the specific windows
	_context.setWindows(basicWindows);
	
	// add files
	APPL_INFO("show list of command line input : ");
	for( int32_t iii=0 ; iii<_context.getCmd().size(); iii++) {
		APPL_INFO("parameter [" << iii << "] is \"" << _context.getCmd().get(iii) << "\"");
	}
	APPL_INFO("==> Init " PROJECT_NAME " (END)");
	return true;
}




/**
 * @brief main application function Un-Initialisation
 */
void APP_UnInit(ewol::Context& _context) {
	APPL_INFO("==> Un-Init " PROJECT_NAME " (START)");
	// Get the curent windows
	ewol::widget::Windows* tmpWindows = _context.getWindows();
	// Remove windows :
	_context.setWindows(NULL);
	
	if (NULL != tmpWindows) {
		delete(tmpWindows);
		tmpWindows = NULL;
	}
	APPL_INFO("==> Un-Init " PROJECT_NAME " (END)");
}

