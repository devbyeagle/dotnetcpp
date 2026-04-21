#include <exception>

#include "dotnetcpp/System/Exception.h"

namespace System
{
	Exception::Exception(const std::string& message) noexcept
		: Exception()
	{
		_message = message;
	}

	const char* Exception::what() const noexcept
	{
		return _message.empty() ? "" : _message.c_str();
	}
} // namespace System
