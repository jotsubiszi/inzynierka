TARGET=final

SRC=PID.c pinConfig.c motors.c sensors.c lineFollower.c main.c
OBJ=$(SRC:.c=.o)

CC=avr-gcc
MCU=atmega328p

CFLAGS=-mmcu=$(MCU) -std=c99 -Werror -Wall

TOOLS_DIR=tools
COMPILE_COMMANDS=compile_commands.json

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	rm -rf *.o *.elf

$(COMPILE_COMMANDS):
	$(TOOLS_DIR)/compile_commands_with_extra_include_paths.sh > $@

dev: $(COMPILE_COMMANDS)

dev-clean:
	rm -rf $(COMPILE_COMMANDS)

.PHONY: clean dev dev-clean
