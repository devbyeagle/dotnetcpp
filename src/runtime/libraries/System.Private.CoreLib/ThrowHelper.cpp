#include "dotnetcpp/System/Exception.h"
#include "dotnetcpp/System/ThrowHelper.h"

namespace System
{
    [[noreturn]]
    void ThrowHelper::ThrowInvalidOperationException_InvalidOperation_NoValue()
    {
        throw Exception("Nullable object must have a value.");
    }
}
