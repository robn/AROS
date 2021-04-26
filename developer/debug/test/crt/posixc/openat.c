/*
    Copyright (C) 1995-2014, The AROS Development Team. All rights reserved.
*/

#define _POSIX_C_SOURCE 200809L

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include "test.h"

int main()
{
    int fd, dfd, ret;
    struct stat st;
    DIR *dir;

    /* absolute */
    fd = openat(AT_FDCWD, "T:abs", O_RDWR | O_CREAT);
    TEST((fd >= 0));
    close(fd);
    unlink("T:abs");

    /* relative to current dir */
    chdir("T:");
    fd = openat(AT_FDCWD, "relcwd", O_RDWR | O_CREAT);
    TEST((fd >= 0));
    close(fd);
    ret = stat("T:relcwd", &st);
    TEST((ret == 0));
    unlink("T:relcwd");

    /* relative to dir fd */
    chdir("SYS:");
    dir = opendir("T:");
    dfd = dirfd(dir);
    TEST((dfd >= 0));
    fd = openat(dfd, "reldir", O_RDWR | O_CREAT);
    TEST((fd >= 0));
    close(fd);
    ret = stat("T:reldir", &st);
    TEST((ret == 0));
    unlink("T:reldir");

    cleanup();

    return OK;
}

void cleanup()
{
}
