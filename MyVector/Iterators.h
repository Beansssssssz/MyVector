#pragma once


template <typename Vector>
class VectorIterator
{
public:
  using ValueType = typename Vector::ValueType;
  using PointerType = ValueType*;
  using ReferenceType = ValueType&;

public:
  VectorIterator(PointerType ptr)
    :_ptr(ptr) {}

  VectorIterator& operator++() {
    _ptr++;
    return *this;
  }

  VectorIterator operator++(int) {
    VectorIterator iterator = *this;
    ++(*this);
    return iterator;
  }

  VectorIterator& operator--() {
    _ptr--;
    return *this;
  }

  VectorIterator operator--(int) {
    VectorIterator iterator = *this;
    --(*this);
    return iterator;
  }

  ReferenceType operator[](int index) {
    return *(_ptr + index);
  }

  PointerType operator->() {
    return _ptr;
  }

  ReferenceType operator*() {
    return *_ptr;
  }

  bool operator==(const VectorIterator& other) const {
    return _ptr == other._ptr;
  }

  bool operator!=(const VectorIterator& other) const {
    return _ptr != other._ptr;
  }

private:
  PointerType _ptr;
};

template <typename Vector>
class ReverseVectorIterator
{
public:
  using ValueType = typename Vector::ValueType;
  using PointerType = ValueType*;
  using ReferenceType = ValueType&;

public:
  ReverseVectorIterator(PointerType ptr)
    :_ptr(ptr) {}

  ReverseVectorIterator& operator++() {
    _ptr++;
    return *this;
  }

  ReverseVectorIterator operator++(int) {
    ReverseVectorIterator iterator = *this;
    ++(*this);
    return iterator;
  }

  ReverseVectorIterator& operator--() {
    _ptr--;
    return *this;
  }

  ReverseVectorIterator operator--(int) {
    ReverseVectorIterator iterator = *this;
    --(*this);
    return iterator;
  }

  ReverseVectorIterator operator[](int index) {
    return *(_ptr + index);
  }

  ReverseVectorIterator operator->() {
    return _ptr;
  }

  ReverseVectorIterator operator*() {
    return *_ptr;
  }

  bool operator==(const ReverseVectorIterator& other) const {
    return _ptr == other._ptr;
  }

  bool operator!=(const ReverseVectorIterator& other) const {
    return _ptr != other._ptr;
  }

private:
  PointerType _ptr;
};
