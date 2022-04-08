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
LCCFLAGS = -Wm-yc -debug

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

# Create the wizard.c file from wizard.png
res/wizard_walk_up.c:	res/wizard_walk_up.png
	$(PNG2ASSET) res/wizard_walk_up.png -sh 16 -spr8x8
# Create the wizard.c file from wizard.png
res/wizard_walk_down.c:	res/wizard_walk_down.png
	$(PNG2ASSET) res/wizard_walk_down.png -sh 16 -spr8x8
# Create the wizard.c file from wizard.png
res/wizard_walk_side.c:	res/wizard_walk_side.png
	$(PNG2ASSET) res/wizard_walk_side.png -sh 16 -spr8x8
# Create the player_basic_proj..c file from player_basic_proj.png
res/player_basic_proj.c: res/player_basic_proj.png
	$(PNG2ASSET) res/player_basic_proj.png -spr8x8 -tiles_only

# Create the knight sprite .c files from the .png files. 
res/knight_walk_up.c: res/knight_walk_up.png
	$(PNG2ASSET) res/knight_walk_up.png -sh 16 -spr8x8
res/knight_walk_down.c: res/knight_walk_down.png
	$(PNG2ASSET) res/knight_walk_down.png -sh 16 -spr8x8
res/knight_walk_side.c: res/knight_walk_side.png
	$(PNG2ASSET) res/knight_walk_side.png -sh 16 -spr8x8

# Create the title screen tilemap and tiles. 
res/sketch_titlescreen.c: res/sketch_titlescreen.png
	$(PNG2ASSET) res/sketch_titlescreen.png -map -noflip

# Power-up sprite.
res/powerorb.c: res/powerorb.png
	$(PNG2ASSET) res/powerorb.png -spr8x8 -tiles_only
# Elemental type icons. 
res/fire.c: res/fire.png
	$(PNG2ASSET) res/fire.png -map
res/frost.c: res/frost.png
	$(PNG2ASSET) res/frost.png -map
res/shock.c: res/shock.png
	$(PNG2ASSET) res/shock.png -map
# HUD Icons
res/hearts.c: res/hearts.png	
	$(PNG2ASSET) res/hearts.png -map
res/bar.c: res/bar.png
	$(PNG2ASSET) res/bar.png -map -noflip

# Tilemaps
res/topleft.c: res/topleft.png res/bricktileset.png
	$(PNG2ASSET) res/topleft.png -map -noflip -source_tileset res/bricktileset.png -tile_origin 33
res/topright.c: res/topright.png res/bricktileset.png
	$(PNG2ASSET) res/topright.png -map -noflip -source_tileset res/bricktileset.png -tile_origin 33
res/bottomleft.c: res/bottomleft.png res/bricktileset.png
	$(PNG2ASSET) res/bottomleft.png -map -noflip -source_tileset res/bricktileset.png -tile_origin 33
res/bottomright.c: res/bottomright.png res/bricktileset.png
	$(PNG2ASSET) res/bottomright.png -map -noflip -source_tileset res/bricktileset.png -tile_origin 33
res/bricktileset.c: res/bricktileset.png
	$(PNG2ASSET) res/bricktileset.png -map -noflip -tiles_only

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
