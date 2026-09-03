# ----------------------------
# Makefile Options
# ----------------------------

NAME = Ender Portal
ICON = icon.png
DESCRIPTION = "a game using ender pearls for teleportation"
COMPRESSED = NO

CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
