#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

/**
 * This is a template file for all leetcode problems
 * Author: @ Mohammad Arafat Zaman
*/

using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl 

template <class T> void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}" << endl; }

template <class T, class S>
void print_map(map<T, S>& _m) {
    cout << "{ ";
    for (auto & n : _m) {
        cout << n.first << " = " << n.second << ", ";
    }
    cout << "\b }" << endl;
}

#define PI = 3.141592653589793


// https://leetcode.com/problems/odd-even-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode* oddNodeHead = new ListNode(head->val);
        ListNode* evenNodeHead = new ListNode(head->next->val);
        
        head = head->next->next;
        int i = 3;
        ListNode* odd = oddNodeHead;
        ListNode* even = evenNodeHead;
        while (head != nullptr) {
            ListNode* next = new ListNode(head->val);
            if (i % 2 == 0) {
                even->next = next;
                even = even->next;
            } else {
                odd->next = next;
                odd = odd->next;
            }
            i++;
            head = head->next;
        };

        odd->next = evenNodeHead;

        return oddNodeHead;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Run tests
    Solution solver;


    
    return 0;
}

