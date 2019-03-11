CFLAGS=-Wall -std=c11
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

rumcc: $(OBJS)
		$(CC) -o rumcc $(OBJS) $(LDFLAGS)

$(OBJS): rumcc.h

test: rumcc
		./rumcc -test
		./test.sh

clean:
		rm -f rumcc *.o *~
