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

class MainApplication : public ewol::context::Application {
	public:
		bool init(ewol::Context& _context, size_t _initId) {
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
			
			std::shared_ptr<appl::MainWindows> basicWindows = appl::MainWindows::create();
			if (basicWindows == nullptr) {
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

		
		void unInit(ewol::Context& _context) {
			APPL_INFO("==> Un-Init APPL (START)");
			// nothing to do ...
			APPL_INFO("==> Un-Init APPL (END)");
		}
};

/**
 * @brief Main of the program (This can be set in every case, but it is not used in Andoid...).
 * @param std IO
 * @return std IO
 */
int main(int _argc, const char *_argv[]) {
	// second possibility
	return ewol::run(new MainApplication(), _argc, _argv);
}


