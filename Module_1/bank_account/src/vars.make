MAIN_FILES = main.cpp main.o
SOURCES=main.cpp bank_account.cpp
HEADERS=bank_account.hpp
OBJECTS=$(SOURCES:cpp=o)
EXECNAME=main
CLEAN_FILES=out.txt