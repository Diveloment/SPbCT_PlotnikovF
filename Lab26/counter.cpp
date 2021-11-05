#include <dirent.h>
#include <iostream>

int main()
{
   int file_count = 0;
int dir_count = 0;
int total = 0;

DIR * dirp;
struct dirent * entry;

dirp = opendir("/home/SHPK/Projects/Lab26"); 
while ((entry = readdir(dirp)) != NULL) {
    total++;
    if (entry->d_type == DT_REG) {
         file_count++;
    }
}
dir_count = file_count;
std::cout << "Count: " << dir_count << std::endl;
closedir(dirp); 
return 0;
}
