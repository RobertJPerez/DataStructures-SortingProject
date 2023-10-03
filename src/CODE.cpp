/* Luke Fanizzi, Angelina Gargiulo
 * TA : Lauren Olson
 * 5/20/2020
 * This file contains functions that are in the sorting mini lab. These functions use 6 different sorting
 * techniques and their running times were calculated and compared in order to determine
 * the efficiency of each.
 */

#include <iostream>
#include <math.h>
using namespace std;
#include <iostream>
#include <cstdlib>
#include <time.h>

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main (void);
int *makeArr(int size);
void printArray(int arr[], int size);
void selectionSort(int arr[], int len, int loops);
void quickSort(int arr[], int beg, int end);
void merge(int arr[], int le, int m, int r);
void mergeSort(int arr[], int l1, int l2);
void insertionSort(int arr[], int length);
void minMaxSelectionSort(int arr[], int len, int loops);
void insertionSort2(int arr[], int start, int end);
void timSort(int arr[], int start, int end);

int size = 100;
int size2 = 10000;

int main(void) {
	float times = 0;
	int size = 100;
	int size2 = 10000; //intialize variables used

	cout<<"**************PART A**************"<<endl; // Responsible for printing sorting functions
	cout<<"Printing SelectionSort"<<endl;  // runs and prints selectionSort 5 times
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size);
	    selectionSort(arr,size,size-1);
	    printArray(arr,size);
	    delete(arr);
	}
	cout<<"Printing insertionSort"<<endl;// runs and prints insertionSort 5 times
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size);
		insertionSort(arr,size);
		printArray(arr,size);
		delete(arr);
	}
	cout<<"Printing quickSort"<<endl;// runs and prints quickSort 5 times
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size);
		quickSort(arr,0,size-1);
		printArray(arr,size);
		delete(arr);
	}
	cout<<"Printing mergeSort"<<endl; // runs and prints mergeSort 5 times
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size);
		mergeSort(arr,0,size-1);
		printArray(arr,size);
		delete(arr);
	}

	cout<< endl << "*************PART B*******************"<<endl;
	cout<<"Printing SelectionSort run times:"<<endl; //runs and times selectionSort 5 times and
	times = 0;										//calculates the average running time
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size2);
		auto start = high_resolution_clock::now();
	    selectionSort(arr,size2,size2-1);
	    auto stop = high_resolution_clock::now();
	    auto duration = duration_cast<microseconds>(stop - start);
	    times += duration.count();
	    delete(arr);
	    cout << "Time for selectionSort is: " << duration.count()<< endl;
	}
	cout << "Average time for selectionSort is: "<< times/5<< endl;
	cout << endl;
	cout << "Printing insertionSort run times:" << endl;//runs and times insertionSort 5 times and
	times = 0;											//calculates the average running time
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size2);
		auto start = high_resolution_clock::now();
		insertionSort(arr,size2);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		times += duration.count();
		delete(arr);
		cout << "Time for insertionSort is: " << duration.count()<< endl;
	}
	cout << "Average time for insertionSort is: " << times/5<< endl;
	cout << endl;
	cout << "Printing quickSort run times" << endl; //runs and times quickSort 5 times and
	times = 0;										//calculates the average running time
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size2);
		auto start = high_resolution_clock::now();
		quickSort(arr,0,size2-1);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		times += duration.count();
		delete(arr);
		cout << "Time for quickSort is: " << duration.count()<< endl;
	}
	cout << "Average time for quickSort is: " << times/5<< endl;
	cout << endl;
	cout<<"Printing mergeSort run times"<<endl;//runs and times mergeSort 5 times and
	times = 0;									//calculates the average running time
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size2);
		auto start = high_resolution_clock::now();
	    mergeSort(arr,0,size2-1);
	    auto stop = high_resolution_clock::now();
	    auto duration = duration_cast<microseconds>(stop - start);
	    times += duration.count();
	    delete(arr);
	    cout << "Time for mergeSort is: " << duration.count()<< endl;
	}
	cout << "Average time for mergeSort is: " << times/5<< endl;

	cout << endl<< "*************PART C*******************"<< endl;//tests timSort and minMaxSelectionSort
	cout << "Printing minMaxSelectionSort" << endl;//runs and prints minMaxselectionSort 5 times
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size);
	    minMaxSelectionSort(arr,size,size-1);
	    printArray(arr,size);
	    delete(arr);
	}
	cout << endl;
	cout<<"Printing timSort"<<endl;  //runs and prints timSort
	for(int i = 0; i<5; i++){
		int *arr = makeArr(1000);
		timSort(arr,0,1000-1);
		printArray(arr,size2);
		delete(arr);
//																	}
		cout << endl;

	cout << "Printing minMaxSelectionSort run times" << endl; //runs minMaxSelectionSort 5 times and times and
	times = 0;										//calculates the average running time
	for(int i = 0; i<5; i++){
		int *arr = makeArr(size2);
		auto start = high_resolution_clock::now();
		minMaxSelectionSort(arr,size2,size2-1);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		times += duration.count();
		delete(arr);
		cout << "Time for minMaxSelectionSort is: " << duration.count()<< endl;
	}
	cout << "Average time for minMaxSelectionSort is: " << times/5<< endl;
	cout << endl;

	cout << "Printing timSort run times" << endl; //runs minMaxSelectionSort 5 times and times and
	times = 0;									////calculates the average running time
	for(int i = 0; i<5; i++){
	int *arr = makeArr(size2);
	auto start = high_resolution_clock::now();
	timSort(arr,0,size2-1);
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
	times += duration.count();
	delete(arr);
	cout << "Time for timSort is: " << duration.count()<< endl;
	}
	cout << "Average time for timSort is: " << times/5<< endl;

	return 0;
}
}
/*
 This function takes in an integer, size, and creates and returns a pointer to that newly created array.
 This array has all psuedo - random numbers.
 */
