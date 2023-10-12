NAME		= s21_matrix_oop.a
HEADER		=	testt.h
CFLAGS		= -Wall -Werror -Wextra -std=c++17
#-I.
FILES		= test.cc

FILES_TESTS = t2.cc

CC = g++

# s21_matrix_oop.cc \
# 				check.cc \
# 				constructors.cc \
# 				LU.cc \
# 				operators.cc \
# 				set_and_get.cc \
# 				main.cc

OBJ			= $(FILES:%.cc=%.o)

OBJ_TESTS			= $(FILES_TESTS:%.cc=%.o)

%.o: %.cc $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

# This won't run if the .o files don't exist or are not modified
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# This won't run if the source files don't exist or are not modified

clean:
#	rm -f $(OBJ)
	rm -rf *.o *.out *.a unit_test
	rm -rf *.gcda *.gcno report gcov_report.* gcov_report *.info
# comment this line if you don't want it to remove the source files from the root

fclean: clean
	rm -f $(NAME)

main: 
# $(OBJ)
	clang++ $(CFLAGS) set_and_get.cc s21_matrix.cc main.cc -o main 
# $(CC) *.o -o main
#	$(CC) -std=c++17 main.cc -o main s21_matrix_oop.a
	./main

debag: 
	clang++ $(CFLAGS) set_and_get.cc s21_matrix.cc main.cc -o main

test: $(OBJ)
	$(CC) $(CFLAGS) test.cc -o test

gtest: $(OBJ_TESTS)
#	$(CC) $(CFLAGS) $(NAME) -I"/usr/local/include/gtest" gtests.cc -o gtests
	$(CC) $(CFLAGS)  $(OBJ_TESTS) -I /usr/local/lib -o gtests
	./gtests

re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean main debag test gtest fclean all re