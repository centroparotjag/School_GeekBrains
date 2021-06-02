#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "main.h"





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    // 1.   Написать программу, которая создаст два текстовых файла,
    //      примерно по 50-100 символов в каждом (особого значения не имеет);

    const std::string word1 ("This canonical novel was based in part on Conrad’s experiences as a steamboat captain on the Congo in 1890.");
    const std::string word2 ("Come, children, let us shut up the box and the puppets, for our play is played out.");

    std::string filename1 = "file_1.txt";
    std::string filename2 = "file_2.txt";

    create_and_write_file_txt ( filename1, word1 );
    create_and_write_file_txt ( filename2, word2 );


    // 2.   Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в
    //      динамически выделенный сегмент памяти нужного размера.

    std::string word;
    std::ifstream fis( filename1 );
    fis >> word;



//    while (!fis.eof()) {

//    }





//    //fis.getLine(word);
//    char c;
//    fis.get(c);







    // 3.   * Написать программу, которая проверяет присутствует ли указанное пользователем при
    //      запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).





    //    std::string word;
    //    std::ifstream fis("hello.txt");
    //    fis >> word;
    //    //fis.getLine(word);
    //    char c;
    //    fis.get(c);



    return a.exec();
}


void create_and_write_file_txt( const std::string& name_file , const std::string& word ){
    std::ofstream fos ( name_file );     //, std::ofstream::app
    fos << word << "\n";
    fos.close();
}

