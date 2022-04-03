/*
** EPITECH PROJECT, 2022
** Error.hpp
** File description:
** Error.hpp
*/

#include <string>
#include <exception>

#ifndef ERROR_HPP_
#define ERROR_HPP_

class Error : public std::exception
{
    public:
        Error(std::string const &message, std::string const &component = "Unknown")
        : _message(message), _component(component) {}

        virtual const std::string &getComponent() const { return _component; }

        char const *what() const noexcept { return _message.c_str(); }

    private:
        std::string _message;
        std::string _component;
};

class FileWrongError : public Error
{
    public:
        FileWrongError(std::string const &message, std::string const &component = "Unknown")
        : Error(message, component) {};
};

class DLLoaderError : public Error
{
    public:
        DLLoaderError(std::string const &message, std::string const &component = "Unknown")
        : Error(message, component) {};
};

class CoreError : public Error
{
    public:
        CoreError(std::string const &message, std::string const &component = "Unknown")
        : Error(message, component) {};
};

class GamesError : public Error
{
    public:
        GamesError(std::string const &message, std::string const &component = "Unknown")
        : Error(message, component) {};
};

class GraphicsError : public Error
{
    public:
        GraphicsError(std::string const &message, std::string const &component = "Unknown")
        : Error(message, component) {};
};

#endif /* !ERROR_HPP_ */
