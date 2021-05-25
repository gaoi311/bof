    #include <stdio.h>
    int main(void){
            unsigned int num = 0xffffffff, l = 0x7fffffff;;
            printf("num is %d bits long\n", sizeof(num) * 8);
            printf("num = 0x%x\n", num);
            printf("num + 1 = 0x%x\n\n", num + 1);
            printf("l = %d (0x%x)\n", l, l);
            printf("l + 1 = %d (0x%x)\n", l + 1 , l + 1);
            return 0;
    }

