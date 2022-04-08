DIR =../include #променлива, която търси в предишната директория на /include и в самата директория /include
CC=gcc # променлива
CFLAGS=-I$(IDIR) 

ODIR=obj
LDIR =../lib

LIBS=-lm #променлива, която задава с какъв флаг да се компилират файловете

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
