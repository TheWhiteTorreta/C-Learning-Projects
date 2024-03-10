#include <stdio.h>
#include <conio.h>

float TaxAmnt, Balance, Salary, TaxRate=0.20;
char ans;
 float Tax_Cal(float tax)
 { tax=(Salary*TaxRate)+Balance;
 return(tax);
 }

 void main()
 {
 clrscr();
 do{
     printf(“Enter salary: ”);
     scanf(“%f”,&Salary);
     printf(“\nEnter balance: ”);
     scanf(“%f”,&balance);
     printf(“\nTax to be collected: %.2f”,Tax_Cal(TaxAmnt));
     printf(“Another Transaction?[y/n]:”);
     ans=getche();
     }while(ans!=’n’);
 getch();
 } 