class Solution {
public:
    stack<char> process(const string& s) {
        stack<char> result;

        for(char ch : s) {
            if (ch != '#') {
                result.push(ch);
            } else if(!result.empty()) {
                result.pop();
            }
        }
        return result;
    }
    bool backspaceCompare(string s, string t) {
        stack<char> str = process(s);
        stack<char> ttr = process(t);

        while(!str.empty() && !ttr.empty()) {
            if(str.top() != ttr.top()) {
                return false;
            }
            str.pop();
            ttr.pop();
        }
        return str.empty() && ttr.empty();
    }
};