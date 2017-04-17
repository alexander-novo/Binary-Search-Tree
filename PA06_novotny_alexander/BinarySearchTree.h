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

        auto placeNode ( std::shared_ptr<BinaryNode<ItemType>> treePtr,
                         std::shared_ptr<BinaryNode<ItemType>> newNodePtr );
        auto removeValue ( std::shared_ptr<BinaryNode<ItemType>> treePtr,
                           const ItemType& target,
                           bool& isSuccessful );
        auto removeNode ( std::shared_ptr<BinaryNode<ItemType>> nodePtr );
        auto removeLeftMostNode ( std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                  ItemType& inorderSuccesor );
        auto findNode ( std::shared_ptr<BinaryNode<ItemType>> treePtr,
                        const ItemType& target );

        int getHeightFrom ( std::shared_ptr<BinaryNode<ItemType>> treePtr ) const;
        int getSizeFrom ( std::shared_ptr<BinaryNode<ItemType>> treeptr ) const;

        void preorder ( void visit ( ItemType& ), std::shared_ptr<BinaryNode<ItemType>> treePtr ) const;
        void inorder ( void visit ( ItemType& ), std::shared_ptr<BinaryNode<ItemType>> treePtr ) const;
        void postorder ( void visit ( ItemType& ), std::shared_ptr<BinaryNode<ItemType>> treePtr ) const;

    private:
        std::shared_ptr<BinaryNode<ItemType>> rootPtr;

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
auto BinarySearchTree<ItemType>::placeNode ( std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                             std::shared_ptr<BinaryNode<ItemType>> newNodePtr )
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
auto BinarySearchTree<ItemType>::removeValue ( std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                               const ItemType& target,
                                               bool& isSuccessful )
{
    //TODO
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeNode ( std::shared_ptr<BinaryNode<ItemType>> nodePtr )
{
    //TODO
}

template<class ItemType>
auto BinarySearchTree<ItemType>::removeLeftMostNode ( std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                                      ItemType& inorderSuccesor )
{
    //TODO
}

template<class ItemType>
auto BinarySearchTree<ItemType>::findNode ( std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                            const ItemType& target )
{
    //TODO
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeightFrom ( std::shared_ptr<BinaryNode<ItemType>> treePtr ) const
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
int BinarySearchTree<ItemType>::getSizeFrom ( std::shared_ptr<BinaryNode<ItemType>> treeptr ) const
{
    //TODO
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorder ( void visit ( ItemType& ), std::shared_ptr<BinaryNode<ItemType>> treePtr ) const
{
    //TODO
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorder ( void visit ( ItemType& ), std::shared_ptr<BinaryNode<ItemType>> treePtr ) const
{
    //TODO
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorder ( void visit ( ItemType& ), std::shared_ptr<BinaryNode<ItemType>> treePtr ) const
{
    //TODO
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
    //TODO
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData () const
{
    //TODO
}

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData ( const ItemType& newData )
{
    //TODO
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
    //TODO
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains ( const ItemType& anEntry ) const
{
    //TODO
}

template<class Itemtype>
void BinarySearchTree<ItemType>::preorderTraverse ( void visit ( ItemType& ) ) const
{
    //TODO
}

template<class Itemtype>
void BinarySearchTree<ItemType>::inorderTraverse ( void visit ( ItemType& ) ) const
{
    //TODO
}

template<class Itemtype>
void BinarySearchTree<ItemType>::postorderTraverse ( void visit ( ItemType& ) ) const
{
    //TODO
}

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree::operator=( const BinarySearchTree<ItemType>& newTree )
{
    //TODO
}

template<class ItemType>
std::ostream& operator<<( std::ostream& out, const BinarySearchTree<ItemType>& outTree )
{

    outTree.rootPtr->print ( out, true, "" );
    return out;
}