FLEX=flex
BISON=bison
FFLAGS=-lfl
TDSFLAGS=-L./lib -I./include -ltds -lgci
CC=gcc
DEBUGFLAG=-t
VERBFLAG=-v

all:cmc

alex.c: alex.l
	$(FLEX) -o$@ $<

asin.c: asin.y
	$(BISON) $(DEBUGFLAG) $(VERBFLAG) -o$@ -d $<

cmc: asin.c alex.c
	$(CC) -g -o$@ $^ $(TDSFLAGS) $(FFLAGS) 

clean:
	rm -f asin.c alex.c cmc *.o 
