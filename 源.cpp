#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>num;
        for (auto i : grid)
            for (int j : i)
                num.push_back(j);
        int length = num.size();
        k = k % length;        
        for (int i = 0; i < k; i++) {
            int temp = num[length - 1];
            num.insert(num.begin(), temp);
            num.pop_back();
       }
        int s = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size();j++) {
                grid[i][j] = num[s];
                s++;
            }
        return grid;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<int>> ans = sol.shiftGrid(grid, 2);
    for (auto i : ans)
        for (auto j : i)
            cout << j << "  ";
    return 0;
}