main: main.o funcs.o imageio.o
	g++ -o main -std=c++11 main.o funcs.o imageio.o


main.o: main.cpp funcs.cpp funcs.h 
	g++ -c -std=c++11 main.cpp funcs.cpp
 

imageio.o: imageio.cpp imageio.h
	g++ -c -std=c++11 imageio.cpp

clean:
	rm -f sample.o imageio.o main.o funcs.o
	rm -f main a.out sample
	rm -f taskA.pgm taskB.pgm taskC.pgm taskD.pgm taskE.pgm taskF.pgm
