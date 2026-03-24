#pragma once

#include <stdexcept>
#include <type_traits>

namespace System
{
    template<typename T>
    struct Nullable
    {
        static_assert(std::is_scalar_v<T> || std::is_class_v<T>, "T must be a primitive or struct");
    private:
        bool hasValue;
        T value;
    public:
        constexpr Nullable() noexcept = default;
        constexpr Nullable(std::nullptr_t) noexcept { }

        Nullable(const T& value)
        {
            this->value = value;
            hasValue = true;
        }

        constexpr bool HasValue() const noexcept
        {
            return hasValue;
        }

        T& Value()
        {
            if (!hasValue)
                throw std::runtime_error("Nullable object has no value");
            return value;
        }

        const T& Value() const
        {
            if (!hasValue)
                throw std::runtime_error("Nullable object has no value");
            return value;
        }

        constexpr T GetValueOrDefault(const T& defaultValue) const
        {
            return hasValue ? value : defaultValue;
        }

        explicit operator T() const { return Value(); }

        friend bool operator==(const Nullable& n1, const Nullable& n2)
        {
            if (n1.HasValue())
            {
                if (n2.HasValue()) return n1.Value() == n2.Value();
                return false;
            }
            if (n2.HasValue()) return false;
            return true;
        }
    };
}
