/*
 *
 * BASE ON HIGHEST AC% TO LOWEST AC%
 *
 */

//Single Number: Given an array of integers, 
//              every element apperas twice exept for one. 
//              Find that singal one

class Solution {
public: 
    int singleNumber( int A[], int n) {
        int x = 0;
        for(size_t i = 0; i < n; ++i) {
            x = x ^ A[i];
        }
        return x;
    }
}

//Maximum Depth of Binary Tree

/*
 * struct TreeNode {
 *      int val;
 *      TreeNode * left;
 *      TreeNode * right;
 *      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if( root == NULL) {
            return 0;
        }
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};

// Same Tree
class Solution {
public: 
    bool isSameTree(TreeNode *p, TreeNode *p) {
        if(!p && !q) {
            return true;
        }

        if(!p || !q) {
            return false;
        }

        return p -> val == q -> val
            && isSameTree(p -> left, q -> left) 
            && isSameTree(p -> right, q -> right);
    }
}


//Reverse Integer
class Solution {
    public:
        int reverse(int x) {
            int r = 0;
            for( ; x; x /= 10) { // each time divide by 10 then return digit
                r = r*10 + x%10; // recompute the value.
            }
            return r;
        }
}

//Best time to buy and sell stock II 
class Solution {
    public: 
        int maxProfit(vector <int> &prices) {
            int sum = 0;
            for(int i = 1; i < price.size(); i++) {
                int diff = prices[i] - price[i-1];
                if(diff > 0) {
                    sum += diff;
                }
            }
            return sum;
        }
}
//
//

