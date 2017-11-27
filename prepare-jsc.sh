#!/bin/bash
set -e

if [ ! -d "wk-svn" ]; then
	# svn checkout https://svn.webkit.org/repository/webkit/branches/safari-604.3.5.1-branch wk-svn
	git clone git://git.webkit.org/WebKit.git wk-svn

	patch -p1 < ../wk.patch
fi

rm -fr DTX_JSC.framework

cd wk-svn

xcodebuild IPHONEOS_DEPLOYMENT_TARGET=10.0 -project Source/bmalloc/bmalloc.xcodeproj -scheme bmalloc -configuration Release  -sdk iphonesimulator -derivedDataPath ./DTXJSCBuild
xcodebuild IPHONEOS_DEPLOYMENT_TARGET=10.0 -project Source/WTF/WTF.xcodeproj -scheme WTF -configuration Release  -sdk iphonesimulator -derivedDataPath ./DTXJSCBuild
xcodebuild IPHONEOS_DEPLOYMENT_TARGET=10.0 -project Source/JavaScriptCore/JavaScriptCore.xcodeproj -scheme JavaScriptCore -configuration Release -sdk iphonesimulator -derivedDataPath ./DTXJSCBuild

xcodebuild IPHONEOS_DEPLOYMENT_TARGET=10.0 -project Source/bmalloc/bmalloc.xcodeproj -scheme bmalloc -configuration Release  -sdk iphoneos -derivedDataPath ./DTXJSCBuild
xcodebuild IPHONEOS_DEPLOYMENT_TARGET=10.0 -project Source/WTF/WTF.xcodeproj -scheme WTF -configuration Release  -sdk iphoneos -derivedDataPath ./DTXJSCBuild
xcodebuild IPHONEOS_DEPLOYMENT_TARGET=10.0 -project Source/JavaScriptCore/JavaScriptCore.xcodeproj -scheme JavaScriptCore -configuration Release -sdk iphoneos -derivedDataPath ./DTXJSCBuild

cp -R DTXJSCBuild/Build/Products/Release-iphoneos/JavaScriptCore.framework ../DTX_JSC.framework
rm -f ../DTX_JSC.framework/JavaScriptCore
lipo -create DTXJSCBuild/Build/Products/Release-iphoneos/JavaScriptCore.framework/JavaScriptCore DTXJSCBuild/Build/Products/Release-iphonesimulator/JavaScriptCore.framework/JavaScriptCore -output ../DTX_JSC.framework/DTX_JSC 
install_name_tool -id DTX_JSC ../DTX_JSC.framework/DTX_JSC
/usr/libexec/PlistBuddy -c "Set :CFBundleExecutable DTX_JSC" -c "Set :CFBundleName DTX_JSC" -c "Set :CFBundleIdentifier com.wix.JavaScriptCore" ../DTX_JSC.framework/Info.plist
codesign -f -s - -- ../DTX_JSC.framework
