#pragma once

#include "Object.h"

namespace System
{
    class ThrowHelper : public Object
    {
    public:
        [[noreturn]]
        static void ThrowInvalidOperationException_InvalidOperation_NoValue();
    };
}
