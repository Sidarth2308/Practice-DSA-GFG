#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
int countAndMerge(vector<int> &arr, int low, int mid, int high)
{
	int sizeA = mid - low + 1;
	int sizeB = high - mid;
	vector<int> A(sizeA);
	vector<int> B(sizeB);
	for (int i = 0; i < sizeA; i++)
	{
		A[i] = arr[i + low];
	}
	for (int i = 0; i < sizeB; i++)
	{
		B[i] = arr[i + mid + 1];
	}
	int count = 0;
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

			count = count + (sizeA - i);
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

	return count;
}
int countInversions(vector<int> &arr, int l, int r)
{
	int count = 0;
	if (l < r)
	{
		int m = (l + r) / 2;
		count += countInversions(arr, l, m);
		count += countInversions(arr, m + 1, r);
		count += countAndMerge(arr, l, m, r);
	}
	return count;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/2.CountInversionsInArray/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/2.CountInversionsInArray/Output.txt");

	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(inputFile.rdbuf());

	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << countInversions(arr, 0, n - 1) << endl;
	}
	inputFile.close();
	out.close();
}