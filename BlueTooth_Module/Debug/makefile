################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
BlueTooth_Module.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: BlueTooth_Module.elf secondary-outputs

# Tool invocations
BlueTooth_Module.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,BlueTooth_Module.map -mmcu=atmega16 -o "BlueTooth_Module.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

BlueTooth_Module.lss: BlueTooth_Module.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S BlueTooth_Module.elf  >"BlueTooth_Module.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: BlueTooth_Module.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 BlueTooth_Module.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) BlueTooth_Module.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
