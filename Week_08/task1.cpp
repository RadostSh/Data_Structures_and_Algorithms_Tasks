class Solution {
public:
    size_t getValue(char ch) {
        switch(ch) {
            case 'A': return 0; break;
            case 'C': return 1; break;
            case 'G': return 2; break;
            case 'T': return 3; break;
        }
        return 0;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        const size_t LEN = 10;
        if(s.size() < LEN) {
            return {};
        }

        size_t hash = 0;
        for(int i = 0; i < LEN; i++) {
            hash *= 4;
            hash += getValue(s[i]);
        }

        vector<string> result;
        unordered_map<size_t, size_t> hashCounter;
        hashCounter[hash] = 1;

        size_t oldNumberMult = pow(4, LEN - 1);
        for(size_t i = LEN; i < s.size(); i++) {
            hash -= oldNumberMult * getValue(s[i - LEN]);
            hash *= 4;
            hash += getValue(s[i]);

            if(hashCounter[hash] == 1) {
                result.push_back(s.substr(i - LEN + 1, LEN));
            }
            hashCounter[hash]++;
        }
        return result;
    }
};