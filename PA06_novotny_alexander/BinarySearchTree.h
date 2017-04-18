#pragma once

#include <memory>
#include <iostream>
#include <string>

template<class ItemType>
class BinarySearchTree
{
    protected:
        template<class NodeType>
        struct BinaryNode
        {
            ItemType value;
            std::shared_ptr<BinaryNode<NodeType>> left = nullptr;
            std::shared_ptr<BinaryNode<NodeType>> right = nullptr;

            void print ( std::ostream& out, bool isLeft, std::string indent) const
            {
                if ( right != nullptr ) right->print ( out, false, indent + ( isLeft ? " |    " : "      " ) );
                out << indent;
                if ( isLeft )
                {
                    out << " \\";
                }
                else
                {
                    out << " /";
                }
                out << "--- " << value << '\n';
                if ( left != nullptr ) left->print ( out, true, indent + ( isLeft ? "      " : " |    " ) );
            }
        };

        typedef std::shared_ptr<BinaryNode<ItemType>> NodePtr;

        auto placeNode ( NodePtr treePtr,
                         NodePtr newNodePtr );
        auto removeValue ( NodePtr treePtr,
                           const ItemType& target,
                           bool& isSuccessful );
        auto removeNode ( NodePtr nodePtr );
        auto removeLeftMostNode ( NodePtr treePtr,
                                  ItemType& inorderSuccesor );
        auto findNode ( NodePtr treePtr,
                        const ItemType& target ) const;

        int getHeightFrom ( NodePtr treePtr ) const;
        int getSizeFrom ( NodePtr treePtr ) const;

        void preorder ( void visit ( ItemType& ), NodePtr treePtr ) const;
        void inorder ( void visit ( ItemType& ), NodePtr treePtr ) const;
        void postorder ( void visit ( ItemType& ), NodePtr treePtr ) const;

    private:
        NodePtr rootPtr;

    public:
        BinarySearchTree ();
        BinarySearchTree ( const ItemType& root );
        BinarySearchTree ( const BinarySearchTree<ItemType>& tree );
        ~BinarySearchTree ();

        bool isEmpty () const;
        int getHeight () const;
        int getNumberOfNodes () const;
        ItemType getRootData () const;
        void setRootData ( const ItemType& newData );
        bool add ( const ItemType& newEntry );
        bool remove ( const ItemType& target );
        void clear ();
        ItemType getEntry ( const ItemType& anEntry ) const;
        bool contains ( const ItemType& anEntry ) const;

        void preorderTraverse ( void visit ( ItemType& ) ) const;
        void inorderTraverse ( void visit ( ItemType& ) ) const;
        void postorderTraverse ( void visit ( ItemType& ) ) const;

        BinarySearchTree<ItemType>& operator=( const BinarySearchTree<ItemType>& newTree );

        template<class Test>
        friend std::ostream& operator<<( std::ostream& out, const BinarySearchTree<Test>& outTree );
};

// PROTECTED METHODS //////////////////////////////////////////////////////////

