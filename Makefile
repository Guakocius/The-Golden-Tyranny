CC = g++
CFLAGS = -I./src/include/
SRC = ./src/
OBJ = $(patsubst %.cpp, %.o, $(shell find $(SRC) -name "*.cpp"))
TARGET = the-golden-tyranny

all: $(TARGET) rm_objects

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

rm_objects:
	rm -f $(OBJ)
