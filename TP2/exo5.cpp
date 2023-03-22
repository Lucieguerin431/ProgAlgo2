#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
    // stop statement = condition + return (return stop the function even if it does not return anything)
    if(origin.size()<=1){
        return;
    }

    // initialisation
    Array& first = w->newArray(origin.size()/2);
    Array& second = w->newArray(origin.size()-first.size());

    // split
    for(size_t i=0; i<first.size(); i++){
        first[i]=origin[i];
    }
    for(size_t j=0; j<second.size(); j++){
        second[j]=origin[first.size()+j];
    }

    // recursiv
    splitAndMerge(first);
    splitAndMerge(second);

    // merge
    merge(first,second,origin);
}

void merge(Array& first, Array& second, Array& result)
{
	int id=0;
	int ig=0;

	while(ig!=first.size() || id!=second.size()){
		if(ig==first.size()){
			result[ig+id]=second[id];
			id++;
		} else if(id==second.size()){
			result[ig+id]=first[ig];	
			ig++;	
		} else if(first[ig]<second[id]){
			result[ig+id]=first[ig];
			ig++;
		} else {
			result[ig+id]=second[id];
			id++;
		}
	}

}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
