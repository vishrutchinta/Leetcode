class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        while(i<nums.size()){
            int value = abs(nums[i]);
            int indx = value-1;
            if(nums[indx]<0){
                ans.push_back(value);
            }
            else{
                nums[indx] = -nums[indx];
            }
            i++;
            
        }
        return ans;
        

        
    }
};