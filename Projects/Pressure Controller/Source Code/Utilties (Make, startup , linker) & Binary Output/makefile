#copyright ali-khaled-$(ProjectName)

CC=arm-none-eabi
CFLAGS=-mcpu=cortex-m3 -mthumb -gdwarf-2
INCS= -I .
LIBS=
APPSRC = $(wildcard ../Application_SWCs_Src/*.c)
APPOBJ = $(APPSRC:.c=.o)
HWSRC = $(wildcard ../HW_AB_Src/*.c)
HWOBJ = $(HWSRC:.c=.o)
APPASS=$(wildcard  ../Application_SWCs_Src/*.s)
APPAsOBJ= $(APPASS:.s=.o)
HWASS=$(wildcard  ../HW_AB_Src/*.s)
HWAsOBJ= $(HWASS:.s=.o)
STARTSRC = $(wildcard *.c)
STARTOBJ = $(STARTSRC:.c=.o)
STARTUPAss=$(wildcard *.s)
STARTUPAssOBJ= $(STARTUPAss:.s=.o)
ProjectName= Pressure_Controller

all: $(ProjectName).bin
	@echo "Build is done.."
	
%.o: %.c
	$(CC)-gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
$(ProjectName).elf: $(APPOBJ) $(HWOBJ) $(STARTOBJ) $(APPAsOBJ) $(HWAsOBJ) $(STARTUPAssOBJ)
	$(CC)-ld.exe -T linker_script.ld -Map=output.map $(LIBS) $(APPOBJ) $(HWOBJ) $(STARTOBJ) $(APPAsOBJ) $(HWAsOBJ) $(STARTUPAssOBJ) -o $(ProjectName).elf

$(ProjectName).bin: $(ProjectName).elf

	$(CC)-objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin 
	
	
