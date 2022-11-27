#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T>
{
public:
    Stack();
    ~Stack() = default;
    //returns wether stack is empty
    bool empty() const;
    //returns size
    size_t size() const;
    //adds item to back
    void push(const T& item);
    //removes item from back
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary

};

template <typename T>
Stack<T>::Stack(){

}

template <typename T>
bool Stack<T>::empty() const{
    if(std::vector<T>::size() == 0){
        return true;
    }else{
        return false;
    }
}

template <typename T>
size_t Stack<T>::size() const{
    return std::vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item){
    std::vector<T>::push_back(item);
}

template <typename T>
void Stack<T>::pop(){
    if(Stack<T>::size() <= 0){
        throw std::underflow_error("No items in Stack");
    }
    else {
        std::vector<T>::pop_back();
    }
}

//need to scope to vector class to use its functions
template <typename T>
const T& Stack<T>::top() const{
    if(Stack<T>::size() <= 0){
        throw std::underflow_error("No items in Stack");
    }
    else{
        return std::vector<T>::operator[](std::vector<T>::size()-1);
    }
    
}


#endif