CC = g++
CFLAGS = -c -Wall -DDEBUG -g
LDFLAGS = -lcomdlg32 -lgdi32
COMMON_SOURCES = findAndManipulate.cpp

EXE4 = findAndManipulate

all:  $(EXE4)


$(EXE4): $(EXE4).cpp
	$(CC)  $^ -o $@ $(LDFLAGS)

clean:
	rm  $(EXE4).exe