class Solution {
public:

    vector<int> ngll(vector<int>& height){
        vector<int> ans;
        int runningMax = height[0];
        int size = height.size()-1;
        for(int i=0;i<=size;i++){
            runningMax = max(runningMax, height[i]);
            ans.push_back(runningMax);
        }
        return ans;
    }
    vector<int> ngrr(vector<int>& height){
        vector<int> ans;
        int runningMax = height[height.size()-1];
        int i = height.size()-1;
        int size = 0;
        while(i>=size){
            runningMax = max(runningMax, height[i]);
            ans.push_back(runningMax);
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int trap(vector<int>& height) {
        int area = 0;
        int sum;

        vector<int> ngl = ngll(height);
        vector<int> ngr = ngrr(height);
        int size = ngl.size()-1;
        for(int i=0;i<=size;i++){
            sum = min(ngl[i], ngr[i]) - height[i];
            area += sum;
        }
        return area;

    }
};