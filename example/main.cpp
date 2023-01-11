#include <ramcpp/ram.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>

auto from_file(const std::filesystem::path& p) -> ramcpp::bytes_t
{
    ramcpp::bytes_t res;
    res.resize(std::filesystem::file_size(p));

    std::ifstream file{p, std::ios::in | std::ios::binary};
    file.read(reinterpret_cast<char*>(res.data()), res.size());

    return res;
}

auto main() -> int
{
    const auto bytes = from_file("bin/files/alice.txt");
    const auto chunk_views = ramcpp::hashed_views(bytes);

    for (const auto h : chunk_views.hashes)
    {
        std::cout << "hash:  " << h << "\t";
        std::cout << "bytes: " << chunk_views.views.at(h).size() << std::endl;
    }

    return 0;
}
