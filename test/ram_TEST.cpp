#include <ramcpp/ram.h>

#include <gtest/gtest.h>

#include <algorithm>

namespace std {

auto operator==(const ramcpp::chunk_t lhs, const ramcpp::chunk_t rhs) -> bool
{
    return equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

} // namespace std

namespace ramcpp::test {

struct RamTest : public ::testing::Test
{
    const bytes_t m_a{11, 22, 33, 44, 55};
    const bytes_t m_d{55, 44, 33, 22, 11};
    const bytes_t m_r{45, 23, 8, 212, 17};
};

TEST_F(RamTest, empty)
{
    EXPECT_TRUE(chunks({}).empty());
}

TEST_F(RamTest, window_size_0)
{
    EXPECT_TRUE(chunks(m_a, 0).empty());
}

TEST_F(RamTest, window_size_1_ascending)
{
    const chunks_t exp{
        {m_a.begin(), 2},
        {m_a.begin() + 2, 2},
        {m_a.begin() + 4, m_a.end()}
    };

    EXPECT_EQ(exp, chunks(m_a, 1));
}

TEST_F(RamTest, window_size_1_descending)
{
    const chunks_t exp{{m_d.begin(), m_d.end()}};
    EXPECT_EQ(exp, chunks(m_d, 1));
}

TEST_F(RamTest, window_size_1_random)
{
    const chunks_t exp{
        {m_r.begin(), 4},
        {m_r.begin() + 4, m_r.end()}
    };

    EXPECT_EQ(exp, chunks(m_r, 1));
}

TEST_F(RamTest, window_size_fits)
{
    const chunks_t exp{{m_d.begin(), m_d.end()}};
    EXPECT_EQ(exp, chunks(m_d, 5));
}

TEST_F(RamTest, oversized_window)
{
    const chunks_t exp{{m_r.begin(), m_r.end()}};
    EXPECT_EQ(exp, chunks(m_r, 12));
}

TEST_F(RamTest, single_element)
{
    const bytes_t b{11};
    const chunks_t exp{{b.begin(), b.end()}};

    EXPECT_EQ(exp, chunks(b, 1));
}

TEST_F(RamTest, normal_ascending)
{
    const chunks_t exp{
        {m_a.begin(), 3},
        {m_a.begin() + 3, m_a.end()}
    };

    EXPECT_EQ(exp, chunks(m_a, 2));
}

TEST_F(RamTest, normal_descending)
{
    const chunks_t exp{{m_d.begin(), m_d.end()}};
    EXPECT_EQ(exp, chunks(m_d, 2));
}

TEST_F(RamTest, normal_random)
{
    const chunks_t exp{
        {m_r.begin(), 4},
        {m_r.begin() + 4, m_r.end()}
    };

    EXPECT_EQ(exp, chunks(m_r, 2));
}

} // namespace Template::test
