#include <types.h>
#include <syscall.h>
#include <lib.h>
#include <proc.h>
#include <thread.h>
#include <addrspace.h>
#include <current.h>
#include <kern/unistd.h>
#include "opt-waitpid.h"

void sys__exit(int status) {
    #if OPT_WAITPID
    struct proc *p = curproc;
    p->p_status = status & 0xff; /* just lower 8 bits returned */
    proc_remthread(curthread);
    lock_acquire(p->p_lockl);
    cv_signal(p->p_cv, p->p_lockl);
    lock_release(p->p_lockl);
    #else
    struct addrspace *as = proc_getas();
    as_destroy(as);
    #endif
    thread_exit();

    panic("thread_exit returned (should not happen)\n");
    (void) status; // TODO: handle status
}