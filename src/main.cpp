#include "../hpp/Graph.hpp"
#include "../hpp/Tas_id.hpp"
#include "../hpp/Dijkstra.hpp"



int intComp(int i1, int i2){
    return i1 < i2 ? 1 : 0;
}

/*int pairCompare( std::pair<Noeud<char,int>*, int> p1, std::pair<Noeud<char,int>*, int> p2){
    return p1.second < p2.second ? 1 : 0;
    //return std::tr1::get<1>(i1) < std::tr1::get<1>(i2) ? 1 : 0;
}*/

int main(){
    std::cout << "Hello World" << std::endl;
    /*
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

    

    delete nTest;
    
    delete graph;


    Tas<int, intComp> *tasTest = new Tas<int, intComp>();
    int t1 = 1;
    int t2 = 2;
    int t3 = 3;
    int t4 = 4;
    int t5 = 5;
    int t6 = 6;

    //Ajout d'objets dans le tas
    tasTest->ajout(&t6);
    tasTest->ajout(&t5);
    tasTest->ajout(&t4);
    tasTest->ajout(&t3);
    tasTest->ajout(&t2);
    tasTest->ajout(&t1);

    std::cout << *tasTest << std::endl; //1,3,2,6,4,5,

    //Extraction du min
    std::cout << *tasTest->outMin() << std::endl; //1

    std::cout << *tasTest << std::endl; //2,3,5,6,4,

    //recherche d'éléments à l'intérieur
    std::cout << tasTest->recherche(&t2) << std::endl; //true

    std::cout << tasTest->recherche(&t1) << std::endl; // false
    
    delete tasTest;


    Tas_Id<int, intComp> *tasTest2 = new Tas_Id<int, intComp>();


    //Ajout d'objets dans le tas
    tasTest2->ajout(&t5);
    tasTest2->ajout(&t6);
    tasTest2->ajout(&t4);
    tasTest2->ajout(&t3);
    tasTest2->ajout(&t2);
    tasTest2->ajout(&t1);

    std::cout << *tasTest2 << std::endl; //1,3,2,6,4,5,

    //Extraction du min
    std::cout << *tasTest2->outMin() << std::endl; //1

    std::cout << *tasTest2 << std::endl; //2,3,5,6,4,

    //recherche d'éléments à l'intérieur
    std::cout << tasTest2->recherche(&t2) << std::endl; //true

    std::cout << tasTest2->recherche(&t1) << std::endl; // false
    
    delete tasTest2;
    */

    
    Graph<char, int>* subject = new Graph<char,int>();

    Noeud<char,int>* nodeA = new Noeud<char, int>('1');
    Noeud<char,int>* nodeB = new Noeud<char, int>('2');
    Noeud<char,int>* nodeC = new Noeud<char, int>('3');
    Noeud<char,int>* nodeD = new Noeud<char, int>('4');
    Noeud<char,int>* nodeE = new Noeud<char, int>('5');
    Noeud<char,int>* nodeF = new Noeud<char, int>('6');
    Noeud<char,int>* nodeG = new Noeud<char, int>('7');
    Noeud<char,int>* nodeH = new Noeud<char, int>('8');
    Noeud<char,int>* nodeI = new Noeud<char, int>('9');

    subject->addNoeud(nodeA);
    subject->addNoeud(nodeB);
    subject->addNoeud(nodeC);
    subject->addNoeud(nodeD);
    subject->addNoeud(nodeE);
    subject->addNoeud(nodeF);
    subject->addNoeud(nodeG);
    subject->addNoeud(nodeH);
    subject->addNoeud(nodeI);


    subject->addPath(nodeA, nodeB, 4);
    subject->addPath(nodeA, nodeH, 8);
    subject->addPath(nodeB, nodeC, 8);
    subject->addPath(nodeB, nodeH, 11);
    subject->addPath(nodeC, nodeD, 7);
    subject->addPath(nodeC, nodeI, 2);
    subject->addPath(nodeC, nodeF, 4);
    subject->addPath(nodeD, nodeE, 9);
    subject->addPath(nodeD, nodeF, 14);
    subject->addPath(nodeE, nodeF, 10);
    subject->addPath(nodeF, nodeG, 2);
    subject->addPath(nodeG, nodeH, 1);
    subject->addPath(nodeG, nodeI, 6);
    subject->addPath(nodeI, nodeH, 7);

    std::cout << *subject << std::endl;

    Dijkstra<char>(subject, nodeA);

    delete subject;

    return 0;
}