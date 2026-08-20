class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int nsize = nums.size();
        int minz = nums[0]+nums[1]+nums[2];
        int minx=0;
        for(int i=0;i<nsize;i++){
            int st = i+1;
            int end = nsize-1;
            
            while(st<end){
                
            int sum = nums[i]+nums[st]+nums[end];
            int diff = sum-target;
                if(abs(diff) < abs(minz-target)){
                    minz = sum;
                }
                if(sum<target){
                    st++;
                }
                else if(sum>target){
                    end--;
                }
                else{
                    return sum;
                }
                
            }
            

        }
        return minz;
        
    }
};