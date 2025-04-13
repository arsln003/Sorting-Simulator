#include <iostream>
#include <iomanip>
#include<thread>
#include<chrono>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
int g1;
int g2;
using namespace std;

void waitForKeyPress()
{
    cout << "Press any key to continue...";
    cin.get();
}
void printSeparator(char separator = '-')
{
    for (int i = 0; i < 100; i++)
    {
        cout << separator;
    }
    cout << endl;
}
void printHeader(string header)
{
    cout << setw(45) << right << "                                 ||-------------------------------------------||" << endl;
    cout << setw(50) << left << "        " << header << endl;
    cout << setw(45) << right << "                                 ||-------------------------------------------||" << endl;
}
void printOptions()
{
    cout << setw(20) << left << "1. Single Sorting" << endl;
    cout << setw(20) << left << "2. Comparison" << endl;
    cout << setw(20) << left << "3. History" << endl;

    cout << setw(20) << left << "4. Exit" <<
        endl;
}
void displayArray(int arr[], int size, int start) {
    for (int i = start; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "     ";
}
void printFooter(string footer)
{
    cout << setw(100) << footer << endl << endl << endl << endl;
}
void displaysort(int* arr, int size, int index) {
    for (int i = 0; i < size; i++) {
        if (i == index) {
            cout << "[" << arr[index] << "] ";
        }
        else {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
void selection_sort(int* arr, int size)
{



    int index, temp;
    for (int i = 0; i < size - 1; i++) {
        index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        cout << "smallest value : " << arr[index] << endl;
        displaysort(arr, size, index);
        cout << "swapping  " << endl;
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
        this_thread::sleep_for(chrono::seconds(1));

    }
    cout << "AFTER SORTING:     ";
    displayArray(arr, size, 0);


}
void displaySorting(int a[], int l, int r, int mid) {

    cout << "\nArray: ";
    for (int i = l; i <= r; i++) {
        if (i == mid) {
            cout << "[" << a[i] << "] ";
        }
        else {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}
void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int* a = new int[n1];
    int* b = new int[n2];

    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }



    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            k++; i++;
        }
        else {
            arr[k] = b[j];
            k++; j++;
        }
    }

    while (i < n1) {
        arr[k] = a[i];
        k++; i++;
    }

    while (j < n2) {
        arr[k] = b[j];
        k++; j++;
    }

    cout << "Merging: ";
    displayArray(arr, r + 1, l);
    cout << endl;

    delete[] a;
    delete[] b;
}
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        this_thread::sleep_for(chrono::seconds(1));


        // cout << "Before splitting: ";

        displaySorting(arr, l, r, mid);


        displayArray(arr, mid + 1, l);
        displayArray(arr, r + 1, mid + 1);





        mergesort(arr, l, mid);
        /*  system("cls");
          cout << "            "; displayArray(b, r, 0);*/
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
void display(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void displaySortingp(int a[], int l, int r, int pivot) {
    for (int i = l; i <= r; i++) {
        if (i == pivot) {
            cout << "[" << a[i] << "] ";
        }
        else {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, r);

    return i + 1;
}
void quicksort(int a[], int l, int r) {
    if (l < r) {
        this_thread::sleep_for(chrono::seconds(1));
        displaySortingp(a, l, r, r);

        int pi = partition(a, l, r);
        displaySortingp(a, l, r, pi);

        quicksort(a, l, pi - 1);

        quicksort(a, pi + 1, r);
    }
}
void printSteps(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        this_thread::sleep_for(chrono::seconds(1));
        std::cout << "Step " << i + 1 << ": [";
        for (int k = 0; k <= i; ++k) {
            std::cout << arr[k];
            if (k < i) std::cout << ", ";
        }
        std::cout << "] (Unsorted: [";
        for (int k = i + 1; k < n; ++k) {
            std::cout << arr[k];
            if (k < n - 1) std::cout << ", ";
        }
        std::cout << "])\n";
    }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key,
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void option1(int* arr, int n)
{
    system("cls");

    printHeader("SORTING SIMULATOR");
    printFooter("by Ateeb Azam, Arsalan, Qasim");
    cout << setw(45) << right << "                               ALGORITHMS        BEST CASE               AVERAGE CASE           WORST CASE       " << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << setw(45) << right << "                     || INSERTION SORT     ||   O(n)                 ||   O(n)^2          ||   O(n)^2          ||" << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << setw(45) << right << "                     || SELECTION SORT     ||   O(n)^2               ||   O(n)^2          ||    O(n)^2         ||" << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << setw(45) << right << "                     || MERGE SORT         ||   O(nlog[n])           ||   O(nlog[n])      ||    O(nlog[n])     ||" << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << setw(45) << right << "                     || QUICK SORT         ||   O(nlog[n])           ||   O(nlog[n])      ||    O(n)^2         ||" << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << "choose [1-4]" << endl;
    int opt;
    cin >> opt;
    system("cls");

    switch (opt)
    {
    case 1:
    {
        printHeader("INSERTION SORT");
        cout << "ARRAY FOR SORTING      ";

        display(arr, n);
        fstream outputFile("insertion_sort.txt", ios::app);
        outputFile << "\nInsertion Sort: " << endl;
        outputFile << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";
        }
        outputFile << endl;
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(arr, n);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        printSteps(arr, n);
        cout << "\nARRAY AFTER SORTING!\n";
        displayArray(arr, n);
        cout << "time taken " << duration.count() << " nanoseconds " << endl;
        outputFile << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";

        }
        outputFile.close();
    }


    break;
    case 2:
    {
        printHeader("SELECTION SORT");
        cout << "ARRAY FOR SORTING      ";
        display(arr, n);
        fstream outputFile("selection_sort.txt", ios::app);
        outputFile << "Selection Sort: " << endl;
        outputFile << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";
        }
        outputFile << endl;

        auto start = std::chrono::high_resolution_clock::now();

        selection_sort(arr, n);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "time taken " << duration.count() << " nanoseconds " << endl;
        outputFile << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";

        }
        outputFile.close();
    }
    break;
    case 3:
    {
        printHeader("MERGE SORT");
        cout << "ARRAY FOR SORTING      ";
        cout << "[ ]=mid\n";
        display(arr, n);
        fstream outputFile("merge_sort.txt", ios::app);
        outputFile << "Merge Sort: " << endl;
        outputFile << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";
        }
        outputFile << endl;
        auto start = std::chrono::high_resolution_clock::now();

        mergesort(arr, 0, n - 1);
        auto stop = std::chrono::high_resolution_clock::now();

        cout << "\nARRAY AFTER SORTING:  ";
        displayArray(arr, n, 0);
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "\ntime taken " << duration.count() << " nanoseconds " << endl;
        outputFile << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";

        }
        outputFile.close();
    }
    break;
    case 4:
    {
        printHeader("QUICK SORT");
        cout << "ARRAY FOR SORTING      ";
        cout << "[ ]=pivot\n";
        cout << "\n             SORTING IS DONE FIRST ON THE LEFT SIDE OF THE PIVOT  THEN THE RIGHT SIDE IF NEEDED!\n\n";

        display(arr, n);
        fstream outputFile("quick_sort.txt", ios::app);
        outputFile << "Quick Sort: " << endl;
        outputFile << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";
        }
        outputFile << endl;
        auto start = std::chrono::high_resolution_clock::now();

        quicksort(arr, 0, n - 1);
        auto stop = std::chrono::high_resolution_clock::now();

        cout << "\nARRAY AFTER SORTING:  ";
        displayArray(arr, n, 0);
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "\ntime taken " << duration.count() << " nanoseconds " << endl;
        outputFile << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";

        }
        outputFile.close();
    }
    break;

    default:
        break;
    }
}
void option2(int* arr, int n, int* a)
{
    printHeader("SORTING SIMULATOR");
    printFooter("by Ateeb Azam, Arsalan, Qasim");
    cout << setw(45) << right << "                               ALGORITHMS        BEST CASE               AVERAGE CASE           WORST CASE       " << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << setw(45) << right << "                     || INSERTION SORT     ||   O(n)                 ||   O(n)^2          ||   O(n)^2          ||" << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << setw(45) << right << "                     || SELECTION SORT     ||   O(n)^2               ||   O(n)^2          ||    O(n)^2         ||" << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << setw(45) << right << "                     || MERGE SORT         ||   O(nlog[n])           ||   O(nlog[n])      ||    O(nlog[n])     ||" << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;
    cout << setw(45) << right << "                     || QUICK SORT         ||   O(nlog[n])           ||   O(nlog[n])      ||    O(n)^2         ||" << endl;
    cout << setw(45) << right << "                     ||----------------------------------------------------------------------------------------||" << endl;


    cout << "CHOOSE ANY 2!" << endl;
    int opt1, opt2;
    cin >> opt1 >> opt2;
    g1 = opt1; g2 = opt2;
    system("cls");
    /*12 13 14
      21 23 24
      31 32 34
      41 42 43*/
    if (opt1 == 1 && opt2 == 2 || opt1 == 2 && opt2 == 1)
    {
        printHeader("INSERTION SORT");
        cout << "ARRAY FOR SORTING      ";
        display(arr, n);
        fstream outputFile("insertion_sort.txt", ios::app);
        outputFile << "\nInsertion Sort: " << endl;
        outputFile << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";
        }
        outputFile << endl;
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(arr, n);
        auto stop = std::chrono::high_resolution_clock::now();
        printSteps(arr, n);
        auto duration_insertion = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "time taken " << duration_insertion.count() << " nanoseconds." << endl;
        outputFile << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";

        }
        outputFile.close();


        //selection sort
        fstream outputFileS("selection_sort.txt", ios::app);
        outputFileS << "Selection Sort: " << endl;
        outputFileS << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFileS << arr[i] << " ";
        }
        outputFileS << endl;
        printHeader("SELECTION SORT");
        cout << "ARRAY FOR SORTING      ";
        display(a, n);
        auto start_sec = std::chrono::high_resolution_clock::now();
        selection_sort(a, n);
        auto stop_sec = std::chrono::high_resolution_clock::now();
        auto duration_selection = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_sec - start_sec);
        cout << "time taken " << duration_selection.count() << " nanosecond" << endl;
        outputFileS << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFileS << arr[i] << " ";

        }
        outputFileS.close();


        int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

        if (result == IDOK) {
            // cout << "Arsalan";
             // Continue with further code here
            cout << setw(45) << right << "    || INSERTION SORT                              | SELECTION SORT                             ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
            cout << "    ||" << duration_insertion.count() << " nanosecond" << "                               |   " << duration_selection.count() << " nanoseconds                   || " << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                   Algorithmic Approach                                   ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||Insertion sort incrementally builds the      |Selection sort repeatedly selects the       ||" << endl;
            cout << setw(45) << right << "    ||sorted sequence by taking each element from  |minimum element from the unsorted part of   ||" << endl;
            cout << setw(45) << right << "    ||the unsorted section and placing it in its   |the array, placing it at the beginning,     ||" << endl;
            cout << setw(45) << right << "    ||correct position within the sorted part.     |thus incrementally growing the sorted       ||" << endl;
            cout << setw(45) << right << "    ||                                             |portion of the array.                       ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                   Efficiency and Performance:                            ||" << endl;
            cout << setw(45) << right << "    ||Insertion sort's efficiency surpasses        |Selection sort has a consistent performance ||" << endl;
            cout << setw(45) << right << "    ||selection sort, especially with smaller or   |regardless of the initial order of          ||" << endl;
            cout << setw(45) << right << "    ||partially sorted datasets, as it adapts to   |elements. However, it is generally less     ||" << endl;
            cout << setw(45) << right << "    ||and capitalizes on the existing order within |efficient than insertion sort for most      ||" << endl;
            cout << setw(45) << right << "    ||the input data.                              |cases.                                      ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


        }
        else {
            // Stop execution if the user clicks "Cancel" or closes the message box
            //main();
            system("pause");
        }

    }
    else if (opt1 == 1 && opt2 == 3 || opt1 == 3 && opt2 == 1)
    {
        printHeader("INSERTION SORT");
        cout << "ARRAY FOR SORTING      ";
        display(arr, n);
        fstream outputFile("insertion_sort.txt", ios::app);
        outputFile << "\nInsertion Sort: " << endl;
        outputFile << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";
        }
        outputFile << endl;
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(arr, n);
        auto stop = std::chrono::high_resolution_clock::now();
        printSteps(arr, n);
        auto duration_insertion = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "time taken " << duration_insertion.count() << " nanoseconds." << endl;
        outputFile << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";

        }
        outputFile.close();
        //merge sort
        printHeader("MERGE SORT");
        cout << "ARRAY FOR SORTING      ";
        display(a, n);
        cout << "[ ]=mid\n";
        fstream outputFileM("merge_sort.txt", ios::app);
        outputFileM << "\nMerge Sort: " << endl;
        outputFileM << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFileM << arr[i] << " ";
        }
        outputFileM << endl;
        auto startM = std::chrono::high_resolution_clock::now();
        mergesort(a, 0, n - 1);
        auto stopM = std::chrono::high_resolution_clock::now();


        cout << "\nARRAY AFTER SORTING:  ";
        displayArray(a, n, 0);
        auto duration_MERGE = std::chrono::duration_cast<std::chrono::nanoseconds>(stopM - startM);
        cout << "time taken " << duration_MERGE.count() << " nanoseconds." << endl;

        outputFileM << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFileM << arr[i] << " ";

        }
        outputFileM.close();
        int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

        if (result == IDOK) {
            // cout << "Arsalan";
             // Continue with further code here
            cout << setw(45) << right << "    || INSERTION SORT                              | MERGE SORT                                 ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
            cout << "    ||" << duration_insertion.count() << " nanosecond" << "                               |   " << duration_MERGE.count() << " nanoseconds                       || " << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                       Adaptability:                                      ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||Insertion sort's adaptive nature allows it   |Merge sort consistently performs with       ||" << endl;
            cout << setw(45) << right << "    ||to perform more efficiently with partially   |O(n log n) time complexity, maintaining     ||" << endl;
            cout << setw(45) << right << "    ||sorted arrays, completing in less time than  |stability regardless of the initial order   ||" << endl;
            cout << setw(45) << right << "    ||its worst-case scenario when the input data  |of elements and lacking inherent            ||" << endl;
            cout << setw(45) << right << "    ||is nearly sorted.                            |adaptability to pre-existing order in the   ||" << endl;
            cout << setw(45) << right << "    ||                                             |input.                                      ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                       Space Complexity                                   ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||It's an in-place sorting algorithm, utilizing|It necessitates extra memory for merging,   ||" << endl;
            cout << setw(45) << right << "    ||a constant amount of extra memory for        |creating temporary arrays proportional to   ||" << endl;
            cout << setw(45) << right << "    ||variables, without requiring additional space|the input size. This gives merge sort a     ||" << endl;
            cout << setw(45) << right << "    ||proportional to the input size.              |space complexity of O(n).                   ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


        }
        else {
            // Stop execution if the user clicks "Cancel" or closes the message box
            //main();
            system("pause");
        }



    }
    else if (opt1 == 1 && opt2 == 4 || opt1 == 4 && opt2 == 1)
    {
        printHeader("INSERTION SORT");
        cout << "ARRAY FOR SORTING      ";
        display(arr, n);
        fstream outputFile("insertion_sort.txt", ios::app);
        outputFile << "\nInsertion Sort: " << endl;
        outputFile << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";
        }
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(arr, n);
        auto stop = std::chrono::high_resolution_clock::now();
        printSteps(arr, n);
        auto duration_insertion = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        cout << "time taken " << duration_insertion.count() << " nanoseconds." << endl;
        outputFile << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFile << arr[i] << " ";

        }
        outputFile.close();
        //QUICK SORT
        printHeader("QUICK SORT");
        cout << "ARRAY FOR SORTING      ";
        display(a, n);
        cout << "[ ]=pivot\n";
        cout << "\n             SORTING IS DONE FIRST ON THE LEFT SIDE OF THE PIVOT  THEN THE RIGHT SIDE IF NEEDED!\n\n";

        display(a, n);
        fstream outputFileq("quick_sort.txt", ios::app);
        outputFileq << "Quick Sort: " << endl;
        outputFileq << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFileq << arr[i] << " ";
        }
        auto startQ = std::chrono::high_resolution_clock::now();

        quicksort(a, 0, n - 1);
        cout << "\nARRAY AFTER SORTING:  ";
        displayArray(a, n, 0);
        auto stopQ = std::chrono::high_resolution_clock::now();
        auto duration_QUICK = std::chrono::duration_cast<std::chrono::nanoseconds>(stopQ - startQ);
        cout << "time taken " << duration_QUICK.count() << " nanoseconds." << endl;
        outputFileq << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFileq << arr[i] << " ";

        }
        outputFileq.close();

        int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

        if (result == IDOK) {
            // cout << "Arsalan";
             // Continue with further code here
            cout << setw(45) << right << "    || INSERTION SORT                              | QUICK SORT                                 ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
            cout << "    ||" << duration_insertion.count() << " nanosecond" << "                               |   " << duration_QUICK.count() << " nanoseconds                   || " << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                      Adaptability:                                       ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||It is adaptive, meaning its performance is   |It is not as adaptive as insertion sort,    ||" << endl;
            cout << setw(45) << right << "    ||better when the input array is partially     |as its performance doesn't necessarily      ||" << endl;
            cout << setw(45) << right << "    ||sorted.                                      |improve with partially sorted input.        ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                       Space Complexity:                                  ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||It is an in-place sorting algorithm, meaning |It is also an in-place sorting algorithm,   ||" << endl;
            cout << setw(45) << right << "    ||it doesn't require additional memory beyond  |but it requires a small amount of           ||" << endl;
            cout << setw(45) << right << "    ||the original array.                          |additional memory for the recursive call    ||" << endl;
            cout << setw(45) << right << "    ||                                             |stack.                                      ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


        }
        else {
            // Stop execution if the user clicks "Cancel" or closes the message box
            //main();
            system("pause");
        }


    }
    //else if (opt1 == 2 && opt2 == 1)
    //{
    //    printHeader("INSERTION SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(arr, n);
    //    fstream outputFile("insertion_sort.txt");
    //    outputFile << "Insertion Sort: " << endl;
    //    outputFile << "Before Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFile << arr[i] << " ";
    //    }
    //    auto start = std::chrono::high_resolution_clock::now();
    //    insertionSort(arr, n);
    //    auto stop = std::chrono::high_resolution_clock::now();
    //    printSteps(arr, n);
    //    auto duration_insertion = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    //    cout << "time taken " << duration_insertion.count() << " nanoseconds." << endl;

    //    outputFile << "After Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFile << arr[i] << " ";

    //    }
    //    outputFile.close();
    //    //selection sort


    //    printHeader("SELECTION SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(a, n);
    //    fstream outputFiles("selection_sort.txt");
    //    outputFiles << "Selection Sort: " << endl;
    //    outputFiles << "Before Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFiles << arr[i] << " ";
    //    }
    //    outputFiles << endl;
    //    auto start_sec = std::chrono::high_resolution_clock::now();
    //    selection_sort(a, n);
    //    auto stop_sec = std::chrono::high_resolution_clock::now();
    //    auto duration_selection = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_sec - start_sec);
    //    cout << "time taken " << duration_selection.count() << endl;
    //    outputFile << "After Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFiles << arr[i] << " ";

    //    }
    //    outputFiles.close();
    //    int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

    //    if (result == IDOK) {
    //        // cout << "Arsalan";
    //         // Continue with further code here
    //        cout << setw(45) << right << "    || INSERTION SORT                              | SELECTION SORT                             ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
    //        cout << "    ||" << duration_insertion.count() << " nanosecond" << "                               |   " << duration_selection.count() << " nanoseconds                   || " << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                   Algorithmic Approach                                   ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||Insertion sort incrementally builds the      |Selection sort repeatedly selects the       ||" << endl;
    //        cout << setw(45) << right << "    ||sorted sequence by taking each element from  |minimum element from the unsorted part of   ||" << endl;
    //        cout << setw(45) << right << "    ||the unsorted section and placing it in its   |the array, placing it at the beginning,     ||" << endl;
    //        cout << setw(45) << right << "    ||correct position within the sorted part.     |thus incrementally growing the sorted       ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |portion of the array.                       ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                   Efficiency and Performance:                            ||" << endl;
    //        cout << setw(45) << right << "    ||Insertion sort's efficiency surpasses        |Selection sort has a consistent performance ||" << endl;
    //        cout << setw(45) << right << "    ||selection sort, especially with smaller or   |regardless of the initial order of          ||" << endl;
    //        cout << setw(45) << right << "    ||partially sorted datasets, as it adapts to   |elements. However, it is generally less     ||" << endl;
    //        cout << setw(45) << right << "    ||and capitalizes on the existing order within |efficient than insertion sort for most      ||" << endl;
    //        cout << setw(45) << right << "    ||the input data.                              |cases.                                      ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


    //    }
    //    else {
    //        // Stop execution if the user clicks "Cancel" or closes the message box
    //        //main();
    //        system("pause");
    //    }
    //}
    else if (opt1 == 2 && opt2 == 3 || opt1 == 3 && opt2 == 2)
    {
        printHeader("SELECTION SORT");
        cout << "ARRAY FOR SORTING      ";
        display(arr, n);
        fstream outputFiles("selection_sort.txt", ios::app);
        outputFiles << "\nSelection Sort: " << endl;
        outputFiles << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFiles << arr[i] << " ";
        }
        outputFiles << endl;
        auto start_sec = std::chrono::high_resolution_clock::now();
        selection_sort(arr, n);
        auto stop_sec = std::chrono::high_resolution_clock::now();
        auto duration_selection = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_sec - start_sec);
        cout << "time taken " << duration_selection.count() << endl;
        outputFiles << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFiles << arr[i] << " ";

        }
        outputFiles.close();
        //merge sort
        printHeader("MERGE SORT");
        cout << "ARRAY FOR SORTING      ";
        display(a, n);
        cout << "[ ]=mid\n";
        fstream outputFilem("merge_sort.txt", ios::app);
        outputFilem << "Merge Sort: " << endl;
        outputFilem << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFilem << arr[i] << " ";
        }
        outputFilem << endl;
        auto startM = std::chrono::high_resolution_clock::now();
        mergesort(a, 0, n - 1);
        auto stopM = std::chrono::high_resolution_clock::now();


        cout << "\nARRAY AFTER SORTING:  ";
        displayArray(a, n, 0);
        auto duration_MERGE = std::chrono::duration_cast<std::chrono::nanoseconds>(stopM - startM);
        cout << "time taken " << duration_MERGE.count() << " nanoseconds." << endl;
        outputFilem << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFilem << arr[i] << " ";

        }
        outputFilem.close();
        int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

        if (result == IDOK) {
            // cout << "Arsalan";
             // Continue with further code here
            cout << setw(45) << right << "    || SELECTION SORT                              | MERGE SORT                                 ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
            cout << "    ||" << duration_selection.count() << " nanosecond" << "                    |   " << duration_MERGE.count() << " nanoseconds                       || " << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                        Use Cases:                                        ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||It is often used for educational purposes    |It is suitable for large datasets and is    ||" << endl;
            cout << setw(45) << right << "    ||due to its simplicity. It is not the most    |commonly used in practice. Its efficient    ||" << endl;
            cout << setw(45) << right << "    ||efficient choice for large datasets or       |performance makes it a good choice for      ||" << endl;
            cout << setw(45) << right << "    ||real-world applications.                     |external sorting where data doesn't fit     ||" << endl;
            cout << setw(45) << right << "    ||                                             |into memory.                                ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                       Space Complexity                                   ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||It is an in-place sorting algorithm, meaning |It requires additional memory for the       ||" << endl;
            cout << setw(45) << right << "    ||it does not require additional memory beyond |merging process, so it is not an in-place   ||" << endl;
            cout << setw(45) << right << "    ||the original array.                          |algorithm. Its space complexity is O(n),    ||" << endl;
            cout << setw(45) << right << "    ||                                             |where n is the number of elements.          ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


        }
        else {
            // Stop execution if the user clicks "Cancel" or closes the message box
            //main();
            system("pause");
        }


    }
    else if (opt1 == 2 && opt2 == 4 || opt1 == 4 && opt2 == 2)
    {
        printHeader("SELECTION SORT");
        cout << "ARRAY FOR SORTING      ";
        display(arr, n); fstream outputFiles("selection_sort.txt", ios::app);
        outputFiles << "\nSelection Sort: " << endl;
        outputFiles << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFiles << arr[i] << " ";
        }
        outputFiles << endl;
        auto start_sec = std::chrono::high_resolution_clock::now();

        selection_sort(arr, n);
        auto stop_sec = std::chrono::high_resolution_clock::now();
        auto duration_selection = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_sec - start_sec);
        cout << "time taken " << duration_selection.count() << endl;
        outputFiles << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFiles << arr[i] << " ";

        }
        outputFiles.close();

        //quick sort
        printHeader("QUICK SORT");
        cout << "ARRAY FOR SORTING      ";
        display(a, n);
        cout << "[ ]=pivot\n";
        cout << "\n             SORTING IS DONE FIRST ON THE LEFT SIDE OF THE PIVOT  THEN THE RIGHT SIDE IF NEEDED!\n\n";

        display(a, n);
        fstream outputFileq("quick_sort.txt", ios::app);
        outputFileq << "Quick Sort: " << endl;
        outputFileq << "Before Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFileq << arr[i] << " ";
        }
        outputFileq << endl;
        auto startQ = std::chrono::high_resolution_clock::now();

        quicksort(a, 0, n - 1);
        cout << "\nARRAY AFTER SORTING:  ";
        displayArray(a, n, 0);
        auto stopQ = std::chrono::high_resolution_clock::now();
        auto duration_QUICK = std::chrono::duration_cast<std::chrono::nanoseconds>(stopQ - startQ);
        cout << "time taken " << duration_QUICK.count() << " nanoseconds." << endl;
        outputFileq << "After Sorting: ";
        for (int i = 0; i < n; i++) {
            outputFileq << arr[i] << " ";

        }
        outputFileq.close();

        int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

        if (result == IDOK) {
            // cout << "Arsalan";
             // Continue with further code here
            cout << setw(45) << right << "    || SELECTION SORT                              | QUICK SORT                                 ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
            cout << "    ||" << duration_selection.count() << " nanosecond" << "                        |" << duration_QUICK.count() << " nanoseconds                      || " << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                      Adaptability:                                       ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||It is often used for educational purposes    |It is suitable for large datasets and is    ||" << endl;
            cout << setw(45) << right << "    ||due to its simplicity. It is not the most    |commonly used in practice.                  ||" << endl;
            cout << setw(45) << right << "    ||efficient choice for large datasets or       |                                            ||" << endl;
            cout << setw(45) << right << "    ||real-world applications.                     |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                       Space Complexity:                                  ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||It is an in-place sorting algorithm, meaning |It is also an in-place sorting algorithm,   ||" << endl;
            cout << setw(45) << right << "    ||it doesn't require additional memory beyond  |but it requires a small amount of           ||" << endl;
            cout << setw(45) << right << "    ||the original array.                          |additional memory for the recursive call    ||" << endl;
            cout << setw(45) << right << "    ||                                             |stack.                                      ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


        }
        else {
            // Stop execution if the user clicks "Cancel" or closes the message box
            //main();
            system("pause");
        }


    }
    //else if (opt1 == 3 && opt2 == 1)
    //{
    //    printHeader("INSERTION SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(arr, n);
    //    fstream outputFile("insertion_sort.txt");
    //    outputFile << "Insertion Sort: " << endl;
    //    outputFile << "Before Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFile << arr[i] << " ";
    //    }
    //    auto start = std::chrono::high_resolution_clock::now();
    //    insertionSort(arr, n);
    //    auto stop = std::chrono::high_resolution_clock::now();
    //    printSteps(arr, n);
    //    auto duration_insertion = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    //    cout << "time taken " << duration_insertion.count() << " nanoseconds." << endl;
    //    outputFile << "After Sorting: ";

    //    for (int i = 0; i < n; i++) {
    //        outputFile << arr[i] << " ";

    //    }
    //    outputFile.close();
    //
    //    //merge sort
    //    printHeader("MERGE SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(a, n);
    //    cout << "[ ]=mid\n";
    //    fstream outputFilem("merge_sort.txt");
    //    outputFilem << "Merge Sort: " << endl;
    //    outputFilem << "Before Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFilem << arr[i] << " ";
    //    }
    //    outputFilem << endl;
    //    auto startM = std::chrono::high_resolution_clock::now();
    //    mergesort(a, 0, n - 1);
    //    auto stopM = std::chrono::high_resolution_clock::now();


    //    cout << "\nARRAY AFTER SORTING:  ";
    //    displayArray(a, n, 0);
    //    auto duration_MERGE = std::chrono::duration_cast<std::chrono::nanoseconds>(stopM - startM);
    //    cout << "time taken " << duration_MERGE.count() << " nanoseconds." << endl;
    //    outputFilem << "After Sorting: ";

    //    for (int i = 0; i < n; i++) {
    //        outputFilem << arr[i] << " ";

    //    }
    //    outputFilem.close();

    //    int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

    //    if (result == IDOK) {
    //        // cout << "Arsalan";
    //         // Continue with further code here
    //        cout << setw(45) << right << "    || INSERTION SORT                              | MERGE SORT                                 ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
    //        cout << "    ||" << duration_insertion.count() << " nanosecond" << "                               |   " << duration_MERGE.count() << " nanoseconds                   || " << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                       Adaptability:                                      ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||Insertion sort's adaptive nature allows it   |Merge sort consistently performs with       ||" << endl;
    //        cout << setw(45) << right << "    ||to perform more efficiently with partially   |O(n log n) time complexity, maintaining     ||" << endl;
    //        cout << setw(45) << right << "    ||sorted arrays, completing in less time than  |stability regardless of the initial order   ||" << endl;
    //        cout << setw(45) << right << "    ||its worst-case scenario when the input data  |of elements and lacking inherent            ||" << endl;
    //        cout << setw(45) << right << "    ||is nearly sorted.                            |adaptability to pre-existing order in the   ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |input.                                      ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                       Space Complexity                                   ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||It's an in-place sorting algorithm, utilizing|It necessitates extra memory for merging,   ||" << endl;
    //        cout << setw(45) << right << "    ||a constant amount of extra memory for        |creating temporary arrays proportional to   ||" << endl;
    //        cout << setw(45) << right << "    ||variables, without requiring additional space|the input size. This gives merge sort a     ||" << endl;
    //        cout << setw(45) << right << "    ||proportional to the input size.              |space complexity of O(n).                   ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


    //    }
    //    else {
    //        // Stop execution if the user clicks "Cancel" or closes the message box
    //        //main();
    //        system("pause");
    //    }
    //}
    //else if (opt1 == 3 && opt2 == 2)
    //{
    //    printHeader("SELECTION SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(arr, n);
    //    fstream outputFiles("selection_sort.txt");
    //    outputFiles << "Selection Sort: " << endl;
    //    outputFiles<< "Before Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFiles << arr[i] << " ";
    //    }
    //    outputFiles << endl;
    //    auto start_sec = std::chrono::high_resolution_clock::now();
    //    selection_sort(arr, n);
    //    auto stop_sec = std::chrono::high_resolution_clock::now();
    //    auto duration_selection = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_sec - start_sec);
    //    cout << "time taken " << duration_selection.count() << endl;

    //    outputFiles << "After Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFiles << arr[i] << " ";

    //    }
    //    outputFiles.close();

    //    //merge sort
    //    printHeader("MERGE SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(a, n);
    //    cout << "[ ]=mid\n";
    //    fstream outputFilem("merge_sort.txt");
    //    outputFilem << "Merge Sort: " << endl;
    //    outputFilem << "Before Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFilem << arr[i] << " ";
    //    }
    //    outputFilem << endl;
    //    auto startM = std::chrono::high_resolution_clock::now();
    //    mergesort(a, 0, n - 1);
    //    auto stopM = std::chrono::high_resolution_clock::now();


    //    cout << "\nARRAY AFTER SORTING:  ";
    //    displayArray(a, n, 0);
    //    auto duration_MERGE = std::chrono::duration_cast<std::chrono::nanoseconds>(stopM - startM);
    //    cout << "time taken " << duration_MERGE.count() << " nanoseconds." << endl;

    //    outputFilem << "After Sorting: ";
    //    for (int i = 0; i < n; i++) {
    //        outputFilem << arr[i] << " ";

    //    }
    //    outputFilem.close();
    //    int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

    //    if (result == IDOK) {
    //        // cout << "Arsalan";
    //         // Continue with further code here
    //        cout << setw(45) << right << "    || SELECTION SORT                              | MERGE SORT                                 ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
    //        cout << "    ||" << duration_selection.count() << " nanosecond" << "                        |   " << duration_MERGE.count() << " nanoseconds                   || " << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                        Use Cases:                                        ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||It is often used for educational purposes    |It is suitable for large datasets and is    ||" << endl;
    //        cout << setw(45) << right << "    ||due to its simplicity. It is not the most    |commonly used in practice. Its efficient    ||" << endl;
    //        cout << setw(45) << right << "    ||efficient choice for large datasets or       |performance makes it a good choice for      ||" << endl;
    //        cout << setw(45) << right << "    ||real-world applications.                     |external sorting where data doesn't fit     ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |into memory.                                ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                       Space Complexity                                   ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||It is an in-place sorting algorithm, meaning |It requires additional memory for the       ||" << endl;
    //        cout << setw(45) << right << "    ||it does not require additional memory beyond |merging process, so it is not an in-place   ||" << endl;
    //        cout << setw(45) << right << "    ||the original array.                          |algorithm. Its space complexity is O(n),    ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |where n is the number of elements.          ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


    //    }
    //    else {
    //        // Stop execution if the user clicks "Cancel" or closes the message box
    //        //main();
    //        system("pause");
    //    }
    //}
    else if (opt1 == 3 && opt2 == 4 || opt1 == 4 && opt2 == 3)
    {
        printHeader("MERGE SORT");
        cout << "ARRAY FOR SORTING      ";
        display(arr, n);
        cout << "[ ]=mid\n";
        auto startM = std::chrono::high_resolution_clock::now();
        mergesort(arr, 0, n - 1);
        auto stopM = std::chrono::high_resolution_clock::now();


        cout << "\nARRAY AFTER SORTING:  ";
        displayArray(arr, n, 0);
        auto duration_MERGE = std::chrono::duration_cast<std::chrono::nanoseconds>(stopM - startM);
        cout << "time taken " << duration_MERGE.count() << " nanoseconds." << endl;
        //quick sort
        printHeader("QUICK SORT");
        cout << "ARRAY FOR SORTING      ";
        display(a, n);
        cout << "[ ]=pivot\n";
        cout << "\n             SORTING IS DONE FIRST ON THE LEFT SIDE OF THE PIVOT  THEN THE RIGHT SIDE IF NEEDED!\n\n";

        display(a, n);
        auto startQ = std::chrono::high_resolution_clock::now();

        quicksort(a, 0, n - 1);
        cout << "\nARRAY AFTER SORTING:  ";
        displayArray(a, n, 0);
        auto stopQ = std::chrono::high_resolution_clock::now();
        auto duration_QUICK = std::chrono::duration_cast<std::chrono::nanoseconds>(stopQ - startQ);
        cout << "time taken " << duration_QUICK.count() << " nanoseconds." << endl;



        int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

        if (result == IDOK) {
            // cout << "Arsalan";
             // Continue with further code here
            cout << setw(45) << right << "    || QUICK SORT                                  | MERGE SORT                                 ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
            cout << "    ||" << duration_QUICK.count() << " nanosecond" << "                        |   " << duration_MERGE.count() << " nanoseconds                   || " << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                       Space Complexity                                   ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||Yes, quicksort is an in-place sorting        |No, merge sort is not an in-place sorting   ||" << endl;
            cout << setw(45) << right << "    ||algorithm. However, it requires a small      |algorithm. It requires additional memory    ||" << endl;
            cout << setw(45) << right << "    ||amount of additional memory for the          |for the merging process, making its space   ||" << endl;
            cout << setw(45) << right << "    ||recursive call stack.                        |complexity O(n).                            ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                         Adaptability:                                    ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||It's an in-place sorting algorithm, utilizing|Merge sort's performance is consistent      ||" << endl;
            cout << setw(45) << right << "    ||a constant amount of extra memory for        |regardless of the initial order of the      ||" << endl;
            cout << setw(45) << right << "    ||variables, without requiring additional space|elements.                                   ||" << endl;
            cout << setw(45) << right << "    ||proportional to the input size.              |                                            ||" << endl;
            cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
            cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


        }
        else {
            // Stop execution if the user clicks "Cancel" or closes the message box
            //main();
            system("pause");
        }


    }
    //else if (opt1 == 4 && opt2 == 1)
    //{
    //    printHeader("INSERTION SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(arr, n);
    //    auto start = std::chrono::high_resolution_clock::now();
    //    insertionSort(arr, n);
    //    auto stop = std::chrono::high_resolution_clock::now();
    //    printSteps(arr, n);
    //    auto duration_insertion = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    //    cout << "time taken " << duration_insertion.count() << " nanoseconds." << endl;
    //    //QUICK SORT
    //    printHeader("QUICK SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(a, n);
    //    cout << "[ ]=pivot\n";
    //    cout << "\n             SORTING IS DONE FIRST ON THE LEFT SIDE OF THE PIVOT  THEN THE RIGHT SIDE IF NEEDED!\n\n";

    //    display(a, n);
    //    auto startQ = std::chrono::high_resolution_clock::now();

    //    quicksort(arr, 0, n - 1);
    //    cout << "\nARRAY AFTER SORTING:  ";
    //    displayArray(a, n, 0);
    //    auto stopQ = std::chrono::high_resolution_clock::now();
    //    auto duration_QUICK = std::chrono::duration_cast<std::chrono::nanoseconds>(stopQ - startQ);
    //    cout << "time taken " << duration_QUICK.count() << " nanoseconds." << endl;


    //    int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

    //    if (result == IDOK) {
    //        // cout << "Arsalan";
    //         // Continue with further code here
    //        cout << setw(45) << right << "    || INSERTION SORT                              | QUICK SORT                                 ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
    //        cout << "    ||" << duration_insertion.count() << " nanosecond" << "                               |   " << duration_QUICK.count() << " nanoseconds                   || " << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                      Adaptability:                                       ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||It is adaptive, meaning its performance is   |It is not as adaptive as insertion sort,    ||" << endl;
    //        cout << setw(45) << right << "    ||better when the input array is partially     |as its performance doesn't necessarily      ||" << endl;
    //        cout << setw(45) << right << "    ||sorted.                                      |improve with partially sorted input.        ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                       Space Complexity:                                  ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||It is an in-place sorting algorithm, meaning |It is also an in-place sorting algorithm,   ||" << endl;
    //        cout << setw(45) << right << "    ||it doesn't require additional memory beyond  |but it requires a small amount of           ||" << endl;
    //        cout << setw(45) << right << "    ||the original array.                          |additional memory for the recursive call    ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |stack.                                      ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


    //    }
    //    else {
    //        // Stop execution if the user clicks "Cancel" or closes the message box
    //        //main();
    //        system("pause");
    //    }

    //}
    //else if (opt1 == 4 && opt2 == 2)
    //{
    //    printHeader("SELECTION SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(arr, n);
    //    auto start_sec = std::chrono::high_resolution_clock::now();
    //    selection_sort(arr, n);
    //    auto stop_sec = std::chrono::high_resolution_clock::now();
    //    auto duration_selection = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_sec - start_sec);
    //    cout << "time taken " << duration_selection.count() << endl;
    //    //quick sort
    //    printHeader("QUICK SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(a, n);
    //    cout << "[ ]=pivot\n";
    //    cout << "\n             SORTING IS DONE FIRST ON THE LEFT SIDE OF THE PIVOT  THEN THE RIGHT SIDE IF NEEDED!\n\n";

    //    display(a, n);
    //    auto startQ = std::chrono::high_resolution_clock::now();

    //    quicksort(a, 0, n - 1);
    //    cout << "\nARRAY AFTER SORTING:  ";
    //    displayArray(a, n, 0);
    //    auto stopQ = std::chrono::high_resolution_clock::now();
    //    auto duration_QUICK = std::chrono::duration_cast<std::chrono::nanoseconds>(stopQ - startQ);
    //    cout << "time taken " << duration_QUICK.count() << " nanoseconds." << endl;


    //    int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

    //    if (result == IDOK) {
    //        // cout << "Arsalan";
    //         // Continue with further code here
    //        cout << setw(45) << right << "    || SELECTION SORT                              | QUICK SORT                                 ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
    //        cout << "    ||" << duration_selection.count() << " nanosecond" << "                        |   " << duration_QUICK.count() << " nanoseconds                   || " << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                      Adaptability:                                       ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||It is often used for educational purposes    |It is suitable for large datasets and is    ||" << endl;
    //        cout << setw(45) << right << "    ||due to its simplicity. It is not the most    |commonly used in practice.                  ||" << endl;
    //        cout << setw(45) << right << "    ||efficient choice for large datasets or       |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||real-world applications.                     |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                       Space Complexity:                                  ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||It is an in-place sorting algorithm, meaning |It is also an in-place sorting algorithm,   ||" << endl;
    //        cout << setw(45) << right << "    ||it doesn't require additional memory beyond  |but it requires a small amount of           ||" << endl;
    //        cout << setw(45) << right << "    ||the original array.                          |additional memory for the recursive call    ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |stack.                                      ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


    //    }
    //    else {
    //        // Stop execution if the user clicks "Cancel" or closes the message box
    //        //main();
    //        system("pause");
    //    }

    //}
    //else if (opt1 == 4 && opt2 == 3)
    //{

    //    printHeader("MERGE SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(arr, n);
    //    cout << "[ ]=mid\n";
    //    auto startM = std::chrono::high_resolution_clock::now();
    //    mergesort(arr, 0, n - 1);
    //    auto stopM = std::chrono::high_resolution_clock::now();


    //    cout << "\nARRAY AFTER SORTING:  ";
    //    displayArray(arr, n, 0);
    //    auto duration_MERGE = std::chrono::duration_cast<std::chrono::nanoseconds>(stopM - startM);
    //    cout << "time taken " << duration_MERGE.count() << " nanoseconds." << endl;
    //    //quick sort
    //    printHeader("QUICK SORT");
    //    cout << "ARRAY FOR SORTING      ";
    //    display(a, n);
    //    cout << "[ ]=pivot\n";
    //    cout << "\n             SORTING IS DONE FIRST ON THE LEFT SIDE OF THE PIVOT  THEN THE RIGHT SIDE IF NEEDED!\n\n";

    //    display(a, n);
    //    auto startQ = std::chrono::high_resolution_clock::now();

    //    quicksort(arr, 0, n - 1);
    //    cout << "\nARRAY AFTER SORTING:  ";
    //    displayArray(a, n, 0);
    //    auto stopQ = std::chrono::high_resolution_clock::now();
    //    auto duration_QUICK = std::chrono::duration_cast<std::chrono::nanoseconds>(stopQ - startQ);
    //    cout << "time taken " << duration_QUICK.count() << " nanoseconds." << endl;



    //    int result = MessageBox(NULL, L"DO YOU WANT A COMPARISON IN THEORY?", L"Heading", MB_OKCANCEL);

    //    if (result == IDOK) {
    //        // cout << "Arsalan";
    //         // Continue with further code here
    //        cout << setw(45) << right << "    || QUICK SORT                                  | MERGE SORT                                 ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;
    //        cout << "    ||" << duration_QUICK.count() << " nanosecond" << "                        |   " << duration_MERGE.count() << " nanoseconds                   || " << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                       Space Complexity                                   ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||Yes, quicksort is an in-place sorting        |No, merge sort is not an in-place sorting   ||" << endl;
    //        cout << setw(45) << right << "    ||algorithm. However, it requires a small      |algorithm. It requires additional memory    ||" << endl;
    //        cout << setw(45) << right << "    ||amount of additional memory for the          |for the merging process, making its space   ||" << endl;
    //        cout << setw(45) << right << "    ||recursive call stack.                        |complexity O(n).                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                         Adaptability:                                    ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||It's an in-place sorting algorithm, utilizing|Merge sort's performance is consistent      ||" << endl;
    //        cout << setw(45) << right << "    ||a constant amount of extra memory for        |regardless of the initial order of the      ||" << endl;
    //        cout << setw(45) << right << "    ||variables, without requiring additional space|elements.                                   ||" << endl;
    //        cout << setw(45) << right << "    ||proportional to the input size.              |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||                                             |                                            ||" << endl;
    //        cout << setw(45) << right << "    ||------------------------------------------------------------------------------------------||" << endl;


    //    }
    //    else {
    //        // Stop execution if the user clicks "Cancel" or closes the message box
    //        //main();
    //        system("pause");
    //    }
    //}


}

