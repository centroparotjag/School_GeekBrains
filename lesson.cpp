#include <iostream>
#include <cstdlib>

#include "lesson.h"
#include "lesson_second.cpp"

extern int i, j , k , l ;


int main(int argc, const char** argv) { 

//  1.Написать программу, вычисляющую выражение a * (b + (c / d)) 
//	и выводящую результат с плавающей точкой, где a, b, c, d – целочисленные константы;
	int a = 5, b = 3, c = 9, d = 13;
	double result;

	result = a * (b + ((double)c / d));

	printf("\n1.\t%1.13f\n", result);


//  2. Дано целое число, выведите на экран разницу между этим числом и числом 21. 
//	Если же заданное число больше, чем 21, необходимо вывести удвоенную разницу 
//	между этим числом и 21. При выполнении задания следует использовать тернарный оператор.
	int number = 533;
	int result_2;

	result_2 = number > 21 ? (number - 21) * 2 : 21 - number;
	printf("\n2.\t%d\n", result_2);


//  3. * Написать программу, вычисляющую выражение из первого задания, 
//	а переменные для неё инициализировать в другом файле

	result = e * (f + ((double)g / h));		// e, f, g, h in lesson.h
	printf("\n3.1\t%1.13f\n", result);

	assign_values (3, 1, 14, 13);			// assign values (i, j, k, l) in lesson_second.cpp
	result = i * (j + ((double)k / l));		// extern variables 
	printf("3.1\t%1.13f\n", result);


//  4. * Описать трёхмерный целочисленный массив, размером 3х3х3, указатель на значения 
//	внутри массива и при помощи операции разыменования вывести на экран значение 
//  центральной ячейки получившегося куба [1][1][1]


    return 0; 
}