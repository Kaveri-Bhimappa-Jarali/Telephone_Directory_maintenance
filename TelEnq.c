#include <stdio.h>
#include "FileFunction.h"
/*Function Name:TelephoneEnquiry()
Arguments:void
Return Type:void
Author:Kaveri
Date:09-09-2025
*/
void TelephoneEnquiry() {
    int Choice;
    while(1) {
        printf("\n\n");
        printf("%60s","Telephone Directory Maintenance System\n");
        printf("%61s","---------------------------------------\n");
        printf("%62s","---------------------------------------\n\n");
        printf("%60s","Telephone Enquiry Menu\n");
        printf("%61s","------------------------\n");
        printf("%62s","-------------------------\n\n");
        printf("%53s", "1.Enquiry an Employee Name\n");
        printf("%56s", "2. Enquiry on Telephone Number\n");
        printf("%45s", "3. Go to Main Menu\n");
        printf("%44s","Enter Your Choice : ");
        scanf("%d",&Choice);
        switch(Choice){
            case 1:
                fnEnquiryByName();
                break;
            case 2:
                fnTelNumberEnqiry();
                break;
            case 3:
                return;
            default:
                printf("Invalid Choice Entered...!\n");
                break;
        }
    }
}
