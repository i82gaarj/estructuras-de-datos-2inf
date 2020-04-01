#ifndef __ED_BTree_HPP__
#define __ED_BTree_HPP__

#include <cassert>
#include <exception>
#include <memory>
#include <iostream>

/** @brief a BTree's Node.*/
template <class T>
class BTNode
{
public:

    /** @brief Define a shared reference to a BTNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< BTNode<T> > Ref;

    /** @name Life cicle.*/
    /** @{*/

    /** @brief Create a BTNode.
     * @post n_children() == 0
     */
    BTNode (T const& it=T(), BTNode<T>::Ref left=nullptr, BTNode<T>::Ref right=nullptr)
    {
        _item = it;
        _left = left;
        _right = right;
    }

    /** @brief Destroy a BTNode. **/
    ~BTNode()
    {}

    /** @}*/

    /** @name Observers.*/
    /** @{*/

    /** @brief Get the data item.*/
    const T& item() const
    {
        return _item;
    }

    /** @brief Has it a left child?*/
    bool has_left() const
    {
        if (_left != nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    /** @brief get the left child.
     * @pre has_left()
     */
    const BTNode<T>::Ref& left() const
    {
        return _left;
    }

    /** @brief get the left child.
     * @pre has_left()
     */
    BTNode<T>::Ref& left()
    {
        return _left;
    }

    /** @brief Has it a right child? */
    bool has_right() const
    {
        if (_right != nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    /**
     * @brief get the right child.
     * @pre has_right()
     */
    const BTNode<T>::Ref& right() const
    {
        return _right;
    }

    /**
     * @brief get the right child.
     * @pre has_right()
     */
    BTNode<T>::Ref& right()
    {
        return _right;
    }

    /** @}*/

    /** @name Modifiers.*/
    /** @{*/

    /** @brief Set the data item.*/
    void set_item(const T& new_it)
    {
        _item = new_it;
    }

    /**
     * @brief Set the left child.
     * @pre new_child != nullptr
     */
    void set_left(BTNode<T>::Ref const& new_child)
    {
        _left = new_child;
    }

    /**
     * @brief Remove link to the left child.
     * @post not has_left()
     */
    void remove_left()
    {
        _left = nullptr;
    }

    /**
     * @brief Set the right child.
     * @pre new_child != nullptr
     */
    void set_right(BTNode<T>::Ref const& new_child)
    {
        _right = new_child;
    }

    /**
     * @brief Remove linkt to the right child.
     * @post not has_right()
     */
    void remove_right()
    {
        _right = nullptr;
    }

protected:
    std::shared_ptr <BTNode <T>> _left;
    std::shared_ptr <BTNode <T>> _right;
    T _item;
};

/**
 * @brief ADT BTree.
 * Models a BTree of T.
 */
template<class T>
class BTree
{
  public:

  /** @name Life cicle.*/
  /** @{*/

    /** @brief Create an empty BTree.
     * @post is_empty()
     */
    BTree ():
        _root(nullptr)
    {}

    /** @brief Create a BTree using a given node as root.*/
    BTree (typename BTNode<T>::Ref& new_root):
        _root(new_root)
    {}

  /** @brief Create Leaf BTree.
   * @post not is_empty()
   */
  BTree (const T& item):
      _root(new BTNode<T>(item, nullptr, nullptr))
  {}


  /** @brief Destroy a BTree.**/
  ~BTree()
  {}

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const
  {
      return _root.get() == nullptr;
  }

  /** @brief Get the root item.
   * @pre not is_empty();
   */
  T const& item() const
  {
      assert(!is_empty());
      return _root->item();
  }

  /**
   * @brief Get the root node.
   */
  typename BTNode<T>::Ref const& root() const
  {
      return _root;
  }

  /**
   * @brief Get the root node.
   */
  typename BTNode<T>::Ref& root()
  {
      return _root;
  }

  /** @}*/

  /** @name Modifiers*/

  /** @{*/

  /**
   * @brief set a new root node.
   * @pre new_root != nullptr
   * @post not is_empty()
   */
  void set_root(typename BTNode<T>::Ref& new_root)
  {
      assert(new_root.get() != nullptr);
      _root = new_root;
      assert(!is_empty());
  }

  /**
   * @brief Remove the link to the root node
   * @post is_empty()
   */
  void remove_root()
  {
      _root.reset();
      assert(is_empty());
  }

  /** @brief set the roor's item.
   * @pre not is_empty()
   */
  void set_item(const T& new_it)
  {
      assert(!is_empty());
      _root->set_item(new_it);
  }

  /** @}*/

private:

  /** @brief Copy constructor.
   * @warning we don't want a copy constructor.
   */
  BTree(const BTree<T>& other)
  {}

protected:

  typename BTNode<T>::Ref _root;

};


/**  @brief Fold a binary tree node.
 * The output format will be:
 * [<item> : <left> : <right>] or [] if its a empty node (nullptr).
*/
template<class T>
std::ostream&
fold_btnode (std::ostream& out, typename BTNode<T>::Ref const& node)
{
    out << "[";
    if (node != nullptr){
        out << node -> item() << " : ";
        fold_btnode <T>(out, node -> left());
        out << " : ";
        fold_btnode <T>(out, node -> right());
    }
    out << "]";

    return out;
}

/**  @brief Fold a binary tree. */
template<class T>
std::ostream&
fold_btree ( std::ostream& out, BTree<T> const& tree)
{
    fold_btnode<T> (out, tree.root());
    return out;
}

/** @brief Load a btnode from a input stream.
 * @return the node on success.
 * @warning runtime_error will throw if worng input format is found.
 */
template<class T>
std::istream&
unfold_btnode (std::istream& in, typename BTNode<T>::Ref& node) noexcept(false)
{
    char sep=' ';
    while(in && sep!='[')
        in >> sep;
    if (!in)
        throw std::runtime_error("Wrong input format.");
    sep = static_cast<char>(in.peek());
    if (sep != ']')
    {
        T item;
        in >> item;
        if (!in)
            throw std::runtime_error("Wrong input format.");
        while(in && sep!=':')
            in >> sep;
        if (!in)
            throw std::runtime_error("Wrong input format.");
        typename BTNode<T>::Ref left;
        unfold_btnode<T>(in, left);
        if (!in)
            throw std::runtime_error("Wrong input format.");
        while(in && sep!=':')
            in >> sep;
        if (!in)
            throw std::runtime_error("Wrong input format.");
        typename BTNode<T>::Ref right;
        unfold_btnode<T>(in, right);
        if (!in)
            throw std::runtime_error("Wrong input format.");
        node = std::make_shared< BTNode<T> >(item, left, right);
    }
    else
        in >> sep;//remove the close bracket from stream.
    return in;
}

/** @brief Load a tree from a input stream.
 * @warning runtime_error will throw if worng input format is found.
 */
template<class T>
std::istream&
unfold_btree(std::istream& in, BTree<T>& tree)
{
    typename BTNode<T>::Ref root;
    unfold_btnode<T> (in, root);
    if (in)
    {
        if (root.get() == nullptr)
        {
            if (!tree.is_empty())
                tree.remove_root();
        }
        else
            tree.set_root(root);
    }
    return in;
}

#endif
