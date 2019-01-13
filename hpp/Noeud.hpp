#ifndef NOEUD_HPP
#define NOEUD_HPP


#include <iostream>
#include <vector>

template<class I, class C>
class Noeud{
    private:
        // Liste d'adjacence représentée par un vector de (Noeud, coût) pour chaque voisins du noeud
        std::vector< std::pair< Noeud<I,C>*, C > > neighbours;
        // Identifiant du noeud
        I id;
    public:
        // CONSTRUCTOR
        Noeud(I ident);
        // DESTRUCTOR
        ~Noeud();

        // Recupère les voisins du noeud
        std::vector< std::pair< Noeud<I,C>*, C > > getNeighbours() const { return neighbours; }
        // Recupère l'identifiant du noeud
        I get_numero() const { return id; }
        // Ajoute un chemin entre ce noeud et le noeud node avec un coût cost
        void addPath(Noeud<I,C>* node, C cost);
        // Retire un chemin vers le noeud node
        void removePath(Noeud<I,C>* node);
        // Surcharge de l'opérateur <<
        template <class I2, class C2>
            friend std::ostream& operator << (
                std::ostream &os, 
                const Noeud<I2,C2> &node);

};

template<class I, class C>
Noeud<I,C>::Noeud(I ident){
    id = ident;
    neighbours = std::vector< std::pair< Noeud<I,C>*, C > >();
}

template<class I, class C>
Noeud<I,C>::~Noeud(){

}

template<class I, class C>
void Noeud<I,C>::addPath(Noeud<I,C>* node, C cost){
    this->neighbours.push_back( std::make_pair(node, cost) ) ;
    std::cout << this->get_numero() << " vers " << node->get_numero() << " = " << cost << std::endl;
}

template<class I, class C>
void Noeud<I,C>::removePath(Noeud<I,C>* node){

    std::vector< std::pair< Noeud<I,C>*, C > > vec = neighbours;

    for( typename std::vector< std::pair< Noeud<I,C>*, C > >::iterator it = vec.begin(); it != vec.end(); it++){
        if( it->first == node ){
            neighbours.erase(it);
        }
    }
}

template<class I, class C>
std::ostream& operator << (std::ostream &os,const Noeud<I,C> &node){
    os << node.get_numero() << "{ \n";

    std::vector< std::pair< Noeud<I,C>*, C > > vec = node.getNeighbours();
    
    for( typename std::vector< std::pair< Noeud<I,C>*, C > >::iterator it = vec.begin() ; it != vec.end() ; it++){
        os << " \r{ " << (it->first)->get_numero() << " : " << it->second << "} \n";
    }
    
    os << "}" << std::endl;
    return os;
}




#endif