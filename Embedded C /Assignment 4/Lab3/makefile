#@copyright : Mostafa

CC=arm-none-eabi-
CFLAG= -mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
Project_name=learn-in-depth_cortex_m4


all:$(Project_name).bin
	@echo "====================Build is Done===================="
	
	

	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAG) $(INCS)  $< -o $@
	

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS)  $(OBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf 
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.o *.bin *.elf
	
clean:
	rm *.bin *.elf
	