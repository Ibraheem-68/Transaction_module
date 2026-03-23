#include <stdio.h>
void charges() { printf("#50 was deducted due to charges\n"); }
enum TransactionType { CREDIT, DEBIT };
double handle_transaction(double balance, enum TransactionType type, double amount);

struct user {
    char name[50];
    char surname[50];
    char nin[15];
    char phone_number[11];
    char password[15];
};
int main()
{
    struct user userInfo;
    printf("Enter Name\n");
    scanf("%s", userInfo.name);

    printf("\nEnter Surname\n");
    scanf("%s", userInfo.surname);

    printf("\nEnter NIN\n");
    scanf("%s", userInfo.nin);

    printf("\nEnter Phone Number\n");
    scanf("%s", userInfo.phone_number);

    printf("\nEnter Password\n");
    scanf("%s", userInfo.password);

    printf("\nRegistration Successfull!!!\n");
    printf("Registration details:\n");
    printf("Name: %s\n", userInfo.name);
    printf("Surname: %s\n", userInfo.surname);
    printf("NIN: %s\n", userInfo.nin);
    printf("Phone Number: %s\n", userInfo.phone_number);
    printf("Password: %s\n", userInfo.password);
    double current_balance;
    double amount;
    int option;
    printf("\nInput current balance\n");
    scanf("%lf", &current_balance);

    printf("Please select the transaction type\n");
    printf("1. Credit\n");
    printf("2. Debit\n");
    printf("3. Check Balance\n");
    printf("Enter option:\n");
    scanf("%d", &option);
    if(option == 3) {
        printf("Current Balance is %f\n", current_balance);
    }
    if(option == 1) {

        printf("Enter Amount to be credited:\n");
        scanf("%lf", &amount);

        current_balance = handle_transaction(current_balance, CREDIT, amount);
        printf("New Balance is %f\n", current_balance);
    }
    if(option == 2) {
        printf("Enter Amount to be debited:\n");
        scanf("%lf", &amount);
        current_balance = handle_transaction(current_balance, DEBIT, amount);

        printf("New Balance is %f\n", current_balance);
    }
}

double handle_transaction(double balance, enum TransactionType type, double amount)
{

    const double charge = 50;
    const double minimum_chargable_amount = 10000;

    switch(type) {
    case CREDIT:
        if(amount > minimum_chargable_amount) {
            amount = amount - charge;
            charges();
        }

        balance = (balance + amount);

    case DEBIT:
        if(amount > balance) {
            printf("ERROR; INSUFFICIENT BALANCE\n");
            return balance;
        }
        if(amount > minimum_chargable_amount) {
            charges();
            amount = amount + charge;
        }

        balance = balance - amount;
        break;

    default:
        printf("ERROR, INVALID TRANSACTION TYPE!!!");
    }

    return balance;
}
