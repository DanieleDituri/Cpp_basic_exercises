#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <cassert>


template <typename T>
void swap(T &a, T &b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
void funct(T a, T b)
{

}

template <>
void funct(char *a, char *b)
{

}

template <typename T, typename Q>
void funct2(T a, Q b)
{

}

template <typename Q, typename T>
Q funct3(T a)
{
  return Q();
}

template <typename T = int>
void funct4()
{
  T res;
}

template <typename T>
void set_data(T *array, unsigned int size, const T &value)
{
  assert(array != nullptr);
  for(unsigned int i = 0 ; i < size ; ++i)
  {
    array[i] = value;
  }
}

struct somma
{
  double operator()(double lhs, int rhs) const
  {
    return lhs + rhs;
  }
};

template <typename R, typename T, typename F>
R sum_data(const T *array, unsigned int size, const R &init, F sum)
{
  assert(array != nullptr);

  R result = init;
  
  for(unsigned int i = 0 ; i < size ; ++i)
  {
    result = sum(result, array[i]);
  }

  return result;
}

#endif