OUTPUT_NAME = hangman
COMPILE_OPS = -o3 -g -Wall
SOURCE_FILES = main.c

all: main.c
	gcc $(COMPILE_OPS) -o $(OUTPUT_NAME) $(SOURCE_FILES)

clean:
	rm $(OUTPUT_NAME)
