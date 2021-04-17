/*
    Copyright (C) 2021, The AROS Development Team. All rights reserved.

    POSIX.1-2008 function pause().
*/

#include <aros/debug.h>
#include <errno.h>

/*****************************************************************************

    NAME */
#include <unistd.h>

        int pause (

/*  SYNOPSIS */
        void)

/*  FUNCTION

    INPUTS

    RESULT

    NOTES
        Not implemented.

    EXAMPLE

    BUGS

    SEE ALSO

    INTERNALS

******************************************************************************/
{
    /* TODO: Implement pause() */
    AROS_FUNCTION_NOT_IMPLEMENTED("posixc");
    errno = ENOSYS;

    return -1;
} /* pause() */
