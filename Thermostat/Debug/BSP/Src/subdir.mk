################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/Src/bsp_button.c \
../BSP/Src/bsp_lcd.c \
../BSP/Src/bsp_temp_sensor.c 

OBJS += \
./BSP/Src/bsp_button.o \
./BSP/Src/bsp_lcd.o \
./BSP/Src/bsp_temp_sensor.o 

C_DEPS += \
./BSP/Src/bsp_button.d \
./BSP/Src/bsp_lcd.d \
./BSP/Src/bsp_temp_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/Src/%.o BSP/Src/%.su BSP/Src/%.cyclo: ../BSP/Src/%.c BSP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/HCMUT/Semester 5/Embedded/Assignment/Thermostat/App/Inc" -I"D:/HCMUT/Semester 5/Embedded/Assignment/Thermostat/BSP/Inc" -I"D:/HCMUT/Semester 5/Embedded/Assignment/Thermostat/Drivers/I2C_LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP-2f-Src

clean-BSP-2f-Src:
	-$(RM) ./BSP/Src/bsp_button.cyclo ./BSP/Src/bsp_button.d ./BSP/Src/bsp_button.o ./BSP/Src/bsp_button.su ./BSP/Src/bsp_lcd.cyclo ./BSP/Src/bsp_lcd.d ./BSP/Src/bsp_lcd.o ./BSP/Src/bsp_lcd.su ./BSP/Src/bsp_temp_sensor.cyclo ./BSP/Src/bsp_temp_sensor.d ./BSP/Src/bsp_temp_sensor.o ./BSP/Src/bsp_temp_sensor.su

.PHONY: clean-BSP-2f-Src

