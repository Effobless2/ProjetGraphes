#ifndef EMPLACEMENT_HPP
#define EMPLACEMENT_HPP

#include <iostream>

template<class K, class V>
class Emplacement{
    private:
        K key;
        V value;

    public:
        Emplacement* next = NULL;
        Emplacement();
        Emplacement(K key, V value);
        ~Emplacement();

        K getKey()const {return key;}
        V getValue()const {return value;}
        Emplacement* getNext(){return next;}

        void setValue(V newValue) {value = newValue;}

        friend std::ostream & operator << (std::ostream& os, Emplacement const & e);

};
template<class K, class V>
Emplacement<K, V>::Emplacement(){
}

template<class K, class V>
Emplacement<K, V>::Emplacement(K key, V value){
    this->key = key;
    this->value = value;
}
template<class K, class V>
Emplacement<K,V>::~Emplacement(){
    if (this->next != NULL){
        delete this->next;
    }

}

template<class K, class V>
std::ostream & operator << (std::ostream& os, Emplacement<K, V> const & e){
    os << e.getKey() << " : " << e.getValue() << std::endl;
    return os;
}
#endif