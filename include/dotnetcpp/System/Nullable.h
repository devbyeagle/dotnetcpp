#pragma once

// Upstream reference: 
// https://github.com/dotnet/dotnet/blob/main/src/runtime/src/libraries/System.Private.CoreLib/src/System/Nullable.cs

#include <stdexcept>
#include <type_traits>
#include <utility>

#include "Object.h"

namespace System
{   
    template<typename T>
    struct Nullable : public Object
    {
        static_assert(std::is_copy_constructible<T>::value, "T must be a value type");

    private:
        bool hasValue;
        T value;

    public:
        constexpr Nullable() noexcept { }

        constexpr Nullable(std::nullptr_t) noexcept { }

        constexpr Nullable(const T& value) noexcept(std::is_nothrow_constructible_v<T, const T&>)
        {
            this->value = value;
            hasValue = true;
        }

        constexpr bool HasValue() const noexcept { return hasValue; }

        constexpr T& Value()& 
        {
            if (!hasValue)
            {
                throw std::runtime_error();
            }
            return value;
        }

        constexpr T GetValueOrDefault() const& { return value; }
        constexpr T GetValueOrDefault(const T& defaultValue) const& { return hasValue ? value : defaultValue;  }

        bool Equals(const Object* other) const override
        {
            if (!hasValue) return other == nullptr;
            if (other == nullptr) return false;

            // Try dynamic cast
            const Nullable<T>* o = dynamic_cast<const Nullable<T>*>(other);
            if (!o || !o->hasValue) return false;
            return value == o->value;
        }

        Nullable<T>& operator=(const T& v)
        {
            value = v;
            hasValue = true;
            return *this;
        }

        explicit operator T() const { return Value(); }
    };
}
