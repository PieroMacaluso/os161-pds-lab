    //hello.h file
    
    #ifndef _hello_h
    #define _hello_h
    #include <types.h>
    #include <lib.h>

    #include "opt-hello.h"
    #if OPT_HELLO
    void hello(void);
    #endif
     
    #endif