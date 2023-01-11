#pragma once

#include <cstddef>
#include <cstdint>
#include <span>
#include <vector>

namespace ramcpp {

using byte_t  = std::uint8_t;
using bytes_t = std::vector<byte_t>;

using chunk_t  = std::span<const byte_t>;
using chunks_t = std::vector<chunk_t>;

auto chunks(const bytes_t&, std::size_t window = 1024) -> chunks_t;

} // namespace ramcpp
