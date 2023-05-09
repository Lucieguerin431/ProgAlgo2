#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return nodeIndex*2+1;
}

int Heap::rightChild(int nodeIndex)
{
    return nodeIndex*2+2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;
	(*this)[i]=value;
    while (i>0 && (*this)[i]>(*this)[(i-1)/2])
	{
        swap((*this)[i],(*this)[(i-1)/2]);
		i=i+((i-1)/2);
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i_max = nodeIndex;
	int valeurRight=-1;
	int valeurLeft=-1;
	int indexRight=rightChild(nodeIndex);
	int indexLeft=leftChild(nodeIndex);

	if(indexRight < heapSize){
		valeurRight=(*this)[rightChild(nodeIndex)];
	} else {
		valeurRight=-1;
	}

	if(indexLeft<heapSize){
		valeurLeft=(*this)[leftChild(nodeIndex)];
	} else {
		valeurLeft=-1;
	}
	

	if((*this)[nodeIndex] < valeurRight){
		i_max = indexRight;	
	}

    if((*this)[i_max] < valeurLeft){
		i_max = indexLeft;
	}


	if(i_max!=nodeIndex){
		swap(nodeIndex, i_max);
		heapify(heapSize, i_max);
	}
}

void Heap::buildHeap(Array& numbers)
{
	int n=numbers.size();
	for (int i = 0; i < n; i++)
	{
		insertHeapNode(n,numbers[i]);
	}
}

void Heap::heapSort()
{
	for (int i = (*this).size()-1; i >= 0; i--)
	{
        swap(0,i);
        heapify(i,0);
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
