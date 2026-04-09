#pragma once

#include "Nullable.h"
#include "Object.h"

namespace System {
  class Exception : public Object, public std::exception {
  private:
    Nullable<std::string> _message;

  public:
    Exception() = default;
    Exception(Nullable<const char*> message);

    const char* what() const noexcept override;
  };
} // namespace System
