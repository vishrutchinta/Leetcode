class Solution {
public:
    int search(vector<int>& ans, int k) {
        int i = 0;
        int st = 0;
        int end = ans.size()-1;
        int fi = end;
        while(st<=end){
            int mid = (st+end)/2;
            if(ans[mid] == k){
                return mid;
            }
            else if(ans[st]<=ans[mid]){
                if(ans[st] <=k && k<ans[mid]){
                    end = mid-1;
                }
                else{
                st = mid+1;
                }
            }
            else if(ans[mid]<=ans[end]){
                if(ans[mid]<=k && k<=ans[end]){
                    st = mid;
                }
                else{
                end = mid-1;
                }
            }

        }
        return -1;

    }
};