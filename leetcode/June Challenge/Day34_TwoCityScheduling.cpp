// https://leetcode.com/explore/featured/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/
// M1 - O(nlogn) time complexity and O(n) space Complexity
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        multimap <int, int> cost;
        int ans = 0;
        for (int i=0; i<n; i++) {
            cost.insert({costs[i][0]-costs[i][1], i});
        }
        multimap <int, int>:: iterator it;
        it = cost.begin();
        for (int i=0; i<n; i++) {
            if(i<n/2) {
                ans += costs[it->second][0];
            }else{
                 ans += costs[it->second][1];
            }
            it ++;
        }
        return ans;
    }
};

//M2 - O(nlogn) Time Complexity and O(1) Space Complexity
bool comp(vector<int> x,vector <int> y) {
        return (x[0]-x[1]) < (y[0] - y[1]);
    }
class Solution {
    
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int ans=0;
        sort(costs.begin(), costs.end(),comp);
        for (int i=0; i<n; i++) {
            if(i<n/2) {
                ans += costs[i][0];
            } else{
                ans += costs[i][1];
            }
        }
        return ans;
    }
   
};
