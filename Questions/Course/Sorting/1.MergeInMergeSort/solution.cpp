#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
vector<int> Merge(vector<int> arr, int n, int low, int mid, int high)
{
	vector<int> A(mid - low + 1);
	vector<int> B(high - mid);
	int sizeA = size(A);
	int sizeB = size(B);
	for (int i = low, j = 0; i <= mid; i++, j++)
	{
		A[j] = arr[i];
	}
	for (int i = mid + 1, j = 0; i <= high; i++, j++)
	{
		B[j] = arr[i];
	}
	int i = 0, j = 0, x = low;
	while (i < sizeA && j < sizeB)
	{
		if (A[i] <= B[j])
		{
			arr[x] = A[i];
			i++;
		}
		else
		{
			arr[x] = B[j];
			j++;
		}
		x++;
	}
	while (i < sizeA)
	{
		arr[x] = A[i];
		i++;
		x++;
	}
	while (j < sizeB)
	{
		arr[x] = B[j];
		j++;
		x++;
	}
	return arr;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/1.MergeInMergeSort/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/1.MergeInMergeSort/Output.txt");

	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(inputFile.rdbuf());

	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;
	while (t--)
	{
		int n, low, mid, high;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cin >> low >> mid >> high;
		arr = Merge(arr, n, low, mid, high);
		n = size(arr);
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	inputFile.close();
	out.close();
}