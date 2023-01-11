# Rapid Asymmetric Maximum (RAM)

C++20 implementation of the _Rapid Asymmetric Maximum_ (RAM) algorithm as presented by
Widodo et al. in the 2017 paper _A new content-defined chunking algorithm for data deduplication in cloud storage_.

ISO citation:
```
WIDODO, Ryan NS; LIM, Hyotaek; ATIQUZZAMAN, Mohammed.
A new content-defined chunking algorithm for data deduplication in cloud storage.
Future Generation Computer Systems, 2017, 71. Jg., S. 145-156.
``` 

### Dependencies
* usage: none
* development: gtest


### Example
```c++
#include <ramcpp/ram.h>

auto main() -> int
{
    ramcpp::bytes_t b{33, 11, 66, 22, 77, 55, 99, 44, 100, 88};

    const auto hs1 = ramcpp::hashed_chunks(b, 2);
    print(hs1); // [1656014895450681491 | 33 11 66], [15260561608136800858 | 22 77 55 99], ...

    b.insert(b.begin(), 7);

    const auto hs2 = ramcpp::hashed_chunks(b, 2);
    print(hs2); // [15260561608214301689 | 7 33 11 66], [15260561608136800858 | 22 77 55 99], ...

    // only 1st chunk changed due to insert

    return 0;
}

```

### Build & Run (on Linux)
```bash
git clone https://github.com/franklange/ramcpp.git
cd ramcpp
mkdir build
cd build
cmake -DRAMCPP_EXAMPLES=ON ..
cmake --build . -j
./bin/ramcpp_example
```

