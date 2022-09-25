#ifndef HASHTABLE_MYVECTOR_H
#define HASHTABLE_MYVECTOR_H

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<stdexcept>
#include<sstream>
#include<exception>

using namespace std;
template <typename T>
class MyVector
{
private:
    T *data;						//pointer to int(array) to store elements
    int v_size;						//current size of vector (number of elements in vector)
    int v_capacity;					//capacity of vector
public:
    MyVector();						//No argument constructor
    MyVector(int cap);				//One Argument Constructor
    MyVector(const MyVector& other);//Copy Constructor
    ~MyVector();					//Destructor
    void push_back(T element);		//Add an element at the end of vector
    void insert(int index, T element); //Add an element at the index
    void erase(int index);			//Removes an element from the index
    T& operator[](int index);		//return reference of the element at index
    T& at(int index); 				//return reference of the element at index
    const T& front();				//Returns reference of the first element in the vector
    const T& back();				//Returns reference of the Last element in the vector
    int size() const;				//Return current size of vector
    int capacity() const;			//Return capacity of vector
    bool empty() const; 			//Rturn true if the vector is empty, False otherwise
    void shrink_to_fit();			//Reduce vector capacity to fit its size
    void display();
    void reserve(int N);
    T* cbegin() {
        return &data[0];
    }

    const T* cbegin() const {
        return &data[0];
    }

};

//===================================================
class IndexOutOfBounds: public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Index is out of bound";
    }
};

//No argument constructor
template <typename T>
MyVector<T>::MyVector()
        : v_capacity(0), v_size(0), data(NULL) {}

//One Argument Constructor
template <typename T>
MyVector<T>::MyVector(int cap)
        : v_capacity(cap), v_size(0), data(NULL) {}

//Destructor
template <typename T>
MyVector<T>::~MyVector(){
    delete[] data;
}

//Return current size of vector
template <typename T>
int MyVector<T>::size() const{
    return v_size;
}
//Return capacity of vector
template <typename T>
int MyVector<T>::capacity() const{
    return v_capacity;
}
//Return true if the vector is empty, False otherwise
template <typename T>
bool MyVector<T>::empty()const{
    return (size()==0);

}
//return reference of the element at index
template <typename T>
T& MyVector<T>::operator[](int index){
    return data[index];
}
//return reference of the element at index
template <typename T>
T& MyVector<T>::at(int index) {
    if (index<0 || index>=v_size)
        throw IndexOutOfBounds();
    return data[index];
}
//Removes an element from the index
template <typename T>
void MyVector<T>::erase(int index){
    if (index<0 || index>=v_size)
        throw IndexOutOfBounds();
    for (int j = index+1; j < v_size; j++)
        data[j-1] = data[j];
    v_size--;
}


template <typename T>
void MyVector<T>::reserve(int N){
    if (v_capacity >= N) return;
    T* B = new T[N];
    for (int j = 0; j < v_size; j++)
        B[j] = data[j];
    if (data != NULL) delete [] data;
    data = B;
    v_capacity = N;
}

//Add an element at the index
template <typename T>
void MyVector<T>::insert(int index, T element){
    if (index<0 || index>v_size-1)
        throw IndexOutOfBounds();
    else
    if (v_size >= v_capacity)
        reserve(max(1, 2 * v_capacity));
    for (int j = (v_size - 1); j >= index; j--)
        data[j+1] = data[j];
    data[index] = element;
    v_size++;
}
//Returns reference of the first element in the vector
template <typename T>
const T& MyVector<T>::front(){
    return data[0];
}
//Returns reference of the Last element in the vector
template <typename T>
const T& MyVector<T>::back(){
    return data[v_size-1];
}

//Add an element at the end of vector
template <typename T>
void MyVector<T>::push_back(T element){
    if (v_size >= v_capacity)
        reserve(max(1, 2 * v_capacity));
    data[v_size++] = element;
}

//Reduce vector capacity to fit its size
template <typename T>
void MyVector<T>::shrink_to_fit(){
    v_capacity = v_size;
}


#endif //HASHTABLE_MYVECTOR_H
