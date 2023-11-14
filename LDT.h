                                             /***** Lazy Deletion Tree *****/

/*A lazy - deletion binary search tree is a binary search tree where erased objects are simply tagged as erased 
while the nodes themselves remain in the tree.Occasionally, a member function may be called to clean up(delete) all erased nodes at once.
Almost all functions will be implemented by calling the corresponding function on the root node.*/

#pragma once
#include <iostream>
using namespace std;

template <typename DataType>
class LDT
{
public:
	                                            /***** Function Members *****/
	LDT();
	 //Construct a LDT object.
	void inorder(ostream & out) const; //need fix
	void insertx(DataType const &);     //need change
	bool empty() const;
	//Return true if the tree is empty(the size is 0).

	int size() const;
    //Returns the number of nodes in the tree not including nodes tagged as erased.

	int height() const;
	//Returns the height of the tree including nodes tagged as erased.

	bool member(DataType const &obj) const;
	//Return true if the argument is in the tree and not tagged as erased and false otherwise. 

	DataType front() const;
	/*Return the minimum non - erased object of this tree by calling front on the root node.
	The object will be the first argument of a pair (*, true) returned by the node member function, 
	and will throw an exception underflow if the second for (*, false) (the tree has size zero). 
	Hint: What type of traversal will you need? Under what conditions do you continue searching, 
	and under what conditions do you return?*/

	DataType back() const;
	/*Return the maximum non - erased object of this tree by calling back on the root node. 
	The object returned will be a pair of the form (*, true); return the first object. 
	This member function may throw an underflow exception if the tree has zero size.*/

	bool insert(DataType const &);
	/*Insert the new object into the tree: If the object is already in the tree and not tagged as erased, 
	return false and do nothing; if the object is already in the tree but tagged as erased, untag it and return true; 
	if the object is not in the tree, create a new leaf node in the appropriate location and return true. 
	If the root node is nullptr, this requires the creation of a new root node; otherwise, 
	the corresponding function is called on the root node.*/

	bool erase(DataType const &);
	/*Removes the object from the tree: If the object is not already in the tree, return false; 
	if the object is in the tree but tagged as erased, return false; if the object is in the tree and not tagged as erased, 
	tag it as erased and return true. If the root node is nullptr, all that is done is that false is returned; otherwise, 
	the corresponding function is called on the root node.*/

	void clear();
	//Delete all the nodes in the tree.

	void clean();
	//Delete all nodes tagged as deleted within the tree following the description found in the lazy - deletion node class.



private:
	                                                   /***** Node class *****/
	class Node
	{
	public:
		DataType data;
		Node * left;
		Node * right;
		bool erased;

		//--- Definition of Node constructor
		Node()
			: left(0), right(0), erased(false)
		{}

		Node(DataType item)
			: data(item), left(0), right(0), erased(false)
		{}

	}; // end of class Node declaration

	typedef Node * NodePointer;

	                                    /***** Private Function Members *****/
	void inorderAux(ostream & out,
		LDT<DataType>::NodePointer subtreePtr) const;
	
	int heightaux(NodePointer mr) const;
	//Returns the height of the tree including nodes tagged as erased.

	                                                 /***** Data Members *****/
	NodePointer myRoot; 
	//A pointer to the root node.
	int count;          
	//A variable storing the number of non-erased objects in the tree.

}; 

//--- Definition of LDT constructor
template <typename DataType>
inline LDT<DataType>::LDT()
	: myRoot(0), count(0)
{}

//--- Definition of empty()
template <typename DataType>
inline bool LDT<DataType>::empty() const
{
	return myRoot == 0;
}

//--- Definition of size()
template<typename DataType>
inline int LDT<DataType>::size() const
{
	if (empty()) return 0;
	else return count;
}

template<typename DataType>
inline int LDT<DataType>::heightaux(LDT<DataType>::NodePointer myRoot) const {
	if (myRoot == NULL) return 0;
	int l = heightaux(myRoot->left);
	int r = heightaux(myRoot->right);
	if (l > r) return l + 1;
	else return r + 1;
}

template<typename DataType>
inline int LDT<DataType>::height() const {
	if (empty()) return 0;
    else return	heightaux(myRoot);
}


template<typename DataType>
inline bool LDT<DataType>::member(DataType const & obj) const
{
	return false;
}

template<typename DataType>
inline DataType LDT<DataType>::front() const
{
	return DataType();
}

template<typename DataType>
inline DataType LDT<DataType>::back() const
{
	return DataType();
}

template<typename DataType>
inline bool LDT<DataType>::insert(DataType const &)
{
	return false;
}

//--- Definition of insertx()
template<typename DataType>
inline void LDT<DataType>::insertx(const DataType & item)
{
	LDT<DataType>::NodePointer
		locptr = myRoot,   // search pointer
		parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in LDT
	while (!found && locptr != 0)
	{
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	if (!found)
	{                                 // construct node containing item
		locptr = new LDT<DataType>::Node(item);
		
		if (parent == 0)               // empty tree
			myRoot = locptr;
		else if (item < parent->data)  // insert to left of parent
			parent->left = locptr;
		else                           // insert to right of parent
			parent->right = locptr;
	}
	else {
		cout << "Item already in the tree\n";
	}
}


template<typename DataType>
inline bool LDT<DataType>::erase(DataType const &)
{
	return false;
}

template<typename DataType>
inline void LDT<DataType>::clear()
{
}

template<typename DataType>
inline void LDT<DataType>::clean()
{
}

//--- Definition of inorder()
template <typename DataType>
inline void LDT<DataType>::inorder(ostream & out) const
{
	inorderAux(out, myRoot);
}



//--- Definition of inorderAux()
template <typename DataType>
void LDT<DataType>::inorderAux(ostream & out, LDT<DataType>::NodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		inorderAux(out, subtreeRoot->left);    // L operation
		out << subtreeRoot->data << "  ";      // V operation
		inorderAux(out, subtreeRoot->right);   // R operation
	}
}

