class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ptr1=0, ptr2=0;

        while(ptr1<g.size() && ptr2<s.size()){
            if(g[ptr1] <= s[ptr2]){
                ptr1++;
                ptr2++;
            }
            else ptr2++;
        }
        return ptr1;
    }
};