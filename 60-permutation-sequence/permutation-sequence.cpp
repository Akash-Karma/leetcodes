class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        k--;
        string ans = "";
        int fact = 1;
        for(int i = 1; i<n; i++){
            numbers.push_back(i);
            fact *= i;
        }
        numbers.push_back(n);
        while(true){
            ans += to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0) break;
            k %= fact;
            fact = fact/numbers.size();
        }
        return ans;
    }
};