#include"header.h"

void display_student(list*ptr)
{
	if(ptr==NULL)
		fprintf(stderr,"no record found..\n");
	printf("STUDENT DATA\n");
	printf("----------------------------------------------\n");
	while(ptr!=NULL)
	{
		printf("|%d\t|%s\t|%f|\n",ptr->id,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
		printf("----------------------------------------------\n");
		printf("data displayed succesfully\n");
}
