#ifndef OUR_PAIR_HPP
#define OUR_PAIR_HPP

template<class A, class B>
class ourPairs{
    public:
    	A first;
	    B second;
        ourPairs(A f, B s){
            first = f;
            second = s;
        }
};

template<class A, class B>
int pairCompare(ourPairs<A,B> p1, ourPairs<A,B> p2){
    return p1.second < p2.second ? 1 : 0;
}

#endif