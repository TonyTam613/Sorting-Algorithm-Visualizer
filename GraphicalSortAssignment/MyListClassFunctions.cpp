#include "MyListClassHeader.h"
#include "AllegroHeader.h"

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_FONT *arial;

void MyList::mergeSort(int left, int right, int &swaps, int &comps){
    if (left < right)
    {
        //finds the value for the middle element of the array
        int middle = (left+right)/2;

        // Sort first and second halves and keeps spilling the left side until theres only 1 left
        mergeSort(left, middle, swaps, comps);
        //after finishing splitting the left side moves on the the right sides
        mergeSort(middle+1, right, swaps, comps);

        //merges the elements back together
        merge(left, middle, right, swaps, comps);
    }
}

void MyList::merge(int left, int middle, int right, int &swaps, int &comps){
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 =  right - middle;

    // create temp arrays
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = getVal(left + i);
    for (j = 0; j < n2; j++)
        R[j] = getVal(middle + 1+ j);

    // Merge the temp arrays back into the original vector depending on which is bigger
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        comps++;
        if (L[i] <= R[j])
        {
            setVal(k, L[i]);
            MoveUpdate(k);
            TextUpdate(swaps, comps, "Merge Sort");
            i++;
        }
        else
        {
            setVal(k, R[j]);
            swaps++;
            MoveUpdate(k);
            TextUpdate(swaps, comps, "Merge Sort");
            j++;
        }
        k++;
    }

    //Copy the remaining elements of L[], if there are any left over
    while (i < n1)
    {
        setVal(k, L[i]);
        MoveUpdate(k);
        TextUpdate(swaps, comps, "Merge Sort");
        i++;
        k++;
    }

    //Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        setVal(k, R[j]);
        MoveUpdate(k);
        TextUpdate(swaps, comps, "Merge Sort");
        j++;
        k++;
    }
}

void MyList::quickSort(int first, int last, int &swaps, int &comps){
    if (first < last){
        int partitionNum = 0;

        //moves all the numbers to the proper side of the pivot
        partitionNum = partition(first, last, swaps, comps);
        quickSort(first, partitionNum - 1, swaps, comps);
        quickSort(partitionNum + 1, last, swaps, comps);
    }
}

int MyList::partition(int low, int high, int &swaps, int &comps){
    int pivot = 0;
    int Holder = 0;
    pivot = getVal(high);

    int i = (low - 1);

    //compares vals and swaps if needed, in order to move things to the correct side of the pivot
    for (int j = low; j < high; j++){
        comps++;
        if (getVal(j) <= pivot){
            swaps++;
            i++;
            Holder = getVal(j);
            setVal(j, getVal(i));
            setVal(i, Holder);
            MoveUpdate(high, j);
            TextUpdate(swaps, comps, "Quick Sort");

        }
    }

    swaps++;
    Holder = getVal(high);
    setVal(high, getVal(i+1));
    setVal(i+1, Holder);
    MoveUpdate(high, i);
    TextUpdate(swaps, comps, "Quick Sort");
    return (i + 1);

}

int MyList::BinarySearch(int end, int start, int x, int &comps){
    int mid = (end + start) / 2;
    MoveUpdate(end, start, mid);
    al_rest(1);

    //it conpares the mid val to the val that is being searched for and looks on the side of the array that it should be on, and keeps splitting it in half until it finds it
    if (end >= start){
        comps++;
        if (getVal(mid) == x){
            return mid;
        }
        if (getVal(mid) > x){
            return BinarySearch(mid - 1, start, x, comps);
        }
        else{
            return BinarySearch(end, mid + 1, x, comps);
        }
    }
    return -1;
}

void MyList::bubbleSort(int end, int &swaps, int &comps){
    int j = 0;

    //compares the current val to the one in front of it and swaps it if its bigger and after each run through it decreases the value of the end so that it doesn't compare already in order values again
    if (end > 1) {
        for (int i = 0; i < end; i++){
            comps++;
            if (getVal(i) > getVal(i+1)){
                swaps++;
                j = getVal(i);
                setVal(i, getVal(i+1));
                setVal(i+1, j);
                MoveUpdate(i, i+1);
                TextUpdate(swaps, comps, "Bubble Sort");
            }
        }
        bubbleSort(end - 1, swaps, comps);
    }
}

void MyList::setVal(int index, int Num){
    //sets the value of the vector at a certain index to a certain number
    ListofNumbers[index] = Num;
}

