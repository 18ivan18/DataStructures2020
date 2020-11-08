#ifndef __PROB6_TESTS_H
#define __PROB6_TESTS_H

#include "test_utils.hpp"

TEST_CASE("Empty list")
{
    //must not crash
    removedups(nullptr);
}

TEST_CASE("Remove inner")
{
    node<int> *l = tolist<int>({1, 2, 2, 2, 2, 3, 7});
    removedups(l);
    CHECK(tovector(l) == std::vector<int>{1, 2, 3, 7});
}

TEST_CASE("Remove with first")
{
    node<int> *l = tolist<int>({2, 2, 2, 2, 3, 7});
    removedups(l);
    CHECK(tovector(l) == std::vector<int>{2, 3, 7});
}

TEST_CASE("Remove with last")
{
    node<int> *l = tolist<int>({1, 2, 3, 7, 7, 7});
    removedups(l);
    CHECK(tovector(l) == std::vector<int>({1, 2, 3, 7}));
}

#endif
