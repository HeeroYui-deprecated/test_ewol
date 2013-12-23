#!/usr/bin/python
import lutinModule as module
import lutinTools as tools
import datetime

def get_desc():
	return "EWOL test software"


def create(target):
	# module name is 'edn' and type binary.
	myModule = module.Module(__file__, 'test_ewol', 'PACKAGE')
	# add the file to compile:
	myModule.add_src_file([
		'appl/debug.cpp',
		'appl/init.cpp',
		'appl/MainWindows.cpp',
		'appl/TestButton.cpp',
		'appl/TestImage.cpp',
		'appl/TestButtonColor.cpp',
		'appl/TestLabel.cpp'])
	# 'appl/TestScene.cpp'
	
	myModule.add_module_depend(['ewol'])
	
	now = datetime.datetime.now()
	
	versionID=str(now.year-2013)+"."+str(now.month)+"."+str(now.day)
	
	myModule.compile_flags_CC([
		"-DPROJECT_NAME=\"\\\""+myModule.name+"\\\"\"",
		"-DAPPL_VERSION_TAG_NAME=\"\\\""+versionID+"\\\"\"",
		"-DBUILD_TIME=\"\\\""+str(now.day)+"/"+str(now.month)+"/"+str(now.year)+"\\\"\""])
	
	myModule.copy_file('../data/icon.png','icon.png')
	
	myModule.copy_folder('../data/icon.*','')
	myModule.copy_folder('../data/cube.*','')
	myModule.copy_folder('../data/grass.*','')
	myModule.copy_folder('../data/stone*','')
	myModule.copy_folder('../data/sphere.png','')
	myModule.copy_folder('../data/sphere.obj','')
	
	myModule.add_path(tools.get_current_path(__file__))
	
	myModule.copy_folder("../data/FreeSerif*","fonts/")
	
	
	# set the package properties :
	myModule.pkg_set("VERSION", versionID)
	myModule.pkg_set("COMPAGNY_TYPE", "org")
	myModule.pkg_set("COMPAGNY_NAME", "Edouard DUPIN")
	myModule.pkg_set("MAINTAINER", ["Mr DUPIN Edouard <yui.heero@gmail.com>"])
	myModule.pkg_set("ICON", tools.get_current_path(__file__) + "/../data/icon.png")
	myModule.pkg_set("SECTION", ["Development"])
	myModule.pkg_set("PRIORITY", "optional")
	myModule.pkg_set("DESCRIPTION", "ewol test software")
	myModule.pkg_set("NAME", "test software")
	
	myModule.pkg_add("RIGHT", "SET_ORIENTATION")
	myModule.pkg_add("RIGHT", "VIBRATE")
	
	# add the currrent module at the 
	return myModule




