all:derle bagla calistir
derle:
	g++ -c -I "./include"  ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include"  ./src/AltigenList.cpp -o ./lib/AltigenList.o
	g++ -c -I "./include"  ./src/SayiDugum.cpp -o ./lib/SayiDugum.o
	g++ -c -I "./include"  ./src/AgacDugum.cpp -o ./lib/AgacDugum.o
	g++ -c -I "./include"  ./src/Altigen.cpp -o ./lib/Altigen.o
	g++ -c -I "./include"  ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	g++ -c -I "./include"	./src/AltigenDugum.cpp -o ./lib/AltigenDugum.o

bagla:
	g++ ./lib/AltigenList.o ./lib/SayiDugum.o ./lib/AgacDugum.o ./lib/Altigen.o ./lib/IkiliAramaAgaci.o ./lib/main.o ./lib/AltigenDugum.o -o ./bin/program
calistir:
	./bin/program