#ifndef __PROB6_TESTS_H
#define __PROB6_TESTS_H

#include "test_utils.hpp"

TEST_CASE("Empty list")
{
    //must not crash
    node<int> *l = nullptr;
    removesub<int> (l, nullptr);
}

TEST_CASE("Empty sublist")
{
    //must not crash
    node<int> *l = tolist<int>({1, 2, 3});
    removesub<int> (l, nullptr);
}

TEST_CASE("Delete at end")
{
    node<int> *l = tolist<int>({1, 2, 3, 4, 5, 6});
    node<int> *sub = tolist<int>({6});
    removesub (l, sub);
    CHECK(tovector(l) == std::vector<int>{1, 2, 3, 4, 5});

    sub = tolist<int>({3, 4, 5});
    removesub (l, sub);
    CHECK(tovector(l) == std::vector<int>{1, 2});
}

TEST_CASE("Delete inside")
{
    node<int> *l = tolist<int>({1, 2, 3, 4, 5, 6});
    node<int> *sub = tolist<int>({2});
    removesub (l, sub);
    CHECK(tovector(l) == std::vector<int>{1, 3, 4, 5, 6});

    sub = tolist<int>({3, 4, 5});
    removesub (l, sub);
    CHECK(tovector(l) == std::vector<int>{1, 6});
}

TEST_CASE("Delete at beginning")
{
    node<int> *l = tolist<int>({1, 2, 3, 4, 5, 6});
    node<int> *sub = tolist<int>({1});
    removesub (l, sub);
    CHECK(tovector(l) == std::vector<int>{2, 3, 4, 5, 6});

    sub = tolist<int>({2, 3, 4});
    removesub (l, sub);
    CHECK(tovector(l) == std::vector<int>{5, 6});
}

TEST_CASE("Delete multiple occurrences")
{
    node<int> *l = tolist<int>({1, 2, 3, 2, 3, 4, 2, 3});
    node<int> *sub = tolist<int>({2, 3});
    removesub (l, sub);
    CHECK(tovector(l) == std::vector<int>{1, 4});
}

#endif
