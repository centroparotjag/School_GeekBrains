
#include "main.h"


//    1. Задать целочисленный массив, состоящий из элементов 0 и 1.
//    Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ]. Написать функцию, заменяющую в
//    принятом массиве 0 на 1, 1 на 0 (** без примененияif-else, switch, () ? :);




//---------- Only output replacement! -------------
void Task1_replace_the_array1_output (char *arr, char size_arr1){

    printf("\tBefore replacement output: array1[%d] = { ", size_arr1);
    for (int i = 0; i < size_arr1; ++i) {
        printf("%d", arr[i]);
        printf((size_arr1-1 == i) ? " };\n" : ", ");
    }




    printf("\tAfter replacement output:  array1[%d] = { ", size_arr1);
    for (int i = 0; i < size_arr1; ++i) {
        printf("%d", (~arr[i]) & 0x01);     // вариант 1 инверсии младшего бита
//        printf("%d", arr[i] ^ 0x01);        // вариант 2 инверсии младшего бита
        printf((size_arr1-1 == i) ? " };\n" : ", ");
    }


}


//---------- Replacement array1 data! -------------
void Task1_replacement_data_in_array1 (char *arr, char size_arr1){

    for (int i = 0; i < size_arr1; ++i) {
//        arr[i] =  (~arr[i]) & 0x01;         // вариант 1 инверсии младшего бита
        arr[i] =  arr[i] ^ 0x01;          // вариант 2 инверсии младшего бита
    }

}