void option3() {
    int choice;
    cout << "Which one you want to see?\n1.insert\n2.selection\n3.merge\n4.quick\n";
    cin >> choice;
    string line;

    switch (choice)
    {
    case 1:
    {
        ifstream inputFile("insertion_sort.txt");


        // Check if the file is open
        if (!inputFile.is_open()) {
            cerr << "Error opening the file for reading!" << endl;
            return;
        }
        const char* fileName = "insertion_sort.txt";

        // Use the system command to open the file with the default program
        std::system(("start " + std::string(fileName)).c_str());
        // Close the file
        inputFile.close();

        break;
    }
    case 2:
    {
        ifstream inputFile("selection_sort.txt");


        // Check if the file is open
        if (!inputFile.is_open()) {
            cerr << "Error opening the file for reading!" << endl;
            return;
        }

        const char* fileName = "selection_sort.txt";

        // Use the system command to open the file with the default program
        std::system(("start " + std::string(fileName)).c_str());

        // Close the file
        inputFile.close();

        break;
    }
    case 3:
    {
        ifstream inputFile("merge_sort.txt");


        // Check if the file is open
        if (!inputFile.is_open()) {
            cerr << "Error opening the file for reading!" << endl;
            return;
        }

        const char* fileName = "merge_sort.txt";

        // Use the system command to open the file with the default program
        std::system(("start " + std::string(fileName)).c_str());


        // Close the file
        inputFile.close();

        break;
    }
    case 4:
    {
        ifstream inputFile("quick_sort.txt");


        // Check if the file is open
        if (!inputFile.is_open()) {
            cerr << "Error opening the file for reading!" << endl;
            return;
        }

        const char* fileName = "quick_sort.txt";

        // Use the system command to open the file with the default program
        std::system(("start " + std::string(fileName)).c_str());

        // Close the file
        inputFile.close();

        break;
    }
    }
}
int main()
{
    int option;
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(0)));

    const int arraySize = 500;
    int randomNumbers[arraySize];

    // Generate random numbers between -250 and 250 and store them in the array
    for (int i = 0; i < arraySize; ++i) {
        randomNumbers[i] = rand() % 501 - 250;
    }

    // Open a file for writing
    ofstream outputFile("random_numbers.txt");

    // Check if the file is open
    if (!outputFile.is_open()) {
        cerr << "Error opening the file for writing!" << endl;
        return 1;
    }

    // Write the generated random numbers to the file
    for (int i = 0; i < arraySize; ++i) {
        outputFile << randomNumbers[i] << " ";
    }

    // Close the file
    outputFile.close();

    //  cout << "Random Numbers (-250 to 250) written to random_numbers.txt." << endl;

    printHeader("SORTING SIMULATOR");
    printFooter("by Ateeb Azam, Arsalan, Qasim");
    int n;

    cout << "How many numbers would you want to store in an array from the file: ";
    cin >> n;
    int* arr = new int[n];
    // Open the file for reading
    ifstream inputFile("random_numbers.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        cerr << "Error opening the file for reading!" << endl;
        return 1;
    }

    // Read the random numbers from the file and store them back into the array
   // cout << "Reading random numbers from the file: ";
    for (int i = 0; i < n; ++i) {
        inputFile >> arr[i];
        cout << arr[i] << " ";
    }

    // Close the file
    inputFile.close();
    cout << endl;

    printOptions();

    cout << "Enter your option: ";
    cin >> option;

    switch (option)
    {
    case 1:
        // Code for Single Sorting
        option1(arr, n);
        break;
    case 2:
        system("cls");
        option2(arr, n, arr);
        break;
    case 3:
        // Code for History
        system("cls");
        printHeader("SORTING SIMULATOR");
        printFooter("by Ateeb Azam, Arsalan, Qasim");
        option3();
        break;

    case 4:
        cout << "Exiting...";
        waitForKeyPress();
        return 0;
    default:
        cout << "Invalid option!";
        waitForKeyPress();
    }
    system("pause");
    system("cls");
    main();

    return 0;
}