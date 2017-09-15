################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../wci/frontend/Java/tokens/JavaErrorToken.cpp \
../wci/frontend/Java/tokens/JavaNumberToken.cpp \
../wci/frontend/Java/tokens/JavaSpecialSymbolToken.cpp \
../wci/frontend/Java/tokens/JavaStringToken.cpp \
../wci/frontend/Java/tokens/JavaWordToken.cpp 

OBJS += \
./wci/frontend/Java/tokens/JavaErrorToken.o \
./wci/frontend/Java/tokens/JavaNumberToken.o \
./wci/frontend/Java/tokens/JavaSpecialSymbolToken.o \
./wci/frontend/Java/tokens/JavaStringToken.o \
./wci/frontend/Java/tokens/JavaWordToken.o 

CPP_DEPS += \
./wci/frontend/Java/tokens/JavaErrorToken.d \
./wci/frontend/Java/tokens/JavaNumberToken.d \
./wci/frontend/Java/tokens/JavaSpecialSymbolToken.d \
./wci/frontend/Java/tokens/JavaStringToken.d \
./wci/frontend/Java/tokens/JavaWordToken.d 


# Each subdirectory must supply rules for building sources it contributes
wci/frontend/Java/tokens/%.o: ../wci/frontend/Java/tokens/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


