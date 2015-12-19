#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int solution2(vector<int> & A) {
    int n = A.size();
    int result = 0;
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1])
            result = result + 1;
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        if (i > 0) {
            if (A[i - 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }
        if (i < n - 1) {
            if (A[i + 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }
        r = max(r , count);
    }
    return result + r;
}

int solution(vector<int>& A)
{
	int c1{0},maxc{0},mid_i{0};
	for(int i{0};i<A.size();i++)
	{
		if(i<A.size() && A[i]==1)
		{
			c1++;
		}
		else
		{
			maxc = max(maxc, c1);
			if(i>0 && i<A.size()-1)
			{
				if(A[i-1]==1 && A[i+1]==1)
				{
					if(mid_i>0){
						c1 = (i-mid_i-1);
					}
					mid_i = i;
				}
				else c1 = 0;
			}
			else c1 = 0;
		}
	}
	//Cover the case when the ending sequence of one's is the longest
	maxc = max(maxc, c1);
	if(c1==A.size())
		--maxc;

	return 1 + maxc;
}

int main()
{
	vector<pair<vector<int>,int>> data = {
		{{0},1},
		{{1},1},
		{{0,1},2},
		{{1,1},2},
		{{1,1,0,1,1},5},
		{{1,1,0,0,1,1},3},
		{{0,1,1,0,0,1,1,0},3},
		{{0,1,1,0,1,1,0},5},
		{{0,0,1,1,1,1,0,0,0,1,1,1,1,0,1,0,0,},6},
		{{0,1,0,1,0,1,0,1,0,1},3},
		{{1,0,1,0,1,0,0},3},
		{{0,1,0,1,1},4},
		{{0,0,0,0},1},
		{{1,1,1,1},4},
		{{1,0,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1},12},
		{{0,1,0,0,1,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},6},
		{{1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,1,0,0,1,1,1,1},10},
		{{0,0,0,0,0,0,0,0,0,0,0,0},1},
		{{1,1,1,1,1,0,0,0,0,0,},6},
		{{0,0,0,0,0,1,1,1,1,1,},6}
	};

	int tc{1};
	for(auto& e:data)
	{
		int r = solution(e.first);
		cout<<"#"<<tc<<" : "<<r<<"/"<<e.second<<" - "<<(r==e.second?"SUCCESS":"FAIL")<<endl;
		++tc;
	}
}
