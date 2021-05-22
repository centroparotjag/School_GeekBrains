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
	unsigned int number = 0;

	//------- Input of number ------
	printf("\tEnter a number to check (natural prime number check): ");
	std::cin >> number;

	int Check_Status = 1;

	// brute force %
	for (unsigned int i = 2; i < number; ++i){		
		if ( number % i == 0 ) {				// Not natural check
			printf("\tDivisible by = %d\n", i);		// test DEBUG	
			Check_Status = 0;		
			break;
		}
	}


	if ( Check_Status && number > 1){
		printf("\t%d - Yes: This number is natural prime\n", number);		
	}
	else {
		printf("\t%d - No: This is not a natural prime number.\n", number);
	}



//	3.Написать программу, выводящую на экран “истину”, если две целочисленные константы, 
//	объявленные в её начале либо равны десяти сами по себе, либо их сумма равна десяти.
	printf("\n3.");

	const int first_const  = 8;
	const int second_const = 2;

	if ( (first_const + second_const) == 10 || first_const == 10 || second_const == 10 ){
		printf("\ttrue\n");
	}



//	4.*Написать программу, которая заполняет диагональные элементы квадратной матрицы единицами. 
//	Размеры матрицы нужно задать константными числами, матрицу нужно инициализировать нулями.
	printf("\n4.\n\n");

	const char size_matrix = 22;

    for (int y = 0; y < size_matrix; y++) {
        for (int x = 0; x < size_matrix; x++) {
        	if ( y == x || (x+y+1) == size_matrix ){
        		printf("1 ");
        	}
        	else{
        		printf("0 ");
        	}
        }
        printf("\n");
    }



//	5.*Написать программу, которая определяет является ли год високосным. 
//	Каждый 4-й год является високосным, кроме каждого 100-го, при этом каждый 400-й – високосный. 
//	Для проверки работы вывести результаты работы программы в консоль


//  Вопрос к заказчику: 0 - високосный год? Если нет - то добавить ко всем условиям*: if( (*) && Year != 0 )

	printf("\n5.");

	int Year = 0;

	//------- Input year ------
	printf("\tEnter year: ");
	std::cin >> Year;

	if ( ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0)){
		printf("\t%d - leap year\n", Year);
	}
	else {
		printf("\t%d - not a leap year\n", Year);
	}




    return 0; 
}