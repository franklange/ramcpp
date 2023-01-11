#pragma once

#include <cstdint>
#include <span>
#include <unordered_map>
#include <vector>

namespace ramcpp {

using u32 = std::uint32_t;

using byte_t  = std::uint8_t;
using bytes_t = std::vector<byte_t>;

using chunk_t  = bytes_t;
using chunks_t = std::vector<chunk_t>;

using view_t  = std::span<const byte_t>;
using views_t = std::vector<view_t>;

using hash_t   = std::uint64_t;
using hashes_t = std::vector<hash_t>;

using chunk_map_t = std::unordered_map<hash_t, chunk_t>;
using view_map_t  = std::unordered_map<hash_t, view_t>;

struct hashed_chunks_t
{
    hashes_t  hashes;
    chunk_map_t chunks;

    auto operator<=>(const hashed_chunks_t&) const = default;
};

struct hashed_views_t
{
    hashes_t  hashes;
    view_map_t views;

    auto operator<=>(const hashed_views_t&) const = default;
};

} // namespace ramcpp
