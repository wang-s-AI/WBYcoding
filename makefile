CC      = gcc
CFLAGS  = -Wall -Wextra -O2 -std=c11
OBJS    = main.o map.o player.o package.o forklift.o

game: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c game.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o game