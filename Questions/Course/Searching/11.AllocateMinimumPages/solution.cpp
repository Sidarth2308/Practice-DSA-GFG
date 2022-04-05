#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
bool isFeasible(vector<int> arr, int n, int k, int ans)
{
	int req = 1, sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + arr[i] > ans)
		{
			req++;
			sum = arr[i];
		}
		else
		{
			sum += arr[i];
		}
	}
	return (req <= k);
}
int AllocatePages(vector<int> arr, int n, int k)
{
	int sum = 0, mx = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		mx = max(mx, arr[i]);
	}
	int low = mx, high = sum, res = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (isFeasible(arr, n, k, mid))
		{
			res = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return res;
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
		cin >> x;
		cout << AllocatePages(arr, n, x) << endl;
	}

	inputFile.close();
	out.close();
}