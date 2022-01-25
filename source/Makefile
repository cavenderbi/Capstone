CC	= ~/Downloads/gbdk/bin/lcc -Wa-l -Wl-m

# CFLAGS	=

BINS	= game.gb

all:	$(BINS)

make.bat: Makefile
	@echo "REM Automatically generated from Makefile" > make.bat
	@make -sn | sed y/\\//\\\\/ | grep -v make >> make.bat

%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o:	%.s
	$(CC) $(CFLAGS) -c -o $@ $<

%.s:	%.c
	$(CC) $(CFLAGS) -S -o $@ $<

%.gb:	%.o
	$(CC) -o $@ $<

clean:
	rm -f *.o *.lst *.map *.gb *.ihx *.sym *.cdb *.adb *.asm

# Link file, and write 0x80 at position 0x143 in header
game.gb:	game.o
	$(CC) $(CFLAGS) -Wm-yC -o game.gb game.o
# Run the game in the emulator. 
emu: game.gb
	wine ~/Downloads/bgbw64/bgb64.exe game.gb