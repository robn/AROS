/*
 * SPDX-FileCopyrightText: 2021 Arnav Yash Chandra <arnavyash2004@outlook.com>
 * SPDX-License-Identifier: 0BSD
 *
 * POSIX.1-2008 function getdelim().
 */

#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>

#define INITIAL_BUFFSZ 128

ssize_t getdelim(char **lineptr, size_t *n, int delimiter, FILE *stream) {
  if (lineptr == NULL || stream == NULL || n == NULL) {
    errno = EINVAL;
    return -1;
  }

  int c = getc(stream);

  if (c == EOF) {
    return -1;
  }

  if (*lineptr == NULL) {
    *lineptr = malloc(INITIAL_BUFFSZ);
    if (*lineptr == NULL) {
      return -1;
    }
    *n = INITIAL_BUFFSZ;
  }

  size_t pos = 0;
  while (c != EOF) {
    if (pos + 1 >= *n) {
      size_t new_size = *n + (*n >> 2);
      if (new_size < INITIAL_BUFFSZ) {
        new_size = INITIAL_BUFFSZ;
      }
      char *new_ptr = realloc(*lineptr, new_size);
      if (new_ptr == NULL) {
        return -1;
      }
      *n = new_size;
      *lineptr = new_ptr;
    }

    ((unsigned char *)(*lineptr))[pos++] = c;
    if (c == delimiter) {
      break;
    }

    c = getc(stream);
  }

  (*lineptr)[pos] = '\0';
  return pos;
}
