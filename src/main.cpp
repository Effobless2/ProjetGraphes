#include "../hpp/Graph.hpp"

int main(){
    std::cout << "Hello World" << std::endl;

    Noeud<int, int> *n1 = new Noeud<int, int>(1);
    Noeud<int, int> *n2 = new Noeud<int, int>(2);
    Noeud<int, int> *n3 = new Noeud<int, int>(3);
    Noeud<int, int> *n4 = new Noeud<int, int>(4);
    Noeud<int, int> *n5 = new Noeud<int, int>(5);
    Noeud<int, int> *n6 = new Noeud<int, int>(6);
    Noeud<int, int> *n7 = new Noeud<int, int>(7);
    Noeud<int, int> *n8 = new Noeud<int, int>(8);


    std::vector<Noeud<int,int>*> vec = std::vector<Noeud<int,int>*>();
    vec.push_back(n1);
    vec.push_back(n2);
    vec.push_back(n3);
    vec.push_back(n4);
    vec.push_back(n5);
    vec.push_back(n6);
    vec.push_back(n7);
    vec.push_back(n8);


    Graph<int, int>* graph = new Graph<int,int>(vec);


    graph->affiche();
    std::cout << std::endl;

    std::cout << *graph << std::endl;

    
    delete graph;
    return 0;
}