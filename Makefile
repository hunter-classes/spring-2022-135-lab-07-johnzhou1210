OBJS=main.o reformat.o

main: main.o reformat.o
	g++ -o main $(OBJS)

main.o: main.cpp

reformat.o: reformat.cpp reformat.h

clean:
	rm -f $(OBJS)
