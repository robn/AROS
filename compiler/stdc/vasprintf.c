/*
    Copyright (C) 1995-2021, The AROS Development Team. All rights reserved.

    GNU function vasprintf().
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

struct _vasprintf_state {
    char  *buf;
    size_t alloc;
    size_t pos;
};

static int _vasprintf_uc (char c, struct _vasprintf_state *state)
{
    if (state->pos == state->alloc) {
        state->buf = realloc(state->buf, state->alloc+128);
        state->alloc += 128;
    }

    state->buf[state->pos++] = c;

    return 1;
}

/*****************************************************************************

    NAME */
#include <stdio.h>

        int vasprintf (

/*  SYNOPSIS */
        char       **strp,
        const char  *format,
        va_list      args)

/*  FUNCTION
        Formats a list of arguments. Allocates memory for the output and puts a
        pointer to it in strp. The caller must free that memory with free().

    INPUTS
        strp   - Pointer to a string pointer where the output buffer will be
                 allocated.

        format - A printf() format string.
        args   - A list of arguments for the format string.

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
    struct _vasprintf_state state;

    state.buf   = NULL;
    state.alloc = 0;
    state.pos   = 0;

    rc = __vcformat (&state, (void *)_vasprintf_uc, format, args);
    if (rc < 0) {
        free(state.buf);
        return rc;
    }

    _vasprintf_uc('\0', &state);

    *strp = state.buf;

    return rc;
} /* vasprintf */
