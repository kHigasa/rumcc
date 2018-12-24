rumcc: rumcc.c

test: rumcc
		./test.sh

clean:
		rm -f rumcc *.o *~ tmp*