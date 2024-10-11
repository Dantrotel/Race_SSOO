all:
	g++ -std=c++11 -pthread race.cpp -o race

clean:
	rm -f race
