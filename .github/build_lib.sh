#!/usr/bin/env bash

cmake_params="" # All params passed to cmake to generate build files
export ARCH=$1
export CMAKE=cmake
export PATH=$PATH:~/cmake_folder/bin

export JAVA_HOME="/usr/lib/jvm/java-11-openjdk-amd64/"
export POLLY_ROOT=`pwd`/toolchains/polly

function add_to_cmake_params {
  local param
  for param; do
    cmake_params="$cmake_params $param"
  done
}

echo "=====>Cleaning to prepare clean build"
echo "=====>Remove build directory"
rm -rf ../build-ledger-core

echo "=====>Create which will contain artifacts"
cd .. && (mkdir lib-ledger-core-artifacts || echo "lib-ledger-core-artifacts directory already exists")

echo "=====>Create build directory"
(mkdir build-ledger-core || echo "build-ledger-core directory already exists") && cd build-ledger-core

echo "=====>Start build"
unamestr=`uname`

echo "======> CMake config for $unamestr in $BUILD_CONFIG mode"

echo "Resetting xcode tools..."

export POLLY_IOS_BUNDLE_IDENTIFIER='com.ledger.core'
#Needed for nocodesign toolchains
export XCODE_XCCONFIG_FILE=$POLLY_ROOT/scripts/NoCodeSign.xcconfig
echo "command_ios with architecture : $ARCH"
if [ "$ARCH" == "armv7" ]; then
export TOOLCHAIN_NAME='ios-nocodesign-11-2-dep-9-3-armv7'
export OSX_SYSROOT=iphoneos
elif [ "$ARCH" == "arm64" ]; then
export TOOLCHAIN_NAME='ios-nocodesign-11-2-dep-9-3-arm64'
export OSX_SYSROOT=iphoneos
else
export TOOLCHAIN_NAME='ios-nocodesign-11-2-dep-9-3'
export OSX_SYSROOT=iphonesimulator
export ARCH=x86_64
#Copy iphone.cmake which is not forcing CMAKE_OSX_SYSROOT to iphoneos in cache
cp `pwd`/../lib-ledger-core/tools/build_ios/iphone.cmake `pwd`/../lib-ledger-core/toolchains/polly/os/
fi

cp `pwd`/../lib-ledger-core/tools/build_ios/framework.plist.in `pwd`
cp `pwd`/../lib-ledger-core/tools/build_ios/install_name.sh `pwd`

echo 'Fixing NoCodeSign (see https://github.com/ruslo/polly/issues/302 for further details)'
sed -i '' '/CODE_SIGN_ENTITLEMENTS/d' $(pwd)/../lib-ledger-core/toolchains/polly/scripts/NoCodeSign.xcconfig

BUILD_CONFIG="Release"
add_to_cmake_params -G "Xcode" -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_TESTS=OFF -DCMAKE_OSX_ARCHITECTURES:STRING=${ARCH} -DCMAKE_MACOSX_BUNDLE:BOOL=ON -DCMAKE_OSX_SYSROOT:STRING=${OSX_SYSROOT} -DCMAKE_TOOLCHAIN_FILE=${POLLY_ROOT}/${TOOLCHAIN_NAME}.cmake

echo $cmake_params
cmake $cmake_params -S ../lib-ledger-core -B .

echo "======> Build for $unamestr in $BUILD_CONFIG mode"
echo " >>> Starting iOS build for architecture ${ARCH} with toolchain ${TOOLCHAIN_NAME} for ${OSX_SYSROOT}"
xcodebuild -project ledger-core.xcodeproj -configuration Release -jobs 4

PATH_TO_LIB=../lib-ledger-core-build/core/src/
if [ "$ARCH" == "armv7" -o "$ARCH" == "arm64" ]; then
    export BUILD_TYPE=ios/${ARCH}
    PATH_TO_LIB=../lib-ledger-core-build/core/src/Release-iphoneos
else
    export BUILD_TYPE=ios/x86_64
    PATH_TO_LIB=../lib-ledger-core-build/core/src/Release-iphonesimulator
fi

mkdir -p ../lib-ledger-core-artifacts/$BUILD_TYPE
cp -r $PATH_TO_LIB/*ledger-core* ../lib-ledger-core-artifacts/$BUILD_TYPE
