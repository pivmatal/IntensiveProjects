TARGET = ../build/Quest_1
TARGET2 = ../build/Quest_2

CC = gcc-11 -Wall -Werror -Wextra 
SRCO = dmanager_module.o
SRCO2 = list_test.o list.o

.PHONY: all clean rebuild

$(TARGET): $(SRCO)
	$(CC) -o $(TARGET) $(SRCO)

$(TARGET2): $(SRCO2)
	$(CC) -o $(TARGET2) $(SRCO2)

door_struct: $(TARGET)

list_test: $(TARGET2)

all: $(TARGET)

clean: clean1 clean2

clean1:
	rm $(TARGET) *.o

clean2:
	rm $(TARGET2) *.o

dmanager_module.o: dmanager_module.o
	$(CC) -c dmanager_module.c -o dmanager_module.o

rebuild: clean all

list_test.o: list_test.o
	$(CC) -c list_test.c -o list_test.o

list.o:  list.o
	$(CC) -c list.c -o list.o