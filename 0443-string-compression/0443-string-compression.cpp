class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        for (int i = 0; i < chars.size(); i++) {
            int count = 0;
            int j = i;
            while (j < chars.size() && chars[j] == chars[i]) {
                count++;
                j++;
            }
            ans.push_back(chars[i]);
            if (count > 1) {
                for (char c : to_string(count)) {
                    ans.push_back(c);
                }
            }
            i = j - 1;
        }
        chars = ans;
        return ans.size();
    }
};