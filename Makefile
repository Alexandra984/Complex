CPPFLAGS=-g -Wall -Wextra

all: build/ build/demo

build/:
	@mkdir -p build

build/demo: build/main.o build/complex.o
	g++ -g -o build/demo build/main.o build/complex.o

build/main.o: src/main.cpp src/complex.hpp
	g++ $(CPPFLAGS) -c -o build/main.o src/main.cpp

build/complex.o: src/complex.cpp src/complex.hpp
	g++ $(CPPFLAGS) -c -o build/complex.o src/complex.cpp

clean:
	@rm -f build/*.o
