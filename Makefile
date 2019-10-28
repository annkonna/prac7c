CC = gcc
CFLAGS = -g

empcr: empcr.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm empcr

.PHONY: empcr
