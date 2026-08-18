class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size()-1;
        vector<vector<int>> temp2;
        sort(nums.begin(),nums.end());
        int target = 0;
        while(target<=size && size>1){
            if (target > 0 && nums[target] == nums[target - 1]){ 
            target++;
            continue;}
            int st = target+1;
            int end = size;
            int t = -(nums[target]);
            while(st<end){
            if(nums[st]+nums[end]==t){
                
                temp2.push_back({nums[target],nums[st],nums[end]});
                while (st < end && nums[st] == nums[st + 1]) st++;
                while (st < end && nums[end] == nums[end - 1]) end--;
                st++;
                end--;
                
                
            }
            else if(nums[st]+nums[end]<t && st<end){
                st++;
            }
            else if(nums[st]+nums[end]>t && st<end){
                end--;
            }
            }
            target++;
            

        }
        return temp2;
        
    }
};