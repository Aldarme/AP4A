################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Humidity.cpp \
../src/Light.cpp \
../src/Pressure.cpp \
../src/Scheduler.cpp \
../src/Server.cpp \
../src/Temperature.cpp \
../src/main.cpp 

OBJS += \
./src/Humidity.o \
./src/Light.o \
./src/Pressure.o \
./src/Scheduler.o \
./src/Server.o \
./src/Temperature.o \
./src/main.o 

CPP_DEPS += \
./src/Humidity.d \
./src/Light.d \
./src/Pressure.d \
./src/Scheduler.d \
./src/Server.d \
./src/Temperature.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


