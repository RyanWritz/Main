//Ryan W. Writz (c) 2020
//ECE 373 Hw 2

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FL 20

int main()
{
char FileLoc[FL]= "/dev/ece";
unsigned int read_value;
unsigned int write_value;
ssize_t bytes_read, bytes_written;
int CloseSuccess;
int FileDesc = open(FileLoc, O_RDWR);
printf("Opening file at %s (1)\n", FileLoc);



//First Read of syscall_val
if(FileDesc == -1)		//Read Failed 
{
	printf("Open Failed, check that you have read/write access to location(1)\n");
}else
{	
	printf("Open was successful(1)\n");
	bytes_read = read(FileDesc,&read_value,sizeof(unsigned int));
	//int_rv = atoi(&read_value);
	if(bytes_read == -1)
	{
		printf("Read Failed(1)\n");
	}else
	{	
		printf("Read was successful, %ld bytes read(1)\n",bytes_read);
		printf("Syscall_val = %d\n", read_value);
		printf("Enter a new value to make syscall_val.\n");
		scanf("%d",&write_value);

		bytes_written = write(FileDesc,&write_value,sizeof(unsigned int));
		if(bytes_written == -1)
		{
				printf("Write Failed\n");
		}else
		{
			printf("%d written successfully to Syscall_val\n",write_value);
			CloseSuccess = close(FileDesc);
			if(CloseSuccess == -1)
			{
				printf("Close Failed(1)\n");
			}else
			{
				printf("File closed properly(1)\n");

			}
		}	
	}
}
//Resetting read to make sure we can read new written value 		
FileDesc = open(FileLoc, O_RDWR);

if(FileDesc == -1)		//Read Failed 
{
	printf("Open Failed, check that you have read/write access to location(2)\n");
}else
{	
	printf("Opening file at %s (2)\n", FileLoc);
	printf("Open was successful (2)\n");
	bytes_read = read(FileDesc,&read_value,sizeof(unsigned int));
	if(bytes_read == -1)
	{
		printf("Read Failed(2)\n");
	}else
	{	
		printf("Read was successful, %ld bytes read (2)\n",bytes_read);
		printf("Syscall_val = %d\n", read_value);
		CloseSuccess = close(FileDesc);
		if(CloseSuccess == -1)
		{
			printf("Close Failed(2)\n");
		}else
		{
			printf("File closed properly(2)\n");

		} 
	}
}
	return 0;
}

