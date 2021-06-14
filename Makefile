CC = clang
CFLAGS = `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm -v

SRCPATH = src
HDRPATH = include
LIBPATH = lib
OBJPATH = obj

vpath %.c $(SRCPATH)
vpath %.h $(HDRPATH)
vpath %.o $(OBJPATH)
vpath %.a $(LIBPATH)

HDRS =
SRCS = maintest.c
OBJS =

EXEC = MindlessRogue

all : $(EXEC)

test : maintest.c
	$(CC) -o $@ $< $(CFLAGS)

$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

$(OBJS): $($@:.o=.c) $(HDRS) Makefile
	$(CC) -o $@ $($@:.o=.c) -c $(CFLAGS)

clean:
	rm -rf $(EXEC) HDRPATH

.PHONY: all clean
