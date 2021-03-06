/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

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
#ifdef _WIN32
            std::string str = this->str();
            while (str.length() > 256) {
                std::cout << str.substr(0, 256);
                str = str.erase(0, 256);
            }
            std::cout << str;
#else
            std::cout << this->str();
#endif
        }
    };

}
}