/*
 *
 *  � Stout Games 2019
 *
 */

#pragma once

#include <iostream>
#include <mutex>

#include "BlackRoot/Pubc/Stringstream.h"

namespace BlackRoot {
namespace Util {

    class Cout : public std::ostringstream {
    protected:
        static std::mutex Mutex;

    public:
        Cout() = default;

        ~Cout()
        {
            std::lock_guard<std::mutex> guard(Mutex);
            std::cout << this->str();
        }
    };

}
}