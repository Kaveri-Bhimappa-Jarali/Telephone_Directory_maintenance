#include <stdio.h>
#include "FileFunction.h"

/*Function Name:EmployeeMaintenance()
Arguments:void
Return Type:void
Author:Diksha
Date:09-09-2025
*/
void EmployeeMaintenance()
{
    int Choice;
    while (1)
    {
        printf("\n\n");
        printf("%60s", "Telephone Directory Maintenance System\n");
        printf("%61s", "---------------------------------------\n");
        printf("%62s", "---------------------------------------\n\n");
        printf("%60s", "Employee Maintenance Menu\n");
        printf("%65s", "------------------------------\n");
        printf("%66s", "-------------------------------\n\n");
        printf("%50s", "1. Add Employee\n");
        printf("%60s", "2. Print EMployee Details\n");
        printf("%53s", "3. Go to Main Menu\n");
        printf("%45s", "Enter Your Choice : ");
        scanf("%d", &Choice);

        switch (Choice)
        {
        case 1:
            AddEmployees();
            break;
        case 2:
            PrintEmployees();
            break;
        case 3:
            return;
        default:
            printf("Invalid Choice Entered...!\n");
            break;
        }
    }
}
