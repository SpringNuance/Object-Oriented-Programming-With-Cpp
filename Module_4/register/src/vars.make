MAIN_FILES = main.cpp main.o
SOURCES=main.cpp register.cpp vehicle.cpp boat.cpp aircraft.cpp
HEADERS=register.hpp vehicle.hpp boat.hpp aircraft.hpp
OBJECTS=$(SOURCES:cpp=o)
EXECNAME=main
CLEAN_FILES=*.txt