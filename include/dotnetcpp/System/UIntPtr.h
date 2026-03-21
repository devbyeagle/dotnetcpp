#pragma once

#include "UInt64.h"
#include "UInt32.h"

#if INTPTR_MAX == INT64_MAX
using nuint = System::UInt64;
#else
using nuint = System::UInt32;
#endif

namespace System
{
    struct UIntPtr
    {
    private:
        nuint _value;
    public:
        UIntPtr(UInt64 value)
        {
#if 
        }
    };
}
