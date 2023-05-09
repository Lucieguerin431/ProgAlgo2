#include "tp6.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
	/**
	  * Make a graph from a matrix
	  * first create all nodes, add it to the graph then connect them
	  * this->appendNewNode
	  * this->nodes[i]->appendNewEdge
	  */
	for (int i=0; i<nodeCount; i ++){
		GraphNode *node = new GraphNode(i);
		this->appendNewNode(node);
	}
	for(int i=0; i<nodeCount; i++){
		for(int j; j<nodeCount; j++){
			if(adjacencies[i][j]!=0){
				this->nodes[i]->appendNewEdge(this->nodes[j], adjacencies[i][j]);
			}
		}
	}

}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{

	/**
	  * Fill nodes array by travelling graph starting from first and using recursivity
	*/

	nodes[nodesSize]=first;
	visited[first->value]=1;
	nodesSize++;

	for(Edge* e= first->edges; e!=NULL; e=e->next){
		if(!visited[e->destination->value]){
			deepTravel(e->destination, nodes, nodesSize, visited);
		}
	}
}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[]){
	/*
	 * Fill nodes array by travelling graph starting from first and using queue
	 * nodeQueue.push(a_node)
	 * nodeQueue.front() -> first node of the queue
	 * nodeQueue.pop() -> remove first node of the queue
	 * nodeQueue.size() -> size of the queue
	 */
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);
	
	while (!nodeQueue.empty()){
		GraphNode* node = nodeQueue.front();
		nodeQueue.pop();
		visited[node->value]=true;
		nodes[nodesSize++] = node;

		for(Edge* edge= node->edges; edge!=NULL; edge=edge->next){
			if(visited[edge->destination->value]==false){
				nodeQueue.push(edge->destination);
			}
		}

	}
}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
	/**
	  Detect if there is cycle when starting from first
	  (the first may not be in the cycle)
	  Think about what's happen when you get an already visited node
	**/
	std::queue<GraphNode*> nodeQueue;
	nodeQueue.push(first);
	
	while (!nodeQueue.empty()){
		GraphNode* node = nodeQueue.front();
		nodeQueue.pop();
		visited[node->value] = true;

		for(Edge* edge= node->edges; edge!=NULL; edge=edge->next){
			if(visited[edge->destination->value]==false){
				nodeQueue.push(edge->destination);
			}
			else if(edge->destination == first){
				return true;
			}
		}
	}

    return false;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 150;
	w = new GraphWindow();
	w->show();

	return a.exec();
}