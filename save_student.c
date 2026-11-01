#include"header.h"

void save_student(list*ptr)
{
	if(ptr==NULL)
	{
		printf("not data to save..\n");
		return;
	}
	FILE*fs=fopen("student.data","wb");
	if(fs==NULL)
	{
		printf("unable to open the file..\n");
		return;
	}
	list*current=ptr;

	while(current!=NULL)
	{
		struct std_data record;
		record.std_id=current->id;
		strcpy(record.std_name,current->name);
		record.std_marks=current->marks;
		if(fwrite(&record,sizeof(record),1,fs)!=1)
		{
			printf("Error writing data..\n");
			fclose(fs);
			return;
		}
		current=current->next;
	}
	fclose(fs);

	printf("data succesfully added into file..\n");
}
