#include <stdio.h>

int main() 
{
  double current_balance, credit, debit, available_balance, new_balance;
  
  const double charge = 50;
  const double minimum_chargable_amount = 10000;
  int option;
   printf("Input current balance\n"); 
   scanf("%lf", &current_balance);
 
  printf ("Please select the transaction type\n");
  printf ("1. Credit\n");
   printf ("2. Debit\n");
   printf("3. Check Balance\n");
   printf ("Enter option:\n");
   scanf("%d", &option);
   if (option==1)
   { 
   printf("Input amount to be credited\n");
   scanf("%lf", &credit);
   if (credit > minimum_chargable_amount){
       
       credit = credit - charge;
   }
    
   new_balance = (current_balance + credit);
   printf("Transaction Successful New Balance is %f\n", new_balance);
   
   if (credit > minimum_chargable_amount) {
   printf("#50 was deducted due to charges\n");
       }
   return 0;
   }
   
   
   if (option==2) {
   
   printf("Input amount to be debited\n");
   scanf("%lf", &debit);
   
   available_balance = current_balance + credit;
   if (debit > available_balance){
       printf("ERROR; INSUFFICIENT BALANCE\n");
     return 0;
  }
  
   if (debit > minimum_chargable_amount){
       
       debit = debit + charge;
       
   }
   new_balance = (current_balance - debit);
   printf("Transaction Successful New Balance is %f\n", new_balance);
    if (debit > minimum_chargable_amount) {
   printf("#50 was deducted due to charges\n");
       }
   return 0;
   }
   
    if(option==3)
      printf("Current Balance is %f\n", current_balance);
   
  
       
      
   
   
    return 0;
    
    }