#!/usr/bin/python
import lutinModule
import lutinTools
import datetime

def Create(target):
	# module name is 'edn' and type binary.
	myModule = lutinModule.module(__file__, 'test_ewol', 'PACKAGE')
	# add the file to compile:
	myModule.AddSrcFile([
		'appl/debug.cpp',
		'appl/init.cpp',
		'appl/MainWindows.cpp',
		'appl/TestButton.cpp',
		'appl/TestImage.cpp',
		'appl/TestButtonColor.cpp',
		'appl/TestLabel.cpp'])
	# 'appl/TestScene.cpp'
	
	myModule.AddModuleDepend(['ewol'])
	
	now = datetime.datetime.now()
	
	versionID=str(now.year-2013)+"."+str(now.month)+"."+str(now.day)
	
	myModule.CompileFlags_CC([
		"-DPROJECT_NAME=\"\\\""+myModule.name+"\\\"\"",
		"-DAPPL_VERSION_TAG_NAME=\"\\\""+versionID+"\\\"\"",
		"-DBUILD_TIME=\"\\\""+str(now.day)+"/"+str(now.month)+"/"+str(now.year)+"\\\"\""])
	
	myModule.CopyFile('../data/icon.png','icon.png')
	
	myModule.CopyFolder('../data/icon.*','')
	myModule.CopyFolder('../data/cube.*','')
	myModule.CopyFolder('../data/grass.*','')
	myModule.CopyFolder('../data/stone*','')
	myModule.CopyFolder('../data/sphere.png','')
	myModule.CopyFolder('../data/sphere.obj','')
	
	myModule.AddPath(lutinTools.GetCurrentPath(__file__))
	
	myModule.CopyFolder("../data/FreeSerif*","fonts/")
	
	
	# set the package properties :
	myModule.pkgSet("VERSION", versionID)
	myModule.pkgSet("COMPAGNY_TYPE", "org")
	myModule.pkgSet("COMPAGNY_NAME", "Edouard DUPIN")
	myModule.pkgSet("MAINTAINER", ["Mr DUPIN Edouard <yui.heero@gmail.com>"])
	myModule.pkgSet("ICON", lutinTools.GetCurrentPath(__file__) + "/../data/icon.png")
	myModule.pkgSet("SECTION", ["Development"])
	myModule.pkgSet("PRIORITY", "optional")
	myModule.pkgSet("DESCRIPTION", "ewol test software")
	myModule.pkgSet("NAME", "test software")
	
	myModule.pkgAdd("RIGHT", "SET_ORIENTATION")
	myModule.pkgAdd("RIGHT", "VIBRATE")
	
	# add the currrent module at the 
	return myModule




