#include <QCoreApplication>
#include <stdio.h>
//#include <iostream>


// 1.
#define VALUE_CHECK(num, arg)   ( (((num) >= 0) && ((num) < (arg)))  ? (true) : (false) )

// 2.
#define ARRAY_VALUE(array, row, columns)    ( *(*((array)+(row))+(columns)) )

// 3.
#define ARRAY_SIZE(arrayref, type_arr)    ( sizeof(arrayref)/sizeof(*(type_arr)) )




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


// 1.   Описать макрокоманду, проверяющую, входит ли переданное ей число в
//      диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно)

//    int num = atoi(argv[1]);
//    int arg = atoi(argv[2]);

    int num = 5;
    int arg = 5;

    printf("1-Task.\nVALUE_CHECK(%d, %d) = %d\n", num , arg, VALUE_CHECK(num, arg) );



// 2.   Описать макрокоманду, получающую доступ к элементу двумерного массива (
//      организованного динамически) посредством разыменования указателей

    printf("\n2-Task.\n");

    // declaration of a dynamic two-dimensional array
    int ** array = new int*[2];
    array[0] = new int[3] {0, 1, 2};
    array[1] = new int[3] {3, 4, 5};



    //------ Print all cell array ---------
    int row;
    int col;
    for (row = 0; row < 2; ++row) {
        for (col = 0; col < 3; ++col) {
            printf("array[%d][%d]=%d\n", row, col, ARRAY_VALUE(array, row, col));

        }
    }


    // freeing the memory of a dynamic two-dimensional array
    delete [] array[0];
    delete [] array[1];
    delete [] array;



// 3.   * Описать макрокоманду, возвращающую количество элементов локального
//      массива, принимающую на вход ссылку на массив и его тип
    printf("\n3-Task.\n");

    int array2[11] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    const int sise_arr2 = sizeof(array2)/sizeof(*array2);
    int (&arrayref)[sise_arr2] = array2;


    printf("Size - %d.\n", (int)ARRAY_SIZE(arrayref, arrayref));




    return a.exec();
}











