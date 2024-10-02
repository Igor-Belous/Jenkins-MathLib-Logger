.PHONY: all s21_math.a test rebuild clean test_reports

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

SRC=$(wildcard s21_*.c) # собираю все файлы функций s21_*.c в переменную SRC
OBJ=$(patsubst %.c,%.o, $(SRC)) # в переменной OBJ собираю все названия файлов функций заменяя расширение на o
ALL_C_SL=$(SRC)

TEST_C_DIR=./unit_tests/
TEST_SRC=$(wildcard $(TEST_C_DIR)/test_s21_*.c)
ALL_C_TEST=$(TEST_C_DIR)all_tests_s21.c $(TEST_SRC) # аналогично для тестовых файлов

# Основная цель — сборка и тестирование
all: test_reports gcov_report test s21_math.a

# Создание статической библиотеки
s21_math.a: $(SRC)
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc s21_math.a $(OBJ)

# Запуск тестов с генерацией отчетов JUnit XML
test: s21_math.a test_reports
ifeq ($(OS), Darwin)
	$(CC) $(STDFLAGS) $(LDFLAGS) $(ALL_C_TEST) -o all_tests_s21 $(LIBS) s21_math.a || { echo "Compilation failed"; exit 1; }
else
	$(CC) $(STDFLAGS) $(LDFLAGS) $(ALL_C_TEST) -o all_tests_s21 $(LIBS) $(UBUNTU_FLAGS) s21_math.a || { echo "Compilation failed"; exit 1; }
endif
	echo "Running tests..."
	CK_XML=yes CK_OUTPUT=./test_reports ./all_tests_s21 || { echo "Tests failed"; exit 1; }


# Цель для пересборки проекта
rebuild: clean all

# Создание директории для отчетов
test_reports:
	mkdir -p test_reports

# Очистка сгенерированных файлов
clean:
	rm -rf all_tests_s21 *.o *.a unit_tests/*.gc* unit_tests/*.info
	rm -rf test_reports/
