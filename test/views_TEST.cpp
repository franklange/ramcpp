#include <ramcpp/ram.hpp>

#include <gtest/gtest.h>

#include <algorithm>

namespace std {

auto operator==(const ramcpp::view_t lhs, const ramcpp::view_t rhs) -> bool
{
    return equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

} // namespace std

namespace ramcpp::test {

struct ViewsTest : public ::testing::Test
{
    const bytes_t m_a{11, 22, 33, 44, 55};
    const bytes_t m_d{55, 44, 33, 22, 11};
    const bytes_t m_r{45, 23, 8, 212, 17};
};

TEST_F(ViewsTest, empty)
{
    EXPECT_TRUE(views({}).empty());
}

TEST_F(ViewsTest, window_size_0)
{
    EXPECT_TRUE(views(m_a, 0).empty());
}

TEST_F(ViewsTest, window_size_1_ascending)
{
    const views_t exp{
        {m_a.begin(), 2},
        {m_a.begin() + 2, 2},
        {m_a.begin() + 4, m_a.end()}
    };

    EXPECT_EQ(exp, views(m_a, 1));
}

TEST_F(ViewsTest, window_size_1_descending)
{
    const views_t exp{{m_d.begin(), m_d.end()}};
    EXPECT_EQ(exp, views(m_d, 1));
}

TEST_F(ViewsTest, window_size_1_random)
{
    const views_t exp{
        {m_r.begin(), 4},
        {m_r.begin() + 4, m_r.end()}
    };

    EXPECT_EQ(exp, views(m_r, 1));
}

TEST_F(ViewsTest, window_size_fits)
{
    const views_t exp{{m_d.begin(), m_d.end()}};
    EXPECT_EQ(exp, views(m_d, 5));
}

TEST_F(ViewsTest, window_oversized)
{
    const views_t exp{{m_r.begin(), m_r.end()}};
    EXPECT_EQ(exp, views(m_r, 12));
}

TEST_F(ViewsTest, single_element)
{
    const bytes_t b{11};
    const views_t exp{{b.begin(), b.end()}};

    EXPECT_EQ(exp, views(b, 1));
}

TEST_F(ViewsTest, normal_ascending)
{
    const views_t exp{
        {m_a.begin(), 3},
        {m_a.begin() + 3, m_a.end()}
    };

    EXPECT_EQ(exp, views(m_a, 2));
}

TEST_F(ViewsTest, normal_descending)
{
    const views_t exp{{m_d.begin(), m_d.end()}};
    EXPECT_EQ(exp, views(m_d, 2));
}

TEST_F(ViewsTest, normal_random)
{
    const views_t exp{
        {m_r.begin(), 4},
        {m_r.begin() + 4, m_r.end()}
    };

    EXPECT_EQ(exp, views(m_r, 2));
}

} // namespace ramcpp::test
