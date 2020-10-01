//
// Header-only libs
//

#ifndef FNV_HPP
#define FNV_HPP

#include <cstdint>

namespace fnv1
{
    inline namespace detail
    {
        template <typename T> T prime();
        template <typename T> T offsetBasis();

        template <> constexpr std::uint32_t prime<std::uint32_t>() { return 16777619U; }
        template <> constexpr std::uint32_t offsetBasis<std::uint32_t>() { return 2166136261U; }

        template <> constexpr std::uint64_t prime<std::uint64_t>() { return 1099511628211ULL; }
        template <> constexpr std::uint64_t offsetBasis<std::uint64_t>() { return 14695981039346656037ULL; }
    }

    template <typename Result, typename Iterator>
    constexpr Result hash(const Iterator i, const Iterator end,
                          const Result result = offsetBasis<Result>()) noexcept
    {
        return (i != end) ? hash(i + 1, end, (result * prime<Result>()) ^ static_cast<std::uint8_t>(*i)) : result;
    }

    template <typename Result, typename T>
    constexpr Result hash(const T& v) noexcept
    {
        return hash<Result>(std::begin(v), std::end(v));
    }
}

#endif // FNV_HPP
