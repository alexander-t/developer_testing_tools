CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lcheck -lrt -lpthread -lm

all: run_tests

run_tests: run_tests.o integer_assertions.o string_assertions.o general_functionality.o
	$(CC) $^ -o $@ $(LDFLAGS)

.c.o: 
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~ run_tests
