#ifndef FILEFUNCTION_H
#define FILEFUNCTION_H

struct Department {
    char DeptName[15];
    long DeptCode;
};

struct Employee{
    char EmpName[15];
    long EmpId;
    char Location[5];
    long TelNumber;
    struct Department dept;
};

// Function declarations
void DepartmentMenu();
void EmployeeMaintenance();
void TelephoneMaintenance();
void TelephoneEnquiry();

long fnGenerateEmployeeId();
long fnGenerateDepartmentCode();
long fnGenerateTelephone(long deptCode);
int isEmployeeIdExist(long EmpID);
int isDeptCodeExist(long DeptCode);
int isNameUnique(char *Name);
void AddDepartments();
void PrintDepartments();
void AddEmployees();
void PrintEmployees();
void AddTelNumber();
void fnEnquiryByName();
void fnTelNumberEnqiry();
#endif
