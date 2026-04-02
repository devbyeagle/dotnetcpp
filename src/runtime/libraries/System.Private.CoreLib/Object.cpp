#include <typeinfo>
#include <cstdint>

#include "dotnetcpp/System/Object.h"

namespace System
{
    const char* Object::ToString() const
    {
        return typeid(*this).name();
    }

    bool Object::Equals(const Object* obj) const
    {
        return this == obj;
    }

    int Object::GetHashCode() const
    {
        return reinterpret_cast<std::uintptr_t>(this) & 0xFFFFFFFF;
    }
}
