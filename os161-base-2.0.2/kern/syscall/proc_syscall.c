#include <types.h>
#include <syscall.h>
#include <lib.h>
#include <proc.h>
#include <thread.h>
#include <addrspace.h>
#include <kern/unistd.h>

void sys__exit(int status) {
    struct addrspace *as = proc_getas();
    as_destroy(as);
    thread_exit();

    panic("thread_exit returned (should not happen)\n");
    (void) status; // TODO: handle status
}