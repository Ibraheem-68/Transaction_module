#include <stdio.h>
    enum TransactionType {CREDIT ,DEBIT};
    double handle_transaction(double balance, enum TransactionType type, double amount);
int main() 
{
  double current_balance;
  double amount; 
  int option;
     printf("Input current balance\n"); 
   scanf("%lf", &current_balance);
 
  printf ("Please select the transaction type\n");
  printf ("1. Credit\n");
   printf ("2. Debit\n");
   printf("3. Check Balance\n");
   printf ("Enter option:\n");
   scanf("%d", &option);
   if(option==3){
      printf("Current Balance is %f\n", current_balance);
   }
        if (option==1){
   
        printf("Enter Amount to be credited:\n");
  scanf("%lf", &amount);
   
 current_balance = handle_transaction(current_balance, CREDIT, amount);
  printf("New Balance is %f\n", current_balance);
    }
     if (option==2){
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
  
  
   if (type==CREDIT)
   { 

   if (amount > minimum_chargable_amount)
       {
       amount = amount - charge;
       printf("#50 was deducted due to charges\n");
   }
    
       balance = balance + amount;
   }
   
   
   else if (type== DEBIT) {
       if (amount > balance){
       printf("ERROR; INSUFFICIENT BALANCE\n");
     return balance;
  }
    
   if (amount > minimum_chargable_amount){
       
       amount = amount + charge;
       
   }
   
    if (amount > minimum_chargable_amount) {
   printf("#50 was deducted due to charges\n");
       }
   balance = (balance - amount);
   }
   
   return balance;
 }