int MyList::getVal(int index){
    //retrieves the val of a certain element in the vector
    return ListofNumbers[index];
}

int MyList::getSize(){
    //gets the size of the vector
    return ListofNumbers.size();
}

MyList::MyList(int Amount){
    int randomNumber = 0;

    srand(time(0)); // seeds the random to current time

    //fills the vector (list) with random numbers
    for (int i = 0; i < Amount; i++){
        randomNumber = rand() % (Screen_H - 42) + 1;
        ListofNumbers.push_back(randomNumber);
    }
}

int MyList::TextInput(){
    bool done = false;
    string InputStr = "";
    int returnVal = 0;

    //appends the corresponding number to a string and gets its int value
    while (!done){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_PAD_0:
                case ALLEGRO_KEY_0:
                    InputStr.append("0");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_1:
                case ALLEGRO_KEY_1:
                    InputStr.append("1");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_2:
                case ALLEGRO_KEY_2:
                    InputStr.append("2");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_3:
                case ALLEGRO_KEY_3:
                    InputStr.append("3");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_4:
                case ALLEGRO_KEY_4:
                    InputStr.append("4");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_5:
                case ALLEGRO_KEY_5:
                    InputStr.append("5");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_6:
                case ALLEGRO_KEY_6:
                    InputStr.append("6");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_7:
                case ALLEGRO_KEY_7:
                    InputStr.append("7");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_8:
                case ALLEGRO_KEY_8:
                    InputStr.append("8");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_9:
                case ALLEGRO_KEY_9:
                    InputStr.append("9");
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_BACKSPACE:
                    if (InputStr.size() != 0){
                        InputStr.pop_back();
                    }
                    TextUpdate(InputStr);
                    break;

                case ALLEGRO_KEY_PAD_ENTER:
                case ALLEGRO_KEY_ENTER:
                    done = true;
                    break;

                default:
                    break;
            }
        }
    }
    returnVal = stoi(InputStr);
    return returnVal;

}

void MyList::MoveUpdate(int pivot, int highlight){
    //clears screen to black
    al_clear_to_color(BLACK);

    //Draws the rectangles, and colours it if its the current rectangle being looked at or the pivot
    for (int i = 0; i < getSize(); i++){
        if (i == pivot){
            al_draw_filled_rectangle( i * (Screen_W/getSize()), Screen_H, (i + 1)  * (Screen_W / getSize()), Screen_H - (getVal(i)), PINK);
        }
        else if (i == highlight){
            al_draw_filled_rectangle( i * (Screen_W/getSize()), Screen_H, (i + 1)  * (Screen_W / getSize()), Screen_H - (getVal(i)), GREEN);
        }
        else{
            al_draw_filled_rectangle( i * (Screen_W/getSize()), Screen_H, (i + 1)  * (Screen_W / getSize()), Screen_H - (getVal(i)), WHITE);
        }
    }

    //draws a line to separate text and rectangles
    al_draw_line(0, 40, Screen_W, 40, WHITE, 2);

}

void MyList::MoveUpdate(int end, int start, int highlight){
    //clears the screen to black
    al_clear_to_color(BLACK);

    //displays the binary sort, and colours the blocks being looked at in pink and the middle block green
    for (int i = 0; i < getSize(); i++){
        if (i >= start && i <= end && i!= highlight){
            al_draw_filled_rectangle( i * (Screen_W/getSize()), Screen_H, (i + 1)  * (Screen_W / getSize()), Screen_H - (getVal(i)), PINK);
        }
        else if (i == highlight){
            al_draw_filled_rectangle( i * (Screen_W/getSize()), Screen_H, (i + 1)  * (Screen_W / getSize()), Screen_H - (getVal(i)), GREEN);
        }
        else{
            al_draw_filled_rectangle( i * (Screen_W/getSize()), Screen_H, (i + 1)  * (Screen_W / getSize()), Screen_H - (getVal(i)), WHITE);
        }
    }

    //draws a line to separate the stats and rectangles
    al_draw_line(0, 40, Screen_W, 40, WHITE, 2);
    al_flip_display();
}

