/*
    Copyright (C) 2003-2018, The AROS Development Team. All rights reserved.

    POSIX.1-2008 function pthread_attr_setguardsize().
*/

#include "pthread_intern.h"
#include "debug.h"

int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize)
{
    AROS_FUNCTION_NOT_IMPLEMENTED("pthread");
    errno = ENOSYS;
    return -1;
}
