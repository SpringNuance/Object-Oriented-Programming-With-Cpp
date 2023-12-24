MAIN_FILES = main.cpp main.o
SOURCES=main.cpp rectangle.cpp
HEADERS=rectangle.hpp
OBJECTS=$(SOURCES:cpp=o)
EXECNAME=main
CLEAN_FILES=out.txt in.txt