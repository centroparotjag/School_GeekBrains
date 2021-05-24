#include "main.h"



//     3. * Написать функцию, в которую передается не пустой одномерный целочисленный массив,
//     функция должна вернуть истину если в массиве есть место, в котором сумма левой и правой
//     части массива равны. Примеры: checkBalance([1, 1, 1, || 2, 1]) → true, checkBalance ([2, 1, 1, 2, 1]) → false,
//     checkBalance ([10, || 1, 2, 3, 4]) → true. Абстрактная граница показана символами ||, эти символы в массив не входят.


int checkBalance (char *array, char size_arr){

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
