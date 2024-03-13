#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>

void gadget() {
    asm("pop %rdi; ret");
    asm("pop %rdx; ret");
}

int main()
{
    setbuf(stdout,NULL);
    char buf[0x20];
    printf("Can you hack my shell?");
    gets(buf);
    return 0;
}


__attribute__((constructor))
void init() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    alarm(60);
}