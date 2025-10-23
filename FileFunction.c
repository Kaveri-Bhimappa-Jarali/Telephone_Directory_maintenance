#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileFunction.h"

/*Function Name:fnGenerateEmployeeId()
Arguments:void
Return Type:long
Author:Diksha
Date:09-09-2025
*/

long fnGenerateEmployeeId()
{
    static long EmployeeId = 1001;
    return EmployeeId++;
}

/*Function Name:fnGenerateDepartmentCode()
Arguments:void
Return Type:long
Author:Diksha
Date:09-09-2025
*/
long fnGenerateDepartmentCode()
{
    static long DepartmentCode = 1001;
    return DepartmentCode++;
}

/*Function Name:fnGenerateTelephone(long deptCode)
Arguments:long deptCode
Return Type:long
Author:Anupama
Date:09-09-2025
*/
long fnGenerateTelephone(long deptCode)
{
    return deptCode * 1000 + 1;
}

/*Function Name:isEmployeeIdExist(long EmpID)
Arguments:long EmpID
Return Type:int
Author:Diksha
Date:09-09-2025
*/
int isEmployeeIdExist(long EmpID)
{
    struct Employee emp;
    FILE *ef = fopen("emp.txt", "r");
    if (ef == NULL)
        return 0;

    while (fscanf(ef, "%ld %14s %4s %ld %14s", &emp.EmpId, emp.EmpName, emp.Location,
                  &emp.dept.DeptCode, emp.dept.DeptName) == 5)
    {
        if (emp.EmpId == EmpID)
        {
            fclose(ef);
            return 1;
        }
    }
    fclose(ef);
    return 0;
}

/*Function Name:isDeptCodeExist(long DeptCode)
Arguments:long DeptCode
Return Type:int
Author:Anupama
Date:09-09-2025
*/
int isDeptCodeExist(long DeptCode)
{
    struct Department dept;
    FILE *df = fopen("Dept.txt", "r");
    if (df == NULL)
        return 0;

    while (fscanf(df, "%ld %14s", &dept.DeptCode, dept.DeptName) == 2)
    {
        if (dept.DeptCode == DeptCode)
        {
            fclose(df);
            return 1;
        }
    }
    fclose(df);
    return 0;
}

/*Function Name:isNameUnique(char *Name)
Arguments:char *Name
Return Type:int
Author:Kaveri
Date:09-09-2025
*/
int isNameUnique(char *Name)
{
    struct Department dept;
    FILE *df = fopen("Dept.txt", "r");
    if (df == NULL)
        return 0;

    while (fscanf(df, "%ld %14s", &dept.DeptCode, dept.DeptName) == 2)
    {
        if (strcmp(dept.DeptName, Name) == 0)
        {
            fclose(df);
            return 1;
        }
    }
    fclose(df);
    return 0;
}

/*Function Name:AddDepartments()
Arguments:void
Return Type:void
Author:Anupama
Date:09-09-2025
*/
// Add Department
void AddDepartments()
{
    struct Department Dept;
    printf("%60s", "Telephone Directory Maintenance System\n");
    printf("%61s", "---------------------------------------\n");
    printf("%62s", "---------------------------------------\n\n");
    printf("%60s", "Add a Department\n");
    printf("%65s", "------------------------------\n");
    printf("%66s", "-------------------------------\n\n");
    FILE *df = fopen("Dept.txt", "a"); 

    if (df == NULL)
    {
        perror("Error opening dept.txt");
        return;
    }
    Dept.DeptCode = fnGenerateDepartmentCode();

    if (isDeptCodeExist(Dept.DeptCode))
    {
        printf("\n\n%60s", "Department Code already exists! Cannot add duplicate.\n");
        fclose(df);
        return;
    }

    printf("\n\n%35s", "Enter Department Name: ");
    if (scanf("%14s", Dept.DeptName) != 1 || strlen(Dept.DeptName) == 0)
    {
        printf("%50s", "\nInvalid Department Name!\n");
        fclose(df);
        return;
    }

    if (isNameUnique(Dept.DeptName))
    {
        printf("%50s", "\nDepartment already exists!\n");
        fclose(df);
        return;
    }

    fprintf(df, "%ld %s\n", Dept.DeptCode, Dept.DeptName); 
    printf("\n\n%60s", "Department added successfully!\n");
    fclose(df);
}

