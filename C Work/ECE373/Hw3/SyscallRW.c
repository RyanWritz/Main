//Ryan W. Writz (c) 2020
//ECE 373 Hw 3

//Procedure for use of code:
//In terminal type the following:
//make CProg(will show file operations happening with printf)
//make cleanc (cleans up the program object)


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

//Variables to control LEDs in Ledmon 
uint32_t LedOn = 0x0000000E;
uint32_t LedOff = 0x0000000F;
uint32_t LedMask = 0xFFFFFFF0;
uint32_t LedStart = 0x8302;

char FileLoc[FL]= "/dev/ece";
uint32_t read_value;
uint32_t write_value, origin_write;
ssize_t bytes_read, bytes_written;
int CloseSuccess;
int FileDesc = open(FileLoc, O_RDWR);
printf("Opening file at %s (1)\n", FileLoc);
//sleep(3); //Use if having issues with init finishing before probe

//First Read of syscall_val
if(FileDesc == -1)		//Read Failed 
{
	printf("Open Failed, check that you have read/write access to location(1)\n");
}else
{	
	printf("Open was successful(1)\n");
	bytes_read = read(FileDesc,&read_value,sizeof(uint32_t));
	//int_rv = atoi(&read_value);
	if(bytes_read == -1)
	{
		printf("Read Failed(1)\n");
	}else
	{	
		printf("Read was successful, %ld bytes read(1)\n",bytes_read);
		//printf("Starting LEDCTL value should be 0x%x\n",LedStart);
		printf("LEDCTL current value = %x\n", read_value);
		//printf("Enter value to enter for LED.\n");	//Only include when userspace needed
		//scanf("%x",&write_value);		
		origin_write = read_value;
		//write_value = (read_value & LedMask) | LedOn;
		write_value = (read_value & LedMask);
		printf("Write_value (read_value & LedMask): %d\n", write_value);
		write_value = write_value | LedOn;
		printf("Write_value (Prior write_value | LedOn): %d\n", write_value);
		bytes_written = write(FileDesc,&write_value,sizeof(uint32_t));
		if(bytes_written == -1)
		{
				printf("Write Failed\n");
		}else
		{
			printf("Arithmetic for LED op here: ");
			printf("(%x & %x)",origin_write,LedMask);
			printf(" | %x\n",LedOn);
			printf("%x written successfully to LED\n",write_value);
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
	bytes_read = read(FileDesc,&read_value,sizeof(uint32_t));
	if(bytes_read == -1)
	{
		printf("Read Failed(2)\n");
	}else
	{	
		printf("Read was successful, %ld bytes read (2)\n",bytes_read);
		printf("Current LEDCTL value is = %x\n", read_value);
		printf("Sleeping for 2 seconds now\n");
		sleep(2);						//Sleeps for 2 seconds 
		write_value = (write_value | LedMask) | LedOff;		//value to turn off LED0
		CloseSuccess = close(FileDesc);
		if(CloseSuccess == -1)
		{
			printf("Close Failed(2)\n");
		}else
		{
			printf("File closed properly(2)\n");
			printf("Please re-bind the device to the e1000e driver once done, while root\n");	

		} 
	}
}
	return 0;
}

