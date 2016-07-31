# Declaration of variables
CC = g++
CC_FLAGS = -Wall -std=c++0x

# File names
EXEC = ./subnet2cidr
#SOURCES = $(wildcard src/*.cpp)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
# LIBS = -lmosquitto -lwiringPi -laugeas
# INC=-I./../include -I/usr/include/libxml2


# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $(EXEC) 

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $(INC) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
