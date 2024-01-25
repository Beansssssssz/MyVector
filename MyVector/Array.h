#pragma once
template<typename T, size_t S>
class Array
{
public:
  Array() {
  }

  constexpr size_t Size() const { return S; }

  T& operator[](size_t index) { return _data[index]; };
  const T& operator[](size_t index) const { return _data[index]; };

  T* Data() { return _data; }
  const T* Data() const { return _data; }

private:
  T _data[S];
};


