#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
int partition(vector<int> &arr, int l, int r)
{
	int pivot = arr[r];
	int i = l - 1;
	int temp;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;
	return (i + 1);
}
int Smallest(vector<int> &arr, int n, int k)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int p = partition(arr, l, r);
		if (p == k - 1)
		{
			return arr[p];
		}
		else if (p > k - 1)
		{
			r = p - 1;
		}
		else
		{
			l = p + 1;
		}
	}
	return 0;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/3.NthSmallestElement/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/3.NthSmallestElement/Output.txt");

	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(inputFile.rdbuf());

	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cin >> k;
		cout << Smallest(arr, n, k) << endl;
	}

	inputFile.close();
	out.close();
}