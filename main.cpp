#include <QCoreApplication>
#include <stdio.h>
//#include <fstream>




// 1.
#define VALUE_CHECK(num, arg)   ( (((num) >= 0) && ((num) < (arg)))  ? (true) : (false) )

// 2.
#define ARRAY_VALUE(array, lines, columns)    ( *(*((array)+(lines))+(columns)) )
//*(*(array+lines)+columns)



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
    int lines;
    int columns;
    int** array = new int*[2];              // lines 2
    for (lines = 0; lines < 2; lines++){
        array[lines] = new int [3];         // columns 3
    }

    //--------- Filling array -----------
    int filling = 0;
    for (lines = 0; lines < 2; ++lines) {
        for (columns = 0; columns < 3; ++columns) {
            array [lines][columns] = filling++;
        }
    }



    //------ Print all cell array ---------
    for (lines = 0; lines < 2; ++lines) {
        for (columns = 0; columns < 3; ++columns) {
            printf("array[%d][%d]=%d\n", lines, columns, ARRAY_VALUE(array, lines, columns));

        }
    }


    // freeing the memory of a dynamic two-dimensional array
    for (lines = 0; lines < 2; lines++){
        delete [] array[lines];             // del lines 2
    }





// 3.   * Описать макрокоманду, возвращающую количество элементов локального
//      массива, принимающую на вход ссылку на массив и его тип
    printf("\n3-Task.\n");





    return a.exec();
}











