#ifndef __PROB5_TESTS_H
#define __PROB5_TESTS_H

#include "doctest.h"
#include "test_utils.hpp"

TEST_CASE("Empty list")
{
    //must not crash
    CHECK (dupsub<int>(nullptr,5) == false);
}

TEST_CASE("Two subslists")
{
    node<int> *l = tolist<int>({1, 2, 2, 3, 2, 2, 7});
    CHECK (dupsub(l,1) == true);
    CHECK (dupsub(l,2) == true);
    CHECK (dupsub(l,3) == false);
}

TEST_CASE("With first")
{
    node<int> *l = tolist<int>({2, 2, 3, 2, 2, 7});
    CHECK (dupsub(l,2) == true);
    CHECK (dupsub(l,3) == false);
}

TEST_CASE("With last")
{
    node<int> *l = tolist<int>({2, 2, 3, 2, 2});
    CHECK (dupsub(l,2) == true);
    CHECK (dupsub(l,3) == false);
}

TEST_CASE("Intertwined")
{
    node<int> *l = tolist<int>({1, 1, 1, 1, 3, 4});
    CHECK (dupsub(l,2) == true);
    CHECK (dupsub(l,3) == false);
    CHECK (dupsub(l,4) == false);
}

#endif
