#copyright ali-khaled-$(ProjectName)

CC=arm-none-eabi
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
ASS=$(wildcard *.s)
AsOBJ= $(ASS:.s=.o)
ProjectName= learn_in_depth_cortex_m3

all: $(ProjectName).bin
	@echo "Build is done.."
	
%.o: %.c
	$(CC)-gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
$(ProjectName).elf: $(OBJ) $(AsOBJ)
	$(CC)-ld.exe -T linker_script.ld -Map=output.map $(LIBS) $(OBJ) $(AsOBJ) -o $(ProjectName).elf

$(ProjectName).bin: $(ProjectName).elf

	$(CC)-objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin 
	
	
