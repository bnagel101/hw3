#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

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
  ~Heap() = default;

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
  void print();
private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int aryNess;
  PComparator comp;
  void sortUp(int);
  void sortDown(int);
};

// Add implementation of member functions here

//constructor
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  aryNess = m;
  comp = c;
}

//print function to just print out the vector
template <typename T, typename PComparator>
void Heap<T,PComparator>::print(){
  int level = 0;
  int maxN = pow(aryNess, level);
  for(int i = 0; i < (int)size(); i++){
    // if(i == maxN - 1){
    //   std::cout << '\n';
    //   level++;
    //   maxN = pow(aryNess, level);
    // }
    std::cout<< data[i] << " ";
  }
  std::cout << "Done \n";
}

//helper function for when using the pop function and need to sort going up in the heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::sortUp(int pos){
  int root = pos;
  for(int i = 1; i <= aryNess; i++){
    int child = pos*aryNess + i;
    if(child < (int)size() && comp(data[child], data[root])){
      root = child;
    }
  }
  
  if(root != pos){
    std::swap(data[pos], data[root]);
    sortUp(root);
  }

}

//helper function for push function for when you need to sort downwards in the heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::sortDown(int pos){
	int child = pos;
	int parent = (child-1)/aryNess;
	if(parent >= 0 && comp(data[child], data[parent])){
		std::swap(data[child], data[parent]);
		sortDown(parent);
	}
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("No items in heap"); 

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("No items in heap");

  }
  std::swap(data[0], data[size()-1]);
  data.pop_back();
  sortUp(0);

}

//Adds a new element to the heap by putting the element in the last spot of the heap and then sorting down
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data.push_back(item);
  sortDown((int)size()-1);

}

//returns size
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
	return data.size();
}

//returns true if heap is empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
	if((int)size() == 0){
		return true;
	}
	return false;
}


#endif

