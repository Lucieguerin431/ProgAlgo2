#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
	Array& sorted=w->newArray(toSort.size());

    sorted[0]=toSort[0];
        // insertion sort from toSort to sorted
        for(size_t i=1; i<toSort.size(); i++){
            int index = -1;
            size_t j = 0;

            while(j<i && sorted[j]<toSort[i]){
                j++;
            }

            index=j;

            if(index>=0){
                for(int pos=i; pos>index ; pos--){
                        sorted[pos]=sorted[pos-1];
                }

                sorted[index]=toSort[i];

            }
            else
            {
                sorted[i]=toSort[i];}
        }
	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}

