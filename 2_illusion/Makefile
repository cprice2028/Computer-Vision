example1.png: example1.ppm
	python3 ppm2png.py example1

example1.ppm: a.out
	./a.out

a.out: example1.cpp
	g++ example1.cpp

clean:
	rm a.out example1.ppm
