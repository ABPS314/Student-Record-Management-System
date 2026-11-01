#include"header.h"

//ADD END METHOD
void add_student(list**ptr,int c)
{
	char op;
	do
	{
	list*new=malloc(sizeof(list));
	new->id=c+1;
	printf("Enter student name: ");
	scanf(" %29[^\n]", new->name);
	printf("Enter marks: ");
	scanf("%f", &new->marks);
	c++;
	new->next=NULL;
	if((*ptr)==NULL)
		(*ptr)=new;
	else
	{
		list*last=(*ptr);
		while(last->next!=NULL)
			last=last->next;
		last->next=new;
	}
	printf("Want to add another student(y/n):");
	scanf(" %c",&op);
	}while(op=='y');
}
