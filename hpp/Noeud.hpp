#ifndef NOEUD_HPP
#define NOEUD_HPP


#include <iostream>
#include <vector>
#include <tr1/tuple>

//using namespace std;
template<class I, class C>
class Noeud{
    private:
        std::vector<std::tr1::tuple<Noeud<I,C>*, C> > neighbours;
        I id;
    public:
        Noeud(I ident);
        ~Noeud();

        std::vector<std::tr1::tuple<Noeud<I,C>*, C> > getNeighbours() const {return neighbours;}
        I get_numero() const {return id;}
        
        void addPath(Noeud<I,C>* node, C cost);
        void removePath(Noeud<I,C>* node);
        template <class I2, class C2>
            friend std::ostream & operator << (
                std::ostream &os, 
                const Noeud<I2,C2> &node);

};

template<class I, class C>
Noeud<I,C>::Noeud(I ident){
    id = ident;
    neighbours = std::vector<std::tr1::tuple<Noeud<I,C>*, C> >();
}

template<class I, class C>
Noeud<I,C>::~Noeud(){

}

template<class I, class C>
void Noeud<I,C>::addPath(Noeud<I,C>* node, C cost){
    std::cout << "adding" << std::endl;
    this->neighbours.push_back(std::tr1::make_tuple(node, cost));
    std::cout << "added" << std::endl;
}

template<class I, class C>
void Noeud<I,C>::removePath(Noeud<I,C>* node){
    std::vector<std::tr1::tuple<Noeud<I,C>*, C> > vec = neighbours;
    for(typename std::vector<std::tr1::tuple<Noeud<I,C>*, C> >::iterator it = vec.begin(); it != vec.end(); it++){
        if (std::tr1::get<0>(*it) == node){
            neighbours.erase(it);
        }
    }
}

template<class I, class C>
std::ostream& operator << (std::ostream &os,const Noeud<I,C> &node){
    os << node->get_numero() << "{ \n";
    std::vector<std::tr1::tuple<Noeud<I,C>*, int> > vec = node->getNeighbours();
    for (typename std::vector<std::tr1::tuple<Noeud<I,C>*, int> >::iterator it = vec.begin(); it != vec.end(); it++){
        os << "      { " << std::tr1::get<0>(*it)->get_numero() << " : " << std::tr1::get<1>(*it) << " }, \n";
    }

    os << "}" << std::endl;
    return os;
}



#endif