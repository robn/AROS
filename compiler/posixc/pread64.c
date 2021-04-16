/*
    Copyright (C) 1995-2021, The AROS Development Team. All rights reserved.

    Read from file descriptor at given offset.
*/
#include <fcntl.h>

/*****************************************************************************

    NAME */
#include <unistd.h>

        ssize_t pread64 (

/*  SYNOPSIS */
        int        filedes,
        void       *buf,
        size_t     count,
        __off64_t  offset)

/*  FUNCTION
        Read from file descriptor at given offset, preserving current seek position.

    INPUTS
        filedes - file descriptor to read from
        buf     - pointer to buffer to read into
        count   - number of bytes to read
        offset  - position in file to read from

    RESULT
        Returns the number of bytes read, or zero for end-of-file. On error,
        reutrns -1 and sets errno.

    NOTES

    EXAMPLE

    BUGS

    SEE ALSO
        lseek64(), read()

    INTERNALS

******************************************************************************/
{
    __off64_t old;
    ssize_t rv;

    if ((old = lseek64(filedes, offset, SEEK_SET)) == -1)
        return -1;

    if ((rv = read(filedes, buf, count)) == -1)
        return -1;

    if (lseek64(filedes, old, SEEK_SET) == -1)
        return -1;

    return rv;
} /* pread64 */

