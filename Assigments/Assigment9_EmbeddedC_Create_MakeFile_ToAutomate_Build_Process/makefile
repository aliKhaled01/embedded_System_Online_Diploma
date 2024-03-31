#copyright ali-khaled-$(ProjectName)

CC=arm-none-eabi
CFLAGS=-g -mcpu=arm926ej-s 
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
ASS=$(wildcard *.s)
AsOBJ= $(ASS:.s=.o)
ProjectName= learn_in_depth

all: $(ProjectName).bin
	@echo "Build is done.."
	
%.o: %.c
	$(CC)-gcc.exe $(CFLAGS) -c $(INCS) $< -o $@
	
startup.o: startup.s
	$(CC)-as.exe $(CFLAGS) $< -o $@
	
$(ProjectName).elf: $(OBJ) $(AsOBJ)
	$(CC)-ld.exe -T linker_script.ld -Map=output.map $(LIBS) $(OBJ) $(AsOBJ) -o $(ProjectName).elf

$(ProjectName).bin: $(ProjectName).elf

	$(CC)-objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin 
	
	
