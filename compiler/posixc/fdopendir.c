/*
    Copyright (C) 1995-2021, The AROS Development Team. All rights reserved.

    POSIX.1-2008 function fdopendir().
*/

#include <aros/debug.h>

#include <proto/dos.h>

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>

#include "__fdesc.h"
#include "__dirdesc.h"

/*****************************************************************************

    NAME */
#include <sys/types.h>
#include <dirent.h>

        DIR *fdopendir (

/*  SYNOPSIS */
        int filedes
        )

/*  FUNCTION
        function associates a directory stream with an existing file descriptor.

    INPUTS
        filedes - The descriptor the stream has to be associated with

    RESULT
        NULL on error or the new stream associated with the descriptor.

    NOTES
        After a successful call to fdopendir, filedes is used internally by the
        implementation, and should not otherwise be used by the application.

    EXAMPLE

    BUGS

    SEE ALSO
         opendir(), dirfd()

    INTERNALS

******************************************************************************/
{
    fdesc *desc;
    DIR *dir;

    desc = __getfdesc(filedes);
    if (!desc) {
        errno = EBADF;
        return NULL;
    }

    if (!(desc->fcb->privflags & _FCB_ISDIR)) {
        errno = ENOTDIR;
        return NULL;
    }

    dir = calloc(1, sizeof(DIR));
    if (!dir) {
        errno = ENOMEM;
        return NULL;
    }

    dir->priv = AllocDosObject(DOS_FIB, NULL);
    if (!dir->priv) {
        errno = ENOMEM;
        free(dir);
        return NULL;
    }

    if (!Examine(desc->fcb->handle, dir->priv)) {
        errno = __stdc_ioerr2errno(IoErr());
        FreeDosObject(DOS_FIB, dir->priv);
        free(dir);
        return NULL;
    }

    dir->fd = filedes;
    dir->pos = 0;
    dir->ent.d_name[NAME_MAX] = '\0';

    return dir;
}

