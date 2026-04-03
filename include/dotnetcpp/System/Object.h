#pragma once

// Upstream reference: 
// https://github.com/dotnet/dotnet/blob/main/src/runtime/src/libraries/System.Private.CoreLib/src/System/Object.cs

namespace System
{
  class Object
  {
  public:
    Object() = default;
    virtual ~Object() = default;

    /// @brief Returns a string that represents the current object.
    /// @returns A string that represents the current object.
    virtual const char* ToString() const;

    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object; otherwise, `false`.
    virtual bool Equals(const Object* obj) const;

    /// @brief Serves as the default hash function.
    /// @return A hash code for the current object.
    virtual int GetHashCode() const; 
  };
}

using object = System::Object;
