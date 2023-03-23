#include<iostream>
#include <vector>
using namespace std;
typedef int T;
class MultiBranchTree {
public:
	MultiBranchTree(T val) {
		this->root = new TreeNode(val);
		this->cur = this->root;
		this->depth = 1;
	}
	void print() {
		TreeNode* tmp = this->root;
		dfs(tmp);
	}
	template <typename NODE>
	void dfs(NODE node) {
		if (node == nullptr) {
			return;
		}
		cout << node->val << " ";
		for (int i = 0; i < node->children.size(); i++)
		{
			dfs(node->children[i]);
		}
	}
	class TreeNode {
	public:
		TreeNode() {}
		TreeNode(T val) {
			this->val = val;
		}
		T val;
		vector<TreeNode*> children;
	private:

	};
	TreeNode* root;
	TreeNode* cur;
	int depth;

private:

};
//int main() {
//	MultiBranchTree tree(0);
//	MultiBranchTree::TreeNode node11(11);
//	MultiBranchTree::TreeNode node22(22);
//
//	tree.cur->children.push_back(&node22);
//	tree.cur->children.push_back(&node11);
//	MultiBranchTree::TreeNode node33(33);
//	tree.cur = tree.cur->children[1];
//	tree.cur->children.push_back(&node33);
//	tree.print();
//	return 0;
//}