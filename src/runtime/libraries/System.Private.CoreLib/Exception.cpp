#include <exception>

#include "dotnetcpp/System/Exception.h"

namespace System
{
	Exception::Exception(Nullable<const char*> message)
	{
		_message = Nullable<std::string>(std::string(message.Value()));
	}

	const char* Exception::what() const noexcept
	{
		return _message.HasValue() ? _message.Value().c_str() : "";
	}
} // namespace System
