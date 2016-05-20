#include "binarysearchtree.h"


node* FindKey(node *root, int k)
{
	while ((root != 0) && (root->key != k))
	{
		if (k < root->key)
			root = root->left;
		else
			root = root->right;
	}
	if (root == 0)
		throw
		exception("Node doesn't exist");
	return root;
}

node* FindMin(node *root)
{
	if (root == 0)
		throw
		exception("You have empty tree");
	while (root->left != 0)
		root = root->left;
	return root;
}

node* FindMax(node *root)
{
	if (root == 0)
		throw
		exception("You have empty tree");
	while (root->right != 0)
		root = root->right;
	return root;
}

node* FindNext(node *_node)
{
	if (_node == 0)
		throw
		exception("You have empty tree");
	if (_node->right != 0)
		return FindMin(_node->right);
	while ((_node->parent != 0) && (_node->parent->right == _node))
		_node = _node->parent;
	if (_node->parent == 0)
		throw
		exception("Next node doesn't exist");
	return _node->parent;
}

node* FindPrevious(node *_node)
{
	if (_node == 0)
		throw
		exception("You have empty tree");
	if (_node->right != 0)
		return FindMax(_node->left);
	while ((_node->parent != 0) && (_node->parent->left == _node))
		_node = _node->parent;
	if (_node->parent == 0)
		throw
		exception("Previous node doesn't exist");
	return _node->parent;
}

void Push(node *&root, node *_node)
{
	if (root == 0)
	{
		root = _node;
		return;
	}
	node* x = root;
	node* y = new node();
	while (x != 0)
	{
		y = x;
		if (x->key <= _node->key)
			x = x->right;
		else
			x = x->left;
	}
	if (y->key <= _node->key)
		y->right = _node;
	else
		y->left = _node;
	_node->parent = y;
}

void Remove(node *&root, int k) // передали дерево и удаляемый элемент
{
	node *x = FindKey(root, k);
	if (x == 0)
		return;
	if ((x->right == 0) && (x->left == 0)) // если это лист
	{
		if (x->parent->right == x)
			x->parent->right = 0;
		else
			x->parent->left = 0;
		delete x; 
		return;
	}
	if ((x->right != 0) && (x->left == 0)) // элемент, имеющий только правого потомка
	{
		node *y = x->right;
		y->parent = x->parent;
		if (x->parent->right == x)
			x->parent->right = y;
		else
			x->parent->left = y;
		delete x;
		return;
	}
	if ((x->right == 0) && (x->left != 0)) //элемент, имеющий только левого
	{
		node *y = x->left;
		y->parent = x->parent;
		if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
		delete x;
		return;
	}
	if ((x->right != 0) && (x->left != 0)) //у элемента есть оба потомка
	{
			if (x == root) {		//логичное удаление корня дерева.
				node* y = root;
				root = FindMin(x->right);
				root->left = x->left;
				root->right = x->right;
				delete y;
				return;
			}
			
			if (x->parent->left == x) {
				node* z = FindMin(x->right);
				x->parent->left->key = FindMin(x->right)->key; // махнулись ключами
				if (z->parent->left == z)//удаляем тот, чьм заменили брешь.
					z->parent->left = 0;
				else
					z->parent->right = 0;
					
			}
			else {
				node* z = FindMin(x->right);
				x->parent->right->key = FindMin(x->right)->key;
				if (z->parent->left == z)//удаляем тот, чьм заменили брешь.
					z->parent->left = 0;
				else
					z->parent->right = 0;
			}

			
			return;
		
	}
}

void WorkAroundSearch(node *_node)
{
	if (_node == 0)
		return;
	queue<node*> q;
	q.push(_node);
	while (!q.empty())
	{
		node *tmp = q.front();
		cout << tmp->key << " ";
		q.pop();
		if (tmp->left != 0)
			q.push(tmp->left);
		if (tmp->right != 0)
			q.push(tmp->right);
	}
}

