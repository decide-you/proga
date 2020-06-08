all:bin/program bin/
bin/program:build/src/main.o build/src/sort.o build/src/work_with_array.o
	g++ -Wall -Werror build/src/main.o build/src/sort.o build/src/work_with_array.o -o bin/program -lm
build/src/sort.o:src/sort.cpp
	g++ -Wall -Werror -c src/sort.cpp -o build/src/sort.o
build/src/main.o:src/main.cpp
	g++ -I src -Wall -Werror -c src/main.cpp -o build/src/main.o
build/src/work_with_array.o:src/work_with_array.cpp
	g++ -Wall -Werror -c src/work_with_array.cpp -o build/src/work_with_array.o
run:
	./bin/program ./input.txt ./output_inc.txt ./output_alph
clean:
	rm -rf build/src/*.o build/test/*.o bin/program bin/program_test output_inc.txt output_alph.txt
