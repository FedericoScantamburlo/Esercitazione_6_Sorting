#pragma once

#include <iostream>
#include <vector>
#include <algorithm>		

using namespace std;

namespace SortLibrary
{
	
template<typename T>						
concept sortable = requires(T& t) 			
{											
    {t < t} -> convertible_to<bool>;	
};

template<sortable T>						
vector<int> bubble_sort(vector<T>& v)			
{
    const unsigned int n = v.size();			
    for (unsigned int i = 0; i < n - 1; i++)		
    {
        for (unsigned int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])				
			{
                swap(v[j], v[j + 1]);	
            }
        }
    }
	return v;
}


template<sortable T>
void heapify(vector<T>& v, int n, int i) 														
{
    int max_node = i;					
    int l_child = 2 * i + 1;
    int r_child = 2 * i + 2;

    if (l_child < n && v[l_child] > v[max_node]) 	
	{
        max_node = l_child;
    }

    if (r_child < n && v[r_child] > v[max_node]) 
	{
        max_node = r_child;
    }

    if (max_node != i) 			
	{
        swap(v[i], v[max_node]);
        heapify(v, n, max_node);		
	}
}

template<sortable T>
vector<int> heap_sort(vector<T>& v) 
{
    int n = v.size();

    for (int i = n / 2 - 1; i >= 0; i--) 	
	{
        heapify(v, n, i);	
    }

    for (int i = n - 1; i > 0; i--) 
	{
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
	return v;
}

}


