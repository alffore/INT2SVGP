##
#
#
##

CC= g++ -c

CLINKER= g++ -lm -o 

CFLAGS= -O2  -Wall

LIBS=

OBJ= main.o \
	Poligonal.o \
	LectorINT.o \
	EscalaP.o \
	SalidaSVG.o

	

DIR_SRC= ./src/
DIR_BIN= ./bin/
DIR_OBJ= ./obj/

all: clean $(OBJ)
	$(CLINKER) $(DIR_BIN)int2svgp.exe $(OBJ) $(LIBS) $(CFLAGS)



%.o: $(DIR_SRC)%.cpp
	$(CC) $(CFLAGS)  $<
	
clean:
	@rm -rfv *.o

docs:
	