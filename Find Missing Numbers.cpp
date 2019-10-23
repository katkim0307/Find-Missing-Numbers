
#include <iostream>
using namespace std;

int main1();	// uses the predefined array
int main2();	// asks the user to put in their own array and its size
int* findMissingVal(int arr[], int n, int& resArrSize);
void printMissingValArr(int arr[], int arrSize);

int main()
{
	main1();
	cout << endl;
	main2();
	return 0;
}

int main1()
{
	int arr[] = { 3, 1, 3, 0, 6, 4 };
	int arrSize = 6;
	int* miaNumArr;
	int miaNumArrSize = arrSize;	//initialize miaNumArrSize to be arrSize
	
	miaNumArr= new int[miaNumArrSize];

	miaNumArr = findMissingVal(arr, arrSize, miaNumArrSize);

	cout << "The initial array is {";
	for (int i = 0; i < arrSize; i++) {
		if (i == arrSize - 1)
			cout << arr[i];
		else
			cout << arr[i] << ", ";
	}
	cout << '}' << endl;

	printMissingValArr(miaNumArr, miaNumArrSize);

	delete[]miaNumArr; miaNumArr = NULL;
	return 0;
}

int* findMissingVal(int arr[], int n, int& resArrSize) 
{
	// creating a temp dynamic array of the range 0 to n
	int* tempArr;
	//initialize the missingValArrSize to the size of given array
	int tempArrSize = n + 1;
	tempArr = new int[tempArrSize];

	// in our case: {0, 1, 2, 3, 4, 5, 6}
	for (int i = 0; i <= n; i++) {
		tempArr[i] = i;
	}

	// the idea is to compare tempArr[] and arr[]
	// tempArr[] = {0, 1, 2, 3, 4, 5, 6}
	// arr[]	 = {3, 1, 3, 0, 4, 6}
	// and use the element of arr[] as the index of tempArr[]
	// assign that element as -1 as a check mark
	// at the end, the unmarked element(s) in tempArr[] will appear > -1
	// NEW tempArr[] = {-1, -1, 2, -1, -1, 5, -1}
	for (int i = 0; i < n; i++) {
		if (tempArr[arr[i]] != -1) {
			tempArr[arr[i]] = -1;
			//tempArrSize--;
		}
	}

	int* missingValArr;
	missingValArr = new int[tempArrSize];

	int count = 0; 
	for (int i = 0; i <= n; i++) {
		if (tempArr[i] > -1) {
			missingValArr[count] = tempArr[i];
			count++;
		}
	}
	//set resArrSize equal to the updated missingValArrSize
	resArrSize = count;
	//reture the base address of missingValArr
	return missingValArr;
}

void printMissingValArr(int arr[], int arrSize)
{
	if (arrSize <= 1)
		cout << "There is " << arrSize << " missing value, and it is {";
	else
		cout << "There are " << arrSize << " missing values, and they are {";

	for (int i = 0; i < arrSize; i++) {
		if (i == arrSize - 1)
			cout << arr[i] << '}';
		else
			cout << arr[i] << ", ";
	}
}

//asks the user to input their own array
int main2()
{
	int arrSize;

	cout << "Please enter the size of your array: \n";
	cin >> arrSize;

	int* arr = new int[arrSize];
	cout << "Please enter the positive values less than or equal to ";
	cout << arrSize << " in your array separated by a space: \n";
	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i];
	}

	int miaNumArrSize = arrSize;	//initialize miaNumArrSize to be arrSize
	int* miaNumArr = new int[miaNumArrSize];

	miaNumArr = findMissingVal(arr, arrSize, miaNumArrSize);
	printMissingValArr(miaNumArr, miaNumArrSize);

	delete[]arr; arr = NULL;
	delete[]miaNumArr; miaNumArr = NULL;
	return 0;
}
