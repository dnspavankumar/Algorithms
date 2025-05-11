class Solution {
public:
    int maxRepeating(string sequence, string word) {
       int count = 0;
        string repeated = word;

        while (sequence.find(repeated) != string::npos) {
            count++;
          //try to find word*2
            repeated += word;
        }

        return count;
    }
};
