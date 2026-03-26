#include "dotnetcpp/System/Nullable.h"

namespace System
{
  template<typename T>
  template<typename U>
  constexpr Nullable<T>::Nullable(U&& value)
  {
    this->value = std::forward<U>(value);
    hasValue = true;
  }
  
  template<typename T>
  constexpr bool Nullable<T>::HasValue() const noexcept
  {
    return hasValue;
  }

  template<typename T>
  const T& Nullable<T>::Value() const
  {
    if (!hasValue)
        throw std::runtime_error("Nullable object has no value");
    return value;
  }

  template<typename T>
  constexpr T Nullable<T>::GetValueOrDefault(const T& defaultValue) const
  {
    return hasValue ? value : defaultValue;
  }
}
