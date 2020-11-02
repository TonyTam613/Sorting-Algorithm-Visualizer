#ifndef GRAPHICALSORTHEADER_H_INCLUDED
#define GRAPHICALSORTHEADER_H_INCLUDED

#define debug cout << __LINE__ << endl;
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <time.h>
#include <string.h>
#include <cstdio>
#include <time.h>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

const int listSize = 100;

using namespace std;

//my Class
class MyList{
    public:
        MyList();
        MyList(int Amount);
        ~MyList();
        void mergeSort(int left, int right, int &swaps, int &comps);
        void quickSort(int first, int last, int &swaps, int &comps);
        int BinarySearch(int end, int start, int x, int &comps);
        void bubbleSort(int end, int &swaps, int &comps);
        int getVal(int index);
        int getSize();
        int TextInput();
        void setVal(int index, int Num);
        void MoveUpdate(int highlight);
        void MoveUpdate(int pivot, int highlight);
        void MoveUpdate(int end, int start, int highlight);
        void TextUpdate(int Swaps, int Comparissons, string SortName);
        void TextUpdate(int Time);
        void TextUpdate(string InputNum);
        void TextUpdate(int Index, string Title, int Num, int comps);
        void setVector(vector<int> Vector1);
        vector<int> getVector();

    private:
        void merge(int left, int middle, int right, int &swaps, int &comps);
        int partition(int low, int high, int &swaps, int &comps);
        int numberOfentries;
        vector<int> ListofNumbers;


};

void counterReset(int &swaps, int &comps);

#endif // GRAPHICALSORTHEADER_H_INCLUDED
