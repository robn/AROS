/*
    Copyright (C) 1995-2021, The AROS Development Team. All rights reserved.

    POSIX.1-2008 function getline().
*/

#include <stdio.h>

ssize_t getline(char ** lineptr, size_t *n, FILE * stream) {
  return getdelim(lineptr, n, '\n', stream);
}
