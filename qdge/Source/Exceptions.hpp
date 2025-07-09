#pragma once

#include <exception>
#include "Core/Core.hpp"

QDGE_NS

namespace Exceptions {
    class AppExistsError : public std::exception {
        const char* what() const noexcept {
            return "Application already exists, however we got here.";
        }
    };

    class FunctionNotDefinedError : public std::exception {
        const char* what() const noexcept {
            return "You were supposed to define that function,\n\
did you even read the docs?";
        }
    };
}

QDGE_NS_END
