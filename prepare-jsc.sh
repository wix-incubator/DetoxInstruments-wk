#!/bin/bash

if [ ! -d "wk-svn" ]; then
	# svn checkout https://svn.webkit.org/repository/webkit/branches/safari-604.3.5.1-branch wk-svn
	git clone git://git.webkit.org/WebKit.git wk-svn
fi

rm -fr JSC.framework

cd wk-svn

patch -p1 < ../wk.diff

export CODE_SIGNING_REQUIRED=NO && Tools/Scripts/build-webkit --ios-simulator --sdk=iphonesimulator
export CODE_SIGNING_REQUIRED=NO && Tools/Scripts/build-webkit --ios-device --sdk=iphoneos
cp -r WebKitBuild/Release-iphoneos/JavaScriptCore.framework ../JSC.framework
rm -f ../JSC.framework/JavaScriptCore
lipo -create WebKitBuild/Release-iphoneos/JavaScriptCore.framework/JavaScriptCore WebKitBuild/Release-iphonesimulator/JavaScriptCore.framework/JavaScriptCore -output ../JSC.framework/JSC 
install_name_tool -id JSC ../JSC.framework/JSC
/usr/libexec/PlistBuddy -c "Set :CFBundleExecutable JSC" -c "Set :CFBundleName JSC" -c "Set :CFBundleIdentifier com.wix.JavaScriptCore" ../JSC.framework/Info.plist
codesign -f -s - -- ../JSC.framework