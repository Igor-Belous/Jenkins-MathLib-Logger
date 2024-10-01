.PHONY: all s21_math.a test gcov_report rebuild clean

CC=gcc
STDFLAGS= -Wall -Werror -Wextra -std=c11
GCOV_FLAGS= -fprofile-arcs -ftest-coverage
UBUNTU_FLAGS= -lsubunit -lrt -lpthread -lm
LIBS= -lcheck
LDFLAGS= -L/usr/local/lib -I/usr/local/include

# Makefile для сборки библиотеки и тестов 
# Цели: all, clean, test, s21_math.a, gcov_report
# Оформить решение как статическую библиотеку (с заголовочным файлом s21_math.h)
OS=$(shell uname -s)

# выполнение команды в терминале Ubuntu 22.04.3 LTS:
# uname -s
# возвращает:
# Linux

SRC=$(wildcard s21_*.c) # собираю все файлы функций s21_*.c в переменную SRC
OBJ=$(patsubst %.c,%.o, $(SRC)) #  в переменной OBJ собираю все названия файлов функций заменяя расширение на o
ALL_C_SL=$(SRC)


TEST_C_DIR=./unit_tests/
TEST_SRC=$(wildcard $(TEST_C_DIR)/test_s21_*.c)
ALL_C_TEST=$(TEST_C_DIR)all_tests_s21.c $(TEST_SRC) #  аналогично для тестовых файлов

all: gcov_report test s21_math.a

s21_math.a: $(SRC)
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc s21_math.a $(OBJ)

test: s21_math.a
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(LDFLAGS) $(ALL_C_TEST) -o all_tests_s21 $(LIBS) s21_math.a
 else # Флаги для GNU 
	$(CC) $(STDFLAGS) $(LDFLAGS) $(ALL_C_TEST) -o all_tests_s21 $(LIBS) $(UBUNTU_FLAGS) s21_math.a
endif
	./all_tests_s21

# Сборка all_tests_s21 + репорты  gcov lcov по покрытию + genhtml - для Убунту или для Макбук

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(LDFLAGS) $(GCOV_FLAGS) $(ALL_C_SL) $(ALL_C_TEST) -o all_tests_s21 $(LIBS)
 else # Флаги для GNU
	$(CC) $(STDFLAGS) $(LDFLAGS) $(GCOV_FLAGS) $(ALL_C_SL) $(ALL_C_TEST) -o all_tests_s21 $(LIBS) $(UBUNTU_FLAGS)
endif 
	./all_tests_s21
	mv *.gc* unit_tests
	lcov -o ./unit_tests/all_tests_s21.info -c -d unit_tests
	genhtml -o test_report ./unit_tests/all_tests_s21.info
	open ./test_report/index.html

rebuild: clean all

clean:
	rm all_tests_s21 *.o *.a unit_tests/*.gc* unit_tests/*.info
	rm -rf test_report/