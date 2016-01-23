BIN=bin
CC=gcc
CFLAGS=-Wall -pedantic -std=c11
OBJECT=obj
SOURCE=src
FILE_OBJ=$(OBJECT)/file.o
SOCK_OBJ=$(OBJECT)/sock.o
AUSOCK_BIN=$(BIN)/ausock

all: $(AUSOCK_BIN)

$(AUSOCK_BIN): $(SOCK_OBJ) $(FILE_OBJ)
	mkdir -p $(BIN)
	gcc $(FILE_OBJ) $(SOCK_OBJ) $(SOURCE)/main.c -o $(AUSOCK_BIN)

$(SOCK_OBJ):
	mkdir -p $(OBJECT)
	$(CC) -c -o $(SOCK_OBJ) $(SOURCE)/sock.c

$(FILE_OBJ):
	mkdir -p $(OBJECT)
	$(CC) -c -o $(FILE_OBJ) $(SOURCE)/file.c

clean:
	rm -rf $(OBJECT)
