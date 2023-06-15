#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool getPath(TreeNode<int>* root, int x, vector<int>& path){
	if(root == NULL)
		return false;

	path.push_back(root->data);

	if(root->data == x)//Node found
		return true;

	if(getPath(root->left,x,path) || getPath(root->right,x,path))
		return true;
	path.pop_back();//backtrack step
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> path;
	if(root == NULL)return path;
	getPath(root,x,path);
	return path;
}
