#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
int distributeChocolates(vector<int> arr, int n, int m)
{
	if (m > n)
		return -1;
	sort(arr.begin(), arr.end());
	int res = arr[m - 1] - arr[0];
	for (int i = 1; i + m - 1 < n; i++)
	{
		res = min(res, arr[i + m - 1] - arr[i]);
	}
	return res;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/4.ChocolateDistribution/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/4.ChocolateDistribution/Output.txt");

	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(inputFile.rdbuf());

	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cin >> m;
		cout << distributeChocolates(arr, n, m) << endl;
	}

	inputFile.close();
	out.close();
}