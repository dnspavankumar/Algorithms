 bool even(int num){
        return num%2==0;
    }
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        
        // Count frequencies of even numbers
        for (int num : nums) {
            if (even(num)) {
                m[num]++;
            }
        }

        int maxFreq = 0;
        int ans = -1;

        // Find the most frequent even number, choosing the smallest in case of a tie
        for (auto& pair : m) {
            int num = pair.first;
            int freq = pair.second;

            if (freq > maxFreq || (freq == maxFreq && num < ans)) {
                ans = num;
                maxFreq = freq;
            }
        }

        return ans;
