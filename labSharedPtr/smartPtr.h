#ifndef SMARTPTR_H
#define SMARTPTR_H
#include <exception>
#include <iostream>
/*class SmartPointerException: public std::exception
{
    const char *what() const throw()
    {
        return "The copied object doesn't exist";
    }
};
*/

template <typename T>
class SmartPointer
{
public:
    //  typedef T* Ptr;
    // typedef T& Ref;
    SmartPointer(T*);
    ~SmartPointer();
    SmartPointer& operator=(const SmartPointer &);
    SmartPointer(const SmartPointer &);

    T& operator*() const
    {
        return *pointer;
    }
    T* operator->() const
    {
        return pointer;
    }

    operator bool() const
    {
        return pointer!=0;
    }
    int getCouter() const
    {
        return *counter;
    }
private:
    T *pointer;
    int *counter;
};

template <typename T>
SmartPointer<T>::SmartPointer(T *ptr)
    : pointer(ptr),counter(new int(0))
{
    (*counter)++;
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
    if(! --(*counter))
    {
        delete counter;
        counter = 0;
        if(pointer)
        {
            delete pointer;
            pointer = 0;
        }
    }

}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> & other)
    :pointer(other.pointer), counter(other.counter)
{
    if(*counter)
        (*counter)++;
    //else
    //  throw SmartPointerException();
}


template <typename T>
SmartPointer<T> &SmartPointer<T>::operator = (const SmartPointer<T> &other)
{
    if (this == &other)
        return *this;
    if(! --(*counter))
    {
        delete counter;
        counter = 0;
        if(pointer)
        {
            delete pointer;
            pointer = 0;
        }
    }
    pointer = other.pointer;
    counter=other.counter;
    (*counter)++;
    return *this;

}

#endif

