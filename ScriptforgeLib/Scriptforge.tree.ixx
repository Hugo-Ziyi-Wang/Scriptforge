export module Scriptforge.tree;
import std;

namespace Scriptforge::Tree {
	template<typename T>requires requires(T t1, T t2) { t1 = t2; }
	class Tree {
	private:
		struct TreeNode;
	public:
		using nodeptr = std::shared_ptr<TreeNode>;
		Tree();
		explicit Tree(const T& node);
		nodeptr root() const;
		nodeptr del(nodeptr node);
		nodeptr add(nodeptr father);
		nodeptr add(nodeptr father, T& node);
		nodeptr add(nodeptr father, const T& node);
	private:
		struct TreeNode
		{
			TreeNode() = default;
			explicit TreeNode(T& v);
			explicit TreeNode(const T& v);
			std::weak_ptr<TreeNode> father;
			std::vector<nodeptr> children;
			T node;
		};
		nodeptr m_root;
	};
	
}