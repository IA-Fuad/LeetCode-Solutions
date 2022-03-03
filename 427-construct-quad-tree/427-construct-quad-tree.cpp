/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    bool allCellHasSameValue(vector<vector<int>>& grid, pair<int, int> bottomLeft, pair<int, int> topRight) {
        int value = grid[bottomLeft.first][bottomLeft.second];
        for (int i = bottomLeft.first; i <= topRight.first; i++) {
            for (int j = bottomLeft.second; j <= topRight.second; j++) {
                if (grid[i][j] != value) return false;
            }
        }
        return true;
    }
    
    Node* rec(vector<vector<int>>& grid, pair<int, int> bottomLeft, pair<int, int> topRight) {
        if (topRight.first == bottomLeft.first && topRight.second == bottomLeft.second) {
            return new Node(grid[bottomLeft.first][bottomLeft.second], true);
        }
        
        int midx = (bottomLeft.first + topRight.first) / 2;
        int midy = (bottomLeft.second + topRight.second) / 2;

        auto tl = rec(grid, bottomLeft, {midx, midy}); 
        auto tr = rec(grid, {bottomLeft.first, midy + 1}, {midx, topRight.second});
        auto bl = rec(grid, {midx + 1, bottomLeft.second}, {topRight.first, midy}); 
        auto br = rec(grid, {midx + 1, midy + 1}, topRight); 

        if (tl->isLeaf and tr->isLeaf and bl->isLeaf and br->isLeaf and tl->val == tr->val and tr->val == bl->val and tl->val == br->val) {
            return new Node(tl->val, true);
        }
        
        return new Node(false, false, tl, tr, bl, br);
    }
    
public:
    Node* construct(vector<vector<int>>& grid) {
        return rec(grid, {0, 0}, {grid.size()-1, grid[0].size()-1});
    }
};