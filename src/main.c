#include <stdio.h>
int main(int arc, char* argv[])
{
    if(argv[1]!=NULL)
    {
        printf("%s", argv[1]);
    }
    else{
        printf("No File was provided...");
    }
    return 0;
}