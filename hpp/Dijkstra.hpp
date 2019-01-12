#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Tas_id.hpp"
#include "Graph.hpp"
#include "Noeud.hpp"
#include <iostream>
#include <map>

template< class I, int compare( std::pair<Noeud<I,int>*, int>, std::pair<Noeud<I,int>*, int> ) >
void Dijkstra(Graph<I,int>* graph, Noeud<I,int>* src){

	int INFINITY = 100000;

	std::cout << "***** INIT *****" << std::endl;
	// Map (Noeud, distance) des résultats de l'algo
	std::map<Noeud<I,int>*, int> result = std::map<Noeud<I,int>*,int>();

	std::map< Noeud<I,int>*, std::pair<Noeud<I,int>*, int>* > tmp = std::map< Noeud<I,int>*, std::pair<Noeud<I,int>*, int>* >(); 

	Tas_Id< std::pair<Noeud<I,int>*, int>, compare> tas_id = Tas_Id< std::pair<Noeud<I,int>*, int>, compare >();
	
	std::vector< Noeud<I, int>* > nodes = graph->getNodes();
	for (typename std::vector<Noeud<I,int>*>::iterator it = nodes.begin(); it != nodes.end(); it++){
		std::cout << "\nTAS : " << tas_id.getSize() << " | DICO : " << tas_id.getSizeDico() << std::endl;
		if (*it == src){
			std::cout << "     on a le source" << std::endl;
			std::pair<Noeud<I,int>*, int> curPair = std::make_pair(*it, 0);
			tmp[*it] = &curPair;
			tas_id.ajout(&curPair);

		} else{
			std::pair<Noeud<I,int>*, int> curPair = std::make_pair(*it, INFINITY);
			tmp[*it] = &curPair;
			tas_id.ajout(&curPair);
		}
	}


	std::cout << "\n\n***** BOUCLE *****" << std::endl;
	std::pair< Noeud<I,int>*, int>* choice;
	//std::tr1::tuple<Noeud<I,int>*,int>* choice;

	int i = 0;
	while(!tas_id.isEmpty()){
		std::cout << i << "[BEFORE] TAS : " << tas_id.getSize() << " | DICO : " << tas_id.getSizeDico() << std::endl;
		choice = tas_id.outMin(); // c'est bien un std::pair
		std::cout << i << "[AFTER] TAS : " << tas_id.getSize() << " | DICO : " << tas_id.getSizeDico() << std::endl;


		//Noeud<I, int>* noeudMin = std::tr1::get<0>(*choice);
		Noeud<I, int>* noeudMin = choice->first;
		//int poidMin = std::tr1::get<1>(*choice);
		int poidMin = choice->second; // Ca on arrive à le recup
		std::cout << "Poid : " << poidMin << std::endl;

		std::cout << i << "****Traitement de" << std::endl;
		std::cout << *noeudMin << std::endl;
		
		/*result[noeudMin] = poidMin;
		
		std::vector< std::tr1::tuple<Noeud<I,int>*, int> > voisinsMin = noeudMin->getNeighbours();

		std::cout << "***Traitement des voisins" << std::endl;

		for( typename std::vector< std::tr1::tuple<Noeud<I,int>*, int> >::iterator it = voisinsMin.begin(); it != voisinsMin.end(); it++){
			std::cout << "**Traitement du voisin" << std::endl;
			Noeud<I, int>* noeudVoisin = std::tr1::get<0>(*it);
			std::cout << *noeudVoisin << std::endl;

			std::tr1::tuple<Noeud<I,int>*, int>* tupleVoisin = tmp[std::tr1::get<0>(*it)];

			if (std::tr1::get<1>(*tupleVoisin) > std::tr1::get<1>(*it) + std::tr1::get<1>(*choice)){
				std::tr1::get<1>(*tupleVoisin) = std::tr1::get<1>(*it) + std::tr1::get<1>(*choice);
				tas_id.updateTas(tupleVoisin);
				std::cout << "**On change la valeur de ce voisin" << std::endl;
			}

		}
		/*for (typename std::vector<std::tr1::tuple<Noeud<I,int>*, int> >::iterator it = (std::tr1::get<0>(*choice))->getNeighbours().begin(); it != std::tr1::get<0>(*choice)->getNeighbours().end(); it++){
			std::cout << "IN FOR getNeighbours" << std::endl;
			std::tr1::tuple<Noeud<I,int>*, int>* curTuple = tmp[std::tr1::get<0>(*it)];
			if (std::tr1::get<1>(*curTuple) > std::tr1::get<1>(*it) + std::tr1::get<1>(*choice)){
				std::tr1::get<1>(*curTuple) = std::tr1::get<1>(*it) + std::tr1::get<1>(*choice);
				tas_id.updateTas(curTuple);
			}
		}*/
		i++;
	}

	/*for (typename std::map<Noeud<I,int>*, int>::iterator it = result.begin(); it != result.end(); it++){
		std::cout << *(std::tr1::get<0>(*it)) << " : " << *(std::tr1::get<1>(*it)) << std::endl;
	}*/
}




#endif