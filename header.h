#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// main structure
typedef struct student_data
{
	int id;
	char name[30];
	float marks;
	struct student_data*next;
} list;

//save and load data structure
struct std_data
{	
	int std_id;
	char std_name[30];
	float std_marks;
} ;

void add_student(list**,int);

void display_student(list*);

void delete_student(list**);

void modify_student(list*);

void save_student(list*);

void load_student(list**);

void sort_student(list*);

