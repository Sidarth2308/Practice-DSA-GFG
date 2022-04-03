#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
int firstOcc(vector<int> arr, int x, int n)
{
	int high = n - 1, low = 0, mid;
	while (low <= high)
	{
		mid = (high + low) / 2;
		if (x == arr[mid])
		{
			if (mid == 0 || arr[mid] != arr[mid - 1])
			{
				return mid;
			}
			else
			{
				high = mid - 1;
			}
		}
		else if (x < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/1.IndexOfFirstOccurance/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/1.IndexOfFirstOccurance/Output.txt");

	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(inputFile.rdbuf());

	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		int x;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cin >> x;
		cout << firstOcc(arr, x, n) << endl;
	}

	inputFile.close();
	out.close();
}