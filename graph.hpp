
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include<iostream>

#include<vector>
#include<list>
#include<string>
#include<iomanip>


#include<set>
#include<map>
#define YELLOW "\033[01;033m"
#define GREEN "\033[01;032m"
#define RESET "\033[01;0m"
 
const int GRAPH_ORDER = 6;

class Vertex{
public:
	std::string m_name;
	int m_node;
       Vertex()
	   : m_name("none")	
	   , m_node(0){}
	Vertex(const Vertex & t)
	{
	//	strcpy(m_name, t.m_name);
		m_name = t.m_name;
		m_node = t.m_node;	
	}
	Vertex(const int n, const std::string name)
		 : m_name(name)
		 , m_node(n){}
	
	Vertex & operator=(const Vertex & obj)
	{
		this->m_name = obj.m_name;
		this->m_node = obj.m_node;
		return *this;		
	}

};

class Edge{
public:
	Vertex m_target;
	Vertex m_source;
	Edge(const Vertex & t,const Vertex & s)
		: m_target(t)
		, m_source(s)
	{}
};

class Graph{
public:
	std::vector<Vertex> gagat;
	std::list<Edge> deposit[GRAPH_ORDER];

public:
	Graph(){}
	Graph(const Graph & t){}
	Graph operator=(const Graph &){}

	void add_vertex(const Vertex & node){
		gagat.push_back(node);
	}
	void add_edge(const Vertex & s, const Vertex & t){
		int p = s.m_node;
		Edge e(s, t);
		deposit[p-1].push_back(e); 	
	}
	
	void add_edge(const Edge & arc){
		int p = arc.m_source.m_node;
		deposit[p-1].push_back(arc); 
	}

	//UNDER CONSTRUCTION
	void delete_node(Vertex & node){
		int p = node.m_node;	
		for (int i = 0 ; i < GRAPH_ORDER; ++i){	
			std::list<Edge>::iterator it;
			for (it = deposit[i].begin();
		  	   it != deposit[i].end(); ++it){
			 	if( (p) == it->m_source.m_node ){
					//deposit[i].erase(it);
				}
			}
		}
	}

	void display_edge(Vertex & vert) const{
		int p = vert.m_node;
		//deposit[p-1].m_target.m_name;				
		std::list<Edge>::const_iterator it;
		for (it = deposit[p-1].begin();
		     it != deposit[p-1].end(); ++it){
			std::cout << it->m_source.m_name << "  "; ///asdFASDFASD
		}
	}
	
	void display() const
	{
		std::cout << "You have this map " << std::endl;
		for (auto x : gagat){
		    std::cout << x.m_node << " " << x.m_name << " -> ";
			display_edge(x);
			std::cout << std::endl;
		}
	}

};

void Dijkstra_algorithm(Graph & g,
	    Vertex & start, Vertex & finish, 
	    std::multimap<int, Edge> & weight,
	    std::multimap<int, Vertex> & path ); 
 

#endif //LINKEDLIST_HPP
