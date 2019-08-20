#include <types.h>
#include <lib.h>
#include <kern/unistd.h>
#include <syscall.h>


int sys_write(int fd, userptr_t buf, size_t count){

    int i;
    char *p = (char *) buf;

    if (fd != STDOUT_FILENO){
        kprintf("sys_write supported only for stdout\n");
        return -1;
    }

    for (i = 0; i< (int)count; i++){
        putch(p[i]);
    }

    return (int)count;
}

int sys_read(int fd, userptr_t buf, size_t count){

    int i;
    char *p = (char *) buf;

    if (fd != STDIN_FILENO){
        kprintf("sys_write supported only for stdin\n");
        return -1;
    }
    for (i = 0; i< (int)count; i++){
        p[i] = getch();
        if (p[i]<0) return i;
    }

    return (int)count;
}