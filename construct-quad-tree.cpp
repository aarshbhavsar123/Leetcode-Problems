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
public:
    Node* construct(vector<vector<int>>& grid) {
        Node* temp = NULL;
        int n = grid.size();
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==0)
                count++;
            }
        }
        if(count==n*n)
        {
            temp = new Node(0,1);
            return temp;
        }
        if(count==0)
        {
            temp = new Node(1,1);
            return temp;
        }
        temp = new Node(1,0);
        int hs = n/2;
        vector<vector<int>>tl(hs,vector<int>(hs)),tr(hs,vector<int>(hs)),bl(hs,vector<int>(hs)),br(hs,vector<int>(hs));
        
        for(int i = 0;i<hs;i++)
        {
            for(int j = 0;j<hs;j++)
            {
                tl[i][j] = grid[i][j];
                tr[i][j] = grid[i][j+hs];
                bl[i][j] = grid[i+hs][j];
                br[i][j] = grid[i+hs][j+hs];
            }
        }
        temp->topLeft = construct(tl);
        temp->topRight = construct(tr);
        temp->bottomLeft = construct(bl);
        temp->bottomRight = construct(br);
        return temp;
    }
};