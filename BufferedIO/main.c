#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *stream = fopen("hello.txt", "w+");
    char string[100];
    fputs("hey there my write", stream);
    fclose(stream);
    stream = fopen("hello.txt", "r+");
    fgets(string, 100, stream);
    printf("%s\n", string);
    fclose(stream);
    return 0;
}
