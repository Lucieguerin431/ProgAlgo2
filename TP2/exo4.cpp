#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
    if (size<=1)
    {
        return;
    }
    
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

    int pivot = toSort[0];
    for(int i=1; i<size; i++){
        if(toSort[i]<pivot){
            lowerArray[lowerSize]=toSort[i];
            lowerSize++;} 
        else {
            greaterArray[greaterSize]=toSort[i];
            greaterSize++;
        }
    }

    // recursiv sort of lowerArray and greaterArray
    recursivQuickSort(lowerArray, lowerSize);
    recursivQuickSort(greaterArray, greaterSize);

    // merge
    for(int j=0; j<lowerSize; j++){
        toSort[j]=lowerArray[j];
    }
        
	toSort[lowerSize]=pivot;

    for(int k=0; k<greaterSize; k++){
        toSort[lowerSize+k+1]=greaterArray[k];
    }

}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
