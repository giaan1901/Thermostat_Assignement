################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/I2C_LCD/lcd_i2c.c 

OBJS += \
./Drivers/I2C_LCD/lcd_i2c.o 

C_DEPS += \
./Drivers/I2C_LCD/lcd_i2c.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/I2C_LCD/%.o Drivers/I2C_LCD/%.su Drivers/I2C_LCD/%.cyclo: ../Drivers/I2C_LCD/%.c Drivers/I2C_LCD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/HCMUT/Semester 5/Embedded/Assignment/Thermostat/App/Inc" -I"D:/HCMUT/Semester 5/Embedded/Assignment/Thermostat/BSP/Inc" -I"D:/HCMUT/Semester 5/Embedded/Assignment/Thermostat/Drivers/I2C_LCD" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-I2C_LCD

clean-Drivers-2f-I2C_LCD:
	-$(RM) ./Drivers/I2C_LCD/lcd_i2c.cyclo ./Drivers/I2C_LCD/lcd_i2c.d ./Drivers/I2C_LCD/lcd_i2c.o ./Drivers/I2C_LCD/lcd_i2c.su

.PHONY: clean-Drivers-2f-I2C_LCD

