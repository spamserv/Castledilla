################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TCP_IP_CONNECTION/server.c 

OBJS += \
./TCP_IP_CONNECTION/server.o 

C_DEPS += \
./TCP_IP_CONNECTION/server.d 


# Each subdirectory must supply rules for building sources it contributes
TCP_IP_CONNECTION/%.o: ../TCP_IP_CONNECTION/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


