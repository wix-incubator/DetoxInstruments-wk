#!/bin/bash
set -e

if [ ! -d "wk-svn" ]; then
	# svn checkout https://svn.webkit.org/repository/webkit/branches/safari-604.3.5.1-branch wk-svn
	git clone git://git.webkit.org/WebKit.git wk-svn
fi

rm -fr DTX_JSC.framework

cd wk-svn

# patch -p1 < ../wk.diff

xcodebuild -project Source/bmalloc/bmalloc.xcodeproj -scheme bmalloc -configuration Debug  -sdk iphonesimulator -derivedDataPath ./DTXJSCBuild
xcodebuild -project Source/WTF/WTF.xcodeproj -scheme WTF -configuration Debug  -sdk iphonesimulator -derivedDataPath ./DTXJSCBuild
xcodebuild -project Source/JavaScriptCore/JavaScriptCore.xcodeproj -scheme JavaScriptCore -configuration Debug -sdk iphonesimulator -derivedDataPath ./DTXJSCBuild

cp -R DTXJSCBuild/Build/Products/Debug-iphonesimulator/JavaScriptCore.framework ../DTX_JSC.framework
mv -f ../DTX_JSC.framework/JavaScriptCore ../DTX_JSC.framework/DTX_JSC
install_name_tool -id DTX_JSC ../DTX_JSC.framework/DTX_JSC
/usr/libexec/PlistBuddy -c "Set :CFBundleExecutable DTX_JSC" -c "Set :CFBundleName DTX_JSC" -c "Set :CFBundleIdentifier com.wix.JavaScriptCore" ../DTX_JSC.framework/Info.plist
codesign -f -s - -- ../DTX_JSC.framework
