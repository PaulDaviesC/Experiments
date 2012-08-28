GCC:=gcc
CC:=${GCC}
INCLUDES:=-I lib
OBJ:=main.o timer.o show.o
all: ${OBJ}
	${CC} ${OBJ} -o main -lnotify 
	@echo Build Complete
main.o: src/main.c
	${CC} ${INCLUDES} -c src/main.c
timer.o: lib/timer.h 
	${CC} ${INCLUDES} -c lib/timer.c
show.o:lib/show.h
	${CC} ${INCLUDES} -c lib/show.c -Wall `pkg-config --libs --cflags glib-2.0 gtk+-2.0` 
clean:
	-rm -rf *.o
	-rm main
