.PHONY: clean

bin/ut_shape: test/ut_shape.cpp test/ut_sort.cpp  test/ut_main.cpp src/circle.h src/rectangle.h src/triangle.h src/sort.h
	g++ -std=c++11 test/ut_main.cpp -o bin/hw2 -lgtest -lpthread

clean:
	rm hw2
