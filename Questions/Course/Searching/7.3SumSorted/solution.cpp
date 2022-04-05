#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
bool isPair(vector<int> arr, int i, int n, int x)
{
	int left = i, right = n;
	// cout << left << " " << right << endl;
	while (left < right)
	{
		if (arr[left] + arr[right] == x)
		{
			return true;
		}
		else if (arr[left] + arr[right] < x)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	return false;
}
bool hasTriplet(vector<int> arr, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (isPair(arr, i + 1, n - 1, x - arr[i]))
			return true;
	}
	return false;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/7.3SumSorted/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/7.3SumSorted/Output.txt");

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
		cout << hasTriplet(arr, n, x) << endl;
	}

	inputFile.close();
	out.close();
}