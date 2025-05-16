#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        sort(potions.begin(), potions.end());  
        
        vector<int> result;
        for (int spell : spells) {
            int left = 0, right = m - 1, index = m;
            while (left <= right) {
                int mid = (left + right)/2;
                if ((long long)spell * potions[mid] >= success) {
                    index = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            result.push_back(m - index);
        }

        return result;
    }
};

    