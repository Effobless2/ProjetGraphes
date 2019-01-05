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



    /////Tests/////
    //Affichage
    graph->affiche();

    //Ajout de noeud et suppression
    Noeud <int, int> *nTest = new Noeud<int, int>(100);
    graph->addNoeud(nTest);
    graph->affiche();
    graph->removeNoeud(nTest);
    graph->affiche();

    //Ajout de chemin et suppression
    std::cout << n1->getNeighbours().size() << std::endl;
    std::cout << n2->getNeighbours().size() << std::endl;
    graph->addPath(n1, n2, 5);
    std::cout << n1->getNeighbours().size() << std::endl;
    std::cout << n2->getNeighbours().size() << std::endl;
    graph->removePath(n1,n2);
    std::cout << n1->getNeighbours().size() << std::endl;
    std::cout << n2->getNeighbours().size() << std::endl;

    delete nTest;
    
    delete graph;
    return 0;
}