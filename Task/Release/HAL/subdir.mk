################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Led.c \
../HAL/SerialMonitor.c \
../HAL/Switchs.c \
../HAL/TmepSensor.c 

OBJS += \
./HAL/Led.o \
./HAL/SerialMonitor.o \
./HAL/Switchs.o \
./HAL/TmepSensor.o 

C_DEPS += \
./HAL/Led.d \
./HAL/SerialMonitor.d \
./HAL/Switchs.d \
./HAL/TmepSensor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


