#include <iostream>
#include <Windows.h>
using namespace std;
//1.Massivdeki cut elementleri duplicate eden funksiya yazin
//	example : 1 2 3 4 5
//	1 2 2 3 4 4 5
void PrintArray(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}cout << endl << endl;
}
int* DublicateArray(int* arr,int &size) {
	int count = 0;
	int* arr2 = new int[size+size] {};
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0) { arr2[count++] = arr[i]; }
		else { arr2[count++] = arr[i]; arr2[count++] = arr[i]; }
	}
	delete[]arr;
	arr = arr2;
	arr2 = nullptr;
	size = count;
	return arr;
}


//2.Massivdeki her 2 elementden bir elementlerin cemi sagina yazilsin
//	10 20 30 40 50 60 70 80
//	10 20 30 30 40 70 50 60 110 70 80 150
void PrintArray(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}cout << endl << endl;
}
int* ChangeArray(int* arr, int& size) {
	int index = 0;
	int* arr2 = new int[size + size] {};
	for (size_t i = 0; i < size-1; i+=2)
	{	
		arr2[index] = arr[i];
		arr2[index + 1] = arr[i + 1];
		arr2[index + 2] = arr[i] + arr[i + 1];
		index += 3;
	}
	delete[] arr;
	arr = arr2;
	arr2 = nullptr;
	size = index;
	return arr;

}





//3.Meselen
//	2 4 1 5 3
//	2 0 0 4 0 0 0 0 1 0 5 0 0 0 0 0 3 0 0 0

void PrintArray(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}cout << endl << endl;
}
int* ChangeArr(int* arr, int& size) {
	int index = 0;
	int* temp = new int[100]{};
	for (size_t i = 0; i < size; i++)
	{
		temp[index++] = arr[i];
		for (size_t k = 0; k < arr[i]; k++)
		{
			temp[index++] = 0;
		}
	}
	delete[]arr;
	arr = temp;
	temp = nullptr;
	size = index;
	return arr;
}
void main() {
	system("color f0");
	//1.Massivdeki cut elementleri duplicate eden funksiya yazin
	//	example : 1 2 3 4 5
	//	1 2 2 3 4 4 5
	int size = 5;
	int* arr = new int[size] {1, 2, 3, 4, 5};
	PrintArray(arr, size);
	arr = DublicateArray(arr, size);
	PrintArray(arr, size);




	//2.Massivdeki her 2 elementden bir elementlerin cemi sagina yazilsin
	//	10 20 30 40 50 60 70 80
	//	10 20 30 30 40 70 50 60 110 70 80 150
	int size = 8;
	int* arr = new int[size] {10, 20, 30, 40, 50, 60, 70, 80};
	PrintArray(arr, size);
	arr = ChangeArray(arr, size);
	PrintArray(arr, size);



	//3.Meselen
	//	2 4 1 5 3
	//	2 0 0 4 0 0 0 0 1 0 5 0 0 0 0 0 3 0 0 0
	int size = 5;
	int* arr = new int[size] {2, 4, 1, 5, 3};
	PrintArray(arr, size);
	arr = ChangeArr(arr, size);
	PrintArray(arr, size);
	cout << endl << endl << endl; system("pause");
}