#include <stdio.h>
#include "FileFunction.h"

/*Function Name:DepartmentMenu() )
Arguments:void
Return Type:void
Author:Anupama
Date:09-09-2025
*/
void DepartmentMenu() {
    int Choice;
    while(1) {
        printf("\n\n");
        printf("%60s","Telephone Directory Maintenance System\n");
        printf("%61s","---------------------------------------\n");
        printf("%62s","---------------------------------------\n\n");
        printf("%60s","Deparment Maintenance System\n");
        printf("%65s", "------------------------------\n");
        printf("%66s", "-------------------------------\n\n");
        printf("%52s", "1. Add Department\n");
        printf("%62s", "2. Print Department Details\n");
        printf("%53s", "3. Go to Main Menu\n");
        printf("%45s","Enter Your Choice : ");
        scanf("%d",&Choice);
        switch(Choice){
            case 1:
                AddDepartments();
                break;
            case 2:
                PrintDepartments();
                break;
            case 3:
                return;
            default:
                printf("Invalid Choice Entered...!\n");
                break;
        }
    }
}
