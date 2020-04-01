#ifndef __ED_BTree_Utils_HPP__
#define __ED_BTree_Utils_HPP__

#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
#include <queue>

#include "btree.hpp"


/** @brief Prefix processing of a node
 * The template class Processor must have an apply interface:
 * bool Processor::apply(BTNode<T>::Ref& node).
 * returning true to continue the process or false to stop it.
 *
 * @arg[in] node is the node to be processed.
 * @arg[in] is the process to be apply to the node item.
 * @pre node.get()!=null
 * @return true if the process must continue.
 */
template <class T, class Processor>
bool
prefix_process(typename BTNode<T>::Ref& node, Processor& p)
{
    assert(node.get()!=nullptr);    

    std::cout << node -> item() << " ";

    if (node -> has_left()){
        prefix_process <T, Processor>(node -> left(), p);
    }
    if (node -> has_right()){
        prefix_process <T, Processor>(node -> right(), p);
    }
    return false;
}

/** @brief Prefix processing of a binary tree
 * The template class Processor must have an apply interface:
 * bool Processor::apply(BTNode<T>::Ref & node).
 * returning true to continue the process or false to stop it.
 *
 * @return true if all nodes were processed.
 */
template <class T, class Processor>
bool
prefix_process(BTree<T>& tree, Processor& p)
{
    bool retVal = true;
    if (!tree.is_empty())
        retVal = prefix_process<T, Processor>(tree.root(), p);
    return retVal;
}

/** @brief Infix processing of a node
 * The template class Processor must have an apply interface:
 * bool Processor::apply(BTNode<T>::Ref& node).
 * returning true to continue the process or false to stop it.
 *
 * @arg[in] node is the node to be processed.
 * @arg[in] is the process to be apply to the node item.
 * @pre node.get()!=null
 * @return true if the process must continue.
 */
template <class T, class Processor>
bool
infix_process(typename BTNode<T>::Ref& node, Processor& p)
{
    assert(node.get()!=nullptr);
    
    if (node -> has_left()){
        infix_process <T, Processor>(node -> left(), p);
    }

    std::cout << node -> item() << " ";

    if (node -> has_right()){
        infix_process <T, Processor>(node -> right(), p);
    }
    return false;
}

/** @brief Infix processing of a binary tree
 * The template class Processor must have an apply interface:
 * bool Processor::apply(BTNode<T>::Ref & node).
 * returning true to continue the process or false to stop it.
 *
 * @return true if all nodes were processed.
 */
template <class T, class Processor>
bool
infix_process(BTree<T>& tree, Processor& p)
{
    bool retVal = true;
    if (!tree.is_empty())
        retVal = infix_process<T, Processor>(tree.root(), p);
    return retVal;
}

/** @brief Postfix processing of a node
 * The template class Processor must have an apply interface:
 * bool Processor::apply(BTNode<T>::Ref & node).
 * returning true to continue the process or false to stop it.
 *
 * @arg[in] node is the node to be processed.
 * @arg[in] is the process to be apply to the node item.
 * @pre node.get()!=null
 * @return true if the process must continue.
 */
template <class T, class Processor>
bool
postfix_process(typename BTNode<T>::Ref& node, Processor& p)
{
    assert(node.get()!=nullptr);

    if (node -> has_left()){
        postfix_process <T, Processor>(node -> left(), p);
    }

    if (node -> has_right()){
        postfix_process <T, Processor>(node -> right(), p);
    }

    std::cout << node -> item() << " ";

    return false;
}

/** @brief Postfix processing of a binary tree
 * The template class Processor must have an apply interface:
 * bool Processor::apply(BTNode<T>::Ref & node).
 * returning true to continue the process or false to stop it.
 *
 * @return true if all nodes were processed.
 */
template <class T, class Processor>
bool
postfix_process(BTree<T>& tree, Processor& p)
{
    bool retVal = true;
    if (!tree.is_empty())
        retVal = postfix_process<T, Processor>(tree.root(), p);
    return retVal;
}


/** @brief Bread-first processing of a btree.
 * The template class Processor must have an apply interface:
 * bool Processor::apply(BTNode<T>::Ref& node).
 * returning true to continue the process or false to stop it.
 *
 * Wise: should you need a queue?
*/
template <class T, class Processor>
bool
breadth_first_process(BTree<T>& tree, Processor& p)
{
    std::queue <std::shared_ptr <BTNode <T>>> queue;

    queue.push(tree.root());

    while(queue.empty() == false){
        std::cout << queue.front() -> item() << " ";
        if (queue.front() -> has_left()){
            queue.push(queue.front() -> left());
        }
        if (queue.front() -> has_right()){
            queue.push(queue.front() -> right());
        }

        queue.pop();
    }
    
    return false;
}

#endif
