#include <QCoreApplication>
#include <iostream>
#include "main.h"

using namespace std;

void(*T1)(char*, char);
void(*T2)(char*);
int (*T3)(char*, char);
void(*T4)(char*, char, char);
void(*T5)(int size, ...);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


//    1. Задать целочисленный массив, состоящий из элементов 0 и 1.
//    Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в
//    принятом массиве 0 на 1, 1 на 0 (** без примененияif-else, switch, () ? :);
        printf("\n1.\n");

        T1 = Task1_replacement_data_in_array1;

        constexpr char size_arr1 = 10;
        char array1[size_arr1] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

        //---------- Replacement array1 data! -------------
        printf("\tBefore replacement array1: array1[%d] = { ", size_arr1);
        for (int i = 0; i < size_arr1; ++i) {
            printf("%d", array1[i]);
            printf((size_arr1-1 == i) ? " };\n" : ", ");
        }

        T1 (array1, size_arr1);  // here the replacement of data in the array1

        printf("\tAfter replacement array1:  array1[%d] = { ", size_arr1);
        for (int i = 0; i < size_arr1; ++i) {
            printf("%d", array1[i]);
            printf((size_arr1-1 == i) ? " };\n" : ", ");
        }



 //    2. Задать пустой целочисленный массив размером 8. Написать функцию,
 //    которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;
        printf("\n2.\n");

        T2 = Task2_filling_the_array1;

        char array2[8] = { 0 };

        T2 (array2);

        printf("\tFilling the array2:   array2[%d] = { ", 8);
        for (int i = 0; i < 8; ++i) {
            printf("%d", array2[i]);
            printf((8-1 == i) ? " };\n" : ", ");
        }



//     3. * Написать функцию, в которую передается не пустой одномерный целочисленный массив,
//     функция должна вернуть истину если в массиве есть место, в котором сумма левой и правой
//     части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
//     checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.
        printf("\n3.\n");

        T3 = Task3_checkBalance;

        constexpr char size_arr3 = 5;
        char array3 [size_arr3] = {1, 1, 1, 2, 1};        // true
//        char array3 [size_arr3] = {2, 1, 1, 2, 1};        // false

        printf("\tCheckBalance: ");
        printf( T3(array3, size_arr3)  ? "true\n" : "false\n");




//     4.* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным),
//     при этом функция должна циклически сместить все элементы массива на n позиций.
        printf("\n4.\n");

        T4 = Task4_shift_array;

        char n = -4;
        constexpr char size_arr4 = 11;
        char array4 [size_arr4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11};


        printf("\tBefore shifting array4[%d] = { ", size_arr4);
        for (int i = 0; i < size_arr4; ++i) {
            printf("%d", array4[i]);
            printf((size_arr4-1 == i) ? " };\n" : ", ");
        }

        printf("\tShift = %d\n", n);

        T4 (array4, size_arr4,  n);

        printf("\tAfter shifting  array4[%d] = { ", size_arr4);
        for (int i = 0; i < size_arr4; ++i) {
            printf("%d", array4[i]);
            printf((size_arr4-1 == i) ? " };\n" : ", ");
        }


//    5.** Написать функцию из первого задания так, чтобы она работала с аргументом переменной длины.
        printf("\n5.\n");

        T5 = Task5_invert_va_data;

        int size = 13;
        char ar[13] = {1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1};

        T5 (size, ar[0], ar[1], ar[2], ar[3], ar[4], ar[5], ar[6], ar[7], ar[8], ar[9], ar[10], ar[11], ar[12]);




//      6.** Написать все функции в отдельных файлах в одном пространстве имён,
//      вызвать их на исполнение в основном файле программы используя указатели на функции.

//      ok



    return a.exec();
}





//    2. Задать пустой целочисленный массив размером 8. Написать функцию,
//    которая с помощью цикла заполнит его значениями 1 4 7 10 13 16 19 22;

    void Task2_filling_the_array1 (char *arr){

        for (int i = 0, k=7; i < 8; ++i) {
            arr[k] = (k*3)+1;
            k--;
        }
    }



//     3. * Написать функцию, в которую передается не пустой одномерный целочисленный массив,
//     функция должна вернуть истину если в массиве есть место, в котором сумма левой и правой
//     части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
//     checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.


    int Task3_checkBalance (char *array, char size_arr){

        for (int i = 0; i < size_arr; ++i) {
            int  left_sum = 0;
            int  right_sum = 0;


            //---- counting the left side ----
            for (int l = 0; l < i+1; ++l){
                left_sum += array[l];
            }

            //---- counting the right side ----
            for (int r = size_arr-1; r > i; --r){
                right_sum += array[r];
            }


            // ---------- Check ----------
            if (left_sum == right_sum){
                return true;
            }

        }

        return false;
    }


//     4.* Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или отрицательным),
//     при этом функция должна циклически сместить все элементы массива на n позиций.

    void Task4_shift_array (char *array, char size_arr,  char n){

        //  shifting + Right
        for (int i = 0; i < n; ++i) {
            char tmp=array[size_arr-1];
            for (int i = size_arr; i > 0; --i) {
                array[i] = array[i-1];
            }
            array[0] = tmp;
        }


        //  shifting - Left
        for (int i = 0; i > n; --i) {
            char tmp=array[0];
            for (int i = 0; i < size_arr; ++i) {
                array[i] = array[i+1];
            }
            array[size_arr-1] = tmp;
        }

    }


//    5.** Написать функцию из первого задания так, чтобы она работала с аргументом переменной длины.
    void Task5_invert_va_data (int size, ...) {

        int arr[size];

        va_list lst;
        va_start(lst, size);

        for (int i = 0; i < size; i++) {
            arr[i] = va_arg(lst, int);
        }

        va_end(lst);

        printf("\tBefore replacement output: array[%d] = { ", size);
        for (int i = 0; i < size; ++i) {
            printf("%d", arr[i]);
            printf((size-1 == i) ? " };\n" : ", ");
        }

        printf("\tAfter replacement output:  array[%d] = { ", size);
        for (int i = 0; i < size; ++i) {
            printf("%d", (~arr[i]) & 0x01);     // вариант 1 инверсии младшего бита
    //        printf("%d", arr[i] ^ 0x01);        // вариант 2 инверсии младшего бита
            printf((size-1 == i) ? " };\n" : ", ");
        }
     }



