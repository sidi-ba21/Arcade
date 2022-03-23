/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <dlfcn.h>
#include <iostream>

extern "C"
{
    int entryPoint(char *filename)
    {
        void (*ptr)(char const *);
        void *handle = dlopen("./lib.so", RTLD_LOCAL | RTLD_LAZY);
        ptr = (void (*)(char const *)) dlsym(handle, "about");
        printf("ptr = %x\n", ptr);
        ptr("test");
        dlclose(handle);
    }
}

int main(int ac, char **av)
{
    entryPoint(av[1]);
    return 0;
}
