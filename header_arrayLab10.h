#pragma once
#include<iostream>
using namespace std;

template<class T>
class ArrayIterator {
public:
    ArrayIterator(T** ptr) : ptr_(ptr) {}
    T& operator*() const { return **ptr_; }
    ArrayIterator<T>& operator++() { ++ptr_; return *this; }
    ArrayIterator<T>& operator--() { --ptr_; return *this; }
    bool operator!=(const ArrayIterator<T>& other) const { return ptr_ != other.ptr_; }
    bool operator=(const ArrayIterator<T>& other) { ptr_ = other.ptr_; return true; }
    T* GetElement() { return *ptr_; }
private:
    T** ptr_;
};


template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista


    void Resize(int newCapacity = 0) {
        if (newCapacity == 0) {
            newCapacity = Capacity * 2 + 1;
        }
        T** newList = new T * [newCapacity];
        for (int i = 0; i < Size; ++i) {
            newList[i] = List[i];
        }
        delete[] List;
        List = newList;
        Capacity = newCapacity;
    }

    void Clear() {
        for (int i = 0; i < Size; ++i) {
            delete List[i];
        }
        delete[] List;
        List = nullptr;
        Capacity = Size = 0;
    }
public:
    Array(); // Lista nu e alocata, Capacity si Size = 0
    ~Array(); // destructor
    Array(int capacity); // Lista e alocata cu 'capacity' elemente
    Array(const Array<T>& otherArray); // constructor de copiere

    T& operator[] (int index); // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array

    int Find(const T& elem); // cauta un element in Array

    int GetSize();
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};

