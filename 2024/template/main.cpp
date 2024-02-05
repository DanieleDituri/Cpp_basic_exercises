#include <iostream>
#include <cassert>

struct compare_int
{
    bool operator()(int a, int b) const
    {
        return a < b;
    }
};

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T, typename Q>
void set(T *array, unsigned int size, const Q &value)
{
    assert(array != nullptr);
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = static_cast<T>(value);
    }
}

template <typename T, typename P>
void sort_array(T *array, unsigned int size, P compare)
{
    unsigned int i, j;

    for(i = 0; i < size - 1; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(compare(array[j], array[i]))
            {
                std::swap(array[i], array[j]);
            }
        }
                
    }
}

template <typename T>
void print_array(T *array, unsigned int size)
{
    for(unsigned int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    int x = 5, y = 10;
    std::cout << "x: " << x << " y: " << y << std::endl;
    swap<int>(x, y);
    std::cout << "swap()" << std::endl;
    std::cout << "x: " << x << " y: " << y << std::endl;

    float f = 5.5, d = 10.5;
    std::cout << "f: " << f << " d: " << d << std::endl;
    swap<float>(f, d);
    std::cout << "swap()" << std::endl;
    std::cout << "f: " << f << " d: " << d << std::endl;

    int a[5] = {0, 0, 0, 0, 0};
    char b[3] = {'0', '0', '0'};

    set<int>(a, 5, 100);
    set<char>(b, 3, 'X');

    int c[5] = {7, 2, 4, 12, 1};

    print_array<int>(c, 5);

    compare_int com;

    sort_array<int>(c, 5, com);

    print_array<int>(c, 5);

    return 0;
}