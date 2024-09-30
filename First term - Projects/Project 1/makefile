#@copyright : Mostafa

CC=arm-none-eabi-
CFLAG= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
Project_name=project1_pressure_detector


all:$(Project_name).bin
	@echo "====================Build is Done===================="
	
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAG) $(INCS)  $< -o $@
%.o: %.s
		$(CC)as.exe $(CFLAG) $< -o $@

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=map_file.map $(OBJ) $(ASOBJ) -o $@
	
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.o *.bin *.elf
	
clean:
	rm *.bin *.elf
	