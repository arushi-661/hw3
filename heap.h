#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_; 
  int m_; 
  PComparator comp_; 
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) {
  m_ = m;
  comp_ = c; 
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data_.size(); 
}

template <typename T, typename PComparator> 
bool Heap<T, PComparator>::empty() const {
  return data_.empty(); 
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }
  return data_[0];
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  data_.push_back(item);
  int i = data_.size() - 1;

  while (i > 0){
    int parent = (i-1)/m_;
    if (comp_(data_[i], data_[parent])){
      std::swap(data_[i], data_[parent]); 
      i = parent; 
    } else {
      break;
    }
  }
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }

  data_[0] = data_.back(); 
  data_.pop_back(); 

  int i = 0;
  int n = data_.size(); 

  while (true){
    int first = m_ * i + 1; //index of i's first child

    if (first >= n){
      break; 
    }

    //finding best child among all 
    int best = first;
    for (int k = first + 1; k < first + m_ && k < n; k++){
      if (comp_(data_[k], data_[best])){
        best = k; 
      }
    }

    if (comp_(data_[best], data_[i])){
      std::swap(data_[best],data_[i]);
        i = best; 
      } else {
        break;
      }
    }
  }
#endif

