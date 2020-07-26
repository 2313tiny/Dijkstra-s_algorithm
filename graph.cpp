#include "graph.hpp" 

//utilities
void show_path(std::multimap<int, Vertex> & path)
{
	for ( auto setItem : path){
		std::cout << std::setw(2) << std::left 
			  << setItem.second.m_node  << " "
			  << std::setw(12) << std::left 
			  << setItem.second.m_name << " - "
			  << setItem.first <<  '\n' ; 
	}
	std::cout << std::endl;	
}

// set all path weight max value , except start node
void set_path( std::multimap<int, Vertex> & path, 
		 Vertex & start,	      
		 std::multimap<int, Vertex>::iterator & it,
		 int value, 
		 std::multimap<bool, Vertex> & checked)
{
	std::multimap<bool, Vertex>::iterator checkedIt;	
	std::multimap<bool, Vertex>::iterator checkedfixedIt;
	checkedIt = checked.begin();
	
	for (it = path.begin(); it != path.end(); ++it ){
			int node = it->second.m_node;
			std::string name = it->second.m_name;
			path.erase(it);
			Vertex start(node, name);
				path.insert(std::make_pair(value, start));
	}
	for (it = path.begin(); it != path.end(); ++it){
		if (it->second.m_node == start.m_node){
			int node = it->second.m_node;
			std::string name = it->second.m_name;
			path.erase(it);
			Vertex start(node, name);
			path.insert(std::make_pair(0, start));
		}	
	}
}

void fix_all_vertex_potential(Graph & graph, std::multimap<int, Vertex> &path,
			      Vertex & start,
		    	      std::multimap<int, Edge> & weight)
{
	std::multimap<int, Edge>::iterator weightIt; //int weight of Edge
	std::multimap<int, Vertex>::iterator pathIt; //int potention of Vertex
	
	int potention = 0; //potention for start point
	//find potenctial for start node   
	for (pathIt = path.begin(); pathIt != path.end(); ++pathIt){
		if (pathIt->second.m_node == start.m_node){
			potention = pathIt->first;
		}
	}
	//	std::cout << potention << "------- " << std::endl;



	for (weightIt = weight.begin(); weightIt != weight.end(); ++weightIt){
		 if (weightIt->second.m_target.m_node == start.m_node){
		//	   std::cout << start.m_node << "----> "; 
		//	   std::cout << weightIt->second.m_source.m_name <<" \n";
		   for (pathIt = path.begin(); pathIt != path.end(); ++pathIt){
			  if (pathIt->second.m_node == weightIt->second.m_source.m_node){
				int node = pathIt->second.m_node;
			      	std::string name = pathIt->second.m_name;
				Vertex phantomNode(node, name);
				int adj = potention + weightIt->first; // was calculated  !!!!!!!!!!!!!!! 
				int node_potention = pathIt->first;  // have potention in path
				int value = (adj < node_potention ) ? adj : node_potention;
				path.erase(pathIt);
				path.insert( std::make_pair(value, phantomNode));		
			  } 	
		   }
		}
	}
}

void find_min_potential(std::multimap<int, Vertex> & path, 
		  	Vertex & min_potential,
			std::multimap<bool, Vertex> & checked)
{
	std::multimap<int, Vertex>::iterator pathIt;
	pathIt = path.begin();
	std::multimap<bool, Vertex>::iterator checkedIt;	
	std::multimap<bool, Vertex>::iterator checkedfixedIt;
	checkedIt = checked.begin();

	//find node with min potention	
	int minValue = 8000; //max value
 	for (pathIt; pathIt != path.end(); ++pathIt){
 		for (checkedIt = checked.begin();
		 checkedIt != checked.end(); ++checkedIt){
			if((pathIt->second.m_node == checkedIt->second.m_node)
				&& (false == checkedIt->first )	) {
				if (minValue > pathIt->first){ // out part
				      std::string name = pathIt->second.m_name;
				      int node = pathIt->second.m_node;
				      Vertex min_potential_fantom(node, name);
				      min_potential = min_potential_fantom;
				      minValue = pathIt->first;
				}			
			}
		}	
	
	}	

	//made true node with min potention
	//i.e this node exclude from finding path 
	for (checkedfixedIt = checked.begin(); 
	      checkedfixedIt != checked.end(); ++checkedfixedIt){
		if (checkedfixedIt->second.m_node == min_potential.m_node){
		int node = checkedfixedIt->second.m_node;
		std::string name = checkedfixedIt->second.m_name;
		Vertex phantomNode(node, name);
		checked.erase(checkedfixedIt);
		checked.insert(std::make_pair(true, phantomNode));
		}
	}
}
		
void Dijkstra_algorithm(Graph & g,
		    Vertex & start, Vertex & finish, 
		    std::multimap<int, Edge> & weight,
		    std::multimap<int, Vertex> & path )
{
	std::multimap<int, Vertex>::iterator pathIt = path.begin();
	std::multimap<bool, Vertex> checked;
	std::multimap<bool, Vertex>::iterator checkedIt;
<<<<<<< HEAD
	std::multimap<bool, Vertex>::iterator finishIt;
=======
<<<<<<< HEAD
	std::multimap<bool, Vertex>::iterator finishIt;
=======
>>>>>>> c5c0ab156dcc88306895e6930767e7688271f370
>>>>>>> c51e404e10eee6750d8b869dee9dc226a1f0b4c3
	Vertex min_potential;	
	
	//if value is false, node not checked  
	for (pathIt; pathIt != path.end(); ++pathIt){
		int node = pathIt->second.m_node;
		std::string name = pathIt->second.m_name;
		Vertex fantomNode(node, name);
		checked.insert(std::make_pair(false, fantomNode));
	}
	
	 //for print working ONLY FOR TEST 	
	/*for (auto & ch : checked){
		std::cout << (bool)ch.first << " " << ch.second.m_name;	
		std::cout << std::endl;
	}*/
	std::cout << "\n";
	show_path(path);
	std::cout << "\n **** PATH FINDER **** " << std::endl;

	// make start point potention equal 0 ...... DONE
	set_path(path, start, pathIt, 10000, checked); 
	show_path(path);

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> c51e404e10eee6750d8b869dee9dc226a1f0b4c3
	//find finish node is ckecked or not
	for (checkedIt = checked.begin(); checkedIt != checked.end(); ++checkedIt){
		if(checkedIt->second.m_node == finish.m_node){
			finishIt = checkedIt;
		}
	}


	//for checking all node 
	for (checkedIt = checked.begin(); checkedIt != checked.end(); ++checkedIt){
		while( false == finishIt->first){
<<<<<<< HEAD
=======
=======

	//for checking all node 
	for (checkedIt = checked.begin(); checkedIt != checked.end(); ++checkedIt){
		while( false == checkedIt->first){
>>>>>>> c5c0ab156dcc88306895e6930767e7688271f370
>>>>>>> c51e404e10eee6750d8b869dee9dc226a1f0b4c3
			//find node with min potention
			//also this point need for check node 
			find_min_potential(path, min_potential, checked);
			std::cout <<"\n" << "node have min_potention " << 
				  min_potential.m_node << " " << min_potential.m_name << " \n";

			//fix potenctial for every node  .... DONE  
			//(start node potential + working for this edge)
			start = min_potential;
			fix_all_vertex_potential(g, path, start, weight);
			//	show_path(path);

			for (auto & ch : checked){
			std::cout <<"[ " <<  (bool)ch.first << " ]  " << ch.second.m_name;	
			std::cout << std::endl;
			}
			show_path(path);
			checkedIt = checked.begin();
		}
	}
} 
