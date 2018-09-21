
/*
 * SortImpls.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Yuun
 */

#ifndef SRC_SORTIMPLS_H_
#define SRC_SORTIMPLS_H_
#include <vector>
#include <iostream>

using namespace std;

void BubbleSort(vector<int> &array, int start, int end);
void InsertionSort(vector<int> &array, int start, int end);
void MergeSort(vector<int> &array, int start, int end);
void IterativeMergeSort(vector<int> &array, int start, int end);
void QuickSort(vector<int> &array, int start, int end);
void ShellSort(vector<int> &array, int start, int end);

void Merge(vector<int> &array, int first, int mid, int last);
void Swap(int &value1, int &value2);


void BubbleSort(vector<int> &array, int start, int end)
{
    bool sorted = false;
    int pass = 1;
    int size = end - start + 1;
    while (!sorted && (pass < size))
    {
        sorted = true;
        for (int index = 0; index < (size - pass); index++)
        {
            int nextIndex = index + 1;
            if (array[index] > array[nextIndex])
            {
                Swap(array[index], array[nextIndex]);
                sorted = false;
            }
        }
        pass++;
    }
}

void InsertionSort(vector<int>& array, int start, int end)
{
    int size = end - start + 1;
    for (int unsorted = start + 1; unsorted < end + 1; unsorted++)
    {
        int nextInt = array[unsorted];
        int index = unsorted - 1;
        while ((index >= start) && (array[index] > nextInt))
        {
            array[index + 1] = array[index];
            index--;
        }

        array[index + 1] = nextInt;
    }
}



void MergeSort(vector<int>& array, int first, int last)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2;
        MergeSort(array, first, mid);
        MergeSort(array, mid + 1, last);
        Merge(array, first, mid, last);
    }
}

void IterativeMergeSort(vector<int>& array, int start, int last)
{
    int size = last - start + 1;
    for (int i = 1; i < size; i = 2 * i)
    {
        for (int j = start; j < size - i; j += 2 * i)
        {
            int low = j;
            int mid = j + i - 1;
            int high;
            if (j + 2 * i - 1 < size - 1)
            {
                high = j + 2 * i - 1;
            }
            else
            {
                high = size - 1;
            }
            Merge(array, low, mid, high);
        }
    }
}

void QuickSort(vector<int>& list, int firstIndex, int lastIndex)
{
    if (lastIndex - firstIndex < 10)
    {
        InsertionSort(list, firstIndex, lastIndex);
        return;
    }
    
    int midIndex = ((lastIndex - firstIndex) / 2) + firstIndex;
    if (list[firstIndex] > list[lastIndex])
    {
        Swap(list[firstIndex], list[lastIndex]);
    }
    
    if (list[firstIndex] > list[midIndex])
    {
        Swap(list[firstIndex], list[midIndex]);
    }
    
    if (list[midIndex] > list[lastIndex])
    {
        Swap(list[midIndex], list[lastIndex]);
    }
    
    int pivot = list[midIndex];
    Swap(list[midIndex], list[lastIndex - 1]);
    int leftIndex = firstIndex + 1;
    int rightIndex = lastIndex - 2;
    bool done = false;
    
    while (!done)
    {
        while (list[leftIndex] < pivot)
        {
            leftIndex++;
        }
        
        while (list[rightIndex] > pivot)
        {
            rightIndex--;
        }
        
        if (rightIndex > leftIndex)
        {
            Swap(list[leftIndex], list[rightIndex]);
            rightIndex--;
            leftIndex++;
        }
        else
        {
            done = true;
        }
    }
    
    Swap(list[leftIndex], list[lastIndex - 1]);
    QuickSort(list, firstIndex, leftIndex - 1);
    QuickSort(list, leftIndex + 1, lastIndex);
//    if (last - first < 10)
//    {
//        InsertionSort(array, first, last);
//        return;
//    }
//    int mid = (last + first) / 2;
//    if (array[first] > array[last])
//    {
//        Swap(array[first], array[last]);
//    }
//    if (array[first] > array[mid])
//    {
//        Swap(array[first], array[mid]);
//    }
//    if (array[mid] > array[last])
//    {
//        Swap(array[mid], array[last]);
//    }
//    int pivot = array[mid];
//    Swap(array[mid], array[last - 1]);
//    int indexFromLeft = first + 1;
//    int indexFromRight = last - 2;
//    bool done = false;
//    while (!done)
//    {
//        while (array[indexFromLeft] < pivot)
//        {
//            indexFromLeft++;
//        }
//
//        while (array[indexFromRight] > pivot)
//        {
//            indexFromRight--;
//        }
//        if (indexFromLeft < indexFromRight)
//        {
//            Swap(array[indexFromLeft], array[indexFromRight]);
//            indexFromLeft++;
//            indexFromRight--;
//        }
//        else
//        {
//            done = true;
//        }
//
//    }
//    Swap(array[indexFromLeft], array[last - 1]);
//    QuickSort(array, first, indexFromLeft - 1);
//    QuickSort(array, indexFromLeft + 1, last);
//
//    //      if (first < last) {
//    //            int pivot = first;
//    //            int pivotE = array[first];
//    //            for (int i = first + 1; i <= last; i++)
//    //            {
//    //                  if (array[i] <= pivotE)
//    //                  {
//    //                        pivot++;
//    //                        Swap(array[i], array[pivot]);
//    //                  }
//    //            }
//    //            Swap(array[pivot], array[first]);
//    //
//    //            //   Swap(array[indexFromLeft], array[last - 1]);
//    //            QuickSort(array, first, pivot - 1);
//    //            QuickSort(array, pivot + 1, last);
//    //      }
}

void ShellSort(vector<int>& array, int start, int end)
{
    int size = end - start + 1;
    for (int gap = size / 2; gap > 0; gap = gap / 2)
    {
        for (int unsorted = gap; unsorted < size; unsorted++)
        {
            int nextInt = array[unsorted];
            int idx = unsorted;
            while ((idx >= gap) && (array[idx - gap] > nextInt))
            {
                array[idx] = array[idx - gap];
                idx = idx - gap;
            }
            array[idx] = nextInt;
        }
    }
}

void Merge(vector<int> &array, int first, int mid, int last) {
    int size = last - first + 1;
    
    int *tempArray = new int[size];
    
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    
    int index = 0;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (array[first1] <= array[first2])
        {
            tempArray[index] = array[first1];
            first1++;
        }
        else
        {
            tempArray[index] = array[first2];
            first2++;
        }
        index++;
    }
    while (first1 <= last1)
    {
        tempArray[index] = array[first1];
        first1++;
        index++;
    }
    while (first2 <= last2)
    {
        tempArray[index] = array[first2];
        first2++;
        index++;
    }
    for (index = 0; index < size; index++)
    {
        array[first] = tempArray[index];
        first++;
    }
    delete[] tempArray;
}

void Swap(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

#endif /* SRC_SORTIMPLS_H_ */
