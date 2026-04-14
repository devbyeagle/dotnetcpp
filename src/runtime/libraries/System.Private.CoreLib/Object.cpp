#include <typeinfo>

#include "dotnetcpp/System/Object.h"

namespace System
{
	std::string Object::ToString() const
	{
		return typeid(*this).name();
	}

	bool Object::Equals(object* obj) const
	{
		return this == obj;
	}
} // namespace System
