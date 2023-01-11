#include <ramcpp/ram.hpp>

#include <gtest/gtest.h>

namespace ramcpp::test {

struct ChunksTest : public ::testing::Test
{
    const bytes_t m_a{11, 22, 33, 44, 55, 66, 77, 88, 99};
    const bytes_t m_d{99, 88, 77, 66, 55, 44, 33, 22, 11};
    const bytes_t m_r{45, 23, 8, 212, 17, 0, 3, 67, 45};
};

TEST_F(ChunksTest, empty)
{
    EXPECT_TRUE(chunks({}).empty());
}

TEST_F(ChunksTest, window_size_0)
{
    EXPECT_TRUE(chunks(m_a, 0).empty());
}

TEST_F(ChunksTest, window_size_1_ascending)
{
    const chunks_t exp{{11, 22}, {33, 44}, {55, 66}, {77, 88}, {99}};
    EXPECT_EQ(exp, chunks(m_a, 1));
}

TEST_F(ChunksTest, window_size_1_descending)
{
    const chunks_t exp{{99, 88, 77, 66, 55, 44, 33, 22, 11}};
    EXPECT_EQ(exp, chunks(m_d, 1));
}

TEST_F(ChunksTest, window_size_1_random)
{
    const chunks_t exp{{45, 23, 8, 212}, {17, 0, 3, 67}, {45}};
    EXPECT_EQ(exp, chunks(m_r, 1));
}

TEST_F(ChunksTest, window_size_fits)
{
    const chunks_t exp{{11, 22, 33, 44, 55, 66, 77, 88, 99}};
    EXPECT_EQ(exp, chunks(m_a, m_a.size()));
}

TEST_F(ChunksTest, window_oversized)
{
    const chunks_t exp{{99, 88, 77, 66, 55, 44, 33, 22, 11}};
    EXPECT_EQ(exp, chunks(m_d, m_d.size() + 10));
}

TEST_F(ChunksTest, single_element)
{
    const chunks_t exp{{101}};
    EXPECT_EQ(exp, chunks({101}));
}

TEST_F(ChunksTest, normal_ascending)
{
    const chunks_t exp{{11, 22, 33}, {44, 55, 66}, {77, 88, 99}};
    EXPECT_EQ(exp, chunks(m_a, 2));
}

TEST_F(ChunksTest, normal_descending)
{
    const chunks_t exp{{99, 88, 77, 66, 55, 44, 33, 22, 11}};
    EXPECT_EQ(exp, chunks(m_d, 2));
}

TEST_F(ChunksTest, normal_random)
{
    const chunks_t exp{{45, 23, 8, 212}, {17, 0, 3, 67}, {45}};
    EXPECT_EQ(exp, chunks(m_r, 2));
}

} // namespace ramcpp::test
