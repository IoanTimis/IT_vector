#include <iostream>
#include "ioan_vector.h"




int main()
{
    it::vector<int> v,z;
    it::vector<int> k({1,2,3,5});

    std::cout << k.capacity()<<" " << k.size() <<"\n";

    std::cout <<"cap: "<<v.capacity()<<"\n";

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    std::cout <<"cap: "<<v.capacity()<<"\n";

    v.push_back(11);

    std::cout <<"cap: "<<v.capacity()<<"\n";

    //v.clear();

    std::cout<<"size: "<< v.size()<<"\n";
    std::cout<<"cap: "<< v.capacity()<<"\n";
    std::cout<<"Vectorul simplu: ";
    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

    std::cout << "\nInsert 10: ";
    v.insert(3,10);

    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

    std::cout<<"\nsize: "<< v.size()<<"\n";

    std::cout << "Sters 5: ";
    v.erase(5);

    for(int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

    std::cout<<"\nGol? " << v.empty();
    std::cout<<"\nsize: "<< v.size()<<"\n";

    std::cout<<"v de ceva: "<< v[0]<<"\n";

    z = v;
    std::cout <<"copia lui v: ";
    for(int i = 0; i < z.size(); i++)
    {
        std::cout << z[i] << " ";
    }
    std::cout<< "\n";

    std::cout<< "Copia lui v dupa pop_back: ";
    z.pop_back();
    for(int i = 0; i < z.size(); i++)
    {
        std::cout << z[i] << " ";
    }
    std::cout<< "\n";


    std::cout <<"(vectorul v)Primu element: " << v.front() <<" , " << "Ultimu element: " << v.back()<<"\n";

    std::cout <<"cap: "<<v.capacity()<<"\n";
    v.reserve(20);
    std::cout <<"Dupa reserve cap: "<<v.capacity()<<"\n";
    v.shrink_to_fit();
    std::cout <<"Dupa shrink cap: "<<v.capacity()<<"\n";
    v.reserve(15);
    std::cout <<"Dupa reserve cap: "<<v.capacity()<<"\n";
    
    v.clear();
    std::cout<<"Gol(dupa clear)? " << v.empty() << "\n"; 
    
    try
    { 
        v.front() = 10;
    }

    catch(std::out_of_range e)
    {
        std::cout << e.what()<< "\n";
    }

    try
    { 
        v.back() = 10;
    }

    catch(std::out_of_range e)
    {
        std::cout << e.what()<< "\n";
    }

     try
    { 
       std::cout << v.at(5)<< "\n";
    }

    catch(std::out_of_range e)
    {
        std::cout << e.what()<< "\n";
    }

    v.clear();
    z.clear();

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    z.push_back(2);
    z.push_back(3);
    z.push_back(4);

    if(v == z)
    {
        std::cout << "Sunt egale! \n";
    }

    else
    {
        std::cout << "Nu sunt egale! \n";
    }

    
    system("pause");

    
}
