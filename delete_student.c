
#include"header.h"
void delete_student(list**ptr)
{
    	if((*ptr)==NULL)
	{
            	printf("no record to delete..\n");
		return ;
	}
	list*last=NULL;
	list*current=(*ptr);
	char del_ch;
    	printf("R/r:Delet through id\nN/n:Delete through name\nE/e:exit back to main menu\n");
    	printf("Enter your Delete choice:");
    	scanf(" %c",&del_ch);

            	switch(del_ch)
            	{
                    	case 'R':
                    	case 'r':
                            	{
                                    	int search_id;
					int id_flag=0;
                                    	printf("Enter the id to delete:");
                                    	scanf("%d",&search_id);
					while(current!=NULL)
					{
						if(search_id==current->id)
						{
							id_flag=1;

							// DELETION CONFIRMATION
							char confirm;
							printf("Are you sure you want to delete %s (ID: %d)? (y/n): ",current->name,current->id);
							scanf(" %c",&confirm);
							if(confirm!='y' && confirm!='Y')
							{
								printf("Deletion cancelled.\n");
								return;
							}

							if(current==(*ptr))
							{
								(*ptr)=current->next;
								free(current);
								printf("record deleted succesfully.\n");
							}
							else
							{
								last->next=current->next;
								free(current);
								printf("record deleted succesfully.\n");
							}
							break;
						}
						else
						{
							last=current;
							current=current->next;
						}
					}
					if(id_flag==0)
					{
						printf("no record avalible to delete..\n");
						return;
					}
				}
				break;
			case 'N':
			case 'n':
				{
					//FIRST LPOOP FOR FINDING SIMOLAR NAMES AND DISPLAYING
					char search_name[30];
					int count=0;
					printf("Enter the name to delete:");
					scanf(" %29[^\n]",search_name);
					printf("Searching for: %s\n", search_name);
					while(current!=NULL)
					{
						printf("Current node: %s\n",current->name);
						if(strcmp(search_name,current->name)==0)
						{
							count++;
							printf("Matched record: %d\t%s\t%f\n",current->id,current->name,current->marks); 
							//current=current->next;
						}
						current=current->next;
					}
					printf("Total matches found: %d\n",count);
					if(count==0)
					{
						printf("No name found in record.\n");
						return;
					}
					
					//SECOND LOOP FOR DELETING
					int delete_id;
					int name_flag=0;
					printf("Enter Id to delete:");
					scanf("%d",&delete_id);
					last=NULL;
					current=(*ptr);
					while(current!=NULL)
					{
						if((current->id==delete_id) && (strcmp(current->name,search_name))==0)
						{
							name_flag=1;

							// DELETION CONFIRMATION
							char confirm;
							printf("Are you sure you want to delete %s (ID: %d)? (y/n): ",current->name,current->id);
							scanf(" %c",&confirm);
							if(confirm!='y' && confirm!='Y')
							{
								printf("Deletion cancelled.\n");
								return;
							}

							if(current==(*ptr))
							{
							(*ptr)=current->next;
							free(current);
							printf("record deleted succesfully.\n");
							}
							else
							{
								last->next=current->next;
								free(current);
								printf("record deleted succesfully.\n");
							}
							break;
						}
						else
						{
							last=current;
							current=current->next;
						}
					}
					if(name_flag==0)
					{
						printf("no record avalible to delete..\n");
						return;
					}
				}
				
		}
}

