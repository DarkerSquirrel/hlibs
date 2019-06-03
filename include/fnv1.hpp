//
// Header-only libs
//

#ifndef FNV_HPP
#define FNV_HPP

#include <cstdint>
#include <vector>

namespace fnv1
{
    static constexpr uint32_t FNV_PRIME32 = 16777619u;
    static constexpr uint32_t OFFSET_BASIS32 = 2166136261u;
    static constexpr uint64_t FNV_PRIME64 = 1099511628211u;
    static constexpr uint64_t OFFSET_BASIS64 = 14695981039346656037u;

    template <class Iterator>
    inline uint32_t hash32(Iterator begin, Iterator end, uint32_t result = OFFSET_BASIS32)
    {
        for (Iterator i = begin; i != end; ++i)
        {
            result *= FNV_PRIME32;
            result ^= *i;
        }
        return result;
    }

    template <class Iterator>
    inline uint64_t hash64(Iterator begin, Iterator end, uint64_t result = OFFSET_BASIS64)
    {
        for (Iterator i = begin; i != end; ++i)
        {
            result *= FNV_PRIME64;
            result ^= *i;
        }
        return result;
    }
}

#endif // FNV_HPP
