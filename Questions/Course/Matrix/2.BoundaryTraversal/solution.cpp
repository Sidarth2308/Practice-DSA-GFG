#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
void BoundaryTraversal(vector<vector<int>> &arr, int n, int m)
{
	if (n == 1)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[0][i] + " ";
		}
	}
	else if (m == 1)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i][0] + " ";
		}
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[0][i] << " ";
		}
		for (int i = 1; i < n; i++)
		{
			cout << arr[i][m - 1] << " ";
		}
		for (int i = m - 2; i >= 0; i--)
		{
			cout << arr[n - 1][i] << " ";
		}
		for (int i = n - 2; i >= 1; i--)
		{
			cout << arr[i][0] << " ";
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
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Matrix/2.BoundaryTraversal/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Matrix/2.BoundaryTraversal/Output.txt");

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
		BoundaryTraversal(arr, n, m);
		cout << endl;
	}

	inputFile.close();
	out.close();
}