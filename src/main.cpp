#include "../hpp/Graph.hpp"
#include "../hpp/Tas_id.hpp"
#include "../hpp/Dijkstra.hpp"

int main(){
    
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

    std::cout << "Le graphe : " << *subject << std::endl;

    Dijkstra<char>(*subject, nodeA);

    delete subject;

    return 0;
}