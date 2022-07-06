CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

OBJ_TEST = $(filter-out main.o, $(OBJ)) 
EXEC= logic 

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@  

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depend:
	g++ -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC)
