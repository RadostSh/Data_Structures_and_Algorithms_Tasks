class Solution {
public:
    string removeStars(string str) {
     stack<char> s;
     for(auto ch:str) {
        if(ch != '*') {
            s.push(ch);
        } else{
            if(!s.empty()) {
             s.pop();
         }
        }
     }

     str = "";

     while(!s.empty()) {
        str += s.top();
        s.pop();
     }
    reverse(str.begin(), str.end());
    return str;

    }
};