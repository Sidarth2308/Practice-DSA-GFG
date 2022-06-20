#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
void threeWaySort(vector<int> &arr, int n)
{
	int low = 0, mid = 0, high = n - 1;
	int pivot = 1;
	while (mid <= high)
	{
		if (arr[mid] < pivot)
		{
			swap(arr[low], arr[mid]);
			mid++;
			low++;
		}
		else if (arr[mid] == pivot)
		{
			mid++;
		}
		else
		{
			swap(arr[mid], arr[high]);
			high--;
		}
	}
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/5.ThreeWaySorting/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/5.ThreeWaySorting/Output.txt");

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
		threeWaySort(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	inputFile.close();
	out.close();
}