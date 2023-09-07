#ifndef IOAN_VECTOR_H // include guard sau header guard
#define IOAN_VECTOR_H
#include <stdexcept>

namespace it
{

template<typename T>
	struct vector_iterator
	{
	public:
		using value_type = T;
		using pointer = value_type*;
		using reference = value_type&;
		
		vector_iterator() : m_ptr(nullptr) {}
		vector_iterator(const vector_iterator& other) : m_ptr(other.m_ptr) {}
		vector_iterator(vector_iterator&& other) noexcept : m_ptr(other.m_ptr) { other.m_ptr = nullptr; }
		vector_iterator(pointer ptr) : m_ptr(ptr) {}

		vector_iterator& operator=(const vector_iterator& other);
		vector_iterator& operator=(vector_iterator&& other) noexcept;

		friend bool operator==(const vector_iterator& Lhs, const vector_iterator& Rhs) { return Lhs.m_ptr == Rhs.m_ptr; }

		friend bool operator!=(const vector_iterator& Lhs, const vector_iterator& Rhs) { return Lhs.m_ptr != Rhs.m_ptr; }
		friend bool operator<(const vector_iterator& Lhs, const vector_iterator& Rhs) { return Lhs.m_ptr < Rhs.m_ptr; }
		friend bool operator>(const vector_iterator& Lhs, const vector_iterator& Rhs) { return Lhs.m_ptr > Rhs.m_ptr; }
		friend bool operator<=(const vector_iterator& Lhs, const vector_iterator& Rhs) { return Lhs.m_ptr <= Rhs.m_ptr; }
		friend bool operator>=(const vector_iterator& Lhs, const vector_iterator& Rhs) { return Lhs.m_ptr >= Rhs.m_ptr; }

		vector_iterator operator++(int) { pointer tmp = m_ptr; ++m_ptr; return tmp; }
		vector_iterator& operator++() { ++m_ptr; return *this; }
		vector_iterator operator--(int) { pointer tmp = m_ptr; --m_ptr; return tmp; }
		vector_iterator& operator--() { --m_ptr; return *this; }
		vector_iterator operator+(int Rhs) const { return m_ptr + Rhs; }
		vector_iterator operator-(int Rhs) const { return m_ptr - Rhs; }
		vector_iterator& operator+=(int Rhs) { m_ptr += Rhs; return *this; }
		vector_iterator& operator-=(int Rhs) { m_ptr -= Rhs; return *this; }
		friend vector_iterator operator+(size_t Lhs, const vector_iterator& Rhs) { return Rhs.m_ptr + Lhs; }
		operator-(const vector_iterator& Rhs) const { return abs(m_ptr - Rhs.m_ptr); }

		pointer ptr() const { return m_ptr; }

		reference operator*() const { return *m_ptr; }
		pointer operator->() const { return m_ptr; }

	private:
		pointer m_ptr;
	};

	template<typename T>
	vector_iterator<T >& vector_iterator<T >::operator=(const vector_iterator& other)
	{
		if (this != &other)
		{
			m_ptr = other.m_ptr;
		}
		return *this;
	}

