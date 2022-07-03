#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
void SnakePattern(vector<vector<int>> &arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < m; j++)
			{
				cout << arr[i][j] << " ";
			}
		}
		else
		{
			for (int j = m - 1; j >= 0; j--)
			{
				cout << arr[i][j] << " ";
			}
		}
	}
	cout << endl;
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
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Matrix/1.SnakePattern/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Matrix/1.SnakePattern/Output.txt");

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
		cout << "Result : " << endl;
		SnakePattern(arr, n, m);
		cout << endl;
	}

	inputFile.close();
	out.close();
}