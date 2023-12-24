MAIN_FILES = main.cpp main.o
SOURCES=main.cpp vector_strings.cpp
HEADERS=vector_strings.hpp
OBJECTS=$(SOURCES:cpp=o)
EXECNAME=main
CLEAN_FILES=out.txt in.txt