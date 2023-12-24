MAIN_FILES = main.cpp main.o
SOURCES=main.cpp dog.cpp cat.cpp mammal.cpp
HEADERS=mammal.hpp dog.hpp cat.hpp
OBJECTS=$(SOURCES:cpp=o)
EXECNAME=main
CLEAN_FILES=out.txt tmp.txt treasures.txt