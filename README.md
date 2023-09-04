In this library i tried to recreate the std vector library implementing the most important functions and making them as similiar as i could do.
It works with dinamic memory,it is able to auto allocate memory(if needed) when u push an element in the vector and many more.

Minimum C++11.

# Sample
```cpp

#include <iostream>
#include "ioan_vector.h"

int main()
{
    it::vector<int> v1;
    it::vector<int> v2({1,2,3,5});

    v1 = v2

    for(int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n";

    cout<< v1.size()<<"\n";
    v1.pop_back();
    v1.push_back(10);
    for(int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n";
    v2.clear();
    cout << v2.empty() << "\n";
    cout << v2.size();
    try
    { 
        v.front() = 10;
    }

    catch(std::out_of_range e)
    {
        std::cout << e.what()<< "\n";
    }


    v1.erase(2);
    v1.insert(3,10);
    v1.capacity();


}
```



