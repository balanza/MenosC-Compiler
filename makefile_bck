cmc: alex.o asin.o
	gcc -o cmc alex.o asin.o -L./lib -I./include -lfl -ltds
asin.o: asin.c
	gcc -c asin.c -I./include
alex.o: alex.c asin.c
	gcc -c alex.c -I./include
asin.c: asin.y
	bison -oasin.c -d asin.y
	mv asin.h ./include
alex.c: alex.l
	flex -oalex.c alex.l
