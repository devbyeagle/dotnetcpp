#include <exception>

#include "dotnetcpp/System/Exception.h"

namespace System
{
	Exception::Exception(const std::string& message)
	{
		_message = message;
	}

	const char* Exception::what() const noexcept
	{
		return _message.c_str();
	}
} // namespace System
