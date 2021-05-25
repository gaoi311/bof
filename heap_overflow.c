#include <stdlib.h>

int main (int argc, char *argv[])
{
    char *buf, *buf1;
    buf = malloc (16); /* ��������16�ֽ��ڴ� */
    buf1 = malloc (16);
    
    if (argc > 1)
        memcpy (buf, argv[1], strlen (argv[1])); /* ����ᷢ����� */
    
    printf ("%#p [ buf  ] (%.2d) : %s \n", buf, strlen(buf), buf);
    printf ("%#p [ buf1 ] (%.2d) : %s \n", buf1, strlen(buf1), buf1);
    printf ("From buf to buf1 : %d\n\n", buf1 - buf);
    
    printf ("Before free buf\n");
    free (buf); /* �ͷ�buf */
    
    printf ("Before free buf1\n");
    free (buf1); /* �ͷ�buf1 */
    
    return 0;
} /* End of main */
