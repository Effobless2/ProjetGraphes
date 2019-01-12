#ifndef TAS_ID_HPP
#define TAS_ID_HPP

#include "Tas.hpp"
#include <map>

template<class N, int compare(N,N)>
class Tas_Id : public Tas<N,compare>{
    private:
        std::map<N*,int> dico;

    public:
        Tas_Id();
        Tas_Id(N*);
        Tas_Id(std::map<N*,int>);
        Tas_Id(std::vector<N*>);

        ~Tas_Id();

        std::map<N*,int> getDico() const {return dico;}


        void ajout(N*);

        void updateTas(N*);

        int getSize() const { return Tas<N,compare>::tas.size(); }
        int getSizeDico() const { return dico.size(); }

        N* outMin();

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

template<class N, int compare(N,N)>
void Tas_Id<N,compare>::ajout(N* newElem){
    std::cout << newElem << std::endl;
    std::cout << "on ajoute" << std::endl;
    Tas<N,compare>::tas.push_back(newElem);
    dico[newElem] = Tas<N,compare>::tas.size()-1;

    int curId = Tas<N,compare>::tas.size() - 1;
    std::cout << curId << std::endl;

    int curParent = (curId - 1) / 2;
    std::cout << curParent << std::endl;

    while(curParent >=0){
        std::cout << "in while" << std::endl;
        if (compare(*Tas<N,compare>::tas[curId],*Tas<N,compare>::tas[curParent])){
            std::swap(Tas<N,compare>::tas[curId], Tas<N,compare>::tas[curParent]);
            std::cout << "         ca bouge" << std::endl;
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
N* Tas_Id<N,compare>::outMin(){
    std::swap(Tas<N,compare>::tas[0], Tas<N,compare>::tas[Tas<N,compare>::tas.size()-1]);
    N* result = Tas<N,compare>::tas[Tas<N,compare>::tas.size()-1];
    Tas<N,compare>::tas.erase(Tas<N,compare>::tas.end()-1);
    dico.erase(result);
    
    if (Tas<N,compare>::tas.size() > 1){
        int curNode = 0;

        int nextToCompare = compare(*Tas<N,compare>::tas[1],*Tas<N,compare>::tas[2]) ? 1 : 2;
        while(nextToCompare < Tas<N,compare>::tas.size()){
            if (Tas<N,compare>::tas[curNode] > Tas<N,compare>::tas[nextToCompare]){
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