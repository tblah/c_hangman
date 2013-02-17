OUTPUT_NAME = hangman
COMPILE_OPS = -o3 -g -Wall
SOURCE_FILES = main.c init.c

all: main.c init.c
	gcc $(COMPILE_OPS) -o $(OUTPUT_NAME) $(SOURCE_FILES)

clean:
	rm $(OUTPUT_NAME)
