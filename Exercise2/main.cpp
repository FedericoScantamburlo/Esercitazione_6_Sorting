#include <cmath> 
#include <iostream>
#include <numeric> 
#include <iostream>
#include <sstream>
#include <chrono>

#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& elm : v)		
        toString << elm << " ";
    toString << "]";

    return toString.str();
}

struct ClassObj			
{    
	double value;
};

inline bool operator< (const ClassObj& lhs, const ClassObj& rhs) 
{
	return lhs.value < rhs.value; 
}		
	
	
int main(int argc, char *argv[])
{
    cout << "argc: " << argc << endl;
    for(int a = 0; a < argc; a++)
        cout << argv[a] << " ";
    cout << endl;

    size_t m = 10;	
    if(argc > 1)
    {
        istringstream convert(argv[1]);	
        convert >> m;					
        cout << "use value: "  << m << endl;
    }
    else
        cerr << "use default value: "  << m << endl;

    vector<int> v1(m);						
    std::iota(v1.begin(), v1.end(), -4); 
	
    srand(3);
	vector<int> v2(m);
    for(size_t i = 0; i < m; i++)	
        v2[i] = rand();			

    vector<int> v3(m, 0);							
    for(size_t i = floor(m * 0.5) + 2; i < m; i++)
        v3[i] = rand() % 1000;	

    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 2, v3.begin());


	cout << "v1: " << ArrayToString(v1) << endl;
	cout << "v2: " << ArrayToString(v2) << endl;
	cout << "v3: " << ArrayToString(v3) << endl;

	//calcolo dei tempi:
    // https://www.epochconverter.com/	
    const auto today_time = std::chrono::system_clock::now();		
    std::cout << "Tempo trascorso dal 1 gennaio 1970: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(today_time.time_since_epoch()).count() << endl;


    unsigned int n_exp = 100;

    double time_elapsed_bubble_sort_v1 = 0.0;				
    for(unsigned int t = 0; t < n_exp; t++)
    {
        vector<int> v(v1);		
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();		
        SortLibrary::bubble_sort<int>(v1);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();	
        time_elapsed_bubble_sort_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
	}
    time_elapsed_bubble_sort_v1 /= n_exp;	

    cout << "Bubble Sort - v1 (microseconds): " << time_elapsed_bubble_sort_v1 << endl;

    double time_elapsed_bubble_sort_v2 = 0.0;
    for(unsigned int t = 0; t < n_exp; t++)
    {
        vector<int> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::bubble_sort<int>(v2);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_sort_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_sort_v2 /= n_exp;

    cout << "Bubble Sort - v2 (microseconds): " << time_elapsed_bubble_sort_v2 << endl;


    double time_elapsed_bubble_sort_v3 = 0.0;
    for(unsigned int t = 0; t < n_exp; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::bubble_sort<int>(v3);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_bubble_sort_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_sort_v3 /= n_exp;

    cout << "Bubble Sort - v3 (microseconds): " << time_elapsed_bubble_sort_v3 << endl;

    double time_elapsed_heap_sort_v1 = 0.0;
    for(unsigned int t = 0; t < n_exp; t++)
    {
        vector<int> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::heap_sort<int>(v1);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_sort_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_sort_v1 /= n_exp;

    cout << "Heap Sort - v1 (microseconds): " << time_elapsed_heap_sort_v1 << endl;

    double time_elapsed_heap_sort_v2 = 0.0;
    for(unsigned int t = 0; t < n_exp; t++)
    {
        vector<int> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::heap_sort<int>(v2);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_sort_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_sort_v2 /= n_exp;

    cout << "Heap Sort - v2 (microseconds): " << time_elapsed_heap_sort_v2 << endl;


    double time_elapsed_heap_sort_v3 = 0.0;
    for(unsigned int t = 0; t < n_exp; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::heap_sort<int>(v3);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_heap_sort_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_sort_v3 /= n_exp;

    cout << "Heap Sort - v3 (microseconds): " << time_elapsed_heap_sort_v3 << endl;


    return 0;
}
