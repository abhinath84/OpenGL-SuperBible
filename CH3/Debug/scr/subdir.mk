################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../scr/Lines.cpp \
../scr/main.cpp \
../scr/triangle.cpp 

OBJS += \
./scr/Lines.o \
./scr/main.o \
./scr/triangle.o 

CPP_DEPS += \
./scr/Lines.d \
./scr/main.d \
./scr/triangle.d 


# Each subdirectory must supply rules for building sources it contributes
scr/%.o: ../scr/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/abhi/Documents/C++/OGLSB_CH3/lib" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


