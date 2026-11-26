class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max = 0;
        int size = nums.size()-1;
        while(!nums.empty()){
            
            if(nums[size]==1){
                count++;
                if(count>max){
                    max = count;
                }
            }
            else{
                count = 0;
            }
            nums.pop_back();
            size--;
        }
        return max;
        
    }
};