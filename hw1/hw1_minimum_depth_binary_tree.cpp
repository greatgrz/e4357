//This is a problem from Leetcode 
//So basically the problem can be described as 
//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

//please note the main function and the test vectors are not included in the program

//Auther: Ruizhen Guo
//Date: 2014/10/11

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        int min_all = 1;  // minimum depth of all paths 
		int min_cur = 1;  // depth of the current path
		if (root == NULL) {
		    return 0;
		}
		else {
			firstInitialize(root, min_all); //a function to get a proper initial value for min_all, preventing from the scenario when min_all is initialized too small compared with a relatively large binary tree
		    minPath(root, min_all, min_cur);//a recursive func to get the minimum depth
		    return min_all;
		}
    }

	void firstInitialize(TreeNode *root, int& min_all) {
		if (root->left != NULL) {
			min_all ++ ; 
			firstInitialize(root->left, min_all);
			return;
		}
		else if (root->right != NULL){
		    min_all ++ ; 
		    firstInitialize(root->right, min_all);
			return;
		}
		else {
		    return;
		}
	}
	void minPath(TreeNode *root, int& min_all, int min_cur) {

		if (root->left != NULL && root->right !=NULL) {
			min_cur ++ ;
			minPath(root->left, min_all, min_cur);
			minPath(root->right, min_all, min_cur);
			return;
		}
		else if (root->left == NULL && root->right !=NULL) {
			min_cur ++;
			minPath(root->right, min_all, min_cur);
			return;
		}
		else if (root->left != NULL && root->right ==NULL) {
			min_cur ++;
			minPath(root->left, min_all, min_cur);
		}
		else if (root->left == NULL && root->right ==NULL) {
			if (min_cur < min_all ){
					min_all = min_cur;
			}
	//		min_cur--;
			return;
		}
	}
};
