#pragma once

#include <type_traits>
#include <utility>

#include "Object.h"

namespace System
{    
    template<typename T>
    struct Nullable : public Object
    {
        static_assert(std::is_trivially_copyable<T>::value, "T must be a value type");
    private:
        bool hasValue;
        T value;
    public:
        constexpr Nullable() noexcept { }
        constexpr Nullable(std::nullptr_t) noexcept { }

        template<typename U = T,
                 typename = std::enable_if_t<!std::is_same_v<std::decay_t<U>, Nullable>>>
        constexpr Nullable(U&& value) : hasValue(true), value(std::forward<U>(value)) { }

        constexpr bool HasValue() const noexcept { return hasValue; }

        constexpr T& Value() &
        {
            if (!hasValue)
            {
                throw;
            }
            return value;
        }

        constexpr const T& Value() const &
        {
            if (!hasValue)
            {
                throw;
            }
            return value;
        }

        constexpr T GetValueOrDefault() const& { return value; }
        constexpr T GetValueOrDefault(T defaultValue) { return hasValue ? value : defaultValue; }

        explicit operator T() const { return Value(); }
    };
}
