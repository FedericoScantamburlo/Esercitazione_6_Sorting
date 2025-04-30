#pragma once

#include <iostream>
#include <vector>

#include <gtest/gtest.h>
#include "SortingAlgorithm.hpp"

namespace SortLibrary 
{

TEST(test_sorting, Test_bubble_sort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    bubble_sort<int>(v);
    std::vector<int> v_sorted = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, v_sorted);
}

TEST(test_sorting, test_heap_sort)
{
    std::vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
    heap_sort<int>(v);
    std::vector<int> v_sorted = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
    EXPECT_EQ(v, v_sorted);
}

}