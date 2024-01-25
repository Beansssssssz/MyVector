#pragma once

#include "Iterators.h"

template<typename T>
class Vector
{
public:
  using ValueType = T;
  using Iterator = VectorIterator<Vector<T>>;
  using ReverseIterator = ReverseVectorIterator<Vector<T>>;

public:
  Vector(size_t initialCapacity = 2)
  {
    ReAlloc(initialCapacity);
  }

  ~Vector() {
    clear();
    ::operator delete(_data, _capacity * sizeof(T));
  }

  void emplace_back(const T& value) {
    if (_size >= _capacity)
      ReAlloc(_capacity * 1.5);

    _data[_size] = value;
    _size++;
  }

  void emplace_back(T&& value) {
    if (_size >= _capacity)
      ReAlloc(_capacity * 1.5);

    _data[_size++] = std::move(value);
  }

  template<typename... Args>
  T& emplace_back(Args&&... args) {
    if (_size >= _capacity)
      ReAlloc(_capacity * 1.5);

    new(&_data[_size]) T(std::forward<Args>(args)...);
    return _data[_size++];
  }

  void pop_back() {
    if (_size <= 0)
      return;
    _size--;
    _data[_size].~T();
  }

  void clear() {
    for (size_t i = 0; i < _size; i++)
      _data[i].~T();
    _size = 0;
  }

  _NODISCARD const T& operator[](size_t index) const {
    return _data[index];
  }

  _NODISCARD T& operator[](size_t index) {
    return _data[index];
  }

  _NODISCARD size_t Size() const { return _size; }
  _NODISCARD size_t MaxSize() const { return _capacity; }

  _NODISCARD Iterator begin() {
    return Iterator(_data);
  }

  _NODISCARD Iterator end() noexcept {
    return Iterator(_data + _size);
  }

  _NODISCARD ReverseIterator rbegin() {
    return ReverseIterator(end());
  }

  _NODISCARD ReverseIterator rend() noexcept {
    return ReverseIterator(begin());
  }

private:
  void ReAlloc(size_t newCapacity) {
    //allocate a new block of memory
    T* newBlock = static_cast<T*>(::operator new(newCapacity * sizeof(T)));

    if (!newBlock)
      throw std::bad_alloc();

    //checks if there is downgrading of the size
    if (newCapacity < _size) 
      _size = newCapacity;

    
    for (size_t i = 0; i < _size; i++) {
      // move or copy construct elements to the new memory block
      new (newBlock + i) T(std::move(_data[i]));

      //calls the deconstructor for all the elements in the old memory block
      _data[i].~T();
    }

    //deleting the old memory block then changing the capacity
    ::operator delete[](_data, _capacity * sizeof(T));
    _data = newBlock;
    _capacity = newCapacity;
  }

  T* _data = nullptr;

  size_t _size = 0;
  size_t _capacity = 0;
};

