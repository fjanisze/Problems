#include <iostream>
using namespace std;

int input[ 1001 ];
int data[ 2002 ];
int raw[ 1001 ];

int main()
{
	int tc{ 0 },cred{ 0 },num{ 0 }, price{ 0 };
	cin >> tc;
	int tcc = 1;
	while( tcc <= tc ) {
		for(int i{ 0 } ; i < 2002 ; ++i ) {
			if( i < 1001 ) {
				input[i] = 0;
				raw[i] = 0;
			}
			data[ i ] = 0;
		}
		cin >> cred;
		cin >> num;
		for(int i{ 0 } ; i < num ; ++i ) {
			cin >> price;
			++input[ price ];
			raw[ i ] = price;
		}
		int cur{ 0 };
		for(int i { 0 } ; i < 1001; ++i ) {
			if( input[ i ] > 0 ) {
				for(int j{ 0 } ; j < input[ i ] ; ++j ) {
					data[ cur++ ] = i;
				}
			}
		}
		//Now find the solution
		for(int i{ 0 } ; i < num ; ++i ) {
			int rem = cred - data[ i ];
			if( rem <= 0 ) continue;
			int l{ 0 },r{ num - 1 },m;
			while( l <= r ) {
				m = ( l + r ) / 2;
				if( data[ m ] == rem ) break;
				else if( data[ m ] > rem )
					r = m - 1;
				else
					l = m + 1;
			}
			if( i != m && data[ i ] + data[ m ] == cred ) {
				int out[2];
				out[0] = -1;
				out[1] = -1;
				for(int k { 0 } ;  k < num ; ++k ) {
					if( out[0] < 0 && data[ i ] == raw[ k ] ) {
						out[0] = k + 1;
						if( out[0] > 0 && out[1] > 0 ) break;
					}
					else if( out[1] < 0 && data[ m ] == raw[ k ] ) {
						out[1] = k + 1;
						if( out[0] > 0 && out[1] > 0 ) break;
					}
				}
				std::cout<<"Case #"<<tcc<<": "<<std::min( out[0], out[1] )<<" "<<
					std::max( out[0],out[1] )<<std::endl;
				break;
			}
		}
		++tcc;
	}
}
