class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int end = nums.size();
        for(int i=0;i<end;i++){
            nums.push_back(nums[i]);
        }
        return nums;
        
    }
};