template<class ItemType>
auto BinarySearchTree<ItemType>::placeNode ( NodePtr treePtr,
                                             NodePtr newNodePtr )
{
    //If this root is empty, place our new node here
    if ( treePtr == nullptr )
    {
        return newNodePtr;
    }
    //Otherwise, place it to the right if it's greater than our root value
    else if ( treePtr->value < newNodePtr->value )
    {
        treePtr->right = placeNode ( treePtr->right, newNodePtr );
    }
    //Otherwise, place it to the left
    else
    {
        treePtr->left = placeNode ( treePtr->left, newNodePtr );
    }

    return treePtr;
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeValue ( NodePtr treePtr,
                                               const ItemType& target,
                                               bool& isSuccessful )
{
    NodePtr nodePtr;
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode ( NodePtr nodePtr )
{
    //TODO
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeLeftMostNode ( NodePtr treePtr,
                                                      ItemType& inorderSuccesor )
{
    //TODO
}

template<class ItemType>
auto BinarySearchTree<ItemType>::findNode ( NodePtr treePtr,
                                            const ItemType& target ) const
{
    if ( treePtr == nullptr ) return treePtr;

    if ( target > treePtr->value ) return findNode ( treePtr->right, target );
    else if ( target < treePtr->value ) return findNode ( treePtr->left, target );
    else return treePtr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeightFrom ( NodePtr treePtr ) const
{
    if ( treePtr == nullptr )
    {
        return 0;
    }
    else
    {
        int leftHeight = getHeightFrom ( treePtr->left );
        int rightHeight = getHeightFrom ( treePtr->right );
        return 1 + ( leftHeight > rightHeight ? leftHeight : rightHeight );
    }
}

template<class ItemType>
int BinarySearchTree<ItemType>::getSizeFrom ( NodePtr treePtr ) const
{
    if ( treePtr == nullptr ) return 0;

    return 1 + getSizeFrom ( treePtr->left ) + getSizeFrom ( treePtr->right );
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorder ( void visit ( ItemType& ), NodePtr treePtr ) const
{
    if ( treePtr == nullptr ) return;

    visit ( treePtr->value );
    preorder ( visit, treePtr->left );
    preorder ( visit, treePtr->right );
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorder ( void visit ( ItemType& ), NodePtr treePtr ) const
{
    if ( treePtr == nullptr ) return;

    inorder ( visit, treePtr->left );
    visit ( treePtr->value );
    inorder ( visit, treePtr->right );
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorder ( void visit ( ItemType& ), NodePtr treePtr ) const
{
    if ( treePtr == nullptr ) return;

    postorder ( visit, treePtr->left );
    postorder ( visit, treePtr->right );
    visit ( treePtr->value );
}

// PUBLIC METHODS /////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree () : rootPtr (nullptr)
{}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree ( const ItemType& root )
{
    rootPtr = new BinaryNode<ItemType>;
    rootPtr->value = root;
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree ( const BinarySearchTree<ItemType>& tree )
{
    //TODO
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree ( )
{
    //TODO
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty () const
{
    return rootPtr == nullptr;
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight () const
{
    return getHeightFrom ( rootPtr );
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes () const
{
    return getSizeFrom ( rootPtr );
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData () const
{
    if ( rootPtr == nullptr ) throw "There is no root data";
    return rootPtr->value;
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData ( const ItemType& newData )
{
    if ( rootPtr == nullptr )
    {
        rootPtr = new BinaryNode<ItemType>;
    }

    //Why is this something we would ever want to do?
    //It sounds like a really bad idea in the case of a Binary Search Tree
    rootPtr->value = newData;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add ( const ItemType& newItem )
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>> ();
    newNodePtr->value = newItem;

    rootPtr = placeNode ( rootPtr, newNodePtr );

    return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove ( const ItemType& target )
{
    //TODO
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear ()
{
    //TODO
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry ( const ItemType& anEntry ) const
{
    std::auto_ptr<BinaryNode<ItemType>> entry = findNode ( rootPtr, anEntry );
    if ( entry == nullptr ) throw "Entry could not be found";
    return *entry;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains ( const ItemType& anEntry ) const
{
    return (findNode ( rootPtr, anEntry ) != nullptr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse ( void visit ( ItemType& ) ) const
{
    preorder ( visit, rootPtr );
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse ( void visit ( ItemType& ) ) const
{
    inorder ( visit, rootPtr );
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse ( void visit ( ItemType& ) ) const
{
    postorder ( visit, rootPtr );
}

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=( const BinarySearchTree<ItemType>& newTree )
{
    //TODO
}

template<class ItemType>
std::ostream& operator<<( std::ostream& out, const BinarySearchTree<ItemType>& outTree )
{

    outTree.rootPtr->print ( out, true, "" );
    return out;
}