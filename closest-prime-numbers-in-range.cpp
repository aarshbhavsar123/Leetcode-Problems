#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> vis(1e6+1, false);
        vis[0] = vis[1] = true;

        
        for(int i = 2; i * i < vis.size(); i++) {
            if (!vis[i]) {
                for(int j = i * i; j < vis.size(); j += i) {
                    vis[j] = true;
                }
            }
        }

        vector<int> primes;
        for(int i = left; i <= right; i++) {
            if (!vis[i]) {
                primes.push_back(i);
            }
        }

        
        if (primes.size() < 2) {
            return {-1, -1};
        }

        
        int minDiff = INT_MAX;
        pair<int, int> closestPair = {-1, -1};
        for(int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i+1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                closestPair = {primes[i], primes[i+1]};
            }
        }

        return {closestPair.first, closestPair.second};
    }
};


