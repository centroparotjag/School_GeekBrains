#include <iostream>
#include <cstdlib>


int main(int argc, const char** argv) { 

//	1 .Написать программу, проверяющую что сумма двух чисел лежит в пределах 
//	от 10 до 20 (включительно), если да – вывести true, в противном случае – false;
	printf("\n1.");

	int first_num  = 0;
	int second_num = 0;

	//------- Input of two numbers ------
	printf("\tInput first number : ");
	std::cin >> first_num;
	printf("\tInput second number: ");
	std::cin >> second_num;


	if ( (first_num + second_num) >= 10 && (first_num + second_num) <= 20 ){
		printf("\ttrue\n");
	}
	else {
		printf("\tfalse\n");
	}


//	2.Написать программу, проверяющую, является ли некоторое число - натуральным простым. 
//	Простое число - это число, которое делится без остатка только на единицу и себя само.
	printf("\n2.");
	unsigned long long number = 0;

	//------- Input of number ------
	printf("\tEnter a number to check (natural number check): ");
	std::cin >> number;


	int Check_Status = 1;

	// brute force %
	for (unsigned long long i = 2; i < number; ++i){		
		if ( number % i == 0 ) {					// Not natural check
			printf("\tDivisible by = %d\n", i);	// test DEBUG	
			Check_Status = 0;		
			break;
		}
	}


	if ( Check_Status && number > 1){
		printf("\tYes\n");		
	}
	else {
		printf("\tNo\n");
	}






    return 0; 
}