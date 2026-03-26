#pragma once

#include <type_traits>

namespace System
{
    template<typename T>
    struct Nullable
    {
        static_assert(std::is_trivially_copyable<T>::value, "T must be a value type");
    private:
        bool hasValue;
        T value;
    public:
        constexpr Nullable() noexcept { }
        constexpr Nullable(std::nullptr_t) noexcept { }

        template<typename U = typename std::remove_cv<T>::type>
        constexpr Nullable(U&& value);

        constexpr bool HasValue() const noexcept;
        const T& Value() const;

        constexpr T GetValueOrDefault() const;
        constexpr T GetValueOrDefault(const T& defaultValue) const;

        explicit operator T() const { return Value(); }
        friend bool operator==(const Nullable& n1, const Nullable& n2);
    };
}