void MyList::MoveUpdate(int highlight){
    //Clears screen to black
    al_clear_to_color(BLACK);

    //highlights current rectangle green
    for (int i = 0; i < getSize(); i++){
        if (i == highlight){
            al_draw_filled_rectangle( i * (Screen_W/getSize()), Screen_H, (i + 1)  * (Screen_W / getSize()), Screen_H - (getVal(i)), GREEN);
        }else{
            al_draw_filled_rectangle( i * (Screen_W/getSize()), Screen_H, (i + 1)  * (Screen_W / getSize()), Screen_H - (getVal(i)), WHITE);
        }
    }

    //draws the line separating stats and rectangles
    al_draw_line(0, 40, Screen_W, 40, WHITE, 2);
}

void MyList::TextUpdate(int Swaps, int Comparissons, string SortName){
    //used stingstream to replace to_string
    stringstream ss;
    stringstream ss2;

    //sets the val for swaps and comps to the string streams
    ss << Swaps;
    ss2 << Comparissons;

    //created olders for displaying purposed
    string Holder = "";
    string Holder2 = "";

    //sets the stringstream val to the string holder
    Holder = ss.str();
    Holder2 = ss2.str();

    //draws all the test to the screen
    al_draw_text(arial, WHITE, Screen_W/5, 2, ALLEGRO_ALIGN_RIGHT, "Swaps: ");
    al_draw_text(arial, WHITE, Screen_W/5, 2, ALLEGRO_ALIGN_LEFT, Holder.c_str());
    al_draw_text(arial, WHITE, Screen_W - 4, 2, ALLEGRO_ALIGN_RIGHT, SortName.c_str());
    al_draw_text(arial, WHITE, (Screen_W*2)/5, 2, ALLEGRO_ALIGN_RIGHT, "Comps: ");
    al_draw_text(arial, WHITE, (Screen_W*2)/5, 2, ALLEGRO_ALIGN_LEFT, Holder2.c_str());

    //updates the display
    al_flip_display();
}

void MyList::TextUpdate(int Time){
    stringstream ss;

    //converts clocks to seconds for display
    ss << (float)Time/CLOCKS_PER_SEC;

    string Holder = "";
    Holder = ss.str();

    //displays the time taken
    al_draw_text(arial, WHITE, (Screen_W*4)/5, 2, ALLEGRO_ALIGN_RIGHT, "Time(seconds): ");
    al_draw_text(arial, WHITE, (Screen_W*4)/5, 2, ALLEGRO_ALIGN_LEFT, Holder.c_str());
    al_flip_display();
}

void MyList::TextUpdate(int Index, string Title, int Num, int comps){
    stringstream ssIndex;
    stringstream ssNum;
    stringstream ssComps;
    string Holder = "";

    ssNum << Num;
    ssIndex << Index;
    ssComps << comps;

    Holder = ssNum.str();

    //displays the search results and stats
    if (Index != -1){
        al_draw_text(arial, WHITE, 70, 2, ALLEGRO_ALIGN_LEFT, "Is At Index: ");
        al_draw_text(arial, WHITE, 2, 2, ALLEGRO_ALIGN_LEFT, Holder.c_str());

        Holder = ssIndex.str();

        al_draw_text(arial, WHITE, 230, 2, ALLEGRO_ALIGN_LEFT, Holder.c_str());
    }
    else{
        al_draw_text(arial, WHITE, 2, 2, ALLEGRO_ALIGN_LEFT, Holder.c_str());
        al_draw_text(arial, WHITE, 77, 2, ALLEGRO_ALIGN_LEFT, "Is not in the array");
    }
    al_draw_text(arial, WHITE, Screen_W - 4, 2, ALLEGRO_ALIGN_RIGHT, Title.c_str());

    Holder = ssComps.str();

    al_draw_text(arial, WHITE, 470, 2, ALLEGRO_ALIGN_RIGHT, "Comps: ");
    al_draw_text(arial, WHITE, 470, 2, ALLEGRO_ALIGN_LEFT, Holder.c_str());

    al_flip_display();
}

void MyList::TextUpdate(string InputNum){
    al_clear_to_color(BLACK);

    //Displays the words that ask you what to search for and the numbers you've typed
    DrawText("Type a number to search: ");
    al_draw_text(arial, WHITE, 350, 2, ALLEGRO_ALIGN_LEFT, InputNum.c_str());
    al_flip_display();
}

void MyList::setVector(vector<int> Vector1){
    ListofNumbers = Vector1;
}

vector<int> MyList::getVector(){
    return ListofNumbers;

}

MyList::~MyList(){
    ListofNumbers.clear();
}

void counterReset(int &swaps, int &comps){
    //resets the counters for the next sort
    swaps = 0;
    comps = 0;
}
