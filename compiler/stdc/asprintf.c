/*
    Copyright (C) 1995-2021, The AROS Development Team. All rights reserved.

    GNU function asprintf().
*/

/*****************************************************************************

    NAME */
#include <stdio.h>

        int asprintf (

/*  SYNOPSIS */
        char       **strp,
        const char  *format,
        ...)

/*  FUNCTION
        Formats a list of arguments. Allocates memory for the output and puts a
        pointer to it in strp. The caller must free that memory with free().

    INPUTS
        strp   - Pointer to a string pointer where the output buffer will be
                 allocated.

        format - A printf() format string.
        ...    - Arguments for the format string

    RESULT
        The number of characters written.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
        printf(), vsprintf()

    INTERNALS

******************************************************************************/
{
    int rc;
    va_list args;

    va_start (args, format);
    rc = vasprintf(strp, format, args);
    va_end (args);

    return rc;
} /* asprintf */

