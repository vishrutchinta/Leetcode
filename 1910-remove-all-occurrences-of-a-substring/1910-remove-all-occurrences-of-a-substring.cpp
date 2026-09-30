class Solution {
public:
    string removeOccurrences(string s, string part){
        int arr[26] = {0};
        int end = s.size();
        
        int i=0;
        for (char ch : s){
            if(s.find(part) < end){
                s.erase(s.find(part),part.size());
            }
        }

            


        
        return s;
    }
};