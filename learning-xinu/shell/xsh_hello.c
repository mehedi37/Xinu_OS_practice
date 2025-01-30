/* xsh_hello.c - xsh_hello */

#include <xinu.h>
#include <stdio.h>

int xsh_hello(){
    printf("Hello Mehedi !\n");
    kprintf("process ID: %d\n", getpid());
    // %x for hexadecimal
    return 0;
}