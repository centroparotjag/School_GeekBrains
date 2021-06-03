#include <QCoreApplication>
#include <fstream>
#include "main.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


// 1.   Написать программу, которая создаст два текстовых файла,
//      примерно по 50-100 символов в каждом (особого значения не имеет);

    const std::string word1 ("This canonical novel was based in part on Conrads experiences as a steamboat captain on the Congo in 1890.");
    const std::string word2 ("Come, children, let us shut up the box and the puppets, for our play is played out.");

    std::string filename1 = "file_1.txt";
    std::string filename2 = "file_2.txt";
    std::string glue_filename3 = "glued_text.txt";

    create_and_write_file_txt ( filename1, word1 );
    create_and_write_file_txt ( filename2, word2 );



// 2.   Написать функцию, «склеивающую» эти файлы, предварительно буферизуя их содержимое в
//      динамически выделенный сегмент памяти нужного размера.

    Glue_text (filename1, filename2, glue_filename3);

    //----- output text from file to console ------
    std::string word;
    std::ifstream fis_glue( glue_filename3 );     // open file 3
    getline (fis_glue, word);

    std::cout << word << std::endl << std::endl; // TEST



// 3.   * Написать программу, которая проверяет присутствует ли указанное пользователем при
//      запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).

    bool status;
    const std::string search ("90.Co");     // search word

    status = Word_Search (search, glue_filename3);

    printf("Status search word - %d\n", status);


    return a.exec();
}




//----------------------------------------------------------------------------------------
void create_and_write_file_txt( const std::string& name_file , const std::string& buffer ){
    std::ofstream fos ( name_file );     //, std::ofstream::app
    fos << buffer << "\n";
    fos.close();
}



//----------------------------------------------------------------------------------------
int get_size_text (const std::string& name_file){
    std::fstream fis( name_file );     // open file
    fis.seekg(0, std::ios::end);        //
    int size = fis.tellg();
    fis.close();
    return size-2;
}



//----------------------------------------------------------------------------------------
void file_buffering (const std::string& name_file, char* buffer){
    int sizefile = get_size_text (name_file);

    std::ifstream fis( name_file );     // open file
    fis.getline(buffer, sizefile+1);
}



//----------------------------------------------------------------------------------------
void Glue_text (const std::string& filename1, const std::string& filename2, const std::string& glue_filename3){
    //------- Get size files -------------
    int size1 = get_size_text (filename1);
    int size2 = get_size_text (filename2);
    int glue_size = size1 + size2;

    //------- Array declaration ----------
    char* buffer1   = new char[size1];
    char* buffer2   = new char[size2];
    char* bufferALL = new char[glue_size];

    //----- Byffering file in array ------
    file_buffering (filename1, buffer1);
    file_buffering (filename2, buffer2);

    //-------- Glue text------------------
    for (int i = 0; i < glue_size; ++i) {
        bufferALL[i] = (i < size1) ? buffer1[i] : buffer2[i-size1];
    }

    create_and_write_file_txt ( glue_filename3, bufferALL );

    delete [] buffer1;
    delete [] buffer2;
    delete [] bufferALL;
}



//----------------------------------------------------------------------------------------
bool Word_Search (const std::string& search, const std::string& filename){
    bool status = true;

//----------- bad algiritm ----------------
//    std::fstream file_search( filename );
//    std::string tmp;
//    bool status = false;
//    while (file_search >> tmp){
//        if(search != tmp){
//            status = false;
//        }
//    }

    //------------ Get size ----------------
    int size_search_world = search.length();
    int size_file = get_size_text (filename);

    //-------- Array declaration -----------
    char* buffer_search_world   = new char[size_search_world];
    char* buffer_file   = new char[size_file];

    //----- Byffering file/word in array ---
    for (int i = 0; i < size_search_world; ++i) {
        buffer_search_world [i] = search[i];
    }

    file_buffering (filename, buffer_file);

    //--------------- Here search ------------------------
    for (int i = 0; i < size_file; ++i) {
        if( buffer_file[i] == buffer_search_world[0] ){
            for (int k = 0; k < size_search_world; ++k) {
                if(buffer_file[i+k] != buffer_search_world[k]){
                    status = false;
                    break;
                }
            }
        }
    }
    //-------------------------------------------------------

    delete [] buffer_search_world;
    delete [] buffer_file;

    return status;
}








