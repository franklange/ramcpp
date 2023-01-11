#include <ramcpp/ram.hpp>
#include <ramcpp/hash.hpp>

#include <algorithm>
#include <iterator>
#include <numeric>

namespace ramcpp {

auto views(const bytes_t& b, const u32 w) -> views_t
{
    if (b.empty() || (w == 0u))
        return {};

    if (w >= b.size())
        return {{b.begin(), b.end()}};

    views_t res;
    auto wstart = b.begin();

    while (std::distance(wstart, b.end()) > (w + 1u))
    {
        const auto wend = wstart + w;
        const auto wmax = std::max_element(wstart, wend);
        const auto cmax = std::find_if(wend, b.end(), [wm = *wmax](const auto m){ return (m >= wm); });

        if (cmax == b.end())
            break;

        res.push_back({wstart, std::next(cmax)});
        wstart = std::next(cmax);
    }

    if (wstart != b.end())
        res.push_back({wstart, b.end()});

    res.shrink_to_fit();

    return res;
}

auto chunks(const bytes_t& b, const u32 w) -> chunks_t
{
    chunks_t res;
    for (const auto v : views(b, w))
        res.push_back({v.begin(), v.end()});

    res.shrink_to_fit();
    return res;
}

auto hashed_views(const bytes_t& b, const u32 w) -> hashed_views_t
{
    hashed_views_t res;
    for (const auto v : views(b, w))
    {
        const auto h = hash(v);
        res.hashes.push_back(h);
        res.views[h] = v;
    }

    return res;
}

auto hashed_chunks(const bytes_t& b, const u32 w) -> hashed_chunks_t
{
    hashed_chunks_t res;
    for (auto& c : chunks(b, w))
    {
        const auto h = hash(c);
        res.hashes.push_back(h);
        res.chunks[h] = std::move(c);
    }

    return res;
}

} // namespace ramcpp
