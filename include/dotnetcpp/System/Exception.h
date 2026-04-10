#pragma once

// Upstream reference:
// https://github.com/dotnet/runtime/blob/main/src/libraries/System.Private.CoreLib/src/System/Exception.cs

#include "Object.h"

namespace System
{
	class Exception
		: public Object,
		  public std::exception
	{
	protected:
		std::string _message;

	public:
		Exception() = default;
		Exception(const std::string& message);

		const char* what() const noexcept override;
	};
} // namespace System
