#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
void Transpose(vector<vector<int>> &arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			swap(arr[i][j], arr[j][i]);
		}
	}
}
void printMatrix(vector<vector<int>> &arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Matrix/3.TransposeOfMatrix/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Matrix/3.TransposeOfMatrix/Output.txt");

	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(inputFile.rdbuf());

	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> arr(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		}
		cout << "Before manipulation : " << endl;
		printMatrix(arr, n, m);
		Transpose(arr, n, m);
		cout << "Result : " << endl;
		printMatrix(arr, n, m);
		cout << endl;
	}

	inputFile.close();
	out.close();
}