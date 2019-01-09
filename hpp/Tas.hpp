#ifndef TAS_HPP

#define TAS_HPP


#include <iostream>
#include <vector>

template<class N, int compFunction(N,N)>
class Tas{
    protected:
        std::vector<N*> tas;
    public:
        Tas();
        Tas(N*);
        Tas(std::vector<N*>);

        ~Tas();

        std::vector<N*> getTas() const {return tas;}

        virtual void ajout(N*);
        virtual N* outMin();
        bool recherche(N*);

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
    tas = _tas;
}


template<class N, int compFunction(N,N)>
Tas<N,compFunction>::~Tas(){/*
    for (typename std::vector<N*>::iterator it = tas.begin(); it != tas.end(); it++){
        delete *it;
    }*/
}

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

    /*
    std::vector<N*>::iterator curId = tas.end()-1;
    std::vector<N*>::iterator it = (curId - 1)/2;
    while(it >= tas.begin()){
        if (**it > *id){
            std::swap(*curId, *it);
            curId = it;
        }
        else{
            it = 
        }
    }*/
}

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
/*
template<class N>
N* outMin(){
    return tas[0];
}*/

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

#endif