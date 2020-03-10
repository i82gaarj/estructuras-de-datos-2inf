#ifndef __Stack_HPP__
#define __Stack_HPP__

#include <cassert>
#include <vector>
#include <memory>

/**
 * @brief ADT Stack.
 * Models a Single linked list[T].
 */
template<class T>
class Stack
{
  public:

  /** @name Life cicle.*/
  /** @{*/

  /** @brief Create an empty Stack.
   * @post is_empty()
   */
  Stack ()
  {
      nElem = 0;
  }

  /** @brief Destroy a Stack.**/
  ~Stack()
  {}

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const
  {
      if (nElem == 0){
          return true;
      }
      else{
          return false;
      }
  }

  /** @brief get the top item.
   * @pre not is_empty()
   */
  const T& top() const
  {
      if (this -> is_empty() == false){
          return v_[nElem - 1];
      }
  }

  /**@}*/

  /** @name Modifiers*/

  /** @{*/

  /** @brief Insert a new item.
   * @post top() == new_it
   */
  void push(const T& new_it)
  {
      v_[nElem] = new_it;
      nElem++;
  }

  /** Remove the top item.
   * @pre not is_empty()
   */
  void pop()
  {
      if (nElem > 0){
          nElem--;
      }
  }

  /** @} */

private:

  /** @brief Copy constructor.
   * @warning we don't want a copy constructor.
   */
  Stack(const Stack<T>& other)
  {}

  /** @brief Assign operator.
   * @warning we don't want the assign operator.
   */
  Stack<T>& operator=(const Stack<T>& other)
  {
      return *this;
  }

protected:

  T v_[50000];
  int nElem;
  
};

#endif
