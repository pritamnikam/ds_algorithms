#include <iostream>

#include <algorithm>

using namespace std;

/*

10.2.7. Implementation of Balanced Binary Search Trees
http://www.cs.ecu.edu/karl/3300/spr16/Notes/DataStructure/Tree/balance2.html#:~:text=%20Implementation%20of%20Balanced%20Binary%20Search%20Trees%20,subtree%20%20of%20a%20node%20is...%20More

Getting the height
A critical issue in keeping a tree height-balanced is how to determine the height
of a node. It will not do to compute the height by examining the entire tree,
since that costs far to much. We need to get the height of a node very quickly.

To than end, let's store the height of each node in the node.
Then all we need to do is be sure to keep the stored height up to date when
making changes. Here is the new Node type, along with a function to compute the
height of a tree and one to install the correct height into a node.


*/

struct Node;
typedef Node* Tree;

int height(const Tree T);

struct Node
{
    int   item;      // Information at this node
    int   ht;        // height of this node
    Node* left;      // The left subtree
    Node* right;     // The right subtree

    Node(int it, Node* lft, Node* rgt)
    {
        item = it;
        left = lft;
        right = rgt;
        ht = 1 + max(height(lft), height(rgt));
    }
};

//==========================================
//               height
//==========================================
// height(T) returns the height of tree T.
//
// Requirement: If T is nonempty, then the
// ht field has already been set correctly
// T.
//==========================================

int height(const Tree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        return T->ht;
    }
}

//==========================================
//               installHeight
//==========================================
// installHeight(T) sets T->ht to the
// height of T.
//
// Requirements:
//   (1) T is not empty.
//   (2) The ht field has already been set
//       correctly in every node of each
//       subtree of T.
//==========================================

void installHeight(Tree T)
{
    T->ht = 1 + max(height(T->left), height(T->right));
}
/*
Rotations
*/

//==========================================
//              singleRotateLeft
//==========================================
// singleRotateLeft(T) performs a single
// rotation from right to left at the
// root of T.
//==========================================

void singleRotateLeft(Tree& T)
{
    Tree r = T->right;
    T->right = r->left;
    installHeight(T);

    r->left = T;
    T = r;
    installHeight(T);
}

//==========================================
//              singleRotateRight
//==========================================
// singleRotateRight(T) performs a single
// rotation from left to right at the
// root of T.
//==========================================

void singleRotateRight(Tree& T)
{
    Tree L = T->left;
    T->left = L->right;
    installHeight(T);

    L->right = T;
    T = L;
    installHeight(T);
}

//==========================================
//              doubleRotateLeft
//==========================================
// doubleRotateLeft(T) performs a double
// rotation from right to left at the
// root of T.
//==========================================

void doubleRotateLeft(Tree& T)
{
    singleRotateRight(T->right);
    singleRotateLeft(T);
}

//==========================================
//              doubleRotateRight
//==========================================
// doubleRotateRight(T) performs a double
// rotation from left to right at the
// root of T.
//==========================================

void doubleRotateRight(Tree& T)
{
    singleRotateLeft(T->left);
    singleRotateRight(T);
}

//==========================================
//              rotateLeft
//==========================================
// rotateLeft(T) performs a rotation from
// from right to left at the root of T, 
// choosing a single or double rotation.
//==========================================

void rotateLeft(Tree& T)
{
    Tree r = T->right;
    int  zag = height(r->left);
    int  zig = height(r->right);

    if (zig > zag)
    {
        singleRotateLeft(T);
    }
    else
    {
        doubleRotateLeft(T);
    }
}

//==========================================
//              rotateRight
//==========================================
// rotateRight(T) performs a rotation from
// from left to right at the root of T, 
// choosing a single or double rotation.
//==========================================

void rotateRight(Tree& T)
{
    Tree L = T->left;
    int  zig = height(L->left);
    int  zag = height(L->right);

    if (zig > zag)
    {
        singleRotateRight(T);
    }
    else
    {
        doubleRotateRight(T);
    }
}

//==========================================
//              rebalance
//==========================================
// rebalance(T) does the following.
//
//   (1) Perform a rotation at T if required.
//
//   (2) Set the ht field of T correctly,
//       regardless of whether or not a
//       rotation is done.
//
// Requirement: T must not be empty.
//==========================================

void rebalance(Tree& T)
{
    int hl = height(T->left);
    int hr = height(T->right);

    if (hr > hl + 1)
    {
        rotateLeft(T);
    }
    else if (hl > hr + 1)
    {
        rotateRight(T);
    }
    else
    {
        installHeight(T);
    }
}

/*
Insertion
Inserting with rebalancing is just the basic algorithm, but with a call to
rebalance each time a subtree of a node is modified.
*/

//=================================================
  //                insert
  //=================================================
  // insert(x,T) inserts x into binary search tree T.
  // If x is already a member of T, it does nothing.
  //
  // This function rebalances T after the insertion
  // if necessary.  It requires that T is
  // height-balanced when insert is called.
  //=================================================

void insert(int x, Tree& T)
{
    if (T == NULL)
    {
        T = new Node(x, NULL, NULL);
    }
    else if (x < T->item)
    {
        insert(x, T->left);
        rebalance(T);
    }
    else if (x > T->item)
    {
        insert(x, T->right);
        rebalance(T);
    }
}

/*
Deletion
For removeSmallest and remove, start with the basic functions, but rebalance
any time a subtree of a node is modified.
*/

//====================================================
  //               removeSmallest
  //====================================================
  // removeSmallest(T) removes the smallest value from
  // binary search tree T and returns the value that
  // was removed.
  //
  // Requirement: T must not be an empty tree.
  //
  // This function rebalances T after removing the 
  // smallest value, if necessary.  It requires that T
  // is height-balanced when removeSmallest is called.
  //====================================================

int removeSmallest(Tree& T)
{
    if (T->left == NULL)
    {
        int  result = T->item;
        Tree p = T;

        T = T->right;   // subtrees are already balanced.
        delete p;
        return result;
    }
    else
    {
        int result = removeSmallest(T->left);
        rebalance(T);
        return result;
    }
}

//====================================================
//                remove
//====================================================
// remove(x,T) removes x from binary search tree T.
// If x is not in T, it does nothing.
//
// This function rebalances T after removing x,
// if necessary.  It requires that T is height-balanced
// when remove is called.
//====================================================

void remove(int x, Tree& T)
{
    if (T != NULL)
    {
        if (x < T->item)
        {
            remove(x, T->left);
            rebalance(T);
        }
        else if (x > T->item)
        {
            remove(x, T->right);
            rebalance(T);
        }
        else if (T->left == NULL)
        {
            Tree p = T;
            T = T->right;
            delete p;
        }
        else if (T->right == NULL)
        {
            Tree p = T;
            T = T->left;
            delete p;
        }
        else {
            T->item = removeSmallest(T->right);
            rebalance(T);
        }
    }
}