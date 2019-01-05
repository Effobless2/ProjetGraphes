#ifndef GRAPH_HPP

#define GRAPH_HPP

#include "Noeud.hpp"

template<class I, class C>
class Graph{
    private:
        std::vector<Noeud<I,C>*> nodes;

    public:
        Graph();
        Graph(std::vector<Noeud<I,C>*> nodes);
        Graph(Noeud<I,C>* node);
        ~Graph();

        std::vector<Noeud<I,C>*> getNodes() const {return nodes;}

        void addNoeud(Noeud<I,C> *node);
        void removeNoeud(Noeud<I,C>* node);
        void removePath(Noeud<I,C>*, Noeud<I,C>*);
        void addPath(Noeud<I,C>* begin, Noeud<I,C>* end, C cost);

        void affiche();
        template <class I2, class C2>
            friend std::ostream& operator << (
                std::ostream &os, 
                const Graph<I2,C2> & g);

};

template<class I, class C>
Graph<I,C>::Graph(){
    nodes = std::vector<Noeud<I,C>*>();
}

template<class I, class C>
Graph<I,C>::Graph(std::vector<Noeud<I,C>*> nodes){
    this->nodes = nodes;
}

template<class I, class C>
Graph<I,C>::Graph(Noeud<I,C>* node){
    this->nodes = std::vector<Noeud<I,C>*>();
    this->addNoeud(node);
}

template<class I, class C>
Graph<I,C>::~Graph(){
    for (std::vector<Noeud<int,int>*>::iterator it = nodes.begin(); it != nodes.end(); it++){
        delete *it;
    }
}

template<class I, class C>
void Graph<I,C>::addNoeud(Noeud<I,C> *node){
    this->nodes.push_back(node);
}

template<class I, class C>
void Graph<I,C>::removeNoeud(Noeud<I,C>* node){
    std::vector<std::tr1::tuple<Noeud<I,C>*, C> > vec = node->getNeighbours();
    for (typename std::vector<std::tr1::tuple<Noeud<I,C>*, C> >::iterator it = vec.begin(); it != vec.end(); it++){
        std::tr1::get<0>(*it)->removePath(node);
    }
    for (typename std::vector<Noeud<I,C>*>::iterator it = nodes.begin(); it != nodes.end(); it++){
        if (node == *it){
            nodes.erase(it);
            break;
        }
    }
}

template<class I, class C>
void Graph<I,C>::addPath(Noeud<I,C>* begin, Noeud<I,C>* end, C cost){
    begin->addPath(end, cost);
    end->addPath(begin, cost);
}

template<class I, class C>
void Graph<I,C>::removePath(Noeud<I,C>* n1, Noeud<I,C>* n2){
    n1->removePath(n2);
    n2->removePath(n1);
}

template<class I, class C>
void Graph<I,C>::affiche(){
    std::cout << *this << std::endl;
}

template<class I, class C>
std::ostream& operator << (std::ostream &os, const Graph<I,C> & g){
    os << "{ ";
    std::vector<Noeud<I,C>*> vec = g.getNodes();
    for (typename std::vector<Noeud<I,C>*>::iterator it = vec.begin(); it != vec.end(); it++){
        os << (*it)->get_numero() << " , ";
    }
    os << "}" << std::endl;
    return os;
}
#endif