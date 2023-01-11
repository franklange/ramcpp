#include <template/template.hpp>

#include <gtest/gtest.h>

namespace Template::test {

struct TemplateTest : public ::testing::Test
{

};

TEST_F(TemplateTest, test)
{
    EXPECT_EQ(1, 1);
}

} // namespace Template::test