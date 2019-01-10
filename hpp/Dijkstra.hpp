#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Tas_id.hpp"
#include "Graph.hpp"
#include "Noeud.hpp"
#include <iostream>
#include <map>

template<class I, class C, int compare(I,I)>
class Dijkstra{
	private:
		// Le graphe à traiter
		Graph<I,C> graph;
		// Le noeud de départ
		Noeud<I,C>* origin;
		// Le noeud choisit à chaque étape
		Noeud<I,C>* workingOn;
		// La table de routage des plus courts chemins de origin vers tout les sommets de graph
		std::map<Noeud<I,C>*, int> results;
		// Le tas utilisé pour traiter les sommets
		Tas_Id<C, compare> handling;
	
	public:
		Dijkstra();
		Dijkstra(Noeud<I,C>*);
		Dijkstra(Graph<I,C>);

		~Dijkstra();

		void toPrint(); //Affiche les plus courts chemins
};




#endif