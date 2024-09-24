#include "hash.hpp"
#include <iostream>

int main(){
    myDataStructures::HashTable<std::string,std::string> phoneBook;
    phoneBook.insert("John","1234567890");
    phoneBook.insert("Jane","0987654321");
    phoneBook.insert("Doe","1234567890");
    phoneBook.insert("Smith","0987654321");
    
    std::cout<<phoneBook["John"]<<std::endl;
    std::cout<<phoneBook["Jane"]<<std::endl;
    std::cout<<phoneBook["Doe"]<<std::endl;
    std::cout<<phoneBook["Smith"]<<std::endl;
}