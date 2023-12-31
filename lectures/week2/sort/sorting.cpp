#include <bits/stdc++.h>
using namespace std;
struct Item {
    int key;
    int value;
    string name;
};
void swap(Item &a, Item &b);
//comparator
bool cmpLess(Item a, Item b);
bool cmpGreater(Item a, Item b);
//sorting algorithms
void selectionSort(Item *a, int l, int r);
void bubbleSort(Item *a, int l, int r);
void insertionSort(Item *a, int l, int r);
void shellSort(Item *a, int l, int r);
void mergeSort(Item *a, int l, int r);
static void merge(Item items[], int lo, int mid, int hi);
int main () {
    freopen("input.txt", "r", stdin);   
    char choice;
    cin >> choice;
    int n;
    cin >> n;
    Item *items = new Item[n];
    for (int i = 0; i < n; i++) {
        cin >> items[i].key >> items[i].value >> items[i].name;
    }
    switch(choice) {
        case 's': selectionSort(items, 0, n - 1);          break;
		case 'b': bubbleSort(items, 0, n - 1);             break;
		case 'i': insertionSort(items, 0, n - 1);          break;
		case 'h': shellSort(items, 0, n - 1);              break;
		case 'm': mergeSort(items, 0, n - 1);              break;
		// case 'N': naiveQuickSort(items, 0, n - 1);         break;
		// case 'M': medianOfThreeQuickSort(items, 0, n - 1); break;
		// case 'R':
		// 	srand(time(NULL));
		// 	randomisedQuickSort(items, 0, n - 1);
		// 	break;

		default:
			fprintf(stderr, "Invalid sorting method\n");
			exit(1);
			break;
    }
    for (int i = 0; i < n; i++) {
        cout << items[i].key << " " << items[i].value << " " << items[i].name << endl;
    }
}
void swap(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;

}
//comparator
bool cmpLess(Item a, Item b) {
    return a.key < b.key;
}
bool cmpGreater(Item a, Item b) {
    return a.key > b.key;
}
//sorting algorithms
void selectionSort(Item *a, int l, int r) {
    for (int i = l; i < r; i++) {
        int minIndex = i;
        for (int j = i + 1; j <= r; j++) {
            if (cmpLess(a[j], a[minIndex])) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
    //time complexity
    /*
    cost:
    first iteration: n-1 comparisons, 1 swap
    second iteration: n-2 comparisons, 1 swap
    ...
    last iteration: 1 comparison, 1 swap
    total: C(number of comparisons)= (n-1) + (n-2) + ... + 1 = n(n-1)/2 = O(n^2)
            s(number of swaps) = n-1 
    */
    //cost is the same, regardless of sortedness of the original array

    /*
    properties:
    -unstable(due to long-range swaps)
    -non-adaptive: performs same steps, regardless of sortedness of original array
    -in-place: sorting is done within original array; does not use temporary arrays
    */
}
void bubbleSort(Item *a, int l, int r) {
    for (int i = r; i > l; i--) {
        bool swapped = false;
        for (int j = l; j < i; j++) {
            if (cmpGreater(a[j], a[j + 1])) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        
        }
        if (!swapped) {
            break;
        }
    }
    //time complexity
    /*
    best case: array is sorted
    -only a single pass is required
    - n- 1 operations, no swaps
    - O(n) time complexity
    */

    /*
    worst case: array is reverse sorted
    -n-1 passes are required
        + first pass: n-1 comparisons, 1 swap
        + second pass: n-2 comparisons, 1 swap
        + ...
        + last pass: 1 comparison, 1 swap
    -n-1 + n-2 + ... + 1 = n(n-1)/2 = O(n^2)
    */

    /*
    properties:
    -stable: comparisons are between adjacent elements only. Elements are only swapped if out of order
    -adaptive: O(n^2) on average, O(n) if input array is sorted
    -in-place: sorting is done within original array; does not use temporary arrays
    */
}
void insertionSort(Item *a, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        Item temp = a[i];
        int j = i;
        for (/* j */; j > l; j--) {
            if (!cmpLess(temp, a[j - 1])) {
                break;
            }
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
    /*
    best case: array is sorted
    -inserting each elements requires one comparision
    - n-1 comparisons
    -best-case time complexity: O(n)
    */

    /*
    worst case:Array is reverse sorted
    -inserting each element requires i comparisons
    - 1 + 2 + ... + n-1 = n(n-1)/2 = O(n^2)
    worst-case time complexity: O(n^2)
    

    */
    //average-case time complexity: O(n^2)

    /*
    properties
    -stable:elements are always inserted to the right of any equal elements
    -adaptive: O(n^2 on average, O(n) if input array is sorted
    -in-place: sorting is done within original array; does not use temporary arrays
    */
}
void shellSort(Item *a, int l, int r) {
    int size = r - l + 1;
    int h;
    for (h = 1; h <= (size - 1) / 9; h = (3 * h) + 1);
    for (; h > 0; h /= 3) {
        for (int i = l + h; i <= r; i++) {
            Item temp = a[i];
            int j = i;
            for (; j >= l + h; j -= h) {
                if (!cmpLess(temp, a[j - h])) {
                    break;
                }
                a[j] = a[j - h];
            }
            a[j] = temp;
        }
    }
    /*
    efficiency depends on the h-sequence

    */

    /*
    properties;
    -unstable: long-range swaps
    -adaptive: shell sort applies a generalisation of insertion sort(which is adaptive)
    -in-place: sorting is done within original array; does not use temporary arrays
    */
}
void mergeSort(Item *a, int l, int r) {
    //divide-and-conquer sorting algorithm

    //time complexity of splitting the array is O(1)-we calculate the midpoint of the array
    /*
    time complexity of merging two sorted subarrays is O(n), where n is the total number of elements in both subarrays
    therefore:
        -merging two subarrays of size 1 takes 2 steps
        -merging two subarrays of size 2 takes 4 steps

        -merging two subarrays of size n/2 takes n steps
    */
    if (l >= r) {
        return ;
    }
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    //merge two sorted subarrays
    merge(a, l, mid, r);

    /*
    split: n-1 splits (log2N levels of splitting)- O(n)
    merge: we have to merge n numbers exactly log2N times- O(nlogn)
    */

    /*
    analysis: merge sort splits array into equal-sized partitions halving at each level=> log2N levels
    -at each level requires <= N comparisons
    -therefore, time complexity is O(nlogn):for every case
    
    */

    /*
    properties: 
    -stable: due to taking from left subarray if items are equal during merge
    -non-adaptive: merge sort performs the same steps regardless of sortedness of original array, O(nlogn) on average
    -not in-place: merge sort requires a temporary array of size n, merge sort also uses O(logn) stack space for recursion
    
    */

}
static void merge(Item items[], int lo, int mid, int hi)
{
	Item *tmp = malloc((hi - lo + 1) * sizeof(Item));

	int i = lo;
	int j = mid + 1;
	int k = 0;

	// Scan both segments, copying to `tmp'.
	while (i <= mid && j <= hi) {
		if (le(items[i], items[j])) {
			tmp[k++] = items[i++];
		} else {
			tmp[k++] = items[j++];
		}
	}

	// Copy items from unfinished segment.
	while (i <= mid) tmp[k++] = items[i++];
	while (j <= hi) tmp[k++] = items[j++];

	// Copy `tmp' back to main array.
	for (i = lo, k = 0; i <= hi; i++, k++) {
		items[i] = tmp[k];
	}

	free(tmp);
}