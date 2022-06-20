#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
bool compare(vector<int> &arr1, vector<int> &arr2)
{
	return (arr1[0] < arr2[0]);
}
int mergeIntervals(vector<vector<int>> &arr, int n)
{
	sort(arr.begin(), arr.end(), compare);
	int res = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[res][1] >= arr[i][0])
		{
			arr[res][1] = max(arr[res][1], arr[i][1]);
			arr[res][0] = min(arr[res][0], arr[i][0]);
		}
		else
		{
			res++;
			arr[res] = arr[i];
		}
	}
	return res + 1;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/6.MergeOverlappingIntervals/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/6.MergeOverlappingIntervals/Output.txt");

	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(inputFile.rdbuf());

	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;
	while (t--)
	{
		int n, start, end;
		cin >> n;
		vector<vector<int>> arr;
		for (int i = 0; i < n; i++)
		{
			cin >> start >> end;
			vector<int> interval = {start, end};
			arr.push_back(interval);
		}
		n = mergeIntervals(arr, n);
		cout << "[ ";
		for (int i = 0; i < n; i++)
		{
			cout << "[" << arr[i][0] << ", " << arr[i][1] << "], ";
		}
		cout << "]" << endl;
	}

	inputFile.close();
	out.close();
}