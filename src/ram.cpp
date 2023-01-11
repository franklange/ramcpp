#include <ramcpp/ram.h>

#include <algorithm>
#include <iterator>
#include <numeric>

#include <iostream>

namespace ramcpp {

auto chunks(const bytes_t& b, const std::size_t w) -> chunks_t
{
    if (b.empty() || (w == 0))
        return {};

    if (w >= b.size())
        return {{b.begin(), b.end()}};


    std::vector<chunk_t> res;

    auto wstart = b.begin();

    while (std::distance(wstart, b.end()) > (w + 1))
    {
        const auto wend = wstart + w;
        const auto wmax = std::max_element(wstart, wend);
        const auto cmax = std::find_if(wend, b.end(), [wm = *wmax](const auto m){ return (m > wm); });

        if (cmax == b.end())
            break;

        res.push_back({wstart, std::next(cmax)});
        wstart = std::next(cmax);
    }

    res.push_back({wstart, b.end()});

    return res;
}

} // namespace ramcpp
