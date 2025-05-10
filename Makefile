CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lcheck -lsubunit -lm
GCOV_FLAGS = --coverage

# Source files
SRC = $(wildcard func/*.c)

HEDER_FILE = $(wildcard s21_matrix.h)

# Test files
TEST_FILES = $(wildcard tests/test_s21_*.c)
TEST_OBJS = $(TEST_FILES:.c=.o)
TEST_MAIN = tests/test_main.c
TEST_MAIN_OBJ = $(TEST_MAIN:.c=.o)

# Object files
OBJS = $(patsubst %.c, %.o, $(SRC))

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

all: s21_matrix.a

s21_matrix.a: $(OBJS)
	ar rcs $@ $(OBJS)

# Regular test build
test: s21_matrix.a $(TEST_OBJS) $(TEST_MAIN_OBJ)
	$(CC) $(TEST_OBJS) $(TEST_MAIN_OBJ) s21_matrix.a -o tests/$@ $(LDFLAGS)
	./tests/$@

# Test with valgrind
test_valgrind: s21_matrix.a $(TEST_OBJS) $(TEST_MAIN_OBJ)
	$(CC) $(TEST_OBJS) $(TEST_MAIN_OBJ) s21_matrix.a -o $@ $(LDFLAGS)
	valgrind --tool=memcheck --leak-check=yes ./$@

# Coverage report
gcov_report: CFLAGS += $(GCOV_FLAGS)
gcov_report:
	mkdir -p coverage_report
	$(CC) $(CFLAGS) -o tests/test $(SRC) $(TEST_FILES) $(TEST_MAIN) $(LDFLAGS)
	./tests/test
	lcov -t "Coverage Report" -c -d . --output-file coverage_report/coverage.info
	lcov --remove coverage_report/coverage.info "*/tests/*" -o coverage_report/filtered.info
	genhtml coverage_report/filtered.info --output-directory coverage_report/
	xdg-open coverage_report/index.html || open coverage_report/index.html

clang-format:
	clang-format -i $(SRC) tests/*.c $(HEDER_FILE)

clean:
	rm -f $(OBJS) s21_matrix.a test test_valgrind
	rm -rf coverage_report
	rm -f tests/*.gcno tests/*.gcda tests/*.o tests/test
	rm -f $(ALL_SRC:.c=.gcno) $(ALL_SRC:.c=.gcda)
