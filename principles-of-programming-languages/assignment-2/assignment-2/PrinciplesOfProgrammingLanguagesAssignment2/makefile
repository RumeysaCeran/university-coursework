hepsi: derle calistir

derle:
	gcc -I ./include -c ./src/BasamakKontrol.c -o ./lib/BasamakKontrol.o
	gcc -I ./include -c ./src/Ilce.c -o ./lib/Ilce.o
	gcc -I ./include -c ./src/Sehir.c -o ./lib/Sehir.o
	gcc -I ./include -c ./src/Kisi.c -o ./lib/Kisi.o
	gcc -I ./include -c ./src/Mahalle.c -o ./lib/Mahalle.o
	gcc -I ./include -c ./src/NesneleriOlustur.c -o ./lib/NesneleriOlustur.o
	gcc -I ./include -c ./src/Oyun.c -o ./lib/Oyun.o
	gcc -I ./include -c ./src/Yerlesim.c -o ./lib/Yerlesim.o
	gcc -I ./include -c ./src/Main.c -o ./lib/Main.o

	gcc -o ./bin/Main.exe \
	./lib/BasamakKontrol.o \
	./lib/Ilce.o \
	./lib/Sehir.o \
	./lib/Kisi.o \
	./lib/Mahalle.o \
	./lib/NesneleriOlustur.o \
	./lib/Oyun.o \
	./lib/Yerlesim.o \
	./lib/Main.o

calistir:
	./bin/Main.exe
