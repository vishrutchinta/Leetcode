class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int count = 0;
        int srow = 0;
        int scol = 0;
        int erow = n-1;
        int ecol = n-1;
        while(scol <= ecol && srow <= erow){
            for(int i = scol;i<=ecol;i++){
                count++;
                matrix[srow][i] = count;
                
            }
            srow++;
            for(int i = srow;i<=erow;i++){
                count++;
                matrix[i][ecol] = count;
            }
            ecol--;
            if (srow <= erow) {
            for(int i = ecol;i>=scol;i--){
                count++;
                matrix[erow][i] = count;
            }
            erow--;
            }
            if(scol<=ecol){
            for(int i=erow;i>=srow;i--){
                count++;
                matrix[i][scol] = count;
            }
            scol++;
            }

        }
        return matrix;
    }
};