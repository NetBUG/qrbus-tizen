################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AppResourceId.cpp \
../src/CameraTools.cpp \
../src/GLtools.cpp \
../src/QRMessagePort.cpp \
../src/QrCodeRecognizerEntry.cpp \
../src/QrCodeRecognizerSample.cpp \
../src/Renderer.cpp \
../src/TouchForm.cpp \
../src/Tracker.cpp 

OBJS += \
./src/AppResourceId.o \
./src/CameraTools.o \
./src/GLtools.o \
./src/QRMessagePort.o \
./src/QrCodeRecognizerEntry.o \
./src/QrCodeRecognizerSample.o \
./src/Renderer.o \
./src/TouchForm.o \
./src/Tracker.o 

CPP_DEPS += \
./src/AppResourceId.d \
./src/CameraTools.d \
./src/GLtools.d \
./src/QRMessagePort.d \
./src/QrCodeRecognizerEntry.d \
./src/QrCodeRecognizerSample.d \
./src/Renderer.d \
./src/TouchForm.d \
./src/Tracker.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: C++ Compiler'
	clang++ -I"pch" -D_DEBUG -I"/home/lubuntu/workspaces/QRDemo/inc" -O0 -g3 -Wall -c -fmessage-length=0 -target arm-tizen-linux-gnueabi -gcc-toolchain /opt/tizen/tizen-sdk/tools/smart-build-interface/../arm-linux-gnueabi-gcc-4.5/ -ccc-gcc-name arm-linux-gnueabi-g++ -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16 -mtune=cortex-a8 -Wno-gnu -fPIE --sysroot="/opt/tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native" -I"/opt/tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/libxml2" -I"/opt/tizen/tizen-sdk/library" -I"/opt/tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include" -I"/opt/tizen/tizen-sdk/platforms/tizen2.2/rootstraps/tizen-device-2.2.native/usr/include/osp" -D_APP_LOG -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


