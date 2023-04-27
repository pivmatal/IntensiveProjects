TARGET = ../build/Quest_1
TARGET2 = ../build/Quest_2
TARGET3 = ../build/Quest_3
TARGET4 = ../build/Quest_4
TARGET5 = ../build/Quest_5

CC = gcc-11 -Wall -Werror -Wextra 
SRCO = s21_string_test.o s21_string.o

.PHONY: all clean rebuild strlen_tests


$(TARGET): $(SRCO)
	$(CC) -o $(TARGET) $(SRCO)

$(TARGET2): $(SRCO)
	$(CC) -o $(TARGET2) $(SRCO)

$(TARGET3): $(SRCO)
	$(CC) -o $(TARGET3) $(SRCO)

$(TARGET4): $(SRCO)
	$(CC) -o $(TARGET4) $(SRCO)

$(TARGET5): $(SRCO)
	$(CC) -o $(TARGET5) $(SRCO)

clean: clean1 clean2 clean3 clean4 clean5

clean1:
	rm $(TARGET) *.o

clean2:
	rm $(TARGET2) *.o

clean3:
	rm $(TARGET3) *.o

clean4:
	rm $(TARGET4) *.o

clean5:
	rm $(TARGET5) *.o

strcat_tests: $(TARGET4)

strlen_tests: $(TARGET)

strcmp_tests: $(TARGET2)

strcpy_tests: $(TARGET3)

strchr_tests: $(TARGET5)

all: $(TARGET)

rebuild: clean all

s21_string_test.o: s21_string_test.o
	$(CC) -c s21_string_test.c -o s21_string_test.o

s21_string.o: s21_string.o
	$(CC) -c s21_string.c -o s21_string.o


