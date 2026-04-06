#pragma once

// Upstream reference: 
// https://github.com/dotnet/runtime/blob/main/src/libraries/System.Private.CoreLib/src/System/Object.cs

namespace System
{
  class Object
  {
  public:
    // Creates a new instance of an Object.
    Object() = default;

    virtual ~Object() = default;

    /// @brief Returns a string that represents the current object.
    /// @returns A string that represents the current object.
    virtual std::string ToString() const;

    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @returns `true` if the specified object is equal to the current object; otherwise, `false`.
    virtual bool Equals(const Object* obj) const;

    static bool ReferenceEquals(const Object* objA, const Object* objB);

    /// @brief Serves as the default hash function.
    /// @return A hash code for the current object.
    virtual int GetHashCode() const; 
  };
}

using object = System::Object;
