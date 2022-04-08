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
            DLLoader(const std::string &filename) {
                Dynamic_loader(filename);
            }
            ~DLLoader() {
                Dynamic_close();
            }
            void Dynamic_loader(const std::string &filename) { 
                this->Dynamic_close();
                _hdnl = dlopen(filename.c_str(), RTLD_LOCAL | RTLD_NOW);
                if (!_hdnl)
                    throw DLLoaderError(dlerror());
                load_sym();
            }
            void load_sym() {
                _sym = dlsym(_hdnl, "entryPoint");
                if (!_sym)
                    throw DLLoaderError(dlerror());
                _instance = reinterpret_cast<T *(*)()>(_sym)();;
            }
            T *getInstance() const {
                return _instance;
            }
            void Dynamic_close() {
                delete _instance;
                _instance = nullptr;
                if (_hdnl && dlclose(_hdnl) != 0)
                    throw DLLoaderError(dlerror());
            }
            void *gethandle() const { return _hdnl; }
        protected:
        private:
            void *_hdnl{nullptr};
            void *_sym{nullptr};
            T *_instance{nullptr};
    };
}

#endif /* !DLLoder_HPP_ */