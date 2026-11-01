#include"header.h"

void load_student(list**ptr)
{
	FILE*fp=fopen("student.data","rb");
	if(fp==NULL)
	{
		printf("no data to load..\n");
		return;
	}
	list*current=(*ptr);
	
	struct std_data record;
	while(fread(&record, sizeof(record),1,fp)==1)
	{
		list*new=malloc(sizeof(list));
		if(new==NULL)
		{
			printf("memory allocation failed..\n");
			break;
		}

		new->id=record.std_id;
		strcpy(new->name,record.std_name);
		new->marks=record.std_marks;
		new->next=NULL;
		if(*ptr==NULL)
		{		
			(*ptr)=new;
			current=new;
		}
		else
		{
			current->next=new;
			current=new;
		}
		
	}
	fclose(fp);
}
