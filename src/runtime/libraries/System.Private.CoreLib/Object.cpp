#include <cstdint>
#include <string>
#include <typeinfo>

#include "dotnetcpp/System/Object.h"

namespace System
{
    std::string Object::ToString() const
    {
        return typeid(*this).name();
    }

    bool Object::Equals(const object* obj) const
    {
        return this == obj;
    }
    
    bool Object::ReferenceEquals(const object* objA, const object* objB)
    {
        return objA == objB;
    }

    int Object::GetHashCode() const
    {
        return reinterpret_cast<std::uintptr_t>(this) & 0xFFFFFFFF;
    }
}

