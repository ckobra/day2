#include "array.h"
#include <stdexcept>

namespace {
  void populate_array(double* array, int size, double value) {
    for (int index = 0; index < size; index++)
      array[index] = value;
  }

  void copy_array(double* source, double* target, int size) {
    for (int index = 0; index < size; index++)
      target[index] = source[index];
  }
}

array::array() {
  n = 0;
  p = nullptr;
}

array::array(int size, double value) {
  n = size;
  p = new double[size];
  populate_array(p, n, value);
}

// Needed since we have to copy internal array
array::array(const array& other) {
  n = other.n;
  p = new double[n];
  copy_array(other.p, p, n);
}

array::array(array&& other) {
  n = other.n;
  p = other.p;
  other.p = nullptr;
}

array::~array() {
  delete [] p;
}

array& array::operator=(const array& other) {
  delete[] p;
  n = other.n;
  p = new double[n];
  copy_array(other.p, p, n);
  return *this;
}

int array::size() const {
  return n;
}

double array::at(int index) const {
  if (index < 0 || index >= n)
    throw std::out_of_range("Invalid index");
  return p[index];
}