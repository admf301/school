
#ifndef H_BTREE
#define H_BTREE

#include "node.h"

template <typename T> class BinaryTree
{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

typedef enum {left_side, right_side} SIDE;
SIDE rnd()
{
	return rand()%2 ? right_side : left_side;
}

/*
* Default constructor
*
******************************************************************************/
template <class T>
BinaryTree<T>::BinaryTree()
{
	root = 0;
}

/*
* public getSize function
*
* @return size of binary tree
******************************************************************************/
template <class T>
unsigned BinaryTree<T>::getSize() const
{
	return _getSize(root);
}

/*
* public getHeight function
*
* @return height of binary tree
******************************************************************************/
template <class T>
unsigned BinaryTree<T>::getHeight() const
{
	return _getHeight(root);
}

/*
* public Insert function
*
* inserts a node into the binary tree
******************************************************************************/
template <class T>
void BinaryTree<T>::Insert(const T& temp)
{
	_Insert(root, temp);
}

/*
* public Inorder function
*
* performs a inorder travsersal of the binary tree
******************************************************************************/
template <class T>
void BinaryTree<T>::Inorder(void (*print)(const T&))
{
	_Inorder(root, print);
}

/*
* private getSize function
*
* if the binary tree has more than 0 nodes, this function counts the number of
* nodes in both sides of the tree
*
* @return the number of nodes in the tree
******************************************************************************/
template <class T>
unsigned BinaryTree<T>::_getSize(Node<T>* ptr) const
{
	if(ptr == 0)
	{
		return 0;
	}

	else
	{
		unsigned l_size = _getSize(ptr->left);
		unsigned r_size = _getSize(ptr->right);

		return 1 + l_size + r_size;
	}
}

/*
* private getHeight function
*
* if the binary tree has more than 0 nodes, this function counts the number
* of nodes in both sides of the tree. then returns the larger of the 2 sides
*
* @return the height of the binary tree
******************************************************************************/
template <class T>
unsigned BinaryTree<T>::_getHeight(Node<T>* ptr) const
{
	if(ptr == 0)
	{
		return 0;
	}

	else
	{
		unsigned l_height = _getHeight(ptr->left);
		unsigned r_height = _getHeight(ptr->right);

		if(l_height > r_height)
		{
			return 1 + l_height;
		}

		else
		{
			return 1 + r_height;
		}
	}
}

/*
* private Insert function
*
* inserts new nodes into the tree by using the given rnd() function to determine
* which side of the tree a node is inserted into
******************************************************************************/
template <class T>
void BinaryTree<T>::_Insert(Node<T>* &node, const T& temp)
{
	if(node == 0)
	{
		Node<T>* new_node;
		new_node = new Node<T>(temp);
		node = new_node;
	}

	else
	{
		unsigned random = rnd();


		if(random == 0)
		{
			_Insert(node->left, temp);
		}

		else
		{
			_Insert(node->right, temp);
		}
	}
}

/*
* private Inorder function
*
* if the binary tree exists, this function performs an inorder travsersal of
* the tree
******************************************************************************/
template <class T>
void BinaryTree<T>::_Inorder(Node<T>* node, void (*print)(const T&))
{
	if(node != NULL)
	{
		_Inorder(node->left, print);
		print(node->data);
		_Inorder(node->right, print);
	}
}

#endif // End of H_BTREE
