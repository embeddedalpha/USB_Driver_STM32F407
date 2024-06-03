################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USB_Device/USB_Device_Driver.c \
../USB_Device/USB_Device_Framework.c 

OBJS += \
./USB_Device/USB_Device_Driver.o \
./USB_Device/USB_Device_Framework.o 

C_DEPS += \
./USB_Device/USB_Device_Driver.d \
./USB_Device/USB_Device_Framework.d 


# Each subdirectory must supply rules for building sources it contributes
USB_Device/%.o USB_Device/%.su USB_Device/%.cyclo: ../USB_Device/%.c USB_Device/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"B:/Application/USB_Device/USB_Device" -I"B:/Application/USB_Device/GPIO" -I"B:/Application/USB_Device/USART" -I"B:/Application/USB_Device/Console" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-USB_Device

clean-USB_Device:
	-$(RM) ./USB_Device/USB_Device_Driver.cyclo ./USB_Device/USB_Device_Driver.d ./USB_Device/USB_Device_Driver.o ./USB_Device/USB_Device_Driver.su ./USB_Device/USB_Device_Framework.cyclo ./USB_Device/USB_Device_Framework.d ./USB_Device/USB_Device_Framework.o ./USB_Device/USB_Device_Framework.su

.PHONY: clean-USB_Device

