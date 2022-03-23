/*
** EPITECH PROJECT, 2022
** displaymodule
** File description:
** displaymodule
*/

#include <dlfcn.h>
#include <iostream>

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
    
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const  std::string &getName() const = 0;

    protected:
    private:
};

#endif /* !IDISPLAYMODULE_HPP_ */