#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
bool Search(vector<int> arr, int n, int x)
{
	int left = 0, right = n - 1;
	while (left != right)
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

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/6.TwoPointerApproach/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/6.TwoPointerApproach/Output.txt");

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
		cout << Search(arr, n, x) << endl;
	}

	inputFile.close();
	out.close();
}