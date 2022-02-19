CC	= ~/Downloads/gbdk/bin/lcc 

CFLAGS	= -Wa-l -Wl-m -Wf--std-c2x -Wm-yC

DEBUGFLAGS = -Wf-debug -Wl-y -Wl-j

BINS = game.gb

all: $(BINS)

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm *.sav *.noi *.cdb

# Link file, and write 0x80 at position 0x143 in header
game.gb: game.o
	$(CC) $(CFLAGS) -o game.gb game.c
# Compile with debug flags.
debug: game.o
	$(CC) $(CFLAGS) -debug -o game.gb game.c
# Run the game in the emulator. 
emu: game.gb
	wine ~/Downloads/bgbw64/bgb64.exe game.gb &