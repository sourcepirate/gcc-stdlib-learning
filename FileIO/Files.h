#ifndef FILES_H
#define FILES_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <error.h>
extern int errno;
class File
{
private:
    int fdesc;
    char* name;
public:
    /*Constructor for the file*/
    File(char* name);
    /*used to read the data from the specified file*/
    void* reads(ssize_t len);
    /*used to write the data from the file and returns the number of data written*/
    ssize_t writes(char* word);

    /*truncate*/
    int truncate();
};


#endif // FILES_H
