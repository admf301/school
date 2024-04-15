//bstree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <cassert>

using namespace std;

template <class K, class V>
struct node
{
	K key;
	V value;
	node<K,V>* left;
	node<K,V>* right;

	node(const K& key = K(), const V& value = V(), node<K,V>* left = nullptr, node<K,V>* right = nullptr)
	{
		this->key = key;
		this->value = value;
		this->left = left;
		this->right = right;
	}

};

template <class K, class V>
class bstree;

template <class K, class V>
class bstree
{

protected:

	node<K,V>* root;
	size_t t_size;
	void insert_f(const K& x, const V& v, node<K,V>* &ptr);
	void remove_f(const K& x, node<K,V>* &ptr);
	node<K,V>* find_min(node<K,V>* ptr) const;
	node<K,V>* find_max(node<K,V>* ptr) const;
	node<K,V>* find(const K& x, node<K,V>* ptr) const;
	void clear_f(node<K,V>* &ptr);
	void clone(node<K,V>* &ptr, node<K,V>* other);
	int find_height(node<K,V>* ptr, int level) const;
	int find_size(node<K,V>* ptr) const;

public:

	bstree();
	~bstree();
	bstree(const bstree<K,V>& x);
	bstree<K,V>& operator=(const bstree<K,V>& x);
	void clear();
	size_t size() const;
	size_t height() const;
	bool empty() const;
	const K& min() const;
	const K& max() const;
	void insert(const K& key, const V& value);
	bool remove(const K& key);
	const node<K,V>* find(const K& key) const;
	void preorder() const;
	void inorder() const;
	void postorder() const;
	void level_order() const;
};

//default constructor
template <class K, class V>
bstree<K,V>::bstree()
{
	root = nullptr;
	t_size = 0;
}

//destructor
template <class K, class V>
bstree<K,V>::~bstree()
{
	clear();
}

template <class K, class V>
void bstree<K,V>::clone(node<K,V>* &ptr, node<K,V>* other)
{
	if(other != nullptr)
	{
		node<K,V>* left = nullptr;
		node<K,V>* right = nullptr;
		clone(left, other->left);
		clone(right, other->right);
		ptr = new node<K,V>(other->key, other->value, left, right);
	}
}

template <class K, class V>
bstree<K,V>::bstree(const bstree<K,V>& x)
{
	*this = x;
}

template <class K, class V>
bstree<K,V>& bstree<K,V>::operator=(const bstree<K,V>& x)
{
	clear();
	clone(root, x.root);
	return *this;
}

template <class K, class V>
void bstree<K,V>::clear_f(node<K,V>* &ptr)
{
	if(ptr != nullptr)
	{
		clear_f(ptr->left);
		clear_f(ptr->right);
		delete ptr;

		if(ptr->left != nullptr)
		{
			ptr->left = nullptr;
		}

		if(ptr->right != nullptr)
		{
			ptr->right = nullptr;
		}

		ptr = nullptr;
	}
}

template <class K, class V>
void bstree<K,V>::clear()
{
	clear_f(root);
}

template <class K, class V>
int bstree<K,V>::find_size(node<K,V>* ptr) const
{
	if(ptr == nullptr)
	{
		return 0;
	}

	else
	{
		return 1 + find_size(ptr->left) + find_size(ptr->right);
	}
}

template <class K, class V>
size_t bstree<K,V>::size() const
{
	return find_size(root);
}

template <class K, class V>
int bstree<K,V>::find_height(node<K,V>* ptr, int level) const
{
	static int max_level = 0;
	if(ptr == nullptr)
	{
		if(level > max_level)
		{
			max_level = level;
		}
	}

	else
	{
		find_height(ptr->left, level + 1);
		find_height(ptr->right, level + 1);
	}

	return max_level;
}

template <class K, class V>
size_t bstree<K,V>::height() const
{
	return find_height(root, 0);
}

template <class K, class V>
bool bstree<K,V>::empty() const
{
	return(root == nullptr);
}

template <class K, class V>
node<K,V>* bstree<K,V>::find_min(node<K,V>* ptr) const
{

	return nullptr;
}

template <class K, class V>
node<K,V>* bstree<K,V>::find_max(node<K,V>* ptr) const
{

	return nullptr;
}

template <class K, class V>
const K& bstree<K,V>::min() const
{
	return 1;
}

template <class K, class V>
const K& bstree<K,V>::max() const
{
	return 1;
}

template <class K, class V>
void bstree<K,V>::insert_f(const K& x, const V& v, node<K,V>* &ptr)
{
	if(ptr == nullptr)
	{
		ptr = new node<K,V>(x, v, nullptr, nullptr);
	}

	else
	{
		if(ptr->key == v.key)
		{
			ptr->value = v;
		}

		else if(ptr->key > v.key)
		{
			insert_f(x, v, ptr->left);
		}

		else
		{
			insert_f(x, v, ptr->right);
		}
	}
}

template <class K, class V>
void bstree<K,V>::insert(const K& key, const V& value)
{
	insert_f(key, value, root);
}

template <class K, class V>
bool bstree<K,V>::remove(const K& key)
{
	return false;
}

template <class K, class V>
const node<K,V>* bstree<K,V>::find(const K& key) const
{
	return nullptr;
}

template <class K, class V>
void bstree<K,V>::preorder() const
{

}

template <class K, class V>
void bstree<K,V>::inorder() const
{

}

template <class K, class V>
void bstree<K,V>::postorder() const
{

}

template <class K, class V>
void bstree<K,V>::level_order() const
{

}

#endif

