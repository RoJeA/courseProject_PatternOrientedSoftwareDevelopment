.PHONY: dirs clean

all: clean dirs bin/ut_all

bin/ut_all: test/ut_main.cpp test/ut_file.h src/node.h src/folder.h src/file.h
	g++ -std=c++11 -Wfatal-errors -o $@ $< -lgtest -lpthread

dirs:
	mkdir -p bin

clean:
	rm -f bin/*
