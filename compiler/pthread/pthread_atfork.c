/*
    Copyright (C) 2003-2018, The AROS Development Team. All rights reserved.

    POSIX.1-2008 function pthread_atfork().
*/

#include "pthread_intern.h"
#include "debug.h"

int pthread_atfork(void (*prepare)(void), void (*parent)(void), void (*child)(void))
{
    AROS_FUNCTION_NOT_IMPLEMENTED("pthread");
    errno = ENOSYS;
    return -1;
}
