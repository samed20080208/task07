
#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class List
{
    size_t _size = 0;
    size_t _capacity = 15;
    T* _array = new T[_capacity];

public:
    List() = default;

    List(size_t capacity)
    {
        while (_capacity < capacity)
            _capacity += 15;

        if (_array != nullptr)
            delete[] _array;
        _array = new T[_capacity];
    }

    ~List() { delete[] _array; }

    void push_back(T item);

    void push_front(T item);

    T& at(size_t index);

    T& operator[](size_t index);

    const T* data() const
    {
        return _array;
    }

    size_t find(T item);

    friend ostream& operator<<(ostream& os, const List<T>& list)
    {
        for (size_t i = 0; i < list._size; ++i)
            os << list._array[i] << " ";

        return os;
    }

    void remove_by_index(size_t index)
    {
        if (index >= _size)
            assert(!"Index out of range");


        for (size_t i = index; i < _size - 1; ++i)
            _array[i] = _array[i + 1];

        --_size;
    }

    void add_by_index(size_t index, T item)
    {
        if (index > _size)
            assert(!"Index out of range");


        if (_size == _capacity)
        {
            _capacity += 15;
            T* new_array = new T[_capacity];

            for (size_t i = 0; i < index; ++i)
                new_array[i] = _array[i];


            new_array[index] = item;

            for (size_t i = index; i < _size; ++i)
                new_array[i + 1] = _array[i];


            delete[] _array;
            _array = new_array;

            ++_size;
        }
        else
        {
            for (size_t i = _size; i > index; --i)
                _array[i] = _array[i - 1];

            _array[index] = item;

            ++_size;
        }
    }
    T& front()
    {
        if (_size == 0)
            assert(!"List is empty");

        return _array[0];
    }

    T& back()
    {
        if (_size == 0)
            assert(!"List is empty");

        return _array[_size - 1];
    }

    void pop_back()
    {
        if (_size == 0)
        {
            assert(!"List is empty");
        }

        --_size;
    }

    void pop_front()
    {
        if (_size == 0)
            assert(!"List is empty");

        for (size_t i = 0; i < _size - 1; ++i)
            _array[i] = _array[i + 1];

        --_size;
    }


    void bubbleSortAscending()
    {
        for (size_t i = 0; i < _size - 1; ++i)
            for (size_t j = 0; j < _size - i - 1; ++j)
                if (_array[j] > _array[j + 1])
                {
                    T temp = _array[j];
                    _array[j] = _array[j + 1];
                    _array[j + 1] = temp;
                }
    }

    void bubbleSortDescending()
    {
        for (size_t i = 0; i < _size - 1; ++i)
            for (size_t j = 0; j < _size - i - 1; ++j)
                if (_array[j] < _array[j + 1])
                {
                    T temp = _array[j];
                    _array[j] = _array[j + 1];
                    _array[j + 1] = temp;
                }
    }

    void sort(bool reverse = false)
    {
        if (reverse)
            bubbleSortDescending();
        else
            bubbleSortAscending();
    }

    void my_unique()
    {
        size_t newSize = 1;

        if (_size == 1)
            cout << "There is only one item" << endl;

        else if (_size == 0)
            cout << "List is empty" << endl;


        else {
            for (size_t i = 1; i < _size; ++i)
            {
                bool isDuplicate = false;

                for (size_t j = 0; j < newSize; ++j)
                    if (_array[i] == _array[j])
                    {
                        isDuplicate = true;
                        break;
                    }

                if (!isDuplicate)
                    _array[newSize++] = _array[i];

            }
            _size = newSize;
        }
    }

    T my_min() const
    {
        if (_size == 0)
            assert(!"List is empty");

        T minValue = _array[0];

        for (size_t i = 1; i < _size; ++i)
            if (_array[i] < minValue)
                minValue = _array[i];


        return minValue;
    }

    T my_max() const
    {
        if (_size == 0)
            assert(!"List is empty");

        T maxValue = _array[0];

        for (size_t i = 1; i < _size; ++i)
            if (_array[i] > maxValue)
                maxValue = _array[i];


        return maxValue;
    }

    T my_sum() const
    {
        if (_size == 0)
            assert(!"List is empty");

        T sum = 0;

        for (size_t i = 1; i < _size; ++i)
            sum += _array[i];


        return sum;
    }

};

template<typename T>
void List<T>::push_front(T item)
{
    if (_size == _capacity)
    {
        _capacity += 15;
        T* new_array = new T[_capacity];

        for (size_t i = 0; i < _size; ++i)
            new_array[i + 1] = _array[i];

        new_array[0] = item;

        delete[] _array;
        _array = new_array;

        ++_size;
    }
    else
    {
        for (size_t i = _size; i > 0; --i)
            _array[i] = _array[i - 1];

        _array[0] = item;

        ++_size;
    }
}

template<typename T>
void List<T>::push_back(T item)
{
    if (_size == _capacity)
    {
        _capacity += 15;
        T* new_array = new T[_capacity];

        for (size_t i = 0; i < _size; ++i)
            new_array[i] = _array[i];


        new_array[_size] = item;

        delete[] _array;
        _array = new_array;

        ++_size;
    }
    else
    {
        _array[_size] = item;

        ++_size;
    }
}

template<typename T>
T& List<T>::at(size_t index)
{
    if (index >= _size)
        assert(!"Index out of range");

    return _array[index];
}

template<typename T>
T& List<T>::operator[](size_t index)
{
    if (index >= _size)
        assert(!"Index out of range");

    return _array[index];
}

template<typename T>
size_t List<T>::find(T item)
{
    for (size_t i = 0; i < _size; ++i)
        if (_array[i] == item)
            return i;

    return -1;
}

int main()
{
    List<int> myList;

    myList.push_back(10);
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_front(7);
    myList.push_front(11);
    myList.push_front(28);
    myList.push_front(32);
    myList.push_front(99);

    cout << "List: " << myList << endl;

    cout << "Element at index 2: " << myList.at(2) << endl;

    myList.remove_by_index(1);
    cout << "After removing element at index 1: " << myList << endl;

    myList.add_by_index(1, 15);
    cout << "After adding 15 at index 1: " << myList << endl;

    cout << "Front element: " << myList.front() << endl;
    cout << "Back element: " << myList.back() << endl;

    myList.pop_back();
    myList.pop_front();
    cout << "After pop_back and pop_front: " << myList << endl;


    myList.sort();
    cout << "After sorting in ascending order: " << myList << endl;


    myList.bubbleSortDescending();
    cout << "After sorting in descending order: " << myList << endl;


    myList.my_unique();
    cout << "After removing duplicates: " << myList << endl;


    cout << "Minimum value: " << myList.my_min() << endl;
    cout << "Maximum value: " << myList.my_max() << endl;
    cout << "Sum of elements: " << myList.my_sum() << endl;

    return 0;
}
