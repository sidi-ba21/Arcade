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

namespace Arcade {

    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;
            virtual const  std::string &getName() = 0;

        /*    virtual void init() = 0;
            virtual void stop() = 0;
        protected:
        private:*/
    };

}

#endif /* !IDISPLAYMODULE_HPP_ */