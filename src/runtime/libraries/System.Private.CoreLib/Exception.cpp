#include <exception>

#include "dotnetcpp/System/Nullable.h"
#include "dotnetcpp/System/Exception.h"

namespace System
{
	Exception::Exception(Nullable<const char*> message)
	{
		_message = Nullable<std::string>(std::string(message.Value()));
	}

	const char* Exception::what() const noexcept
	{
#if _WIN32
		return _message.Value().c_str();
#else
		return _message.HasValue() ? _message.Value().c_str() : "";
#endif
	}
} // namespace System
