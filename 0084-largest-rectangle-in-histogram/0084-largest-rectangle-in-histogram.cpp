class Solution {
public:

    vector<int> nsl(vector<int> heights){
        int n = heights.size();
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
            ans.push_back(st.top());}
            st.push(i);
        }
        return ans;
    }
    vector<int> nsr(vector<int> heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
            ans[i] = st.top();}
            st.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int area = 0;
        st.push(heights[0]);
        vector<int> sl = nsl(heights);
        vector<int> sr = nsr(heights);

        
        for(int i=0;i<heights.size();i++){
            
            if(!st.empty()){
                int sum = heights[i] * (sr[i] - sl[i] -1);
                area = max(sum,area);
            }
            
        
    }
    return area;
}
};