int *makeArr(int size){
	int *Arr = new int[size]; //creates new array
	for(int i = 0; i <= size - 1; i++){ //increments through empty array
		Arr[i] = rand()%10000; //fills in array with randomized numbers
	}
	return Arr; //returns the array
}
/*
 This function takes in an integer array and an integer, size, and prints the array. This function
 returns nothing.
 */
void printArray(int arr[], int size){
    cout << "{";
    for(int i = 0;i<=size-1 ;i++){
        cout << arr[i];
        if (i<size-2){
            cout << ",";
        }
    }
    cout << "}" << endl;
}

/* This function represents the selection sort. It takes in
 * 3 parameters, the array of integers, the length of that
 * array and the number of loops. It doesn't return anything.
 */
void selectionSort(int arr[], int len, int loops) {
	for(int i=0; i<=loops; i++){ //for as long as "i" is not greater than the number of loops
        int m = i; //set an integer to the value of "i"
        for(int j=i+1; j<len; j++){ //for as long as "j" is less than the length...
            if(arr[j]<arr[m]){ //if the index of array[j] is less than that of array[m]...
                m = j; //set "m" equal to "j"
            }
        }
        int tmp = arr[m]; //set a temporary integer to array[m]
        arr[m] = arr[i]; //set array[m] to array[i]
        arr[i] = tmp; //set array[i] to the temporary integer
    }
}

/* This function represents the partition of the array into
 * smaller groups that make sorting easier. It takes in 3
 * parameters, the integer that represents the start of the
 * array and one that represents the end, and of course the array.
 * It returns an integer value that represents the new end.
 */
int partition(int beg, int end, int arr[]){
    int x = beg; //set the beginning of the array to an integer
    int y = end; //set the ending of the array to an integer
    int temp; //initialize a temporary variable
    int j = arr[x]; //set an integer to array[x]
    x++; //increment "x" by 1
    while(x<=y){ //while the beginning of the array is less than the end...
        while(arr[x]<j){ //while array[x] is less than "j"...
            x++; //increment "x" by 1
        }
        while(arr[y]>j){ //while array[y] is greater than "j"...
            y--; //decrement "y" by 1
        }
        if(x<=y){ //if the beginning of the array is less than or equal to the end...
            temp = arr[x]; //set a temporary variable to array[x]
            arr[x] = arr[y]; //set array[x] to array[y]
            arr[y] = temp; //set the array[y] to the temporary variable
            x++; //increment "x" by 1
            y--; //decrement "y" by 1
        }
    }
    arr[beg] = arr[y]; //set the beginning of the array to array[y]
    arr[y] = j; //set array[y] to array[x]
    return y; //return the value of "y"
}

/* This function represents a quick sort. It takes in 3 parameters,
 * the integer array, the beginning of the array, and the end
 * of it. It doesn't return any value.
 */
