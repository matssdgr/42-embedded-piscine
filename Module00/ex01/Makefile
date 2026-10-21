CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

MCU = atmega328p
F_CPU = 16000000  
PORT = /dev/ttyUSB0
BAUD = 115200
PROGRAMMER = arduino

all: hex flash

hex:
	$(CC) -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os main.c -o main.bin
	$(OBJCOPY) -O ihex main.bin main.hex

flash:
	$(AVRDUDE) -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:main.hex:i

clean:
	rm -f main.bin main.hex