#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
int FindPossibleTriangle(vector<int> &arr, int n)
{
	sort(arr.begin(), arr.end());
	int count = 0;
	for (int i = n - 1; i >= 2; i--)
	{
		int left = 0, right = i - 1;
		while (left < right)
		{
			if (arr[left] + arr[right] > arr[i])
			{
				count = count + (right - left);
				right--;
			}
			else
			{
				left++;
			}
		}
	}
	return count;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/9.MaxTriangles/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/9.MaxTriangles/Output.txt");

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
		cout << FindPossibleTriangle(arr, n) << endl;
	}

	inputFile.close();
	out.close();
}