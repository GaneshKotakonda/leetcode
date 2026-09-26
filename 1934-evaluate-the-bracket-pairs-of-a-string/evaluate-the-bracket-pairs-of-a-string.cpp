class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;

        // Store knowledge in unordered_map
        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        vector<string> keys;
        string str = "";
        int k = 0;

        // Extract all keys from s
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                k = 1;
            }

            if (s[i] == ')') {
                k = 0;
                keys.push_back(str);
                str = "";
            }

            if (k == 1 && s[i] != '(') {
                str += s[i];
            }
        }

        // Replace keys using unordered_map
        for (int i = 0; i < keys.size(); i++) {

            if (mp.find(keys[i]) != mp.end()) {
                keys[i] = mp[keys[i]];
            }
            else {
                keys[i] = "?";
            }
        }

        // Construct final string
        k = 0;
        int j = 0;
        str = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                k = 1;
                str += keys[j++];
            }

            if (s[i] == ')') {
                k = 0;
                continue;
            }

            if (k == 0)
                str += s[i];
        }

        return str;
    }
};