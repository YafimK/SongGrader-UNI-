#Declerations
CC = g++
CFLAGS = -std=c++11 -Wall -Wextra
OFLAGS = -o
EXEC = MIR
DELETEDFILE = *.o MIR ex2.tar
TARFILES = README MIR Makefile *.cpp *.h

#Commands
all: clean mir tar

mir:
	$(CC) $(CFLAGS) *.cpp $(OFLAGS) $(EXEC)

clean:
	rm -f -v  -r $(DELETEDFILE)

tar:
	tar cvf ex2.tar $(TARFILES)

.PHONY: all clean tar mir
