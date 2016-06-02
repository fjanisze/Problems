#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <type_traits>
using namespace std;

using ll = long long;


template<long n>
struct fibonacci_nth : std::integral_constant<long, fibonacci_nth<n-1>() + fibonacci_nth<n-2>()>
{};

template<>
struct fibonacci_nth<1> : std::integral_constant<long,1>{};
template<>
struct fibonacci_nth<0> : std::integral_constant<long,0>{};

template<long n>
struct fibonacci_template
{
    static const long value = fibonacci_template<n-1>::value + fibonacci_template<n-2>::value;
};


template<>
struct fibonacci_template<1>
{
    static const long value = 1;
};

template<>
struct fibonacci_template<0>
{
    static const long value = 0;
};


int main()
{
    cout<<fibonacci_nth<10>::value<<" "<<fibonacci_template<10>::value<<endl;
}

