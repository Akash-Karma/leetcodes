class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, maxi=0,ans=0;
        unordered_map <int,int> mp;
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            ans++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                ans--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            maxi=max(maxi,ans);
        }
        return maxi;
        
    }
};