#include <typeinfo>

#include "dotnetcpp/System/Object.h"

namespace System
{
    const char* Object::ToString() const
    {
        return typeid(*this).name();
    }
}
