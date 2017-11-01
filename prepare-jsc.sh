#!/bin/bash

if [ ! -d "wk-svn" ]; then
	# svn checkout https://svn.webkit.org/repository/webkit/branches/safari-604.3.5.1-branch wk-svn
	git clone git://git.webkit.org/WebKit.git wk-svn
fi

rm -fr DTX_JSC.framework

cd wk-svn

patch -p1 < ../wk.diff

export CODE_SIGNING_REQUIRED=NO && Tools/Scripts/build-webkit --release --ios-simulator --sdk=iphonesimulator
export CODE_SIGNING_REQUIRED=NO && Tools/Scripts/build-webkit --release --ios-device --sdk=iphoneos
cp -r WebKitBuild/Release-iphoneos/JavaScriptCore.framework ../DTX_JSC.framework
rm -f ../DTX_JSC.framework/JavaScriptCore
lipo -create WebKitBuild/Release-iphoneos/JavaScriptCore.framework/JavaScriptCore WebKitBuild/Release-iphonesimulator/JavaScriptCore.framework/JavaScriptCore -output ../DTX_JSC.framework/DTX_JSC 
install_name_tool -id DTX_JSC ../DTX_JSC.framework/DTX_JSC
/usr/libexec/PlistBuddy -c "Set :CFBundleExecutable DTX_JSC" -c "Set :CFBundleName DTX_JSC" -c "Set :CFBundleIdentifier com.wix.JavaScriptCore" ../DTX_JSC.framework/Info.plist
codesign -f -s - -- ../DTX_JSC.framework