void quickSort(int arr[], int beg, int end){
    int m = partition(beg, end, arr); //set a variable to the result of the partition function
    if(m-1>beg){ //if that variable minus 1 is less than the beginning of the array...
        quickSort(arr,beg,m-1); //quick sort the variable minus 1
    }
    if(m+1<end){ //if that variable plus 1 is greater than the end of the array...
        quickSort(arr,m+1,end); //quick sort the variable plus 1
    }
}

/* This function represents a merge. It takes in four parameters
 * and returns a void value. It conducts the merging used in
 * merge sorting.
 */
void merge(int arr[], int le, int m, int r){
    int i, j, k; //initialize 3 integers
    int lenL = m - le + 1; //set the length of the right
    int lenR = r - m; //set the length of the right
    int leftArr[lenL]; //initialize left array[left length]
    int rightArr[lenR]; //initialize right array[right length]
    for(i=0; i<lenL; i++){ //for as long as "i" is less than the left length...
    	leftArr[i] = arr[le + i]; //set left array[i]
    }
    for(j = 0; j<lenR; j++){ //for as long as "j" is less than the right length...
    	rightArr[j] = arr[m + 1 + j]; //set right array[j]
    }
    i = 0; //set "i" to 0
    j = 0; //set "j" to 0
    k = le; //set "k" to the length of the array
    while (i < lenL && j < lenR){ //while "i" is less than left length and "j" is less than right length...
        if (leftArr[i] <= rightArr[j]){ //if left array[i] is less than or equal to right array[j]...
            arr[k] = leftArr[i]; //set array[k] accordingly
            i++; //increment "i" by 1
        } else { //if any other scenario...
            arr[k] = rightArr[j]; //set array[k] accordingly
            j++; //increment "j" by 1
        }
        k++; //increment "k" by 1
    }
    while (i < lenL){ //while "i" is less than the left length
        arr[k] = leftArr[i]; //set array[k] accordingly
        k++; //increment "k" by 1
        i++; //increment "i" by 1
    }
    while (j < lenR){ //while "j" is less than the right length...
        arr[k] = rightArr[j]; //set array[k] accordingly
        k++; //increment "k" by 1
        j++; //increment "j" by 1
    }
}

/* This function represents the merge sort. It overall conducts
 * the merge sorting and calls the helper function "merge".
 * It takes in 3 parameters, two lengths and the array. It returns
 * no value.
 */
void mergeSort(int arr[], int l1, int l2) {
    int k; //initialize an integer variable
    if (l1 < l2){ //if length1 is less than length2
        k=(l1+l2)/2; //set "k" to the average of the lengths
        mergeSort(arr,l1,k); //recursively call the function on length1
        mergeSort(arr,k+1,l2); //recursively call the function on length2
        merge(arr,l1,k,l2); //call merge function on two lengths
    }

}

/* This function conducts the insertion sort. It takes in only
 * two parameters, the integer array and the length of the array.
 * It returns a void.
 */
void insertionSort(int arr[], int length){
	int j = 0; //initialize a variable "j"
	int temp = arr[0]; //set a temporary variable to array[0]
    for(int i=1; i<length; i++){ //for as long as "i" is less than the length...
        j = i; //set "j" to "i"
        temp = arr[j]; //set the temporary variable to array[j]
        j--; //decrement "j" by 1
        while(j>= 0 && temp < arr[j]){ //while "j" is greater than or equal to 0 and "temp" < array[j]...
        	arr[j+1] = arr[j]; //set array[j+1] to array[j]
        	j--; //decrement "j" by 1
        }
        arr[j+1] = temp; //set array[j+1] to the temporary variable
    }
    return; //return nothing
}
/*
 This function takes in an integer array and two integers, len and loops. It returns nothing.
 This function implements a different style of sorting using min and max values and is used
 in this lab to compare run time efficiency.
 */
