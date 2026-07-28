class Solution {
public:
    string reverseWords(string s) {
        string sr;
        string rev = "";
        string word = "";
        int i =0;
        while(i<s.size()){
            if(word.empty() == false && char(s[i]) == ' '){
                rev = (word+" ") + rev;
                 
                word = ""; 
            }
            
            else if(char(s[i]) != ' '){
                word += char(s[i]);
                
                
            }
            i++;
            
        }
        if(!word.empty()){
            rev = (word+" ") + rev;
            }
        
        if(!rev.empty() && rev.back() == ' '){
            rev.pop_back();   
        }
        return rev;
    }
};