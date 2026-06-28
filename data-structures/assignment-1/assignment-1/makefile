all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/MainList.cpp -o ./lib/MainList.o
	g++ -c -I "./include" ./src/Shape.cpp -o ./lib/Shape.o
	g++ -c -I "./include" ./src/ShapeList.cpp -o ./lib/ShapeList.o
	g++ -c -I "./include" ./src/Square.cpp -o ./lib/Square.o
	g++ -c -I "./include" ./src/Star.cpp -o ./lib/Star.o
	g++ -c -I "./include" ./src/Triangle.cpp -o ./lib/Triangle.o

bagla:
	g++ ./lib/main.o ./lib/MainList.o ./lib/ShapeList.o ./lib/Square.o ./lib/Star.o ./lib/Triangle.o ./lib/Shape.o -o ./bin/program
calistir:
	./bin/program

