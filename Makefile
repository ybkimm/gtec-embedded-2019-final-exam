SRCS := main.c game_object.c painter.c sprite.c utils.c

OBJS := $(SRCS:.c=.o)
HEDS := $(SRCS:.c=.h) sprite_cards.h

CC 		= gcc
TARGET 	= game
CFLAGS 	= -Wall -Wextra -I.
LFLAGS 	= -lwiringPi -lwiringPiDev

.PHONY: build
build: $(TARGET)

.PHONY: run
run: $(TARGET)
	sudo ./$(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LFLAGS)
