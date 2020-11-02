/**************************************************************
 *   ICS4U   Tony Tam    Jan, 22, 2020                        *
 *                                                            *
 *   This program implements 3 different sorts and 1 search   *
 *   and displays it graphically for the user to see          *
 *   it also collects info on the sorts like                  *
 *   the number of swaps, the number of comparissons          *
 *   and the time taken to sort it                            *
 *   these vectors have been set to have 200 elements         *
 *   but it can be changes in the Header                      *
 **************************************************************/

#include "MyListClassHeader.h"
#include "AllegroHeader.h"

int main(){
    //Declare and Initialize my Lists and Variables
    clock_t Timer; //Declares the variable for the clock (counts in ticks, to be converted later)
    int searchNum = 200;
    int indexNum = 0;
    int swaps = 0;
    int comps = 0;
    vector<int> NumberList;
    MyList MergeSortList(listSize);
    MyList QuickSortList(listSize);
    MyList BubbleSortList(listSize);

    //Makes all the other lists the same as each other so they all sort the same data
    QuickSortList.setVector(MergeSortList.getVector());
    BubbleSortList.setVector(MergeSortList.getVector());

    InitializeAllegro(); //Initialize Allegro Add-ons and other allegro components
    DisplayTitle(Screen_H, Screen_W); //Displays the window that the sorts and search will be displayed on with an appropriate title

    Timer = clock(); //Sets the current time as the value for the clock variable

    MergeSortList.mergeSort(0, listSize-1, swaps, comps); //Starts the merge sort on the list that was made for merge sort
    Timer = clock() - Timer; //subtracts the initial time from the end time to get a number for how many "clocks" or ticks have passed since the start of the search
    MergeSortList.TextUpdate(Timer); //converts the ticks to seconds using a built in value in the time.h, also displays the time taken to sort

    al_rest(2);

    counterReset(swaps, comps); //resets the counters for the next search


    Timer = clock(); //sets time like above
    QuickSortList.quickSort(0, listSize-1, swaps, comps); //Implements quick sort
    Timer = clock() - Timer; //gets the time elapsed
    QuickSortList.TextUpdate(Timer); //displays the time

    al_rest(2);
    counterReset(swaps, comps);

    Timer = clock(); //gets time
    BubbleSortList.bubbleSort(listSize-1, swaps, comps); //uses bubble sort
    Timer = clock() - Timer; //gets time elapsed
    BubbleSortList.TextUpdate(Timer); //displays the time taken


    al_rest(2);
    counterReset(swaps, comps);

    //prints the value of element 55 so that you have a value you can be certain is in the array
    cout << "Search this: " << QuickSortList.getVal(55) << ", because this had been confirmed to be the 55th element in the array" << endl;

    al_clear_to_color(BLACK);

    //Asks user what number they want to search for
    DrawText("Type a number to search: ");
    al_flip_display();

    searchNum = QuickSortList.TextInput(); //sets the number typed in as the search target
    Timer = clock(); //sets current time
    indexNum = QuickSortList.BinarySearch(listSize, 0, searchNum, comps); //implements binary search and returns the index if it is in array, if not it returns -1


    //Either displays the results of the search depending on the index returned (if it was -1 then it says it isn't in the array)
    if (indexNum == -1){
        QuickSortList.TextUpdate(-1, "Binary Search", searchNum, comps);
        Timer = clock() - Timer;
        QuickSortList.TextUpdate(Timer);
    }
    else {
        QuickSortList.TextUpdate(indexNum, "Binary Search", searchNum, comps);
        Timer = clock() - Timer;
        QuickSortList.TextUpdate(Timer);
    }

    al_rest(10);

    return 0;
}
