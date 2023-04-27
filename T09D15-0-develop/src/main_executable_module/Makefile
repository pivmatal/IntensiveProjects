TARGET = ../../build/Quest_3

CC = gcc-11 -Wall -Werror -Wextra 
SRCO = main_executable_module.o data_process.o data_io.o data_stat.o decision.o

.PHONY: all clean rebuild


$(TARGET): $(SRCO)
	$(CC) -o $(TARGET) $(SRCO)

clean:
	rm $(TARGET) *.o

clean2:
	rm ../../build/Quest_6
	rm ../../build/Quest_5

all: $(TARGET)

rebuild: clean all

main_executable_module.o: main_executable_module.o
	$(CC) -c main_executable_module.c -o main_executable_module.o 

data_process.o: data_process.o
	$(CC) -c  ../data_module/data_process.c -o data_process.o 

data_io.o: data_io.o
	$(CC) -c  ../data_libs/data_io.c -o data_io.o 

data_stat.o: data_stat.o
	$(CC) -c  ../data_libs/data_stat.c -o data_stat.o 

decision.o: decision.o
	$(CC) -c  ../yet_another_decision_module/decision.c -o decision.o 


data_stat.a: data_stat.o
	gcc -c ../data_libs/data_stat.c 
	ar r data_stat.a data_stat.o
	ranlib data_stat.a
	rm data_stat.o

build_with_static: main_executable_module.o data_process.o data_io.o data_stat.a decision.o
	gcc -o ../../build/Quest_5 main_executable_module.o data_process.o data_io.o data_stat.a decision.o  
	rm *.o

data_process.so: data_process.o	
	gcc -c -fPIC ../data_module/data_process.c 
	gcc -shared -o data_process.so data_process.o data_stat.a
	rm data_process.o

build_with_dynamic: main_executable_module.o data_process.so data_io.o data_stat.o decision.o
	gcc -o ../../build/Quest_6 main_executable_module.o data_process.so data_io.o data_stat.o decision.o  
	rm *.o

