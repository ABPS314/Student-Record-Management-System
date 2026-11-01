#include"header.h"
//need to modify the case bug are there.....
void modify_student(list*ptr)
{
	if(ptr==NULL)
	{
		printf("No record avalible.\n");
		return;
	}
	list*current=ptr;
	char mod_ch;
        printf("R/r:Modify through id\nN/n:Modify through name\nE/e:exit back to main menu\n");
        printf("Enter your choice:");
        scanf(" %c",&mod_ch);
	
	switch(mod_ch)
		{
			case 'R':
			case 'r':
				{
					int mod_id;
					int id_flag=0;
					printf("Enter the id to modify:");
					scanf("%d",&mod_id);
					while(current!=NULL)
					{
						if(mod_id==current->id)
						{
							id_flag=1;
							char choice;
							printf("N/n:Modify name\nM/m:Modify marks\n");
							printf("Enter your choice:");
							scanf(" %c",&choice);
							if(choice=='N' || choice=='n')
							{
								char mod_name[30];
								printf("Enter the name to update:");
								scanf(" %29[^\n]",mod_name);
								strcpy(current->name,mod_name);
								printf("name updated succesfully.\n");
								break;
							}
							else if(choice=='M' || choice=='m')
							{
								float mod_mark;
								printf("Enter the marks to update:");
								scanf("%f",&mod_mark);
								current->marks=mod_mark;
								printf("marks updated succesfully.\n");
								break;
							}
							else
							{
								printf("invalid choice\n");
								return;
							}

						}
						else
						{
							current=current->next;
						}
					}
					if(id_flag==0)
					{
						printf("no record avalible to updata..\n");
						return;
					}
				}
				break;
			case 'N':
			case 'n':
				{
					//FIRST LOOP FRO FINDING SIMILAR IF EXIST
					int count=0;
					char modify_name[30];
					printf("Enter the name to modify:");
					scanf(" %29[^\n]",modify_name);
					printf("Searching for: %s\n", modify_name);
					while(current!=NULL)
					{
						printf("Current node: %s\n",current->name);
						if(strcmp(current->name,modify_name)==0)
						{
							count++;
							printf("Matched record: %d\t%s\t%f\n",current->id,current->name,current->marks);
						}
						current=current->next;
					}
					printf("Total matches found: %d\n",count);
					if(count==0)
					{
						printf("No name found in record.\n");
						return;
					}

					//SECOND LOOP FOR MODIFYING
					int modify_id;
					int name_flag=0;
					printf("Enter the id to modify:");
					scanf("%d",&modify_id);
					current=(ptr);
					while(current!=NULL)
					{
						if((current->id==modify_id) && (strcmp(current->name,modify_name)==0))
						{
							name_flag=1;
								char mod_choice;
								printf("N/n:Modify name\nM/m:Modify marks\n");
								printf("Enter your choice:");
								scanf(" %c",&mod_choice);
								if(mod_choice=='N' || mod_choice=='n')
								{
									char mod_n_name[30];
									printf("Enter the name to update:");
									scanf(" %29[^\n]",mod_n_name);
									strcpy(current->name,mod_n_name);
									printf("name updated succesfully.\n");
									break;
								}
								else if(mod_choice=='M' || mod_choice=='m')
								{
									float mod_n_mark;
									printf("Enter the marks to update:");
									scanf("%f",&mod_n_mark);
									current->marks=mod_n_mark;
									printf("marks updated succesfully.\n");
									break;
								}
								else
								{
									printf("invalid choice\n");
									return;
								}
						}
						else
						{
							current=current->next;
						}
			

					}
					if(name_flag==0)
					{
						printf("No data matched.\n");
						return;
					}
				}
			case 'E':
			case 'e':
				return;
			default:
				printf("invalid choice..\n");
				break;
		}
}
