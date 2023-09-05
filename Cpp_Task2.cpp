#include<iostream>
#include<Windows.h>
#include<iomanip>
using namespace std;
//My Array Function
int** ReserveArray(int row, int col) {
	int** arr = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	return arr;
}
void InitArray(int**& arr, const int& row, const int& col, const int& min = 1, const int& max = 100) {
	int random = 0; srand(time(0));
	for (size_t i = 0; i < row; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			random = min + rand() % (max - min + 1);
			arr[i][k] = random;
		}
	}
}
void PrintArray(int**& arr, const int& row, const int& col) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			cout << setw(2) << arr[i][k] << " ";
		}cout << endl;
	}cout << endl << endl;
}


//1.Matrixi X oxu uzre qatlayin ve ust uste dusen elementleri vurun
void Fold_X_Axis_Array(int**& arr, int& row, const int& col) {

	for (size_t i = 0; i < row / 2; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			arr[i][k] = arr[i][k] * arr[row - i - 1][k];
		}
	}
	row /= 2;
}



//2.Matrixi Y oxu uzre qatlayin ve ust uste dusen elementleri toplayin
void Fold_Y_Axis_Array(int**& arr, const int& row, int& col) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t k = 0; k < col / 2; k++)
		{
			arr[i][k] = arr[i][k] + arr[i][col - k - 1];
		}
	}
	col /= 2;
}



////3.Sutunu minimal olcuye gelene qeder sixisdirin
void Fold_Y_Axis_Array(int**& arr, const int& row, int& col) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t k = 0; k < col / 2; k++)
		{
			arr[i][k] = arr[i][k] + arr[i][col - k - 1];
		}
	}
	col /= 2;
}



//4.Setiri minimal olcuye gelene qeder sixisdirin.
void Fold_X_Axis_Array(int**& arr, int& row, const int& col) {

	for (size_t i = 0; i < row / 2; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			arr[i][k] = arr[i][k] * arr[row - i - 1][k];
		}
	}
	row /= 2;
}
void main() {
	system("color f0");


	//My Array Function
	int row = 4, col = 4, min = 1, max = 9;
	auto arr = ReserveArray(row, col);
	InitArray(arr, row, col, min, max);
	PrintArray(arr, row, col);


	////1.Matrixi X oxu uzre qatlayin ve ust uste dusen elementleri vurun.
	Fold_X_Axis_Array(arr, row, col);
	PrintArray(arr, row, col);


	//2.Matrixi Y oxu uzre qatlayin ve ust uste dusen elementleri toplayin
	Fold_Y_Axis_Array(arr, row, col);
	PrintArray(arr, row, col);


	//3.Sutunu minimal olcuye gelene qeder sixisdirin
	do
	{
		Fold_Y_Axis_Array(arr, row, col);
		PrintArray(arr, row, col);
	} while (col > 1);


	//4.Setiri minimal olcuye gelene qeder sixisdirin.
	do
	{
		Fold_X_Axis_Array(arr, row, col);
		PrintArray(arr, row, col);
	} while (row > 1);


	cout << endl << endl << endl; cin.get();
}