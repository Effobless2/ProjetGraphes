#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Tas_id.hpp"
#include "Graph.hpp"
#include "Noeud.hpp"
#include <iostream>
#include <map>

template<class I, int compare(std::tr1::tuple<Noeud<I,int>*,int>,std::tr1::tuple<Noeud<I,int>*,int>)>
void Dijkstra(Graph<I,int>* graph, Noeud<I,int>* src){

	int INFINITY = 100000;


	std::map<Noeud<I,int>*, int> result = std::map<Noeud<I,int>*,int>();

	std::map<Noeud<I,int>*, std::tr1::tuple<Noeud<I,int>*, int>*> tmp = std::map<Noeud<I,int>*, std::tr1::tuple<Noeud<I,int>*, int>*>();

	//Tas_Id<std::tr1::tuple<Noeud<I,int>*, int>, compare> tas_id = Tas_Id(src->getNeighbours());
	Tas_Id<std::tr1::tuple<Noeud<I,int>*, int>, compare> tas_id = Tas_Id<std::tr1::tuple<Noeud<I,int>*, int>, compare>();
	
	std::vector< Noeud<I, int>* > nodes = graph->getNodes();
	for (typename std::vector<Noeud<I,int>*>::iterator it = nodes.begin(); it != nodes.end(); it++){
		if (*it == src){
			std::tr1::tuple<Noeud<I,int>*, int> curTuple = std::tr1::tuple<Noeud<I,int>*, int>((*it), 0);
			tmp[*it] = &curTuple;
			tas_id.ajout(&curTuple);

		} else{
			std::tr1::tuple<Noeud<I,int>*, int> curTuple = std::tr1::tuple<Noeud<I,int>*, int>((*it), INFINITY);
			tmp[*it] = &curTuple;
			tas_id.ajout(&curTuple);
		}
	}

	

	std::tr1::tuple<Noeud<I,int>*,int>* choice;
	while(!tas_id.isEmpty()){
		choice = tas_id.outMin();
		result[std::tr1::get<0>(choice)] = std::tr1::get<1>(choice);
		for (typename std::vector<std::tr1::tuple<Noeud<I,int>*, int> >::iterator it = std::tr1::get<0>(choice)->getNeighbours().begin(); it != std::tr1::get<0>(choice)->getNeighbours().end(); it++){
			std::tr1::tuple<Noeud<I,int>*, int>* curTuple = tmp[*it.first];
			if (curTuple->second > *it->second + std::tr1::get<1>(choice)){
				curTuple->second = *it.second + std::tr1::get<1>(choice);
				tas_id.updateTas(curTuple);
			}
		}
	}

	for (typename std::map<Noeud<I,int>*, int>::iterator it = result.begin(); it != result.end(); it++){
		std::cout << *(std::tr1::get<0>(*it)) << " : " << *(std::tr1::get<1>(*it)) << std::endl;
	}
}




#endif