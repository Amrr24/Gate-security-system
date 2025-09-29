################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Door_Security_System.c \
../gpio.c \
../keypad.c \
../lcd.c \
../timer0.c \
../uart.c 

OBJS += \
./Door_Security_System.o \
./gpio.o \
./keypad.o \
./lcd.o \
./timer0.o \
./uart.o 

C_DEPS += \
./Door_Security_System.d \
./gpio.d \
./keypad.d \
./lcd.d \
./timer0.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


