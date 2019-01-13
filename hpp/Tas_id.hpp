#ifndef TAS_ID_HPP
#define TAS_ID_HPP

#include "Tas.hpp"
#include <map>

template<class N, int compare(N,N)>
class Tas_Id : public Tas<N,compare>{
    private:
        // Map qui associe à un l'élement son index dans le vector tas
        std::map<N*,int> dico;

    public:
        // CONSTRUCTORS
        Tas_Id();
        Tas_Id(N*);
        Tas_Id(std::map<N*,int>);
        Tas_Id(std::vector<N*>);
        // DESTRUCTOR
        ~Tas_Id();

        // Recupère la map
        std::map<N*,int> getDico() const {return dico;}
        // Permet d'ajouter un élément dans le tas
        void ajout(N*);
        // Mets à jour l'élément N* dans le tas
        void updateTas(N*);
        // Recupère la taille du tas
        int getSize() const { return Tas<N,compare>::tas.size(); }
        // Recupère la taille du dico
        int getSizeDico() const { return dico.size(); }
        // Recupère le plus petit élément du tas
        N* outMin();
        // Surcharge de l'opérateur <<
        template<class N2, int comp(N2,N2)>
            friend std::ostream& operator << (
                std::ostream &os,
                const Tas_Id<N2, comp> &tas
            );
        
};

template<class N, int compare(N,N)>
Tas_Id<N,compare>::Tas_Id() : Tas<N,compare>::Tas(){
    dico = std::map<N*, int>();
}


template<class N, int compare(N,N)>
Tas_Id<N,compare>::Tas_Id(N* node) : Tas<N,compare>::Tas(node){
    dico = std::map<N, int>();
    dico.insert(node, 0);
    
}

template<class N, int compare(N,N)>
Tas_Id<N,compare>::Tas_Id(std::vector<N*> vec) : Tas<N,compare>::Tas(vec){
    dico = std::map<N, int>();
    for(int it = 0; it < Tas<N,compare>::tas.size(); it++){
        dico[Tas<N,compare>::tas[it]] = it;
    }
    
}

template<class N, int compare(N,N)>
Tas_Id<N,compare>::~Tas_Id(){
    
}


/*
    Surchaege de ajout() de la classe mère Tas
    On ajoute un élément id au tas à la fin puis on rééquilibre celui-ci
    On ajoute aussi l'élement et son index dans la map dico
*/
template<class N, int compare(N,N)>
void Tas_Id<N,compare>::ajout(N* newElem){
    Tas<N,compare>::tas.push_back(newElem);
    dico[newElem] = Tas<N,compare>::tas.size()-1;

    int curId = Tas<N,compare>::tas.size() - 1;

    int curParent = (curId - 1) / 2;

    while(curParent >=0){
        if (compare(*Tas<N,compare>::tas[curId],*Tas<N,compare>::tas[curParent])){
            std::swap(Tas<N,compare>::tas[curId], Tas<N,compare>::tas[curParent]);
            dico[Tas<N,compare>::tas[curId]] = curId;
            dico[Tas<N,compare>::tas[curParent]] = curParent;
            
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
    On supprime aussi l'élément dans la map dico et mets à jour les valeurs dans la map lors du rééquilibrage
*/
template<class N, int compare(N,N)>
N* Tas_Id<N,compare>::outMin(){
    std::swap(Tas<N,compare>::tas[0], Tas<N,compare>::tas[Tas<N,compare>::tas.size()-1]);
    N* result = Tas<N,compare>::tas[Tas<N,compare>::tas.size()-1];
    Tas<N,compare>::tas.erase(Tas<N,compare>::tas.end()-1);
    dico.erase(result);
    
    dico[Tas<N,compare>::tas[0]] = 0;
    if (Tas<N,compare>::tas.size() > 2){
        int curNode = 0;

        unsigned int nextToCompare = compare(*Tas<N,compare>::tas[1],*Tas<N,compare>::tas[2]) ? 1 : 2;
        while(nextToCompare < Tas<N,compare>::tas.size()){
            if (compare((*Tas<N,compare>::tas[nextToCompare]),(*Tas<N,compare>::tas[curNode]))){
                std::swap(Tas<N,compare>::tas[nextToCompare], Tas<N,compare>::tas[curNode]);
                dico[Tas<N,compare>::tas[curNode]] = curNode;
                dico[Tas<N,compare>::tas[nextToCompare]] = nextToCompare;

                curNode = nextToCompare;
                if (Tas<N,compare>::tas.size() > nextToCompare * 2 + 2){
                    nextToCompare = compare(*Tas<N,compare>::tas[nextToCompare * 2 + 1], *Tas<N,compare>::tas[nextToCompare * 2 + 2]) ? 
                        nextToCompare * 2 + 1 
                    : 
                        nextToCompare * 2 + 2;
                } else if (Tas<N,compare>::tas.size() > nextToCompare * 2 + 1){
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


/*
    Permet de mettre à jour un élément du tas. On utilise la map dico pour trouver cet élément et changer sa valeur pour on rééquilibre le tas et on met à jour la map dico
*/
template<class N, int compare(N,N)>
void Tas_Id<N,compare>::updateTas(N* updated){
    int curId = dico[updated];

    int curParent = (curId - 1) / 2;

    while(curParent >=0){
        if (compare(*Tas<N,compare>::tas[curId],*Tas<N,compare>::tas[curParent])){
            std::swap(Tas<N,compare>::tas[curId], Tas<N,compare>::tas[curParent]);
            dico[Tas<N,compare>::tas[curId]] = curId;
            dico[Tas<N,compare>::tas[curParent]] = curParent;
            
            curId = curParent;
            curParent = (curId - 1) / 2;
        }
        else {
            break;
        }
    }

}


template<class N, int compare(N,N)>
std::ostream& operator << (std::ostream &os, Tas_Id<N,compare> &tas){
    std::vector<N*> ltas = tas.getTas();
    for(typename std::vector<N*>::iterator it = ltas.begin(); it != ltas.end(); it++){
        os << **it;
        os << ",";
    }
    os << std::endl;

    os << std::endl;
    std::map<N*,int> dicoTas = tas.getDico();
    for(typename std::map<N*,int>::iterator it = dicoTas.begin(); it != dicoTas.end(); it++){
        os << *(it->first) << " : " << it->second << std::endl;
    }
    
    return os;
}


#endif