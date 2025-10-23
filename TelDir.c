#include <stdio.h>
#include <stdlib.h>
#include "FileFunction.h"
#define Admin_ID 1000

/*Function Name:main()
Arguments:void
Return Type:int
Author:Kaveri
Date:09-09-2025
*/
int main() {
    long EmployeeID;
    printf("%70s","Telephone Directory Maintenance System\n");
    printf("%71s","---------------------------------------\n");
    printf("%72s","---------------------------------------\n\n");
    printf("%50s","Login Screen\n");
    printf("%35s","Enter User ID: ");
    scanf("%ld",&EmployeeID);

    if(EmployeeID==Admin_ID) {
        int Choice;
        while(1) {
            printf("\n\n\n");
            printf("%50s","Main Menu\n");
            printf("%50s","---------\n");
            printf("%50s","---------\n\n");
            printf("%60s","1. Department Maintenance\n");
            printf("%58s","2. Employee Maintenance\n");
            printf("%69s","3. Telephone Directory Maintenance\n");
            printf("%60s","4. Telephone Enquiry Menu\n");
            printf("%42s","5. Exit\n");
            printf("%45s","Enter Your Choice : ");
            scanf("%d",&Choice);

            switch(Choice) {
                case 1: DepartmentMenu();
                        break;
                case 2: EmployeeMaintenance();
                        break;
                case 3: TelephoneMaintenance();
                        break;
                case 4: TelephoneEnquiry();
                        break;
                case 5: exit(0);
                default: printf("Invalid Choice Entered...!\n");
                         break;
            }
        }
    } else {
        printf("Login Denied\n");
    }
    return 0;
}
