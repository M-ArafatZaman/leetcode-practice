#include <bits/stdc++.h>
using namespace std;

template <class T, class S>
void print_map(unordered_map<T, S>& _m) { 
    cout << "{ ";
    for (auto & n : _m) {
        cout << n.first << " = [" << n.second.first << ", " << n.second.second << "], ";
    } 
    cout << "\b }" << endl;
}


// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
    public:
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        int highest = 0;
        int newCount, prevClusterLen, nextClusterLen;
        for (int i : nums) {
            // If i exists and neighbours exists
            if (mp.find(i) != mp.end()) {
                continue;
            }
            // No neighbours
            else if (mp.find(i-1) == mp.end() && mp.find(i+1) == mp.end()) {
                mp[i] = {i, 1};
            }
            // Joining two disjoint sets
            else if (mp.find(i-1) != mp.end() && mp.find(i+1) != mp.end()) {
                prevClusterLen = mp[i-1].second;
                nextClusterLen = mp[i+1].second;
                newCount = prevClusterLen + 1 + nextClusterLen;
                // Update the previous/root cluster
                mp[i - prevClusterLen].second = newCount; // Left most node of the prev cluster
                mp[i-1] = {i-prevClusterLen, newCount}; // Right most node of the prev cluster
                // The current node
                mp[i] = {i - prevClusterLen, newCount};
                // Update the next clustor
                mp[i+1] = {i - prevClusterLen, newCount}; // Left most node of the next cluster
                mp[i + nextClusterLen] = {i - prevClusterLen, newCount}; // Right most node of the next cluster
            }
            // Previous number is in set
            else if (mp.find(i-1) != mp.end() && mp.find(i+1) == mp.end()) {
                prevClusterLen = mp[i-1].second;
                newCount = prevClusterLen + 1;

                mp[i - prevClusterLen].second = newCount; // Left most node of the cluster
                mp[i] = {i - prevClusterLen, newCount}; // Right most node of the cluster
            }
            // Next number is in set
            else if (mp.find(i-1) == mp.end() && mp.find(i+1) != mp.end()) {
                nextClusterLen = mp[i+1].second;
                newCount = nextClusterLen + 1;

                mp[i] = {i, newCount}; // Left most node
                mp[i + nextClusterLen] = {i, newCount}; // Right most node
            }

            highest = max(mp[mp[i].first].second, highest);
            
        };

        
        return highest;
    }
};

int main() {
    Solution sol;
    vector<int> a = {100,4,200,1,3,2}; // => 4
    vector<int> b = {0,3,7,2,5,8,4,6,0,1}; // 0 0 1 2 3 4 5 6 7 8 => 9
    vector<int> c = {1,2,0,1}; // 0 1 1 2 => 3
    vector<int> d = {1,3,5,2,4}; // => 5
    vector<int> e = {-4,-1,4,-5,1,-6,9,-6,0,2,2,7,0,9,-3,8,9,-2,-6,5,0,3,4,-2}; // -6, -6, -6, -5, -4, -3, -2, -2, -1, 0, 0, 0, 1, 2, 2, 3, 4, 4, 5, 7, 8, 9, 9, 9 => 12

    cout << sol.longestConsecutive(a) << endl;
    cout << sol.longestConsecutive(b) << endl;
    cout << sol.longestConsecutive(c) << endl;
    cout << sol.longestConsecutive(d) << endl;
    cout << sol.longestConsecutive(e) << endl;

    return 0;
}