#pragma once

#include <ramcpp/types.hpp>

namespace ramcpp {

template <typename C>
auto hash(const C& chunk) -> hash_t
{
    hash_t h{1u};
    for (const auto byte : chunk)
        h ^= byte + 0x9e3779b97f4a78 + (h << 6u) + (h >> 2u);

    return h;
}

} // namespace ramcpp
