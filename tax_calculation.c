#include <stdio.h>
/*
given yearly salary and tax percentages and we have to calculate tax based on given salary and tax percentages
Less than or equal to 4,00,000 – Tax will be 1%
Greater than 4,00,000 and Less than 10,00,000 – Tax will be 1% for 4,00,000 amount and 15% on remaining amount
Greater than 10, 00, 000 – Tax will be 1% for 4, 00, 000, 15% for next 6, 00, 000 and 25% on remaining amount.
*/

int main()
{
	long int salary;
	float tax;
	printf("Enter yearly salary: ");
	scanf("%ld",&salary);
	tax =0;
	if(salary<=400000)
		tax = salary*1/100;
	else if(salary>400000 && salary<=1000000){
		tax = 400000*1/100;
		tax = tax + (salary-400000)*15/100;
	}
	else{
		tax = 400000*1/100;
		tax = tax + (600000)*15/100;
		tax = tax + (salary-1000000)*25/100;
	}
	printf("Salary: %ld\n",salary);
	printf("Tax: %0.2f\n",tax);
	return 0;
}
