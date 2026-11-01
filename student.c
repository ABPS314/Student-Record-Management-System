#include"header.h"

int main()
{
	list*head=NULL;
	int count=0;
	load_student(&head);
	list*temp=head;
	while(temp!=NULL)
	{
		count++;
		if(temp->id > count)
			count=temp->id;
		temp=temp->next;
	}

	char choice;
	printf("***STUDENT RECORD MANAGEMENT SYSTEM***\n");
	printf("A/a : Add New Record\nD/d : Delete a Record\nS/s : Show the List\nM/m : Modify a Record\nV/v : Save\nT/t : Sort the List\nE/e : Exit\n");
	//scanf(" %c",&choice);
	do
	{
		printf("Enter your main choice:");
		scanf(" %c",&choice);
		if(choice=='A' || choice=='a')
			add_student(&head,count);
		else if(choice=='S' || choice=='s')
			display_student(head);
		else if(choice=='D' || choice=='d')
			delete_student(&head);
		else if(choice=='M' || choice=='m')
			modify_student(head);
		else if(choice=='V' || choice=='v')
			save_student(head);
		else if(choice=='T' || choice=='t')
			sort_student(head);
		else if(choice=='E' || choice=='e')
		{
			char exit_choice;
			printf("S/s : Save and Exit\nE/e : Exit Without Saving\nEnter Your exit Choice:");
			do
			{
				scanf(" %c",&exit_choice);
				if(exit_choice=='S' || exit_choice=='s')
				{
					save_student(head);
					break;
				}
				else if(exit_choice=='E' || exit_choice=='e')
				{
					break;
				}
				else
					printf("enter valib option:");
			}while(exit_choice != 'S' && exit_choice != 's' &&
        			exit_choice != 'E' && exit_choice != 'e');
		}
		
	}while(choice!='E' && choice!='e');

}
