class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string res = "";
        char* str = (char*)s.c_str();
        char* dlim = " ";
        char* word = strtok(str,dlim);
        while(word != NULL){
            string str(word);
            words.push_back(word);
            word = strtok(NULL,dlim);
        }
        for(int i=words.size()-1;i>=0;i--){
            res += words[i];
            res += " ";
        }
        res.pop_back();
        return res;
    }
};