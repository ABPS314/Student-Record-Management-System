#include"header.h"

void sort_student(list*ptr)
{
	if(ptr==NULL)
	{
		printf("no data avalible to sort..\n");
		return;
	}
	if(ptr->next == NULL)
	{
    		printf("Only one record available.\n");
   		return;
	}
	char sort_ch;
	printf("N/n : Sort by Name\nM/m : Sort by Percentage\nEnter Your sort Choice:");
	scanf(" %c",&sort_ch);

	list*last=ptr;
	list*current=last->next;
	switch(sort_ch)
	{
		case 'N':
		case 'n':
			{
				int temp_id;
				char temp_name[30];
				float temp_marks;
				int name_flag=0;
				int count=0;
				list*temp=ptr;

			
				while(temp!=NULL)
				{
					count++;
					temp=temp->next;
				}
				for(int pass=0;pass<count-1;pass++)
				{
					last=ptr;
					current=last->next;

					while(current!=NULL)
					{
						if(strcmp(last->name,current->name)>0)
						{	
							name_flag=1;
							//id swapping
							temp_id=last->id;
							last->id=current->id;
							current->id=temp_id;
							//name swapping
							strcpy(temp_name,last->name);
							strcpy(last->name,current->name);
							strcpy(current->name,temp_name);
							//marks swapping
							temp_marks=last->marks;
							last->marks=current->marks;
							current->marks=temp_marks;
						}
						last=current;
						current=current->next;
					}
				}
				printf("Sorting completed..\n");
				if(name_flag==0)
				{
					printf("data already in sorted order..\n");
					return;
				}
			}
			break;
		case 'M':
		case 'm':
			{
				int temp_id;
				char temp_name[30];
				float temp_marks;
				int mark_flag=0;
				int count=0;
				list*temp=ptr;


				while(temp!=NULL)
				{
					count++;
					temp=temp->next;
				}
				for(int pass=0;pass<count-1;pass++)
				{
					last=ptr;
					current=last->next;

					while(current!=NULL)
					{
						if(last->marks > current->marks)
						{
							mark_flag=1;
							//id swapping
							temp_id=last->id;
							last->id=current->id;
							current->id=temp_id;
							//name swapping
							strcpy(temp_name,last->name);
							strcpy(last->name,current->name);
							strcpy(current->name,temp_name);
							//marks swapping
							temp_marks=last->marks;
							last->marks=current->marks;
							current->marks=temp_marks;
						}
						last=current;
						current=current->next;
					}
				}
				printf("Sorting completed..\n");
				if(mark_flag==0)
				{
					printf("data already in sorted order..\n");
					return;
				}
			}
			break;
		default:
			printf("Invalid sorting choice.\n");
			return;

	}
}
