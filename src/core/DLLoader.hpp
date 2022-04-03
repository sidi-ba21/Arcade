/*
** EPITECH PROJECT, 2022
** DLLoader
** File description:
** DLLoader
*/

#include <iostream>
#include <dlfcn.h>
#include "Error.hpp"

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

namespace Arcade {

    template <typename T>
    class DLLoader {
        public:
            DLLoader() = default;
            DLLoader(std::string &filename) {
                Dynamic_loader(filename);
            }
            ~DLLoader() {dlclose(_hdnl); }

            void Dynamic_loader(std::string &filename) { 
                _hdnl = dlopen(filename.c_str(), RTLD_LOCAL | RTLD_LAZY);
                if (!_hdnl)
                    throw DLLoaderError("bad argument dlopen");
                load_sym();
            }
            void load_sym() {
                _sym = dlsym(_hdnl, "entryPoint");
                if (!_sym)
                    throw DLLoaderError("bad dlsym");
                *(void **) (&_instance) = _sym;
            }
            T *getInstance() const {
                return _instance;
            }
            void Dynamic_close() {
                if (dlclose(_hdnl) != 0)
                    throw DLLoaderError("bad argument dlclose");  
            }
            void *gethandle() const { return _hdnl; }
        protected:
        private:
            void *_hdnl;
            void *_sym;
            T *_instance;
    };
}

#endif /* !DLLoder_HPP_ */