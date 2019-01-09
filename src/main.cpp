#include "../hpp/Graph.hpp"
#include "../hpp/Tas.hpp"

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

    std::cout << *n1 << std::endl;

    //Ajout de noeud et suppression
    Noeud <int, int> *nTest = new Noeud<int, int>(100);
    graph->addNoeud(nTest);
    graph->affiche();
    graph->removeNoeud(nTest);
    graph->affiche();

    //Ajout de chemin et suppression
    std::cout << *n1 << std::endl;
    std::cout << *n2 << std::endl;
    graph->addPath(n1, n2, 5);
    std::cout << *n1 << std::endl;
    std::cout << *n2 << std::endl;
    graph->removePath(n1,n2);
    std::cout << *n1 << std::endl;
    std::cout << *n2 << std::endl;


    Tas<int> *tasTest = new Tas<int>();
    int t1 = 1;
    int t2 = 2;
    int t3 = 3;
    int t4 = 4;
    int t5 = 5;
    int t6 = 6;
    tasTest->ajout(&t6);
    tasTest->ajout(&t5);
    tasTest->ajout(&t4);
    tasTest->ajout(&t3);
    tasTest->ajout(&t2);
    tasTest->ajout(&t1);

    std::cout << *tasTest << std::endl; //1,3,2,6,4,5,

    std::cout << *tasTest->outMin() << std::endl; //1

    std::cout << *tasTest << std::endl; //2,3,5,6,4,

    std::cout << tasTest->recherche(&t2) << std::endl; //true

    std::cout << tasTest->recherche(&t1) << std::endl; // false
    


    delete nTest;
    
    delete graph;

    delete tasTest;

    return 0;
}