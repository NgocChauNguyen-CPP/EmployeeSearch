#include <string.h>
#include "employee.h"
//NOTE: 5 functions have been defined below
//ptr--pointer that points to table to be searched
//tableSize--size of the table
//targetPtr--pointer that points to value that will be searched for in table
//functionPtr--points to a comparison function below 
//and will perform the associated check

//What does setting a function to static do?
//functionPtr is the address of the function just use the name
//()(The second set of parenthese is the arguemnts of the function call)

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void * targetPtr,
			int(*functionPtr)(const void *, PtrToConstEmployee))
{
	PtrToConstEmployee endPtr = ptr + tableSize;
	for(; ptr < endPtr; ++ptr)
	{
		if((*functionPtr)(targetPtr, ptr) == 0)
		{
			return (PtrToEmployee) ptr;
		}
	}
	return NULL;
}

//The functionPtr will point to one of these comparison functions to perform a check
static int compareEmployeeNumber(const void * targetPtr, PtrToConstEmployee tableValuePtr)
{
	return * (long *) targetPtr != tableValuePtr->number;
	//const void * targetPtr ==>typecast as long pointer then dereference
}

static int compareEmployeeName(const void * targetPtr, PtrToConstEmployee tableValuePtr)
{
	return strcmp((char *)targetPtr, tableValuePtr->name);
	//const void * targetPtr ==> typecast as char pointer then pass into strcmp()
}

static int compareEmployeePhoneNumber(const void * targetPtr, PtrToConstEmployee tableValuePtr)
{
	return strcmp((char * )targetPtr, tableValuePtr->phone);
}

static int compareEmployeeSalary(const void * targetPtr, PtrToConstEmployee tableValuePtr)
{
	return * (double*) targetPtr != tableValuePtr->salary;
}

//These are called wrappers. These functions are what you will use in your main.
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber)
{
	return searchEmployeeTable(ptr, tableSize, &targetNumber, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName)
{
	return searchEmployeeTable(ptr, tableSize, targetName, compareEmployeeName);
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone)
{
	return searchEmployeeTable(ptr, tableSize, targetPhone, compareEmployeePhoneNumber);
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary)
{
	return searchEmployeeTable(ptr, tableSize, &targetSalary, compareEmployeeSalary);
}