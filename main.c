#include <stdio.h>

int main() 
{
  double current_balance, credit, debit, charge, available_balance, new_balance;
  
  charge = 50;
  
   printf("Input current balance\n"); 
   scanf("%lf", &current_balance);
 
  
   
   printf("Input amount to be credited\n");
   scanf("%lf", &credit);
   if (credit > 10000){
       
       credit = credit - charge;
       
   }
    
   printf("Input amount to be debited\n");
   scanf("%lf", &debit);
   if (debit > 10000){
       
       debit = debit + charge;
       
   }
   
   available_balance = current_balance + credit;
   if (debit > available_balance){
       printf("ERROR; INSUFFICIENT BALANCE\n");
     return 0;
  }
    
      new_balance = (current_balance - debit + credit);
   printf("Transaction Successful New Balance is %f\n", new_balance);
   
   if (credit > 10000) {
   printf("#50 was deducted due to charges (amount above #10,000)\n");
       }
       
       if (debit > 10000) {
   printf("#50 was deducted due to charges (amount above #10,000)\n");
       }
   
   
    return 0;
    
    }