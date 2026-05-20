CC = g++
CFLAGS = -Wall -std=c++11
OBJ = main.o hamilton.o
TARGET = cykl_hamiltona

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.cpp hamilton.h
	$(CC) $(CFLAGS) -c main.cpp

hamilton.o: hamilton.cpp hamilton.h
	$(CC) $(CFLAGS) -c hamilton.cpp

clean:
	rm -f *.o $(TARGET)