void minMaxSelectionSort(int arr[], int len, int loops) {
	// intializations
	int leftbound = 0; //leftbound is zero
	int rightbound = len - 1; //rightbound is the last index in the array
	 int min = 0; // min and max start at zero
     int max = 0;
     int bound;
     while(leftbound < rightbound){ //checks left bound is smaller than rightbound
    	  min = leftbound; //sets min to leftbound
    	  max = rightbound; //sets max to rightbound

	        for(int j=leftbound; j<=rightbound; j++){//increments from leftbound to rightbound
	            if(arr[j]<arr[min]){ //checks for smaller number
	                min = j; //sets new min

	            }
	            if(arr[j]>arr[max]){ //checks for bigger number
	            	max = j;//sets new max
	            }
	        }

	        if(max == leftbound){//special case if max is the leftbound

	        	bound = arr[rightbound]; //stores value at rightbound
	        	arr[rightbound] = arr[max]; //sets value at rightbound as the value at max
	            arr[max]= bound; //sets the value of max as the stored value of rightbound

	            bound = arr[min];  // stores value at min
	            arr[min] = arr[leftbound]; // sets value at min to value at leftbound
	            arr[leftbound] =  bound; // sets value at leftbound to the value at min
	        }
	        else if(min == rightbound){ // checks special case where min is the rightbound
	        	bound = arr[min]; // stores value at min
	        	arr[min] = arr[leftbound];//sets value  at min to value at leftbound
	        	arr[leftbound] =  bound; //sets value at leftbound to value at min

	        	bound = arr[rightbound]; //stores value at rightbound
	        	arr[rightbound] = arr[max];// sets value at rightbound to value at max
	        	arr[max]= bound; //sets value at max to value at rightbound
	        }

	        else{
				int tmp = arr[min]; //stores value at min
				arr[min] = arr[leftbound]; //sets value at min to value at leftbound
				arr[leftbound] = tmp; //sets value at leftbound to value at min

				int tmp2 = arr[max];//stores value at min
				arr[max] = arr[rightbound];//sets value at max to value at rightbound
				arr[rightbound] = tmp2; //sets value at rightbound to value at max
	        }
        leftbound = leftbound +1; //moves leftbound up 1
        rightbound = rightbound - 1; //moves rightbound down 1
	    }
}
/*
 This function takes in an integer array and two integers, beg and length. This function is a variation
 of insertion sort that is used as a helper function to timSort and returns nothing.
 */
void insertionSort2(int arr[], int beg, int length){
	int j = beg; //inititalizes j as beg (0, often, the beginning of the array)
		int temp = arr[beg]; //stores value at beg
	    for(int i=beg+ 1; i<=length; i++){ // increments through the array
	        j = i; //sets j to i
	        temp = arr[j]; //stores value at j
	        j--; //decrements j
	        while(j>=beg && temp < arr[j]){ //checks if j is greater than beg and that the stored value is less than the value at j.
	        	arr[j+1] = arr[j];// sets the next space value to the value at j
	        	j--; //decrements j
	        }

	        arr[j+1] = temp; //sets value at the next space to the value stored from j
	    }

	}
/*
 This function takes in an integer array, and two ints, start and end. This function uses the 6th
 and final technique of sorting and returns nothing.
 */
void timSort(int arr[], int start, int end){
	int upperbound  = end;// starts upper bound at the end
	int lowerbound = start; //starts lowerbound at the beginning
	int tmp = arr[(lowerbound+upperbound)/2]; //sets tmp to the value at the middle of the array
	while(lowerbound <= upperbound){ //while the lower bound is less than or equal to thye upperbound...
		while(arr[upperbound]>tmp){ // while the value at the upperbound is greater than the stored value
					upperbound= upperbound - 1; //lower the upperbound by 1
				}
		while(arr[lowerbound]<tmp){ //checks if lowerbound value is less than the stored value
			lowerbound = lowerbound +1; //raises the lower bound by 1
		}
		if(lowerbound < upperbound+1){ // checks if the lowerbound is less than or equal to the upperbound
			tmp = arr[lowerbound]; //stores value at the lowerbound
			arr[lowerbound] = arr[upperbound]; //sets value at lower bound to value at upperbound
			arr[upperbound] = tmp; // sets value at upperbound to value at lowerbound
			upperbound= upperbound - 1; // lowers upperbound by 1
			lowerbound = lowerbound +1; //raises lowerbound by 1
		}
	}
	if(lowerbound < end){ //checks if lowerbound index is less than the end of the array
			if(end - lowerbound >size){ // checks if the difference is greater than size(100)
				timSort(arr, lowerbound, end); //calls timSort again with updated parameters
			}
			else if(end - lowerbound < size){ // checks if the difference is less than size(100)
				insertionSort2(arr,lowerbound,end); // calls insertionSort2 on function with new parameters
			}
		}
	if(upperbound > start){// checks if the upperbound is greater than the start
			if(upperbound - start >size){ // checks if the difference is greater than size(100)
				timSort(arr, start, upperbound); //calls timSort again with updated parameters
			}
			else if(upperbound-start<size){// checks if the difference is less than size(100)
				insertionSort2(arr,start,upperbound);// calls insertionSort2 on function with new parameters
			}
		}


}



















