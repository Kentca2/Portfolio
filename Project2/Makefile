#
# CMSC257 - Utility Library
# Code for the CMSC257 Projects
#

# Make environment

CC=gcc
CFLAGS= -c -g -Wall $(INCLUDES)
LINKARGS=-lm

# Files
OBJECT_FILES=	p2.o p2-support.o

# Productions
all : cmsc257-s21-p2

cmsc257-s21-p2 : $(OBJECT_FILES)
	$(CC) $(LINKARGS) $(OBJECT_FILES) -o $@

p2.o : cmsc257-s21-p2.c p2-support.h
	$(CC) $(CFLAGS) $< -o $@

p2-support.o : p2-support.c p2-support.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -v cmsc257-s21-p2 $(OBJECT_FILES)