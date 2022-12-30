#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <utility>

/**
 * This is a template file for all leetcode problems
 * Author: @ Mohammad Arafat Zaman
*/

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}" << endl; }

template <class T, class S> void print_map(map<T, S>& _m) { cout << "{ "; for (auto & n : _m) { cout << n.first << " = " << n.second << ", "; } cout << "\b }" << endl; }

template <class T>
void print_pq(priority_queue<vector<int>, vector<vector<int>>, T> &pq ) {
    vector<vector<int>> temp;
    // Pop and print
    while(!pq.empty()) {
        vector<int> a = pq.top();
        pq.pop();
        temp.push_back(a);
        print_v(a);
    };
    // And back
    for (auto &v : temp) {
        pq.push(v);
    };
};

#define PI = 3.141592653589793

class comp_tasks {
    public:
    bool operator()(vector<int> a, vector<int> b) {
        return a[0] > b[0];
    }
};

class comp_avail_tasks {
    public:
    bool operator()(vector<int> a, vector<int> b) {
        if (a[1] > b[1]) {
            return true;
        } else if (a[1] == b[1]) {
            return a[2] > b[2];
        } else {
            return false;
        }
    }
};

class Solution {
    public:
    vector<int> getOrder(vector<vector<int>>& tasks) { 
        int n = tasks.size();

        for (int i = 0; i < n; ++i) {
            tasks[i].push_back(i);
        }

        priority_queue<vector<int>, vector<vector<int>>, comp_tasks> _task(tasks.begin(), tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, comp_avail_tasks> available_tasks;
        vector<int> orders;

        long long int time = 0;
        int currTaskTime = 0;
        bool doing_task = false;
        pair<int, int> doingCurrTask;

        while (!_task.empty() || !available_tasks.empty()) {

            if (!_task.empty()) {
                vector<int> currTask = _task.top();

                while (time >= currTask[0]) {
                    available_tasks.push(currTask);
                    _task.pop();
                    if (!_task.empty()) {
                        currTask = _task.top();
                    } else {
                        break;
                    }
                };
            }

            if (!available_tasks.empty()) {
                vector<int> topTask = available_tasks.top();
                available_tasks.pop();

                orders.push_back(topTask[2]);
                time += (long long int)topTask[1]-1;
            }

            // if (doing_task) {
            //     currTaskTime++;
            //     if (currTaskTime >= doingCurrTask.second) {
            //         currTaskTime = 0;
            //         doing_task = false;
            //         doingCurrTask = {};
            //     }
            // }
            
            // if (!available_tasks.empty() && !doing_task) {
            //     vector<int> topTask = available_tasks.top();
            //     orders.push_back(topTask[2]);
            //     available_tasks.pop();
            //     doingCurrTask = {topTask[0], topTask[1]};
            //     doing_task = true;
            // }
            
            time++;
        } 

        return orders;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;

    vector<vector<int>> a = {{1,2},{2,4},{3,2},{4,1}};
    //vector<vector<int>> b = {{7,10},{7,12},{7,5},{7,4},{7,2}};

    vector<int> ans = solver.getOrder(a);

    print_v(ans);


    
    return 0;
}

