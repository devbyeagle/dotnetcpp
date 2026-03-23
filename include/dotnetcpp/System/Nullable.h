#pragma once

#include <type_traits>
#include <stdexcept>

namespace System
{
    template<typename T>
    struct Nullable
    {
        static_assert(std::is_arithmetic_v<T> || std::is_trivial_v<T>, "T must be a value type");
    private:
        const bool hasValue;
        T value;
    public:
        Nullable() : hasValue(false) {}
        Nullable(std::nullptr_t) : Nullable() {}
        Nullable(T value) : value(value), hasValue(true) {}

        bool HasValue() const { return hasValue; }
        T Value() const 
        { 
            if (!hasValue) throw std::runtime_error("Nullable object must have a value.");
            return value;
        }

        T GetValueOrDefault() const { return value; }
        T GetValueOrDefault(T defaultValue) const { return hasValue ? value : defaultValue; }

        explicit operator T() const { return Value(); }
    };
}
