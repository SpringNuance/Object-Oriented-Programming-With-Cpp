MAIN_FILES = main.cpp main.o
SOURCES=main.cpp geomvector.cpp
HEADERS=geomvector.hpp
OBJECTS=$(SOURCES:cpp=o)
EXECNAME=main
CLEAN_FILES=out.txt tmp.txt