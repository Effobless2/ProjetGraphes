# Compiler
C_CPP := g++

# Compilation options
CPP_FLAGS := --std=c++98 -Wall -Wextra -pedantic -ggdb -Wno-unused-parameter -Wno-return-type -Wno-variadic-macros -pg -g

SRC := src/

OBJF := obj/

OUT := out/

OBJS := $(OBJF)Emplacement.o $(OBJF)Hashpam.o $(OBJF)main.o  

# Compilation rules

all: $(OUT)main

$(OUT)main : $(OBJS)
	mkdir -p $(OUT)
	$(C_CPP) $(CPP_FLAGS) -o $@ $^	

$(OBJF)%.o : $(SRC)%.cpp
	mkdir -p $(OBJF)
	$(C_CPP) $(CPP_FLAGS) -o $@ -c $< 

clean:
	rm -r obj out

run:
	valgrind ./$(OUT)main