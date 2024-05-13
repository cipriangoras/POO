#include"header_array.h"
template<class T>
inline Array<T>::Array()
{
	List = nullptr;
	Size = 0;
	Capacity = 0;
}

template<class T>
Array<T>::~Array()
{
	Clear();
}

template<class T>
Array<T>::Array(int capacity)
{
	Capacity = capacity;
	Size = 0;
	List = new T*[Capacity];
}

template<class T>
Array<T>::Array(const Array<T>& otherArray)
{
	Size = otherArray.Size;
	Capacity = otherArray.Capacity;
	List = new T * [Capacity];
	for (int i = 0; i < Size; ++i) {
		List[i] = new T(*otherArray.List[i]);
	}
}

template<class T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || index >= Size) {
		throw out_of_range("Index out of range");
	}
	return *List[index];
}

template<class T>
const Array<T>& Array<T>::operator+=(const T& newElem)
{
	if (Size >= Capacity) {
		Resize();
	}
	List[Size++] = new T(newElem);
	return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	if (index < 0 || index > Size) {
		throw std::out_of_range("Index out of range");
	}
	if (Size >= Capacity) {
		Resize();
	}
	for (int i = Size; i > index; --i) {
		List[i] = List[i - 1];
	}
	List[index] = new T(newElem);
	++Size;
	return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	if (index < 0 || index > Size) {
		throw std::out_of_range("Index out of range");
	}
	if (Size + otherArray.Size > Capacity) {
		Resize(Size + otherArray.Size);
	}
	for (int i = 0; i < otherArray.Size; ++i) {
		Insert(index + i, *otherArray.List[i]);
	}
	return *this;
}

template<class T>
const Array<T>& Array<T>::Delete(int index)
{
	if (index < 0 || index >= Size) {
		throw std::out_of_range("Index out of range");
	}
	delete List[index];
	for (int i = index; i < Size - 1; ++i) {
		List[i] = List[i + 1];
	}
	--Size;
	return *this;
}

template<class T>
bool Array<T>::operator=(const Array<T>& otherArray)
{
	if (this == &otherArray) {
		return false;
	}
	Clear();
	Capacity = otherArray.Capacity;
	Size = otherArray.Size;
	List = new T * [Capacity];
	for (int i = 0; i < Size; ++i) {
		List[i] = new T(*otherArray.List[i]);
	}
	return true;
}

template<class T>
void Array<T>::Sort()
{
	for (int i = 0; i < Size - 1; ++i) {
		for (int j = i + 1; j < Size; ++j) {
			if (*List[i] > *List[j]) {
				T* temp = List[i];
				List[i] = List[j];
				List[j] = temp;
			}
		}
	}
}



template<class T>
int Array<T>::BinarySearch(const T& elem)
{
	Sort();
	int left = 0, right = Size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (*List[mid] == elem) {
			return mid;
		}
		if (*List[mid] < elem) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}


template<class T>
int Array<T>::Find(const T& elem)
{
	for (int i = 0; i < Size; ++i) {
		if (*List[i] == elem) {
			return i;
		}
	}
	return -1;
}



template<class T>
int Array<T>::GetSize()
{
	return Size;
}

template<class T>
int Array<T>::GetCapacity()
{
	return Capacity;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
	return ArrayIterator<T>(List);
}


template<class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
	return ArrayIterator<T>(List + Size);
}




