In this library i tried to recreate the std vector library implementing the most important functions and making them as similiar as i could do.

It works with dinamic memory,it is able to auto allocate memory(if needed) when u push an element in the vector and many more.

Minimum C++11.

# Sample
```cpp

#include <iostream>
#include "ioan_vector.h"

int main()
{
    it::vector<int> v1,v2,x;
    it::vector<int> z({1,2,3,5});
    
    std::cout <<"Vector: ";
    for(int i = 0; i < z.size(); i++)
    {
        std::cout << z[i] << " ";
    }
    std::cout << "\n";

    v2 = std::move(z);
    std::cout << "Afisare vector dupa move: ";
    for(int i = 0; i < z.size(); i++)
    {
        std::cout << z[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Size si cap dupa move: " << z.size()<< " " << z.capacity() << "\n";

    v1 = v2;
    x = v2;

    it:: vector<int> y(std::move(x));
    std::cout <<"Copierea vectorului v2 in v1: ";
    for(int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Size v1: " <<v1.size()<< "\n";

    v1.pop_back();
    v1.push_back(10);

    std::cout <<"v1 dupa pop_back() si push_back(10): ";
    for(int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n";

    v2.clear();

    std::cout << "Valori v2 dupa clear() (empty(),size(),capacity()): " << v2.empty() << " " << v2.size() <<" "<< v2.capacity() << "\n";

    try
    { 
        v1.front() = 10;
    }

    catch(std::out_of_range e)
    {
        std::cout << e.what()<< "\n";
    }

    v1.erase(2);
    v1.insert(3,10);
    v1.capacity();
    v1.shrink_to_fit();
    v1.reserve(20);



}

```



