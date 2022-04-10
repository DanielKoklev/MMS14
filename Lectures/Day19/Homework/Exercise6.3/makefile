# my makefile
CC=clang # променлива, съхраняваща компилатора clang
CFLAGS=-lm -pthread #с какви флагове да се компилира
OBJS = main.o sum.o mult.o div.o sub.o # object файлове

.PHONY: all # като се извика make all ще се компилира програмата и нейните зависимости
all: program

program: $(OBJS) # зависимостите са всички object файлове
	$(CC) $^ -o $@ $(CFLAGS) # 

%.o: %.c# името на таргета и зависимостите е еднакво
	$(CC) -c $< -o $@ 

.PHONY: clean# тук е обозначено clean да не се бърка с име на файл
clean: # тук се изчистват всички .о файлове
	rm -rf *.o program