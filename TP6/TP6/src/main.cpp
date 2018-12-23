#include "../hpp/Hashpam.hpp"

int hash(std::string key, int size){
    return 1;
}

int main(){

    Hashpam<std::string, int, hash>* myMap = new Hashpam<std::string, int, hash>();

    myMap->add("hello", 1);

    std::cout << myMap->getValue("hello") << std::endl;

    delete myMap;

    return 0;
}