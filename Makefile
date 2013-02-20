OUTPUT_NAME = hangman
COMPILE_OPS = -o3 -g -Wall
SOURCE_FILES = main.c init.c getGuess.c
HEADDER_FILES = init.h getGuess.h

all: $(SOURCE_FILES) $(HEADDER_FILES)
	gcc $(COMPILE_OPS) -o $(OUTPUT_NAME) $(SOURCE_FILES)

clean:
	rm $(OUTPUT_NAME) 
