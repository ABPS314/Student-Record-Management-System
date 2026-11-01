
CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = student.o add_student.o display_student.o delete_student.o modify_student.o save_student.o load_student.o sort_student.o

out: $(OBJ)
	$(CC) $(OBJ) -o out

%.o: %.c student.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f out $(OBJ)



