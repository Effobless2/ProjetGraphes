#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Tas_id.hpp"
#include "Graph.hpp"
#include "Noeud.hpp"
#include "ourPairs.hpp"
#include <iostream>
#include <map>

/*
	Applique l'algorithme de dijkstra depuis un noeud src sur un graphe graph
	Affiche les plus courts chemins
*/

template<class I>
void Dijkstra(Graph<I,int>* graph, Noeud<I,int>* src){

	// Valeur définie pour l'initialisation des noeuds dans l'algorithme
	int INFINITY = 100000;

	// Map (Noeud, distance) : les résultats qu'on affichera
	std::map<Noeud<I,int>*, int> result = std::map<Noeud<I,int>*,int>();

	// Map temporaire 
	std::map< Noeud<I,int>*, ourPairs<Noeud<I,int>*, int>* > tmp = std::map< Noeud<I,int>*, ourPairs<Noeud<I,int>*, int>* >(); 

	// Tas contenant des paires (Noeud, distance) à traiter lors de l'algorithme
	Tas_Id< ourPairs<Noeud<I,int>*, int>, pairCompare> tas_id = Tas_Id< ourPairs<Noeud<I,int>*, int>, pairCompare >();
	
	// Boucle afin d'initialiser les noeuds du graphe dans l'algorithme de Dijkstra
	std::vector< Noeud<I, int>* > nodes = graph->getNodes();
	for (typename std::vector<Noeud<I,int>*>::iterator it = nodes.begin(); it != nodes.end(); it++){
		// Si on a le noeud src on met son coût à 0 pour le traiter en premier, sinon on met les noeuds à un coût infini
		if (*it == src){
			ourPairs<Noeud<I,int>*, int>* curPair = new ourPairs<Noeud<I,int>*, int>(*it, 0);
			tmp[*it] = curPair;
			tas_id.ajout(curPair);

		} else{
			ourPairs<Noeud<I,int>*, int>* curPair = new ourPairs<Noeud<I,int>*, int>(*it, INFINITY);
			tmp[*it] = curPair;
			tas_id.ajout(curPair);
		}
		
	}

	// Représente le noeud le plus proche de source dans l'algorithme
	ourPairs< Noeud<I,int>*, int>* choice;

	// Tant que le tas n'est pas vide, on applique l'algorithme
	while(!tas_id.isEmpty()){
		// On extrait le noeud le plus proche de source du tas
		choice = tas_id.outMin();

		// Représente le noeud dans la paire extraite
		Noeud<I, int>* noeudMin = choice->first;
		// Représente le poid dans la paire extraite (la distance entre le noeud source et celui extrait)
		int poidMin = choice->second;
		
		// On stocke le noeud et le poid extrait dans les résultats à afficher
		result[noeudMin] = poidMin;

		// On recupère les voisins du Noeud extrait afin de mettre à jour les distances si nécessaire
		std::vector< std::pair<Noeud<I,int>*, int> > voisinsMin = noeudMin->getNeighbours();
		for( typename std::vector< std::pair<Noeud<I,int>*, int> >::iterator it = voisinsMin.begin(); it != voisinsMin.end(); it++){
			// Représent le noeud voisin traité
			Noeud<I, int>* noeudVoisin = (*it).first;

			// On recupère la paire du noeud depuis tmp
			ourPairs<Noeud<I,int>*, int>* tupleVoisin = tmp[(*it).first];

			// Si la distance est plus petite alors on met à jour, sinon rien
			if (tupleVoisin->second > it->second + choice->second){
				tupleVoisin->second = it->second + choice->second;
				tas_id.updateTas(tupleVoisin);
			}

		}
	}

	// On affiche les plus courts chemins du noeud src vers les autres noeuds
	std::cout << "Voici les plus courts chemins (Sommet : Distance) " << std::endl;
	for (typename std::map<Noeud<I,int>*, int>::iterator it = result.begin(); it != result.end(); it++){
		std::cout << ((*it).first)->get_numero() << " : " << (*it).second << std::endl;
		delete tmp[it->first];
	}

	
}




#endif