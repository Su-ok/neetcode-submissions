class Solution {
public:
    unordered_map<int,bool> mp;
    bool dfs(vector<int>& nums, int i) {
        int n=nums.size();
        if(i==n-1) return true;
        if(mp.count(i)) return mp[i];
        if(nums[i]==0) return false;
        int end=i+nums[i];

        for(int j=i+1; j<=end; j++) {
            if(dfs(nums, j)) return mp[i]=true;
        }

        return mp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int goal=n-1;
        
        int i=n-2;
        while(i>=0) {
            if(goal<=i+nums[i]) {
                goal=i;
            }
            i--;
        }

        return goal==0;
    }
};
