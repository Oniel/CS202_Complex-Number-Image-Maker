# Make file for complex plot program.

OBJS = main.o complexPlot.o complexType.o
CC	= g++
DEPS1 = bitmapImage.h
DEPS2 = complexType.h
DEPS3 = complexPlot.h

all: main

main: $(OBJS)
	$(CC) -g -o main bitmapImage.so $(OBJS)

main.o:	main.cpp $(DEPS1) $(DEPS2) $(DEPS3)
	$(CC) -c -g main.cpp

complexType.o: complexType.cpp $(DEPS2)
	$(CC) -c -g complexType.cpp

bioMorph.o:	complexPlot.cpp $(DEPS1) $(DEPS2) $(DEPS3)
	$(CC) -c -g complexPlot.cpp

# -----
# clean by removing object files.

clean:
	rm	$(OBJS)

