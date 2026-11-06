class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        int rows = arr.size();
        int col = arr[0].size();
        int cs = 0;
        int rs = 0;
        int re = rows-1;
        int ce = col-1;
        while(cs<=ce && rs<=re){
            //top
        for(int j=cs;j<=ce;j++){
            ans.push_back(arr[rs][j]);
        }
        //right
        for(int j=rs+1;j<=re;j++){
            ans.push_back(arr[j][ce]);
        }
        //bottom
        if(rs<re){
        for(int j=ce-1;j>=cs;j--){
            ans.push_back(arr[re][j]);
        }
        }
        
        //left
        if(cs<ce){
        for(int j=re-1;j>rs;j--){
            ans.push_back(arr[j][cs]);
        }
        }

        rs++;
        cs++;
        re--;
        ce--;
        }
        return ans;





        }
    
};