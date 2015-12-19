#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			vector<int> dp(nums.size(),0);
			int ans{1};
			dp[0] = nums[0];
			for(int i{1};i<nums.size();i++){
				if(nums[i] < dp[0]){
					dp[0] = nums[i];
				}
				if(nums[i] > dp[ans-1]){
					//Just happend the new value
					dp[ans++] = nums[i];
				}else{
					int l{0},r{ans-1};
					while(l<r)
					{
						int m{(l+r)/2};
						if(dp[m]>=nums[i])
						{
							r = m ;
						}else{
							l = m + 1;
						}
					}
					dp[r] = nums[i];
				}
			}
			return ans;
		}
};

int main()
{
	vector<int> data = {10, 9, 2, 5, 3, 7, 101, 18};
	Solution sol;
	cout<<sol.lengthOfLIS(data)<<endl;;
}
