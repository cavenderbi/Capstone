#
# A Makefile that compiles all .c and .s files in "src" and "res" 
# subdirectories and places the output in a "obj" subdirectory
#

# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
GBDK_HOME = ~/Downloads/gbdk/

LCC = $(GBDK_HOME)bin/lcc 
PNG2ASSET = $(GBDK_HOME)bin/png2asset

# You can set flags for LCC here
# For example, you can uncomment the line below to turn on debug output
LCCFLAGS = -Wm-yc -Wl-yoA -Wm-yn"WIZVWARRIOR" -debug 

# You can set the name of the .gb ROM file here
PROJECTNAME    = WizardsvsWarriors

SRCDIR      = src
OBJDIR      = obj
RESDIR      = res
BINS	    = $(PROJECTNAME).gb
CSOURCES    = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES  = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.s)))
OBJS       = $(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.s=$(OBJDIR)/%.o)

all:	prepare $(BINS)

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | grep -v make >> compile.bat

# Splash screens
res/%.c: res/splashes/%.png 
	$(PNG2ASSET) $< -o $@ -map -noflip -use_map_attributes

# Sprites
res/%.c: res/sprites/size8/%.png
	$(PNG2ASSET) $< -o $@ -spr8x8 -tiles_only
res/%.c: res/sprites/size16%.png
	$(PNG2ASSET) $< -o $@ -sh 16 -spr8x8

# HUD elements. 
res/%.c: res/hud_elements/%.png
	$(PNG2ASSET) $< -o $@ -map -noflip

# Tilemaps
res/bricktileset.c: res/bricktileset.png
	$(PNG2ASSET) res/bricktileset.png -map -noflip -tiles_only
res/%.c: res/rooms/%.png res/bricktileset.png
	$(PNG2ASSET) $< -o $@ -map -noflip -source_tileset res/bricktileset.png -tile_origin 33 

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# If needed, compile .c files i n"src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -S -o $@ $<

# Link the compiled object files into a .gb ROM file
$(BINS):	$(OBJS)
	$(LCC) $(LCCFLAGS) -o $(BINS) $(OBJS)

prepare:
	mkdir -p $(OBJDIR)

clean:
# 	rm -f  *.gb *.ihx *.cdb *.adb *.noi *.map
	rm -f  $(OBJDIR)/*.*

flash: WizardsvsWarriors.gb
	sudo ~/Downloads/gameboyflasher/MacLinuxScript\(1\)/joey.sh ROM WizardsvsWarriors.gb
