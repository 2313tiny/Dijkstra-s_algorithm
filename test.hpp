#ifndef TEST_HPP
#define TEST_HPP
#include<iostream>
#include<cassert>
#define YELLOW "\033[01;033m"
#define GREEN "\033[01;032m"
#define RESET "\033[01;0m"
 
#include<map>
#include<iomanip>

#include"graph.hpp" 
 
 
void test_v1()
{
	Vertex point1(1, "Moscow");
	Vertex point2(2, "St.Petersburg");
	Vertex point3(3, "Kazan");
	Vertex point4(4, "Rostov");
	Vertex point5(5, "Magadan");
	Vertex point6(6, "Tuda-Uta");	

	Graph harta;
	harta.add_vertex(point1);	
	harta.add_vertex(point2);	
	harta.add_vertex(point3);	
	harta.add_vertex(point4);	
	harta.add_vertex(point5);	
	harta.add_vertex(point6);

	harta.add_edge( point1, point4 );
	harta.add_edge( point1, point3 );
	harta.add_edge( point1, point2 );
	harta.add_edge( point2, point4 );
	harta.add_edge( point2, point5 );
	harta.add_edge( point3, point5 );
	harta.add_edge( point3, point6 );
	harta.add_edge( point3, point4 );
	harta.add_edge( point4, point6 );
	harta.add_edge( point5, point6 );

	Edge e1( point1, point4 );
	Edge e2( point1, point3 );
	Edge e3( point1, point2 );
	Edge e4( point2, point4 );
	Edge e5( point2, point5 );
	Edge e6( point3, point5 );
	Edge e7( point3, point6 );
	Edge e8( point3, point4 );
	Edge e9( point4, point6 );
	Edge e10( point5, point6 );


	std::multimap<int, Edge > weight;
	weight.insert(std::make_pair(4, e1) );
	weight.insert(std::make_pair(1, e2) );
	weight.insert(std::make_pair(2, e3) );
	weight.insert(std::make_pair(7, e4) );
	weight.insert(std::make_pair(3, e5) );
	weight.insert(std::make_pair(10, e6) );
	weight.insert(std::make_pair(4, e7) );
	weight.insert(std::make_pair(5, e8) );
	weight.insert(std::make_pair(3, e9) );
	weight.insert(std::make_pair(4, e10) );
 
	std::cout << "Weights for Edges of Graph \n " << std::endl;            
	for( auto mapItem : weight){
		std::cout << std::setw(12) << std::left
			  << mapItem.second.m_target.m_name //???? 
			  << "->" << std::setw(10) << std::left
			  << mapItem.second.m_source.m_name
			  << std::setw(5) << YELLOW   
			  << " \t" << mapItem.first 
			  <<  RESET << "\n";
	}	
	
	std::cout << "\n\n";
	harta.display();

	std::multimap<int, Vertex> path;	
	std::multimap<int, Vertex>::iterator it;
		
	path.insert(std::make_pair(10000, point1) );
	path.insert(std::make_pair(10000, point2) );
	path.insert(std::make_pair(10000, point3) );
	path.insert(std::make_pair(10000, point4) );
	path.insert(std::make_pair(10000, point5) );
	path.insert(std::make_pair(10000, point6) );
	
	Dijkstra_algorithm(harta,
		 	   point1, point6, 
	 	  	   weight,
	  		   path );

}
void test_v2()
{
	
}
void test_v3()
{
	//empty body
}
 
 
#endif // TEST_HPP
