# Bubble Sort

## Input: An array arr[] of n elements.
## Output: The array arr[] sorted in non-decreasing order.

    i = 0 to n-1
        j = 0 to n-1-i
            A[j] > A[j+1] ? swap : do nothing
---
    Procedure:
    1. Start with the first element of the array and iterate through each element up to the second-to-last element (i from 0 to n - 2).
    2. For each element at index i, iterate through the array again, comparing adjacent elements (j from 0 to n - 2 - i).
    3. For each pair of adjacent elements (arr[j], arr[j+1]), if arr[j] is greater than arr[j+1], swap them.
    4. Repeat this process for each element in the array, so after the first pass, the largest element will be at the end of the array.
    5. Continue these passes, reducing the range of elements considered in each pass, until no swaps are performed in a pass, indicating the array is sorted.

## Output: The array arr[] is now sorted in non-decreasing order.

# Insertion Sort
    i = 1 to n:
        key = A[i]
        j = i-1
        while j>=0 and A[j]>key:
            A[j+1] = A[j]
            j--
        A[j+1] = key
---
    1. Start with the second element: Consider the first element as already sorted.
    2. Iterate through the remaining elements:
    3. Pick the current element.
        - Compare it with the element to its left.
        - If the current element is smaller, swap them.
        - Continue comparing and swapping with elements to the left until the correct position is found.
    4. Repeat for each element: Continue this process for all elements in the array.

# Selection Sort
    i = 0 to n-1:
        minIndex = i
        j = i+1 to n:
            update minIndex (if req.)
        swap A[minIndex] and A[i]
---
    1. Set MIN to location 0
    2. Search the minimum element in the list
    3. Swap with value at location MIN
    4. Increment MIN to point to next element
    5. Repeat until list is sorted

# Quick Sort

    quickSort(array, leftmostIndex, rightmostIndex)
    if (leftmostIndex < rightmostIndex)
        pivotIndex <- partition(array,leftmostIndex, rightmostIndex)
        quickSort(array, leftmostIndex, pivotIndex - 1)
        quickSort(array, pivotIndex, rightmostIndex)

    partition(array, leftmostIndex, rightmostIndex)
    set rightmostIndex as pivotIndex
    storeIndex <- leftmostIndex - 1
    for i <- leftmostIndex + 1 to rightmostIndex
    if element[i] < pivotElement
        swap element[i] and element[storeIndex]
        storeIndex++
    swap pivotElement and element[storeIndex+1]
    return storeIndex + 1

# Merge Sort

    MergeSort(A, p, r):
        if p > r
            return
        q = (p+r)/2
        mergeSort(A, p, q)
        mergeSort(A, q+1, r)
        merge(A, p, q, r)

    Merge(A, p, q, r):
    1. Create copies of the subarrays L <- A[p..q] and M <- A[q+1..r].
    2. Create three pointers i, j and k
        i maintains current index of L, starting at 1
        j maintains current index of M, starting at 1
        k maintains the current index of A[p..q], starting at p.
    3. Until we reach the end of either L or M, pick the larger among the elements from L and M and place them in the correct position at A[p..q]
    4. When we run out of elements in either L or M, pick up the remaining elements and put in A[p..q]