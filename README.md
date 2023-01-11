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
...
```

### Build & Run (on Linux)
```bash
git clone https://github.com/franklange/ramcpp.git
cd ramcpp
mkdir build
cd build
cmake -DRAMCPP_EXAMPLES=ON ..
cmake --build . -j
./bin/example
```

