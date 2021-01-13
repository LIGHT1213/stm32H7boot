################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32h750vbtx.s 

S_DEPS += \
./Core/Startup/startup_stm32h750vbtx.d 

OBJS += \
./Core/Startup/startup_stm32h750vbtx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/startup_stm32h750vbtx.o: ../Core/Startup/startup_stm32h750vbtx.s
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Core/Startup/startup_stm32h750vbtx.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

