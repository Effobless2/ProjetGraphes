#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Tas_id.hpp"
#include "Graph.hpp"
#include "Noeud.hpp"
#include "ourPairs.hpp"
#include <iostream>
#include <map>


template<class I>
void Dijkstra(Graph<I,int>* graph, Noeud<I,int>* src){

	int INFINITY = 100000;

	std::cout << "***** INIT *****" << std::endl;
	// Map (Noeud, distance) des résultats de l'algo
	std::map<Noeud<I,int>*, int> result = std::map<Noeud<I,int>*,int>();

	std::map< Noeud<I,int>*, ourPairs<Noeud<I,int>*, int>* > tmp = std::map< Noeud<I,int>*, ourPairs<Noeud<I,int>*, int>* >(); 

	Tas_Id< ourPairs<Noeud<I,int>*, int>, pairCompare> tas_id = Tas_Id< ourPairs<Noeud<I,int>*, int>, pairCompare >();
	
	std::vector< Noeud<I, int>* > nodes = graph->getNodes();
	for (typename std::vector<Noeud<I,int>*>::iterator it = nodes.begin(); it != nodes.end(); it++){
		//std::cout << "\nTAS : " << tas_id.getSize() << " | DICO : " << tas_id.getSizeDico() << std::endl;
		if (*it == src){
			//std::cout << "     on a le source" << std::endl;
			ourPairs<Noeud<I,int>*, int>* curPair = new ourPairs<Noeud<I,int>*, int>(*it, 0);
			tmp[*it] = curPair;
			tas_id.ajout(curPair);

		} else{
			ourPairs<Noeud<I,int>*, int>* curPair = new ourPairs<Noeud<I,int>*, int>(*it, INFINITY);
			tmp[*it] = curPair;
			tas_id.ajout(curPair);
		}
		
	}


	std::cout << "\n\n***** BOUCLE *****" << std::endl;
	ourPairs< Noeud<I,int>*, int>* choice;
	//std::tr1::tuple<Noeud<I,int>*,int>* choice;

	while(!tas_id.isEmpty()){
		std::cout << "###### Etat du tas (lol tata)###########" << std::endl;
		std::cout << tas_id << std::endl;
		std::cout << "########################################" << std::endl;
		//std::cout << i << "[BEFORE] TAS : " << tas_id.getSize() << " | DICO : " << tas_id.getSizeDico() << std::endl;
		choice = tas_id.outMin(); // c'est bien un ourPairs
		//std::cout << i << "[AFTER] TAS : " << tas_id.getSize() << " | DICO : " << tas_id.getSizeDico() << std::endl;


		//Noeud<I, int>* noeudMin = std::tr1::get<0>(*choice);
		Noeud<I, int>* noeudMin = choice->first;
		//int poidMin = std::tr1::get<1>(*choice);
		int poidMin = choice->second; // Ca on arrive à le recup
		std::cout << "Poid : " << poidMin << std::endl;

		std::cout << "****Traitement de ";
		std::cout << *noeudMin << std::endl;
		
		result[noeudMin] = poidMin;
		
		std::vector< std::pair<Noeud<I,int>*, int> > voisinsMin = noeudMin->getNeighbours();

		//std::cout << "***Traitement des voisins" << std::endl;

		for( typename std::vector< std::pair<Noeud<I,int>*, int> >::iterator it = voisinsMin.begin(); it != voisinsMin.end(); it++){
			std::cout << "**Traitement du voisin ";
			Noeud<I, int>* noeudVoisin = (*it).first;
			std::cout << *noeudVoisin << std::endl;

			ourPairs<Noeud<I,int>*, int>* tupleVoisin = tmp[(*it).first];

			if (tupleVoisin->second > it->second + choice->second){
				tupleVoisin->second = it->second + choice->second;
				tas_id.updateTas(tupleVoisin);
				//std::cout << "**On change la valeur de ce voisin" << std::endl;
			}

		}
	}

	for (typename std::map<Noeud<I,int>*, int>::iterator it = result.begin(); it != result.end(); it++){
		std::cout << *((*it).first) << " : " << (*it).second << std::endl;
		delete tmp[it->first];
	}

	
}




#endif