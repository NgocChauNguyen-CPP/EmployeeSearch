#include <stdio.h>
#include <stddef.h>
typedef struct 
{
	/* data */
	long number;
	char * name;
	char * phone;
	double salary;
} Employee, *PtrToEmployee;


typedef const Employee * PtrToConstEmployee;

