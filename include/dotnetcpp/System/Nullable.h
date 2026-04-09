#pragma once

// Upstream reference:
// https://github.com/dotnet/runtime/blob/main/src/libraries/System.Private.CoreLib/src/System/Nullable.cs

#include <type_traits>

#include "Object.h"
#include "ThrowHelper.h"

namespace System
{
	class Exception;

	template <typename T>
	struct Nullable : public Object
	{
		static_assert(std::is_copy_constructible<T>::value, "T must be a value type");

	private:
		bool hasValue;
		T value;

	public:
		constexpr Nullable() noexcept = default;
		constexpr Nullable(std::nullptr_t) noexcept {}

		constexpr Nullable(const T& value) noexcept(std::is_nothrow_constructible<T, const T&>::value)
		{
			this->value = value;
			hasValue = true;
		}

		constexpr bool HasValue() const noexcept { return hasValue; }

		constexpr T& Value() &
		{
			if (!hasValue)
			{
				ThrowHelper::ThrowInvalidOperationException_InvalidOperation_NoValue();
			}
			return value;
		}

		constexpr const T& Value() const&
		{
			if (!hasValue)
			{
				ThrowHelper::ThrowInvalidOperationException_InvalidOperation_NoValue();
			}
			return value;
		}

		constexpr T GetValueOrDefault() const& { return value; }
		constexpr T GetValueOrDefault(const T& defaultValue) const& { return hasValue ? value : defaultValue; }

		explicit operator T() const { return Value(); }
	};
} // namespace System
