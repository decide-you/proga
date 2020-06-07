main:main.cpp
	g++ -g -Wall -o bin/main main.cpp
run:
	./bin/main ./input.txt
clean:
	rm -rf build/*.o out.txt
