CC	= ~/Downloads/gbdk/bin/lcc 

CFLAGS	= -Wa-l -Wl-m -Wf--std-c2x -Wm-yC

BINS = game.gb

all: $(BINS)

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm *.sav *.noi *.cdb

# Link file, and write 0x80 at position 0x143 in header
game.gb: source/game.c
	$(CC) $(CFLAGS) -o game.gb source/game.c
	rm -f *.o *.lst *.map *.ihx *.sym *.cdb *.adb *.asm *.sav *.noi *.cdb
# Compile with debug flags.
debug: game.o
	$(CC) $(CFLAGS) -debug -o game.gb source/game.c
	rm -f *.o *.lst *.map  *.ihx *.sym *.cdb *.adb *.asm *.sav 