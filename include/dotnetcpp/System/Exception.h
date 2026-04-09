#pragma once

// Upstream reference:
// https://github.com/dotnet/runtime/blob/main/src/libraries/System.Private.CoreLib/src/System/Exception.cs

#include "Nullable.h"

namespace System
{
	class Exception
		: public Object,
		  public std::exception
	{
	protected:
		Nullable<std::string> _message;

	public:
		Exception() = default;
		Exception(Nullable<const char*> message);

		const char* what() const noexcept override;
	};
} // namespace System
