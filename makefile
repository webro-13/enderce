# ----------------------------
# Makefile Options
# ----------------------------

NAME = EnderP
ICON = icon.png
DESCRIPTION = "a game using ender pearls for teleportation"
COMPRESSED = YES
ARCHIVED = YES

CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
