#ifndef OUR_PAIR_HPP
#define OUR_PAIR_HPP

/*
Représente une paire générique
*/

#include <iostream>
template<class A, class B>
class ourPairs{
    public:
    	A first;
	    B second;
        
        ourPairs(A f, B s){
            first = f;
            second = s;
        }

        template<class A2, class B2>
        friend std::ostream& operator << (
                std::ostream &os, 
                const ourPairs<A2,B2> &pair);
};

/*
    Permet de comparer deux paires
*/
template<class A, class B>
int pairCompare(ourPairs<A,B> p1, ourPairs<A,B> p2){
    return p1.second < p2.second ? 1 : 0;
}


/*
    Surcharge de << pour l'affichage d'une paire
*/
template<class A, class B>
std::ostream& operator << (std::ostream &os,  const ourPairs<A,B> &pair){
    os << *(pair.first) << std::endl;
    os << "    :    ";
    os << pair.second << std:: endl;
    return os;                
}

#endif