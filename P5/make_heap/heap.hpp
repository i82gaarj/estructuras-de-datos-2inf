#ifndef __ED_Heap_HPP__
#define __ED_Heap_HPP__

#include <cassert>
#include <iostream>
#include <functional>
#include <memory>
#include <algorithm>
#include <vector>

/**
 * @brief Implement the Heap ADT.
 * The parameter template Comp must implement the interface:
 *          bool operator()(T const& a, T const& b)
 * to compare two values a, b.
 * For instance, std::less_equal<T> could be used.
 *
 * It is interesting both the heap can manage its own storage as use a external
 * storage (a given array).
 *
 * For this, you can use two attributes, i.e., my_storage_ and data_.
 *
 * When the heap is created empty with a capacity of elements, my_strogage_ and data_
 * points to a new block of capacity elements. Then when the heap variable is destroied,
 * you must free this memory.
 *
 * When an external storage is used, (i. e. heapify a given vector), my_storage is null and data_ points to
 * the first value of the vector. Then when the heap varible is destroid, you MUST NOT free the memory (my_storage_ is null)
 * because this memory is owned by other external object.
 *
 * The type std::unique_ptr<> is strongly recommended to use for my_storage_ attribute.
 *
 */
template<class T, class Comp = std::less_equal<T> >
class Heap
{
  public:

  /** @name Life cicle.*/
  /** @{*/

    /**
     * @brief Create an empty Heap with a given capacity.
     * @warning the heap is the owner of the reserved memory.
     * @post is_empty()
     */
    Heap (int capacity=0)
    {
        capacidad_ = capacity;
        tamano_ = 0;
        v_ = new T[capacidad_];

        //
        assert(is_a_heap());
        assert(is_empty());
    }

    /**
     * @brief Create an Heap from a array of items.
     * @waring The heap not is the responsable of the memory pointed by @arg data.
     * @post is_full()
     */
    Heap (T* data, size_t size)
    {        
        capacidad_ = size;
        tamano_ = size;
        v_ = new T[capacidad_];

        for (int i = 0; i < tamano_; i++){
            v_[i] = data[i];
        }
        
        heapify();

        assert(is_a_heap());
        assert(is_full());
    }

    /** @brief Destroy a Heap.**/
    ~Heap()
    {
        delete v_;
    }

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const
  {
    if (tamano_ == 0){
        return true;
    }
    else{
        return false;
    }
  }

  /** @brief is the heap full?.*/
  bool is_full () const
  {
      if (capacidad_ == tamano_){
          return true;
      }
      else{
          return false;
      }
  }

  /** @brief Get the heap size. */
  int size() const
  {
      return tamano_;
  }

  /** @brief Get the heap capacity. */
  int capacity() const
  {
      return capacidad_;
  }

  /** @brief Get the root item.
   * @pre not is_empty();
   */
  T const& top() const
  {
      assert(! is_empty());
      return v_[0];
  }

  /** @brief Get the raw vector with the heap data.*/
  T const* data() const
  {
      return v_;
  }

  /** @}*/

  /** @name Modifiers*/

  /** @{*/

  /** @brief insert a new item.
   * @pre not is_full()
   */
  void insert (T const& new_it)
  {
      assert(! is_full());      

        v_[tamano_] = new_it;
        int i = tamano_;
        tamano_++;
        
        while(i > 0 && comp_(v_[i], v_[parent(i)])){
            int aux = v_[i];
            v_[i] = v_[parent(i)];
            v_[parent(i)] = aux;

            i = parent(i);
        }

      //
      assert(is_a_heap());
  }

  /** @brief Remove the root item.
   * @pre not is_empty()
   */
  void remove()
  {
      assert(! is_empty());
      //TODO
        for (int i = 1; i < tamano_; i++){
            v_[i - 1] = v_[i];
        }
        tamano_--;

        heapify();

      //
      assert(is_a_heap());
  }

  /** @}*/
private:

  /** @brief disable copy constructor.*/
  Heap(Heap<T, Comp> const& other);

  /** @brief disable assign operator.*/
  Heap<T, Comp>& operator=(Heap<T, Comp> const& other);

protected:

  /**
   * @brief get the parent of node i
   * @pre i>0
   */
  int parent(int i) const
  {
      assert(i>0);
      
      int parent = i / 2;
      if (i % 2 == 0){
          parent--;
      }
      return parent;
  }

  /**
   * @brief get the left child of node i.
   */
  int left(int i) const
  {
      return (2 * i) + 1;
  }

  /**
   * @brief get the right child of node i.
   */
  int right(int i) const
  {
      return (2 * i) + 2;
  }

  /**
   * @brief Check the head invariant for the subtree.
   * @pre 0<=root && root < size()
   */
  bool is_a_heap(int root=0) const
  {      
      bool left_n = false, right_n = false;
      int l = left(root);
      if (l >= tamano_){
          left_n = true;
      }
      else if (comp_(v_[root], v_[l])){
          left_n = is_a_heap(l);
      }
      else{
          return false;
      }

      int r = right(root);
      if (r >= tamano_){
          right_n = true;
      }
      else if (comp_(v_[root], v_[r])){
          right_n = is_a_heap(r);
      }
      else{
          return false;
      }
      
      return left_n && right_n;
  }

  /** @brief Shitup a node.*/
  void shit_up(int i)
  {
      int p = parent(i);

      //if _comp(item(i), item(p)), swap i with p and shift up p.
      
      if (comp_(v_[i], v_[p])){
          int aux = v_[i];
          v_[i] = v_[p];
          v_[p] = aux;

          shit_up(p);
      }

  }

  /** @brief shitdown a node. */
  void shit_down(int i)
  {
      int n = i; //n will have the node to swap with. by default is the root i.

      int l = left(i); //the left child of i.
      int r = right(i); //the right child of i.

      //if l is a valid index and comp_(item(l), item(n) then now n is l
      //TODO
      if (l >= 0 && l < tamano_ && comp_(v_[l], v_[n])){
          T aux = v_[n];
          v_[n] = v_[l];
          v_[l] = aux;
      }

      //if r is a valid index and comp_(item(r), item(n) then now n i s r
      //TODO
      if (r >= 0 && r < tamano_ && comp_(v_[r], v_[n])){
          T aux = v_[n];
          v_[n] = v_[r];
          v_[r] = aux;
      }

      //if i <> n then invariant is not meet, swap i with n and shift down n.
      //TODO
      if (i != n){
          int aux = i;
          i = n;
          n = i;
          shit_down(n);
      }

  }

    void heapify_(int i){
        int heapest = i;
        int l = left(i);
        int r = right(i);

        if (l < tamano_ && comp_(v_[l], v_[heapest])){
            heapest = l;
        }

        if (r < tamano_ && comp_(v_[r], v_[heapest])){
            heapest = r;
        }

        if (heapest != i){
            T aux = v_[heapest];
            v_[heapest] = v_[i];
            v_[i] = aux;

            heapify_(heapest);
        }
    }
  /** @brief make the subtree starting in root to be a heap.*/
  void heapify(/*int root=0*/)
  {
      //TODO
      //Remenber there are two ways to implement.
      //The best is to use shiftdowns from the second to last level (|size/2| ... 0)
        for (int i = (tamano_ / 2) - 1; i >= 0; i--){
            heapify_(i);
        }
        //std::make_heap(v_, v_ + tamano_);

      //
      assert(is_a_heap());
  }

  Comp comp_; //Functor to compare heap items. comp_(it1, it2)

    T* v_;
    int capacidad_;
    int tamano_;
};


#endif
