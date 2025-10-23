#include <stdio.h>
#include "FileFunction.h"
/*Function Name:TelephoneMaintenance()
Arguments:void
Return Type:void
Author:Kaveri
Date:09-09-2025
*/
void TelephoneMaintenance() {
    int Choice;
    while(1) {
        printf("\n\n");
        printf("%60s","Telephone Directory Maintenance System\n");
        printf("%61s","---------------------------------------\n");
        printf("%62s","---------------------------------------\n\n");
        printf("%70s","Telephone Directory mainenance Menu\n");
        printf("%71s","---------------------------------------\n");
        printf("%72s","---------------------------------------\n\n");
        printf("%58s", "1. Add Telephone Number\n");
        printf("%53s", "2. Go to Main Menu\n");
        printf("%45s","Enter Your Choice : ");
        scanf("%d",&Choice);
        switch(Choice){
            case 1:
                AddTelNumber();
                break;
            case 2:
                return;
            default:
                printf("Invalid Choice Entered...!\n");
                break;
        }
    }
}
