
#include "graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<int> num_traversal;
vector<pair<int, int>> visit_order;
vector<int>::iterator it;
list<int>::iterator adj_it;
list<int> temp_list;
int increment_order= 0;

/*
* Depthfirst function
*
* traverses a graph with the depth-first traversal/search algorithm
* starting at the vertex with the index value v
******************************************************************************/
void Graph::Depthfirst(int v)
{
	int far = 0;

	increment_order++;
	num_traversal[v] = increment_order;
	temp_list = adj_list[v];

	for(adj_it = temp_list.begin(); adj_it != temp_list.end(); adj_it++)
	{
		temp_list = adj_list[v];
		far = distance(temp_list.begin(), adj_it);

		if(*adj_it == 1 && num_traversal[far] == 0)
		{
			visit_order.push_back(make_pair(v, far));
			Depthfirst(far);
		}
	}
}

/*
* Constructor
*
* reads data from the input file of a graph given in adjacency matrix
* representation into 2 vectors. the labels vector holds data for the vertecies
* while the adj_list vector holds data for the edges.
******************************************************************************/
Graph::Graph(const char* filename)
{
	int temp = 0;
	ifstream infile(filename, ios::in);
	char line;

	infile >> line;

	int graph_vert = line - '0';
	size = graph_vert;

	for(int i = 0; i < graph_vert; i++)
	{
		infile >> line;
		labels.push_back(line);
	}

	for(int j = 0; j < graph_vert; j++)
	{
		infile >> line;
		for(int k = 0; k < graph_vert; k++)
		{
			infile >> temp;
			temp_list.push_back(temp);
		}

		adj_list.push_back(temp_list);
		temp_list.erase(temp_list.begin(), temp_list.end());
	}

	infile.close();
}

/*
* Destructor
******************************************************************************/
Graph::~Graph()
{

}

/*
* Getsize function
*
* @return size of graph
******************************************************************************/
int Graph::Getsize() const
{
	return size;
}

/*
* Traverse function
*
* uses the Depthfirst function to traverse a graph. displays the list of
* vertices in the order they are visited and the list of edges showing the
* path(s) of traversal.
******************************************************************************/
void Graph::Traverse()
{
	num_traversal.resize(size);
	it = find(num_traversal.begin(), num_traversal.end(), 0);

	while(it != num_traversal.end())
	{
		Depthfirst(it - num_traversal.begin());
		it = find(num_traversal.begin(), num_traversal.end(), 0);
	}

	cout << "------- traverse of graph ------" << endl;

	for(int i = 1; i <= size; i++)
	{
		it = find(num_traversal.begin(), num_traversal.end(), i);
		cout << labels[it - num_traversal.begin()] << " ";
	}

	cout << endl;

	for(unsigned int j = 0; j < visit_order.size(); j++)
	{
		cout << "(" << labels[visit_order[j].first] << ", " << labels[visit_order[j].second] << ")" << " ";
	}

	cout << endl << "--------- end of traverse -------" << endl << endl;
}

/*
* Printing function
*
* prints the adjacency list of the graph along with formatting.
******************************************************************************/
void Graph::Print() const
{
	int label_count = 0;
	int edge_count = 0;
	int com[] = {3, 3, 2, 1, 2, 2, 1};
	int i = 0;
	int j = 0;

	cout << endl << "Number of vertices in the graph: " << size << endl << endl;
	cout << "-------- graph -------" << endl;

	for(vector<list<int>>::const_iterator it = adj_list.begin(); it != adj_list.end(); it++)
	{
		cout << labels[label_count] << ": ";
		std::list<int> li = *it;

		for(std::list<int>::iterator iter = li.begin(); iter != li.end(); iter++)
		{
			if(*iter == 1)
			{
				cout << labels[edge_count];
				i++;

				if(i != com[j])
				{
					cout << ", ";
				}
			}

			edge_count++;
		}

		cout << endl;
		label_count++;
		j++;
		i = 0;
		edge_count = 0;
	}

	cout << "------- end of graph ------" << endl << endl;
}
