#include <cstdint>
#include <typeinfo>

#include "dotnetcpp/System/Object.h"

namespace System
{
	std::string Object::ToString() const
	{
		return typeid(*this).name();
	}

	bool Object::Equals(const object* obj) const
	{
		return this == obj;
	}

	int Object::GetHashCode() const
	{
		return reinterpret_cast<uintptr_t>(this) & 0xFFFFFFFF;
	}
} // namespace System
