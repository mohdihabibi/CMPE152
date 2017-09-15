################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/Java/JavaError.cpp \
../wci/frontend/Java/JavaErrorHandler.cpp \
../wci/frontend/Java/JavaParserTD.cpp \
../wci/frontend/Java/JavaScanner.cpp \
../wci/frontend/Java/JavaToken.cpp 

OBJS += \
./wci/frontend/Java/JavaError.o \
./wci/frontend/Java/JavaErrorHandler.o \
./wci/frontend/Java/JavaParserTD.o \
./wci/frontend/Java/JavaScanner.o \
./wci/frontend/Java/JavaToken.o 

CPP_DEPS += \
./wci/frontend/Java/JavaError.d \
./wci/frontend/Java/JavaErrorHandler.d \
./wci/frontend/Java/JavaParserTD.d \
./wci/frontend/Java/JavaScanner.d \
./wci/frontend/Java/JavaToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/Java/%.o: ../wci/frontend/Java/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


