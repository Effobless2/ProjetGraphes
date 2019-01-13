#ifndef TAS_HPP

#define TAS_HPP


#include <iostream>
#include <vector>

template<class N, int compFunction(N,N)>
class Tas{
    protected:
        // Vector qui représente le tas
        std::vector<N*> tas;
    public:
        // CONSTRUCTORS
        Tas();
        Tas(N*);
        Tas(std::vector<N*>);
        // DESTRUCTOR
        ~Tas();

        // Recupère le tas
        std::vector<N*> getTas() const {return tas;}
        // Ajoute un élément dans le tas
        virtual void ajout(N*);
        // Retourne le plus petit élément du tas (la racine)
        virtual N* outMin();
        // Recherche si l'élément est présent dans le tas
        bool recherche(N*);
        // Observe si le tas est vide ou non
        bool isEmpty();
        // Surcharge de l'opérateur <<
        template<class N2, int comp(N2,N2)>
            friend std::ostream& operator << (
                std::ostream &os,
                const Tas<N2,comp> &tas);
};

template<class N, int compFunction(N,N)>
Tas<N,compFunction>::Tas(){
    tas = std::vector<N*>();
}

template<class N, int compFunction(N,N)>
Tas<N,compFunction>::Tas(N* first){
    tas = std::vector<N*>();
    tas.push_back(first);
}

template<class N, int compFunction(N,N)>
Tas<N,compFunction>::Tas(std::vector<N*> _tas){
    tas = std::vector<N*>();
    for (typename std::vector<N*>::iterator it = _tas.begin(); it != _tas.end(); it++){
        ajout(*it);
    }
}


template<class N, int compFunction(N,N)>
Tas<N,compFunction>::~Tas(){

}


/*
    On ajoute un élément id au tas à la fin puis on rééquilibre celui-ci
*/
template<class N, int compFunction(N,N)>
void Tas<N,compFunction>::ajout(N* id){
    tas.push_back(id);

    int curId = tas.size() - 1;
    int curParent = (curId - 1) / 2;


    while(curParent >=0){
        if (compFunction(*tas[curId],*tas[curParent])){
            std::swap(tas[curId], tas[curParent]);
            curId = curParent;
            curParent = (curId - 1) / 2;
        }
        else {
            break;
        }
    }
}


/*
    On recupère la racine puis on l'échange de place avec le dernier élément. On supprime l'ancienne racine et on rééquilibre l'arbre
*/
template<class N, int compFunction(N,N)>
N* Tas<N,compFunction>::outMin(){
    std::swap(tas[0], tas[tas.size()-1]);
    N* result = tas[tas.size()-1];
    tas.erase(tas.end()-1);
    
    if (tas.size() > 1){
        int curNode = 0;

        int nextToCompare = compFunction(*tas[1],*tas[2]) ? 1 : 2;
        while(nextToCompare < tas.size()){
            if (tas[curNode] > tas[nextToCompare]){
                std::swap(tas[nextToCompare], tas[curNode]);

                curNode = nextToCompare;
                if (tas.size() > nextToCompare * 2 + 2){
                    nextToCompare = compFunction(*tas[nextToCompare * 2 + 1], *tas[nextToCompare * 2 + 2]) ? 
                        nextToCompare * 2 + 1 
                    : 
                        nextToCompare * 2 + 2;
                } else if (tas.size() > nextToCompare * 2 + 1){
                    nextToCompare = nextToCompare * 2 + 1;
                } else{
                    break;
                }
                
            }
            else{
                break;
            }
        }
    }
    
    return result;
}


template<class N, int compFunction(N,N)>
bool Tas<N,compFunction>::recherche(N* toFind){
    for(typename std::vector<N*>::iterator it = tas.begin(); it != tas.end(); it++){
        if (*it == toFind){
            return true;
        }
    }
    return false;
}


template<class N, int compFunction(N,N)>
std::ostream& operator << (std::ostream &os, const Tas<N, compFunction> &tas){
    std::vector<N*> ltas = tas.getTas();
    for(typename std::vector<N*>::iterator it = ltas.begin(); it != ltas.end(); it++){
        os << **it;
        os << ",";
    }
    os << std::endl;
    return os;
}


template<class N, int compFunction(N,N)>
bool Tas<N, compFunction>::isEmpty(){
    return tas.size() == 0 ? true : false;
}

#endif