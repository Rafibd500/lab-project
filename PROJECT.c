#include<stdio.h>
#include<string.h>
int balance = 0;
char dob[100], phNo[100], address[100], email[100], pass[100], log_email[100], log_pass[100], nm[100];
void deposit_money(){
    int ammount;
    printf("\n--- Deposit Money ---\n");
    printf("Enter amount to deposit: ");
    scanf("%d", &ammount);
    if(ammount>0){
        balance+=ammount;
        printf("\nAmount deposited successfully! New Balance: %d\n", balance);
    }
    else{
        printf("\nInvalid Ammount\n");
    }
    printf("------------------------\n");
}

void check_balance(){
    printf("\n--- Current Balance ---\n");
    printf("\nAccount Holder Name: %s\n", nm);
    printf("Account Holder Email: %s\n", email);
    printf("Current Balance: %d\n", balance);
    printf("------------------------\n");
}

void withdraw_money(){
    printf("\n--- Withdraw Money ---\n");
    int ammount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &ammount);
    if(ammount>0){
        if(balance>=ammount){
        balance-=ammount;
        printf("\nAmount withdrawn successfully! Remaining Balance: %d\n", balance);
        }
        else{
            printf("\nInsufficient Balance. Current Balance: %d\n", balance);
        }
    }
    else{
        printf("\nInvalid Ammount\n");
    }
    printf("------------------------\n");

}

void change_pass(){
    printf("\n--- Change Password ---\n");
    char new_pass[100], current_pass[100];
    printf("Enter current password: ");
    scanf("%s", current_pass);
    if(strcmp(current_pass, pass) == 0){
        printf("Enter new password: ");
        scanf("%s", new_pass);
        strcpy(pass, new_pass);
        printf("\nPassword changed successfully!\n");
    }
    else{
        printf("\nIncorrect Password. Please Try Again.\n");
    }
    printf("------------------------\n");
}

void accDetails(){
    printf("\n--- Account Details ---\n");
    printf("Name: %s\n", nm);
    printf("Date of Birth: %s\n", dob);
    printf("Address %s\n", address);
    printf("Phone Number: %s\n", phNo);
    printf("Email Address: %s\n", email);
    printf("------------------------\n");
}


void info_update(char str[100], int n){
    if(n == 1) printf("Enter New Name: ");
    else if(n == 2) printf("Enter New Date of Birth: ");
    else if(n == 3) printf("Enter New Address: ");
    else if(n == 4) printf("Enter New Phone Number: ");
    else if(n == 5) printf("Enter New Email Address: ");
    char str2[100];
    getchar();
    scanf("%[^\n]%*c", str2);
    strcpy(str, str2);
    printf("Info Update Successfully.\n");
}
void update_profile(){
    int choice2;
    do{

        printf("\n--- Update Your Information ---\n");
        printf("1. Name\n");
        printf("2. Date of Birth\n");
        printf("3. Address: \n");
        printf("4. Phone Number\n");
        printf("5. Email Address\n");
        printf("6. Select If Info Update is Done\n");
        printf("Enter your choice: ");
                scanf("%d", &choice2);

    switch (choice2) {
            case 1:
                info_update(nm, 1);
                break;
            case 2:
                info_update(dob, 2);
                break;
            case 3:
                info_update(address, 3);
                break;
            case 4:
                info_update(phNo, 4);
                break;
            case 5:
                info_update(email, 5);
                break;
            case 6:
                printf("Your Information Update Is Done.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
            }
        }while(choice2 != 6);
}
int main(){
    int choice1, choice;

    //Registration
    printf("1. Registraion Account\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);
    getchar();
    if(choice1 == 1){
        printf("Enter your name: ");
        scanf("%[^\n]%*c", nm);
        printf("Enter your Date of Birth: ");
        getchar();
        scanf("%[^\n]%*c", dob);
        printf("Enter your Address: ");
        scanf("%s", address);
        printf("Enter your Phone Number: ");
        scanf("%s", phNo);
        printf("Enter your email: ");
        scanf("%s", email);
        printf("Enter your Password: ");
        scanf("%s", pass);
    }
    else{
        printf("Invalid choice! Please try again.\n");
        return 0;
    }

    //Login
    printf("1. Login Acoount\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);
    if(choice1 == 1){
        printf("Enter your email: ");
        scanf("%s", log_email);
        printf("Enter your Password: ");
        scanf("%s", log_pass);
        printf("\n");
    }
    else{
        printf("Invalid choice! Please try again.\n");
        return 0;
    }
    if(strcmp(email, log_email)==0 && strcmp(pass, log_pass) == 0){
        do{
            printf("\nBanking Management Menu:\n");
            printf("1. Deposit Money\n");
            printf("2. Withdraw Money\n");
            printf("3. Check Balance\n");
            printf("4. Account Details\n");
            printf("5. Update Profile\n");
            printf("6. Change Password\n");
            printf("7. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                deposit_money();
                break;
            case 2:
                withdraw_money();
                break;
            case 3:
                check_balance();
                break;
            case 4:
                accDetails();
                break;
            case 5:
                update_profile();
                break;
            case 6:
                change_pass();
                break;
            case 7:
                printf("Exiting... Thank you for using our banking system!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
            }
        }while(choice != 7);
    }
    else{
        printf("Incorrect Password or Email. Please Try Again.\n");
    }
    return 0;
}


