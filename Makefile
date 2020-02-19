
CFLAGS = -g -I /usr/local/lib -I include 
LDFLAGS = -lSDL2-2.0.0

SRC  = $(wildcard ./src/*.cpp)
INCL = $(wildcard ./include/*.hpp)
OBJ  = $(patsubst ./src/%.cpp, obj/%.o, $(SRC))

all: source

#  Execute le programme
run: source
	@./source

source: $(OBJ)
	@g++ $(CFLAGS) -o $@ $^ $(LDFLAGS)
obj/%.o: src/%.cpp $(INCL)
	@mkdir -p obj
	@g++ $(CFLAGS) -c -o $@ $<
clean:
	@rm -r obj/*.o
	@rm source
