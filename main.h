#ifndef MAIN_H
#define MAIN_H

#include <iostream>

void create_and_write_file_txt( const std::string& name_file , const std::string& buffer );
int get_size_text (const std::string& name_file);
void file_buffering (const std::string& name_file, char* buffer);
void Glue_text (const std::string& filename1, const std::string& filename2, const std::string& glue_filename3);
bool Word_Search (const std::string& search, const std::string& filename);

#endif // MAIN_H
