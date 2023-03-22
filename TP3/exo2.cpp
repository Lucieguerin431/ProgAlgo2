#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

/**
 * @brief define indexMin and indexMax as the first and the last index of toSearch
 * @param array array of int to process
 * @param toSearch value to find
 * @param indexMin first index of the value to find
 * @param indexMax last index of the value to find
 */
void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
	// do not use increments, use two different binary search loop
    indexMin = indexMax = -1;
    int start=0;
    int end=array.size();
    
    //cherche dans la partie droite
    while(start<end)
    {
        int mid=(start+end)/2;
        if (toSearch>array[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid;
        }
    }
    indexMin=start;

    //réinitialisation de start et end
    start=0;
    end=array.size();

    //cherche dans la partie gauche
    while(start<end)
    {
        int mid=(start+end)/2;
        if (toSearch<array[mid])
        {
            end=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    indexMax=start-1;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
