CC = g++
CFLAGS = -c -Wall -DDEBUG -g
LDFLAGS = -lcomdlg32 -lgdi32
COMMON_SOURCES = createExample.cpp manipulateExample.cpp textExample.cpp
EXE1 = createExample
EXE2 = buttonExample
EXE3 = textExample

all: $(EXE1) $(EXE2) $(EXE3)

$(EXE1): $(EXE1).cpp
	$(CC)  $^ -o $@ $(LDFLAGS)

$(EXE2): $(EXE2).cpp
	$(CC)  $^ -o $@ $(LDFLAGS)

$(EXE3): $(EXE3).cpp
	$(CC)  $^ -o $@ $(LDFLAGS)

clean:
	rm $(EXE1).exe $(EXE2).exe $(EXE3).exe