#pragma once

// Upstream reference: 
// https://github.com/dotnet/runtime/blob/main/src/libraries/System.Private.CoreLib/src/System/Span.cs

#include <type_traits>
#include <stdexcept>

#include "Object.h"

namespace System
{
    template <typename T>
    struct Span : public Object
    {
    private:
        /// @brief A byref or a native ptr.
        T *_reference;
        /// @brief The number of elements this Span contains.
        int _length;

    public:
        /** @brief
         *
         *  @param pointer An unmanaged pointer to memory.
         *  @param length The number of elements the memory contains.
         *
         *  @throws std::invalid_argument
         *  Thrown when T is reference type or contains pointers and hence cannot be stored in unmanaged memory.
         *
         *  @throws std::out_of_range
         *  Thrown when the specified length is negative.
         */
        inline Span(void *pointer, int length)
        {
            if constexpr (std::is_pointer<T>::value || !std::is_trivially_copyable<T>::value)
                throw std::invalid_argument("Type contains references or is not safe");

            if (length < 0)
                throw std::out_of_range("");

            _reference = reinterpret_cast<T *>(pointer);
            _length = length;
        }

        /// @brief Creates a new @ref Span<T> of length 1 around the specified reference.
        /// @param reference A reference to data.
        inline Span(T &reference)
        {
            _reference = &reference;
            _length = 1;
        }

        /// @brief The number of items in the span.
        int Length() const
        {
            return _length;
        }

        /// @brief Gets a value indicating whether this @ref Span<T> is empty.
        /// @return `true` if this span is empty; otherwise, `false`.
        bool IsEmpty() const
        {
            return _length == 0;
        }

        std::string ToString() const override
        {
            if (typeid(T) == typeid(char))
            {
                return std::string(reinterpret_cast<char*>(_reference), _length);
            }
            return "System.Span<" + std::string(typeid(T).name()) + ">[" + std::to_string(_length) + "]";
        }
    };
}
