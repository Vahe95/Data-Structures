#ifndef BinarySearchTree_h__
#define BinarySearchTree_h__

#include <algorithm>
#include <stack>
#include <queue>

template<class T>
class BinarySearchTree
{
private:
	struct Node
	{
		T m_data;
		Node* m_left;
		Node* m_right;

		Node(const T& data = T(), Node* left = nullptr, Node* right = nullptr);
	};

private:
	Node* m_root;

public:
	BinarySearchTree();
	BinarySearchTree(std::initializer_list<T> list);
	BinarySearchTree(const BinarySearchTree& other) = delete;
	BinarySearchTree& operator=(const BinarySearchTree& other) = delete;

	void print_inorder();
	void print_postorder();
	void print_preorder();

	void dfsTravers();
	void bfsTravers();

	Node* min();
	Node* max();

	int minDepth();
	int maxDepth();

	Node* successor(Node* node);
	Node* predecessor(Node* node);

	void insert(const T& data);

	Node* findNode(const T& data);

	Node* lca(const T& data1, const T& data2);

	Node* deleteNode(const T& data);

	~BinarySearchTree();

private:
	static bool hasLeft(Node* node);
	static bool hasRight(Node* node);

	static void inorder(Node* root);
	static void postorder(Node* root);
	static void preorder(Node* root);

	static Node* minHelper(Node* root);
	static Node* maxHelper(Node* root);

	static int minDepthHelper(Node* root);
	static int maxDepthHelper(Node* root);

	static Node* successorHelper(Node* root, Node* node);
	static Node* predecessorHelper(Node* root, Node* node);

	static void insertHelper(Node* root, const T& data);

	static Node* lcaHelper(Node* root, const T& data1, const T& data2);

	static Node* deleteNodeHelper(Node* root, const T& data);

	static void clear(Node* root);

	static void underflowError();
	static void treeIsNotPlanted(Node* root);
};

template<class T>
BinarySearchTree<T>::BinarySearchTree()
	: m_root(nullptr)
{

}

template<class T>
BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> list)
	: BinarySearchTree()
{
	for (auto& element : list)
	{
		insert(element);
	}
}

template<class T>
void BinarySearchTree<T>::print_inorder()
{
	inorder(m_root);
}

template<class T>
void BinarySearchTree<T>::inorder(Node* root)
{
	if (root != nullptr)
	{
		if (root->m_left)
		{
			inorder(root->m_left);
		}

		std::cout << root->m_data << " ";

		if (root->m_right)
		{
			inorder(root->m_right);
		}
	}
	else
	{
		treeIsNotPlanted(root);
	}
}

template<class T>
void BinarySearchTree<T>::print_postorder()
{
	postorder(m_root);
}

template<class T>
void BinarySearchTree<T>::postorder(Node* root)
{
	if (root != nullptr)
	{
		if (root->m_left)
		{
			postorder(root->m_left);
		}

		if (root->m_right)
		{
			postorder(root->m_right);
		}

		std::cout << root->m_data << " ";
	}
	else
	{
		treeIsNotPlanted(root);
	}
}

template<class T>
void BinarySearchTree<T>::print_preorder()
{
	preorder(m_root);
}

template<class T>
void BinarySearchTree<T>::preorder(Node* root)
{
	if (root != nullptr)
	{
		std::cout << root->m_data << " ";

		if (root->m_left)
		{
			preorder(root->m_left);
		}

		if (root->m_right)
		{
			preorder(root->m_right);
		}
	}
	else
	{
		treeIsNotPlanted(root);
	}
}

template<class T>
void BinarySearchTree<T>::dfsTravers()
{
	std::stack<Node*> pendingNodes;

	pendingNodes.push(m_root);

	while (pendingNodes.size() > 0)
	{
		Node* current = pendingNodes.top();

		std::cout << current->m_data << " ";

		pendingNodes.pop();

		if (hasLeft(current))
		{
			pendingNodes.push(current->m_left);
		}

		if (hasRight(current))
		{
			pendingNodes.push(current->m_right);
		}
	}
}

