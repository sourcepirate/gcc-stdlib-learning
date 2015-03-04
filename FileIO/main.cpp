#include <iostream>
#include "Files.h"
using namespace std;

int main()
{
    File *f=new File("newtext.txt");
    cout<<(char*)f->reads(20);
    f->writes("sathya");
    return 0;
}

