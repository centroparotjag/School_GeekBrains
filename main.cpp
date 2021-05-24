#include <QCoreApplication>
#include <iostream>

#include "main.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


//    1. Задать целочисленный массив, состоящий из элементов 0 и 1.
//    Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в
//    принятом массиве 0 на 1, 1 на 0 (** без примененияif-else, switch, () ? :);
        printf("\n1.\n");

        void(*T1_1)(char*, char);
        void(*T1_2)(char*, char);
        T1_1 = Task1_replace_the_array1_output;
        T1_2 = Task1_replacement_data_in_array1;


        char size_arr1 = 10;
        char array1[10] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

        //---------- Only output replacement! -------------
        T1_1 (array1, 10);


        //---------- Replacement array1 data! -------------
        printf("\tBefore replacement array1: array1[%d] = { ", size_arr1);
        for (int i = 0; i < size_arr1; ++i) {
            printf("%d", array1[i]);
            printf((size_arr1-1 == i) ? " };\n" : ", ");
        }


        T1_2 (array1, 10);  // here the replacement of data in the array1

        printf("\tAfter replacement array1:  array1[%d] = { ", size_arr1);
        for (int i = 0; i < size_arr1; ++i) {
            printf("%d", array1[i]);
            printf((size_arr1-1 == i) ? " };\n" : ", ");
        }



 //    2. Задать пустой целочисленный массив размером 8. Написать функцию,
 //    которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
        printf("\n2.\n");

        void(*T2)(char*);
        T2 = Task2_filling_the_array1;

        char Empty_arr[8] = { 0 };

        T2 (Empty_arr);

        printf("\tFilling the array1:   array1[%d] = { ", 8);
        for (int i = 0; i < 8; ++i) {
            printf("%d", Empty_arr[i]);
            printf((8-1 == i) ? " };\n" : ", ");
        }


//     3. * Написать функцию, в которую передается не пустой одномерный целочисленный массив,
//     функция должна вернуть истину если в массиве есть место, в котором сумма левой и правой
//     части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
//     checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.
        printf("\n3.\n");

        int(*T3)(char*, char);
        T3 = checkBalance;


//        char size_arr2 = 10;
//        char array2 [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 36 };


        char size_arr2 = 5;
//        char array2 [5] = {1, 1, 1, 2, 1};
        char array2 [5] = {2, 1, 1, 2, 1};

        printf("\tCheckBalance: ");
        printf( T3(array2, size_arr2)  ? "true\n" : "false\n");













    return a.exec();
}
