# Find-Missing-Numbers

Implement the function: int* findMissing(int arr[], int n, int& resArrSize) \
This function gets an array of integers arr and its logical size n. All elements in arr are
in the range {0, 1, 2, … , n}.

Note that since the array contains n numbers taken from a range of size n+1, there must
be at least one number that is missing (could be more than one number missing, if there
are duplicate values in arr).

When called, it should create and return a new array, that contains all the numbers in
range {0, 1, 2, … , n} that are not in arr. The function should also update the output
parameter, resArrSize, with the logical size of the new array that was created.

For example, if arr=[3, 1, 3, 0, 6, 4], after calling
findMissing(arr, 6, resArrSize), the function should create and return an
array that contains [2, 5], and update the value in resArrSize to be 2.

Note: Your function should run in linear time. That is, it should run in 𝜃(𝑛)
