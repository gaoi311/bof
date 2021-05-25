#include <stdio.h>

int  func ( char  *userdata , short  datalength )
{
    char  *buff;

    if( datalength  !=  strlen(userdata))
    {
        printf("error in func\n");
        return -1;
    }

    datalength = datalength * 2;
    buff = malloc( datalength );
    strncpy( buff, userdata, datalength);

    printf("userdata: %s\n", userdata);
    printf("buff    : %s\n", buff);

    return 0;
}
    
int main(int argc, char *argv[])
{
        if(argc>1)
        {
            func( argv[1], strlen(argv[1]) );
        }
        else
        {
            printf("error in main\n");
        }
}
