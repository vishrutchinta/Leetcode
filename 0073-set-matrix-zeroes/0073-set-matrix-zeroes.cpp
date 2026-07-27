class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        
        vector<bool> posi(rows, false);  
        vector<bool> posj(col, false);    
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    posi[i] = true;
                    posj[j] = true;
                }
            }
        }
        for(int i=0;i<rows;i++){
            
            for(int j=0;j<col;j++){
                if(posi[i]){
                    matrix[i][j] = 0;
                }
                if(posj[j]){
                    matrix[i][j] = 0;
                }
                
            }
        }
    }
};