template<class T>
void BinarySearchTree<T>::bfsTravers()
{
	std::queue<Node*> pendeingNodes;

	pendeingNodes.push(m_root);

	while (pendeingNodes.size() > 0)
	{
		Node* current = pendeingNodes.front();

		pendeingNodes.pop();

		if (hasLeft(current))
		{
			pendeingNodes.push(current->m_left);
		}

		if (hasRight(current))
		{
			pendeingNodes.push(current->m_right);
		}

		std::cout << current->m_data << " ";
	}
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::min()
{
	return minHelper(m_root);
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::minHelper(Node* root)
{
	treeIsNotPlanted(root);

	Node* tmp = root;

	while (hasLeft(tmp))
	{
		tmp = tmp->m_left;
	}

	return tmp;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::max()
{
	return maxHelper(m_root);
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::maxHelper(Node* root)
{
	treeIsNotPlanted(root);

	Node* tmp = root;

	while (hasRight(tmp))
	{
		tmp = tmp->m_right;
	}

	return tmp;
}

template<class T>
int BinarySearchTree<T>::minDepth()
{
	return minDepthHelper(m_root);
}

template<class T>
int BinarySearchTree<T>::minDepthHelper(Node* root)
{
	if (root == nullptr)
	{
		return -1;
	}

	if (root->m_right == nullptr && root->m_left == nullptr)
	{
		return 0;
	}

	if (root->m_left == nullptr)
	{
		return minDepthHelper(root->m_right) + 1;
	}

	if (root->m_right == nullptr)
	{
		return minDepthHelper(root->m_left) + 1;
	}

	return std::min(minDepthHelper(root->m_left), minDepthHelper(root->m_right)) + 1;
}

template<class T>
int BinarySearchTree<T>::maxDepth()
{
	return maxDepthHelper(m_root);
}

template<class T>
int BinarySearchTree<T>::maxDepthHelper(Node* root)
{
	if (root == nullptr)
	{
		return -1;
	}

	int lDepth = maxDepthHelper(root->m_left);
	int rDepth = maxDepthHelper(root->m_right);

	return lDepth > rDepth ? lDepth + 1 : rDepth + 1;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::successor(Node* node)
{
	return successorHelper(m_root, node);
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::successorHelper(Node* root, Node* node)
{
	treeIsNotPlanted(root);

	if (hasRight(node))
	{
		return minHelper(node->m_right);
	}

	Node* tmp = nullptr;

	while (root != nullptr)
	{
		if (node->m_data < root->m_data)
		{
			tmp = root;
			root = root->m_left;
		}
		else if (node->m_data > root->m_data)
		{
			root = root->m_right;
		}
		else
		{
			break;
		}
	}

	return tmp;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::predecessor(Node* node)
{
	return predecessorHelper(m_root, node);
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::predecessorHelper(Node* root, Node* node)
{
	treeIsNotPlanted(root);

	if (hasLeft(node))
	{
		return maxHelper(node->m_left);
	}

	Node* tmp = nullptr;

	while (root != nullptr)
	{
		if (node->m_data < root->m_data)
		{
			root = root->m_left;
		}
		else if (node->m_data > root->m_data)
		{
			tmp = root;
			root = root->m_right;
		}
		else
		{
			break;
		}
	}

	return tmp;
}

template<class T>
void BinarySearchTree<T>::insert(const T& data)
{
	if (m_root == nullptr)
	{
		m_root = new Node(data, nullptr, nullptr);
	}
	else
	{
		insertHelper(m_root, data);
	}
}

template<class T>
void BinarySearchTree<T>::insertHelper(Node* root, const T& data)
{
	if (data < root->m_data)
	{
		if (hasLeft(root))
		{
			insertHelper(root->m_left, data);
		}
		else
		{
			root->m_left = new Node(data, nullptr, nullptr);
		}
	}
	else
	{
		if (hasRight(root))
		{
			insertHelper(root->m_right, data);
		}
		else
		{
			root->m_right = new Node(data, nullptr, nullptr);
		}
	}
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findNode(const T& data)
{
	Node* root = m_root;

	while (root != nullptr)
	{
		if (root->m_data == data)
		{
			return root;
		}
		else if (root->m_data > data)
		{
			root = root->m_left;
		}
		else
		{
			root = root->m_right;
		}
	}

	return nullptr;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::lca(const T& data1, const T& data2)
{
	return lcaHelper(m_root, data1, data2);
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::lcaHelper(Node* root, const T& data1, const T& data2)
{
	treeIsNotPlanted(root);

	if (root->m_data > data1 && root->m_data > data2)
	{
		return lcaHelper(root->m_left, data1, data2);
	}

	if (root->m_data < data1 && root->m_data < data2)
	{
		return lcaHelper(root->m_right, data1, data2);
	}

	return root;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::deleteNode(const T& data)
{
	return deleteNodeHelper(m_root, data);
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::deleteNodeHelper(Node* root, const T& data)
{
	if (root == nullptr)
	{
		underflowError();
	}
	else if (data < root->m_data)
	{
		root->m_left = deleteNodeHelper(root->m_left, data);
	}
	else if (data > root->m_data)
	{
		root->m_right = deleteNodeHelper(root->m_right, data);
	}
	else
	{
		if (root->m_right == nullptr && root->m_left == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->m_left == nullptr)
		{
			Node* tmp = root;
			root = root->m_right;
			delete tmp;
		}
		else if (root->m_right == nullptr)
		{
			Node* tmp = root;
			root = root->m_left;
			delete tmp;
		}
		else
		{
			Node* tmp = minHelper(root->m_right);

			root->m_data = tmp->m_data;

			root->m_right = deleteNodeHelper(root->m_right, tmp->m_data);
		}
	}

	return root;
}

template<class T>
void BinarySearchTree<T>::clear(Node* root)
{
	if (root != nullptr)
	{
		clear(root->m_left);
		clear(root->m_right);
		delete root;
	}
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	clear(m_root);
}

template<class T>
bool BinarySearchTree<T>::hasLeft(Node* node)
{
	return node->m_left != nullptr;
}

template<class T>
bool BinarySearchTree<T>::hasRight(Node* node)
{
	return node->m_right != nullptr;
}

template<class T>
BinarySearchTree<T>::Node::Node(const T& data /*= T()*/, Node* left /*= nullptr*/, Node* right /*= nullptr*/)
	: m_data(data)
	, m_left(left)
	, m_right(right)
{

}

template<class T>
void BinarySearchTree<T>::underflowError()
{
	std::string exception = std::string("Tree is Cut!");
	throw std::underflow_error(exception);
}

template<class T>
void BinarySearchTree<T>::treeIsNotPlanted(Node* root)
{
	if (root == nullptr)
	{
		std::string exception = std::string("The Tree is Not Planted!");
		throw std::runtime_error(exception);
	}
}

#endif // BinarySearchTree_h__