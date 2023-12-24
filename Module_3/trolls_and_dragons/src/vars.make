MAIN_FILES = main.cpp main.o
SOURCES=main.cpp creature.cpp dragon.cpp troll.cpp
HEADERS=creature.hpp dragon.hpp troll.hpp
OBJECTS=$(SOURCES:cpp=o)
EXECNAME=main
CLEAN_FILES=out.txt tmp.txt