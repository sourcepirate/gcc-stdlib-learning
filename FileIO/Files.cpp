#include "Files.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <error.h>
#include <string.h>

using namespace std;

File::File(char* name){
    this->name=name;
    int fd=open(name,O_RDWR);
    try{
    if(fd==-1)
        fd=creat(name,0777);
        if(fd==-1)
            throw "error while opening file";
        this->fdesc=fd;
    }
    catch(const char* msg){
        cout<<msg<<"\n";
    }
}


void* File::reads(ssize_t len)
{
    char buf[238];
    ssize_t ret;
    //cout<<this->fdesc<<"\n";
    ret=read(this->fdesc,buf,len);
    try{
    if(ret==-1)
    {
        throw "unable to read file";
    }
    }
    catch(const char* msg){
        cout<<msg<<"\n";
    }
    return buf;
}

ssize_t File::writes(char* word){
  ssize_t ret;
  ret=write(this->fdesc,word,strlen(word));
  try{
      if(ret==-1)
          throw "unable to write to the file";
  }
  catch(const char* msg){
      cout<<msg<<"\n";
  }
  return ret;
}


