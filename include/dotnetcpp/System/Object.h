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
  };
}

using object = System::Object;
