class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int end = s.size();
        int maxc=0;
        int arr[256] = {0};
        int i=0;
        int j=0;
        int sum = 0;
        while(i<end){
            int ch = (unsigned char)s[i];  
            arr[ch]++;
            sum++;
            if(arr[ch]>1){
                sum=0;
                j++;
                i = j;
                for(int k=0;k<256;k++){
                    arr[k] =0;
                }
                continue;
            }
            maxc = max(sum,maxc);
            i++;
        }
        return maxc;
        
    }
};