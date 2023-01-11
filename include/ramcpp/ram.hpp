#pragma once

#include <ramcpp/defaults.hpp>
#include <ramcpp/types.hpp>

namespace ramcpp {

auto views (const bytes_t&, u32 = defaults::window_size) -> views_t;
auto chunks(const bytes_t&, u32 = defaults::window_size) -> chunks_t;

auto hashed_views (const bytes_t&, u32 = defaults::window_size) -> hashed_views_t;
auto hashed_chunks(const bytes_t&, u32 = defaults::window_size) -> hashed_chunks_t;

} // namespace ramcpp
