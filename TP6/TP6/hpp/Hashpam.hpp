#ifndef HASHPAM_HPP
#define HASHPAM_HPP
#include "./emplacement.hpp"

template <class K, class V, int hash(K, int)>
class Hashpam{
    private:
        Emplacement<K, V>** dico;
        int size;
    public:
        Hashpam();
        Hashpam(int n);
        ~Hashpam();

        void add(K key, V value);
        void remove(K key);
        V getValue(K key);
};

template<class K, class V, int hash(K,int)>
Hashpam<K,V, hash>::Hashpam(){
    this->size = 20;
    dico = new Emplacement<K,V>*[20];
    for (int i = 0; i<20; i++){
        this->dico[i] = NULL;
    }
}

template<class K, class V,int hash(K,int)>
Hashpam<K,V, hash>::Hashpam(int n){
    this->size = n;
    dico = new Emplacement<K,V>*[n];
    for (int i = 0; i<n; i++){
        this->dico[i] = NULL;
    }
}

template<class K, class V, int hash(K,int)>
Hashpam<K,V,hash>::~Hashpam(){
    for (int i = 0; i < this->size; i++){
        delete this->dico[i];
    }
    delete[] this->dico;
}

template<class K, class V, int hash(K,int)>
void Hashpam<K,V, hash>::add(K key, V value){
    int index = hash(key, size);
    if (this->dico[index] == NULL){
        Emplacement<K,V>* emp = new Emplacement<K,V>(key,value);
        this->dico[index] = emp;
    }
    else{
        Emplacement<K,V>* cur = this->dico[index];
        while (cur->next != NULL && cur->getKey() != key){
            cur = cur->next;
        }

        if (cur->getKey() == key){
            cur->setValue(value);
        } else {
            cur->next = new Emplacement<K,V>(key,value);
        }
    }
}

template<class K, class V, int hash(K,int)>
V Hashpam<K,V, hash>::getValue(K key){
    int index = hash(key, size);
    if (this->dico[index] != NULL){
        if (this->dico[index]->next == NULL & this->dico[index]->getKey() == key){
            return this->dico[index]->getValue();
        }
        else{
            Emplacement<K,V> *cur = this->dico[index];
            while ((*cur).next != NULL & (*cur).getKey() != key){
                cur = (*cur).next;
            }
            return (*cur).getKey() == key ? (*cur).getValue() : NULL;
        }
    }
}

template<class K, class V, int hash(K,int)>
void Hashpam<K,V, hash>::remove(K key){
    int index = hash(key, size);
    if (this->dico[index] != NULL){
        Emplacement<K,V>* cur = this->dico[index];
        while ((*cur).next != NULL & (*cur).getKey() != key){
            cur = cur->next;
        }
        if ((*cur).getKey() == key){
            if ((*cur).next == NULL){
                delete cur;
            }
            else{
                Emplacement<K,V> tmp = (*cur);
                cur = (*cur).next;
                delete &tmp;
            }
        }
    }
}

#endif