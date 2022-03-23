/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <dlfcn.h>

extern "C"
{
    int entryPoint()
    {
    }
}

int main(int ac, char **av)
{
    char *filename = av[1];
    void (*ptr)(char *);
    void *handle = dlopen(filename, RTLD_LOCAL | RTLD_LAZY);
    ptr = (void (*)(char*)) dlsym(handle, "about");
    ptr("test");
    dlclose(handle);
    return 0;
}
