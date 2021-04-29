/*
    Copyright (C) 1995-2021, The AROS Development Team. All rights reserved.

    Write to file descriptor at given offset.
*/
#include <fcntl.h>

/*****************************************************************************

    NAME */
#include <unistd.h>

        ssize_t __posixc_pwrite (

/*  SYNOPSIS */
        int           filedes,
        const void   *buf,
        size_t        count,
        off_t         offset)

/*  FUNCTION
        Write to file descriptor at given offset, preserving current seek position.

    INPUTS
        filedes - file descriptor to write to
        buf     - pointer to buffer to write bytes from
        count   - number of bytes to write
        offset  - position in file to write to

    RESULT
        Returns the number of bytes written. On error, returns -1 and sets errno.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
        lseek(), write()

    INTERNALS

******************************************************************************/
{
    off_t old;
    ssize_t rv;

    if ((old = lseek(filedes, offset, SEEK_SET)) == -1)
        return -1;

    if ((rv = write(filedes, buf, count)) == -1)
        return -1;

    if (lseek(filedes, old, SEEK_SET) == -1)
        return -1;

    return rv;
} /* __posixc_pwrite */

