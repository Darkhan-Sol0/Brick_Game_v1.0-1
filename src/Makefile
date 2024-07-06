CC = gcc

VERSION = 1.0-1

FOLDER_SRC = ./brick_game/tetris/
FOLDER_GUI = ./gui/cli/

EXEC = tetris
EXECUTABLE = brick_game.a

MAIN = $(wildcard brick_game.c)
MAIN_O = $(patsubst %.c, %.o, $(MAIN))

SOURCE = $(wildcard $(FOLDER_SRC)*.c $(FOLDER_GUI)*.c)
HEADER = $(wildcard $(FOLDER_SRC)*.h $(FOLDER_GUI)*.h)
OBJECTS = $(patsubst %.c, %.o, $(SOURCE))

CFLAGS = -std=c11 -Wall -Werror -Wextra -lm -lncurses
# LIBSFLAGS = -lcheck -lm -lsubunit -lrt -lpthread -D_GNU_SOURCE
LIBSFLAGS = -lcheck -lm -lrt -lpthread -lncurses -lm -D_GNU_SOURCE

VALGRIND =  valgrind --tool=memcheck --leak-check=yes

TEST_FILES_C = testfile/*.c
TEST_FILES_H = testfile/*.h

CLANG = clang-format -style=Google

GIT_PUSH = gitpushscript.bash

all: $(EXECUTABLE) install

install: uninstall $(EXECUTABLE) $(MAIN)
	$(CC) -c $(MAIN) -o $(MAIN_O) $(CFLAGS) $(LIBSFLAGS) 
	$(CC) $(MAIN_O) $(EXECUTABLE) -o $(EXEC) $(CFLAGS) $(LIBSFLAGS) 
	rm -rf *.o
	mkdir ~/$(EXEC)
	install ./$(EXEC) ~/$(EXEC)/

$(EXECUTABLE): $(OBJECTS)
	ar rc $(EXECUTABLE) $(OBJECTS)
	ranlib $(EXECUTABLE)
	rm -rf $(OBJECTS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LIBSFLAGS) 

uninstall: 
	rm -rf ~/$(EXEC) $(EXEC)

dvi: clean_dvi
	doxygen
	firefox ./doxygen/html/index.html

dvi_short:
	clear
	cat README.dvi

clean_dvi:
	rm -rf ./doxygen/

dist:
	mkdir dist
	cp -a ./brick_game.c ./dist/
	cp -a ./brick_game/ ./dist/
	cp -a ./Makefile ./dist/ 
	cp -a ./gui/ ./dist/ 
	cp -a ./README.dvi ./dist/ 
	tar -czf $(EXEC)_$(VERSION).tar.gz ./dist/
	rm -rf ./dist/

clean_dist:
	rm -rf *.tar.gz

test: clean_test $(EXECUTABLE)
	$(CC) -o test $(TEST_FILES_C) $(EXECUTABLE) $(CFLAGS)  $(LIBSFLAGS)
	./test

test_valgrind: test
	$(VALGRIND) ./test

clean_test:
	rm -rf test

gcov_report: clean_test clean_report $(EXECUTABLE)
	$(CC) --coverage $(SOURCE) ${TEST_FILES_C} $(EXECUTABLE) $(CFLAGS) $(LIBSFLAGS) -o test
	./test
	gcovr -r . --html-details -o gcov_report.html
	# ~/.local/bin/gcovr -r . --html-details -o gcov_report.html
	mkdir GCOVRreport
	mv *.html *.css GCOVRreport
	rm -rf *.gcno *.gcda

open_report:
	firefox GCOVRreport/gcov_report.html

clean_report:
	rm -rf *.gcno *.gcda *.html *.css GCOVRreport

clean: clean_score clean_report clean_test
	rm -rf $(OBJECTS) $(EXECUTABLE) $(MAIN_O)

clean_score: 
	rm -rf highscore.txt

run:
	cd ~/$(EXEC)
	./$(EXEC)

format:
	$(CLANG) -n $(SOURCE) $(HEADER) $(TEST_FILES_C) $(TEST_FILES_H)

setformat:
	$(CLANG) -i $(SOURCE) $(HEADER) $(TEST_FILES_C) $(TEST_FILES_H)

push:
	git add -A
	git commit -m "$(EXEC)_$(VERSION) - $(shell date +'%Y-%m-%d %H:%M')"
	git push origin develop