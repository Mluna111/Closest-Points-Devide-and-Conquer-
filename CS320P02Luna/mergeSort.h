#ifndef _MERGESORT_
#define _MERGESORT_
#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

template <typename Comparable, typename Comparator>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray,int leftPos, int rightPos, int rightEnd, Comparator x);
/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable, typename Comparator>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tmpArray, int left, int right, Comparator x)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center, x);
        mergeSort(a, tmpArray, center + 1, right, x);
        merge(a, tmpArray, left, center + 1, right, x);
    }
}

/**
 * Mergesort algorithm (driver).
 */
template <typename Comparable, typename Comparator>
void mergeSort(vector<Comparable>& a, Comparator x = Point::CompareXCoordinate)
{
    vector<Comparable> tmpArray(a.size());

    mergeSort(a, tmpArray, 0, a.size() - 1, x);
}


/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable, typename Comparator>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray,
    int leftPos, int rightPos, int rightEnd, Comparator x)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while (leftPos <= leftEnd && rightPos <= rightEnd)
        if (x(a[leftPos], a[rightPos]))
            tmpArray[tmpPos++] = std::move(a[leftPos++]);
        else
            tmpArray[tmpPos++] = std::move(a[rightPos++]);

    while (leftPos <= leftEnd)    // Copy rest of first half
        tmpArray[tmpPos++] = std::move(a[leftPos++]);

    while (rightPos <= rightEnd)  // Copy rest of right half
        tmpArray[tmpPos++] = std::move(a[rightPos++]);

    // Copy tmpArray back
    for (int i = 0; i < numElements; ++i, --rightEnd)
        a[rightEnd] = std::move(tmpArray[rightEnd]);
}
template <typename T>
void printVector(vector<T> v) {
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
#endif