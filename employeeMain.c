#include <string.h>
#include <stdlib.h>
#include "Employee.h"

int main(void)
{
	PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
	PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
	PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
	PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

	extern Employee EmployeeTable[];
	extern const int EmployeeTableEntries;

	PtrToEmployee matchPtr;

	//Find ID. Example not found
	matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
	if(matchPtr != NULL)
	{
		printf("Employee ID 1045 is in the record %d\n", matchPtr - EmployeeTable);
	}
	else
	{
		printf("Employee ID is not found in the record\n");
	}
	//Find name. Example found
	matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
	if(matchPtr != NULL)
	{
		printf("Employee Tony Bobcat is in the record %d\n", matchPtr - EmployeeTable);
	}
	else
	{
		printf("Employee Tony Bobcat is not found in the record\n");
	}
	//Find Phone Number. Example found
	matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");
	if(matchPtr != NULL)
	{
		printf("Employee phone 909-555-2134 is in the record %d\n", matchPtr - EmployeeTable);
	}
	else
	{
		printf("Employee phone is not found in the record\n");
	}

	//Find Salary. Example found

	matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);
	if(matchPtr != NULL)
	{
		printf("Employee salary 8.78 is in the record %d\n", matchPtr - EmployeeTable);
	}
	else
	{
		printf("Employee salary is not found in the record\n");
	}

	return EXIT_SUCCESS;
}