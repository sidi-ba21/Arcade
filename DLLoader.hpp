/*
** EPITECH PROJECT, 2022
** DLLoder
** File description:
** DLLoder
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

template <typename T>
class DLLoader {
    public:
        DLLoader();
        T *getInstance(std:string) const;
        ~DLLoader();
    protected:
    private:
};

#endif /* !DLLOADER_HPP_ */
