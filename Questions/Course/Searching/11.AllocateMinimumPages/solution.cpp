#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
bool isPair(vector<int> arr, int low, int high, int x)
{
	int left = low, right = high;
	int sum;
	// cout << left << " " << right << endl;
	while (left < right)
	{
		sum = (arr[left] * arr[left]) + (arr[right] * arr[right]);
		if (sum == x)
		{
			return true;
		}
		else if (sum < x)
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
bool hasPythagoreanTriplets(vector<int> arr, int n)
{
	sort(arr.begin(), arr.end());
	for (int i = n - 1; i > 0; i--)
	{
		if (isPair(arr, 0, i - 1, arr[i] * arr[i]))
			return true;
	}
	return false;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/11.AllocateMinimumPages/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/11.AllocateMinimumPages/Output.txt");

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
		cout << hasPythagoreanTriplets(arr, n) << endl;
	}

	inputFile.close();
	out.close();
}