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
		std::cout << "\nTAS : " << tas_id.getSize() << " | DICO : " << tas_id.getSizeDico() << std::endl;
		if (*it == src){
			ourPairs<Noeud<I,int>*, int>* curPair = new ourPairs<Noeud<I,int>*, int>(*it, 0);
			tmp[*it] = curPair;
			tas_id.ajout(curPair);
			std::cout << "Ajout dans le tas de " << (*it)->get_numero() << " : " << "0" << std::endl;

		} else{
			ourPairs<Noeud<I,int>*, int>* curPair = new ourPairs<Noeud<I,int>*, int>(*it, INFINITY);
			tmp[*it] = curPair;
			tas_id.ajout(curPair);
			std::cout << "Ajout dans le tas de " << (*it)->get_numero() << " : " << INFINITY << std::endl;
		}
		
	}


	ourPairs< Noeud<I,int>*, int>* choice;
	//std::tr1::tuple<Noeud<I,int>*,int>* choice;

	int i = 0;
	while(!tas_id.isEmpty()){

		std::cout << "\n\n***** BOUCLE " << i << " *****" << std::endl;
		std::cout << "TAS : " << tas_id.getSize() << " | DICO : " << tas_id.getSizeDico() << std::endl;
		choice = tas_id.outMin(); // c'est bien un ourPairs


		//Noeud<I, int>* noeudMin = std::tr1::get<0>(*choice);
		Noeud<I, int>* noeudMin = choice->first;
		//int poidMin = std::tr1::get<1>(*choice);
		int poidMin = choice->second; // Ca on arrive à le recup

		std::cout << "****Traitement de " << noeudMin->get_numero() << " : " << poidMin << std::endl;
		
		result[noeudMin] = poidMin;
		
		std::vector< std::pair<Noeud<I,int>*, int> > voisinsMin = noeudMin->getNeighbours();

		std::cout << "***Traitement des voisins" << std::endl;

		for( typename std::vector< std::pair<Noeud<I,int>*, int> >::iterator it = voisinsMin.begin(); it != voisinsMin.end(); it++){
			Noeud<I, int>* noeudVoisin = (*it).first;

			ourPairs<Noeud<I,int>*, int>* tupleVoisin = tmp[(*it).first];

			std::cout << "**Voisin " << noeudVoisin->get_numero() << " : " << (*tupleVoisin).second <<std::endl;

			if (tupleVoisin->second > it->second + choice->second){
				tupleVoisin->second = it->second + choice->second;
				tas_id.updateTas(tupleVoisin);
				std::cout << "***** Update : " << (*tupleVoisin).second << std::endl;
			}

		}
		i++;
	}

	for (typename std::map<Noeud<I,int>*, int>::iterator it = result.begin(); it != result.end(); it++){
		std::cout << ((*it).first)->get_numero() << " : " << (*it).second << std::endl;
		delete tmp[it->first];
	}

	
}




#endif