/*Function Name:PrintDepartments()
Arguments:void
Return Type:void
Author:Anupama
Date:09-09-2025
*/
// Print Departments
void PrintDepartments()
{
    struct Department Dept;
    FILE *df = fopen("Dept.txt", "r");
    if (df == NULL)
    {
        printf("%45s", "The file could not be opened.\n");
        return;
    }

    printf("\n%-15s %-15s\n", "DeptCode", "DeptName");
    printf("-----------------------------\n");

    while (fscanf(df, "%ld %14s", &Dept.DeptCode, Dept.DeptName) == 2)
    {
        printf("%-15ld %-15s\n", Dept.DeptCode, Dept.DeptName);
    }
    fclose(df);
}

/*Function Name:AddEmployees()
Arguments:void
Return Type:void
Author:kaveri
Date:09-09-2025
*/
// Add Employee
void AddEmployees()
{
    struct Employee emp;
    long deptCode;
    int found = 0;
    printf("%60s", "Telephone Directory Maintenance System\n");
    printf("%61s", "---------------------------------------\n");
    printf("%62s", "---------------------------------------\n\n");
    printf("%50s", "Add an Employee\n");
    printf("%65s", "------------------------------\n");
    printf("%66s", "-------------------------------\n\n");

    FILE *ef = fopen("emp.txt", "a");
    FILE *df = fopen("Dept.txt", "r");
    if (ef == NULL || df == NULL)
    {
        printf("File is not Opened..!");
        return;
    }

    emp.EmpId = fnGenerateEmployeeId();

    if (isEmployeeIdExist(emp.EmpId))
    {
        printf("%50s", "Employee ID already exists! Cannot add duplicate.\n");
        fclose(ef);
        fclose(df);
        return;
    }

    printf("\n\n%35s", "Enter Employee Name: ");
    scanf(" %25s", emp.EmpName);

    printf("%27s", "Employee ID :");
    printf("%ld\n", emp.EmpId);

    printf("%37s", "Enter Department Code: ");
    scanf("%ld", &deptCode);

    while (fscanf(df, "%ld %14s", &emp.dept.DeptCode, emp.dept.DeptName) == 2)
    {
        if (emp.dept.DeptCode == deptCode)
        {
            printf("%34s", "Department Name is: ");
            printf("%s\n", emp.dept.DeptName);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("%50s", "Invalid Department Code.\n");
        fclose(ef);
        fclose(df);
        return;
    }

    printf("%30s", "Enter Location: ");
    scanf(" %6s", emp.Location);
    emp.TelNumber = 0;
    fprintf(ef, "%ld %s %s %ld %s %ld\n", emp.EmpId, emp.EmpName, emp.Location,
            emp.dept.DeptCode, emp.dept.DeptName, emp.TelNumber);

    printf("\n\n%60s", "Employee added successfully!\n");

    fclose(ef);
    fclose(df);
}

/*Function Name: PrintEmployees()
Arguments:void
Return Type:void
Author:kaveri
Date:09-09-2025
*/
// Print Employees
void PrintEmployees()
{
    struct Employee emp;
    FILE *ef = fopen("emp.txt", "r");
    if (ef == NULL)
    {
        printf("%50s", "The file could not be opened.\n");
        return;
    }

    printf("\n%-12s %-15s %-15s %-15s %-15s\n", "Emp_ID", "Emp_Name", "Location", "Dept_Code", "Dept_Name");
    printf("---------------------------------------------------------------------\n");

    while (fscanf(ef, "%ld %s %s %ld %s %ld", &emp.EmpId, emp.EmpName, emp.Location,
                  &emp.dept.DeptCode, emp.dept.DeptName,&emp.TelNumber) == 6)
    {
        printf("%-12ld %-15s %-15s %-15ld %-15s\n", emp.EmpId, emp.EmpName, emp.Location,
               emp.dept.DeptCode, emp.dept.DeptName);
    }
    fclose(ef);
}

/*Function Name:AddTelNumber()
Arguments:void
Return Type:void
Author:Kaveri
Date:09-09-2025
*/
void AddTelNumber()
{
    struct Employee emp;
    long empID;
    int found = 0;

    FILE *tf = fopen("emp.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (tf == NULL || temp == NULL)
    {
        perror("Error opening file");
        if (tf)
            fclose(tf);
        if (temp)
            fclose(temp);
        return;
    }

    printf("\n\n%35s", "Enter Employee ID : ");
    scanf("%ld", &empID);
    while (fscanf(tf, "%ld %s %s %ld %s %ld",
                  &emp.EmpId, emp.EmpName, emp.Location,
                  &emp.dept.DeptCode, emp.dept.DeptName, &emp.TelNumber) == 6)
    {
        if (emp.EmpId == empID)
        {
            printf("%25s", "Location :");
            printf("%s\n", emp.Location);
            printf("%33s", "Department Code : ");
            printf("%ld\n", emp.dept.DeptCode);
            printf("%43s", "Telephone Number Allocated :");
            emp.TelNumber = fnGenerateTelephone(emp.dept.DeptCode);
            printf("%ld\n", emp.TelNumber);
            found = 1;
        }

        fprintf(temp, "%ld %s %s %ld %s %ld\n",
                emp.EmpId, emp.EmpName, emp.Location,
                emp.dept.DeptCode, emp.dept.DeptName, emp.TelNumber);
    }

    fclose(tf);
    fclose(temp);

    if (!found)
    {
        printf("Employee ID not found.\n");
        remove("temp.txt");
    }
    else
    {
        remove("emp.txt");
        rename("temp.txt", "emp.txt");
    }
}

/*Function Name:fnEnquiryByName()
Arguments:void
Return Type:void
Author:Diksha
Date:09-09-2025
*/
void fnEnquiryByName()
{
    printf("%60s", "Telephone Directory Maintenance System\n");
    printf("%61s", "---------------------------------------\n");
    printf("%62s", "---------------------------------------\n\n");
    printf("%60s", "Telephone Number Enquiry by Name\n");
    printf("%60s", "----------------------------------\n");
    printf("%62s", "-----------------------------------\n\n");
    struct Employee emp;
    FILE *ef = fopen("emp.txt","r");
    char empName[25];
    printf("\n\n%35s", "Enter Employee Name : ");
    scanf("%s", &empName);
    while (fscanf(ef, "%ld %s %s %ld %s %ld",
                  &emp.EmpId, emp.EmpName, emp.Location,
                  &emp.dept.DeptCode, emp.dept.DeptName, &emp.TelNumber) == 6)
    {
        if (strcmp(emp.EmpName, empName) == 0)
        {
            printf("%-15s %-15s %-15s%-15s\n", "Name", "Location", "DeptName", "TelNumber");
            printf("---------------------------------------------------------------------\n");
            printf("%-15s %-15s %-15s %-15ld", emp.EmpName, emp.Location, emp.dept.DeptName, emp.TelNumber);
        }
    }
    fclose(ef);
}

/*Function Name:fnTelNumberEnqiry()
Arguments:void
Return Type:void
Author:Diksha
Date:09-09-2025
*/
void fnTelNumberEnqiry()
{
    printf("%60s", "Telephone Directory Maintenance System\n");
    printf("%61s", "---------------------------------------\n");
    printf("%62s", "---------------------------------------\n\n");
    printf("%55s", "Telephone Number Enquiry\n");
    printf("%55s", "-------------------------\n");
    printf("%56s", "--------------------------\n\n");

    struct Employee emp;
    FILE *ef = fopen("emp.txt", "r");
    long telNumber;
    int found = 0;

    if (ef == NULL) {
        printf("Error: emp.txt not found.\n");
        return;
    }

    printf("\n\n%35s", "Enter Telephone Number : ");
    scanf("%ld", &telNumber); 

    while (fscanf(ef, "%ld %s %s %ld %s %ld",
                  &emp.EmpId, emp.EmpName, emp.Location,
                  &emp.dept.DeptCode, emp.dept.DeptName, &emp.TelNumber) == 6)
    {
        if (emp.TelNumber == telNumber)
        {
            printf("%25s%s\n", "Employee Name : ", emp.EmpName);
            printf("%20s%s\n", "Location :", emp.Location);
            printf("%28s%s\n", "Department Name : ", emp.dept.DeptName);
            found = 1;
            break; 
        }
    }

    if (!found) {
        printf("\nNo employee found with Telephone Number: %ld\n", telNumber);
    }

    fclose(ef);
}
