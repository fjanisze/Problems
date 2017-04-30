//From code Jam, Problem A. Ample Syrup
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

constexpr long double pi = 3.141592653589793238462643383279502884;

struct pan
{
    long r;
    long double tot_h;
    long double tot_area;
};

pan data[ 1001 ];

long sz;
long n,k;

int main()
{
    long tc;
    cin >> tc;
    for( long t{ 1 } ; t <= tc; ++t )
    {
	cin >> n >> k;
	long r,h;
	for( long i { 0 } ; i < n ; ++i) {
	    cin >> r >> h;
	    pan new_pan;
	    new_pan.r = r;
	    new_pan.tot_h = 2 * pi * h * r;
	    new_pan.tot_area = r * r * pi + new_pan.tot_h;
	    data[i] = new_pan;
	}
	std::sort(data,data + n,[](const pan& a,const pan& b){ return a.r < b.r; });
	//Sorted by r, increasing order
	long double res{ 0 };
	long double out{ 0 };
	for( long i { k - 1 } ; i < n ; ++i )
	{
	    res = data[ i ].tot_area;
	    std::vector<pan> t_set;
	    for( long j { i - 1 } ; j >= 0 ; --j ) {
		t_set.emplace_back( data[ j ] );
	    }
	    std::sort(t_set.begin(),t_set.end(),[](const pan& a,const pan& b){ return a.tot_h > b.tot_h; });
	    for( long j {0} ; j < k - 1 ; ++j)
	    {
		res += t_set[j].tot_h;
	    }
	    out = max( out , res );
	}
	std::cout<<"Case #"<<t<<": "<<std::setprecision(20)<<out<<std::endl;
    }
}