	template<typename T>
	vector_iterator<T >& vector_iterator<T >::operator=(vector_iterator&& other) noexcept
	{ 
		if (this != &other)
		{
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
		return *this; 
	}

	template<typename T>
	struct vector_reverse_iterator
	{
	public:
		using value_type = T;
		using pointer = value_type*;
		using reference = value_type&;

		vector_reverse_iterator() : m_ptr(nullptr) {}
		vector_reverse_iterator(const vector_reverse_iterator& other) : m_ptr(other.m_ptr) {}
		vector_reverse_iterator(vector_reverse_iterator&& other) noexcept : m_ptr(other.m_ptr) { other.m_ptr = nullptr; }
		vector_reverse_iterator(pointer ptr) : m_ptr(ptr) {}

		vector_reverse_iterator& operator=(const vector_reverse_iterator& other);
		vector_reverse_iterator& operator=(vector_reverse_iterator&& other) noexcept;

		friend bool operator==(const vector_reverse_iterator& Lhs, const vector_reverse_iterator& Rhs) { return Lhs.m_ptr == Rhs.m_ptr; }
		friend bool operator!=(const vector_reverse_iterator& Lhs, const vector_reverse_iterator& Rhs) { return Lhs.m_ptr != Rhs.m_ptr; }
		friend bool operator<(const vector_reverse_iterator& Lhs, const vector_reverse_iterator& Rhs) { return Lhs.m_ptr > Rhs.m_ptr; }
		friend bool operator>(const vector_reverse_iterator& Lhs, const vector_reverse_iterator& Rhs) { return Lhs.m_ptr < Rhs.m_ptr; }
		friend bool operator<=(const vector_reverse_iterator& Lhs, const vector_reverse_iterator& Rhs) { return Lhs.m_ptr >= Rhs.m_ptr; }
		friend bool operator>=(const vector_reverse_iterator& Lhs, const vector_reverse_iterator& Rhs) { return Lhs.m_ptr <= Rhs.m_ptr; }

		vector_reverse_iterator operator++(int) { pointer tmp = m_ptr; --m_ptr; return tmp; }
		vector_reverse_iterator& operator++() { --m_ptr; return *this; }
		vector_reverse_iterator operator--(int) { pointer tmp = m_ptr; ++m_ptr; return tmp; }
		vector_reverse_iterator& operator--() { ++m_ptr; return *this; }
		vector_reverse_iterator operator+(int Rhs) const { return m_ptr - Rhs; }
		vector_reverse_iterator operator-(int Rhs) const { return m_ptr + Rhs; }
		vector_reverse_iterator& operator+=(int Rhs)	{ m_ptr -= Rhs; return *this; }
		vector_reverse_iterator& operator-=(int Rhs)	{ m_ptr += Rhs; return *this; }
		friend vector_reverse_iterator operator+(int Lhs, const vector_reverse_iterator& Rhs) { return Rhs.m_ptr - Lhs; }
		size_t operator-(const vector_reverse_iterator& Rhs)	const { return abs(m_ptr - Rhs.m_ptr); }

		pointer ptr() const { return m_ptr; }
		reference operator*() const { return *m_ptr; }
		pointer operator->() const { return m_ptr; }

		

	private:
		pointer m_ptr;
	};

	template<typename T>
	vector_reverse_iterator<T >& vector_reverse_iterator<T >::operator=(const vector_reverse_iterator& other)
	{
		if (this != &other)
		{
			m_ptr = other.m_ptr;
		}
		return *this;
	}

	template<typename T>
	vector_reverse_iterator<T >& vector_reverse_iterator<T >::operator=(vector_reverse_iterator&& other) noexcept
	{
		if (this != &other)
		{
			m_ptr = other.m_ptr;
			other.m_ptr = nullptr;
		}
		return *this;
	}



template<typename T>
class vector
{
    public:
        using value_type = T;
        using pointer = value_type*;
    public:

        vector();
        vector(const vector& other);
        vector(vector&& other); // move constructor
        vector(const std::initializer_list<value_type>& ilist); // initializer list constructor
        ~vector();

        bool operator==(const vector& other);
        bool operator!=(const vector& other) { return !(*this == other); }

        vector& operator=(const vector& other);
        vector& operator=(vector&& other); // move assignment operator

        pointer data();
        size_t capacity(); 
        size_t size();

        void clear();
        bool empty();

        void push_back(value_type value);
        void insert(size_t pos, value_type value);
        void erase(size_t pos);
        void pop_back();

        value_type& operator[](size_t offset);
        value_type& at(size_t offset);
        value_type& front();
        value_type& back();

        void reserve(size_t new_cap);
        void shrink_to_fit();

    private:
        void realloc(size_t new_cap);

    private:

        pointer m_data = nullptr;
        size_t m_size = 0;
        size_t m_capacity = 0;
};

template<typename T>
vector<T>::vector()
     : m_data(nullptr), m_size(0), m_capacity(0)
{}

template<typename T>
vector<T>::vector(const vector& other)
    : m_data(new int[other.m_capacity]), m_size(other.m_size), m_capacity(other.m_capacity)
{
    for(int i = 0; i < m_size; ++i)
    {
        m_data[i] = other.m_data[i];
    }
 
}

template<typename T>
vector<T>::vector(vector&& other)
{
    printf("Move!\n");

    m_data = other.m_data;
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template<typename T>
vector<T>::vector(const std::initializer_list<value_type>& ilist)
{
    printf("IList\n");
    for(auto it = ilist.begin(); it != ilist.end(); ++it)
    {
        push_back(*it);
    }
}

template<typename T>
vector<T>::~vector()
{
    delete[] m_data;
}

template<typename T>
bool vector<T>::operator==(const vector& other)
{
    if(m_size != other.m_size)
    {
        return 0;
    }

    for(int i = 0; i < m_size ; i++)
    {
        if(m_data[i] != other.m_data[i])
        {
            return(0);
        }
    }

    return 1;

}

template<typename T>
vector<T>& vector<T>::operator=(const vector& other)
{
    delete[] m_data;
    m_data = new int[other.m_capacity];
    m_size = other.m_size;
    m_capacity = other.m_capacity;
 
 
 
    for(int i = 0 ; i < m_size ; i++)
    {
        m_data[i] = other.m_data[i];
    }
 
    return *this;
}

template<typename T>
vector<T>& vector<T>::operator=(vector&& other)
{      
    if(this != other)
    {
        delete [] m_data;

        m_data = other.m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }
    return *this;
}

template<typename T>
T* vector<T>::data()
{
    return m_data;
}

template<typename T>
size_t vector<T>::capacity()
{
    return m_capacity;
}

template<typename T>
size_t vector<T>::size() 
{ 
    return m_size;
}

template<typename T>
void vector<T>::clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_capacity = 0;
    m_size = 0;
}

template<typename T>
bool vector<T>::empty() 
{ 
    return m_size == 0;
}

template<typename T>
void vector<T>::push_back(value_type value)
{
   if(m_size >= m_capacity)
    {
        realloc(m_capacity * 1.5);
    }
 
   m_data[m_size] = value;
   m_size++;
}

template<typename T>
void vector<T>::insert(size_t pos, value_type value)
{
    if(m_size >= m_capacity)
    {
        realloc(m_capacity * 1.5);
    }
 
    for(size_t i = m_size;i > pos;i--)
    {
        m_data[i] = m_data[i - 1];
    }
 
    m_data[pos] = value;
    m_size++;
}

template<typename T>
void vector<T>::erase(size_t pos)
{
    if(m_size > 0)
    {
        for(size_t i = pos;i < m_size - 1;i++)
        {
            m_data[i] = m_data[i + 1];
        }
        m_size--;
    }
}

template<typename T>
void vector<T>::pop_back()
{
   m_size--;
}

template<typename T>
T& vector<T>::operator[](size_t offset)
{
    return m_data[offset];
}

template<typename T>
T& vector<T>::at(size_t offset)
{
    if(offset > m_size)
    {
        throw std::out_of_range("The element don t exist");
    }
    return m_data[offset];
}

template<typename T>
T& vector<T>::front()
{   
    if(m_size == 0) 
    {
        throw std::out_of_range("front called on empty vector");
    }
     return m_data[0];   
}

template<typename T>
T& vector<T>::back()
{  
    if(m_size == 0) 
    {
        throw std::out_of_range("back called on empty vector");
    }
    return m_data[m_size - 1];       
}

template<typename T>
void vector<T>::reserve(size_t new_cap)
{
    if(new_cap > m_capacity)
    {
        realloc(new_cap);
    }
}

template<typename T>
void vector<T>::shrink_to_fit()
{
    if(m_size != m_capacity)
    {
        realloc(m_size);
    }
}
 
template<typename T>
void vector<T>::realloc(size_t new_cap)
{
    if(new_cap < 10)
    {
        new_cap = 10;
    }
 
    pointer temp = new value_type[new_cap];
 
    for(size_t i = 0; i < m_size; i++)
    {
        temp[i] = m_data[i];
    }
 
    delete[] m_data;
    m_capacity = new_cap;
    m_data = temp;
}

} // namespace it

#endif