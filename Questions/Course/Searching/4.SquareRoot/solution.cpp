#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
int SQRT(int n)
{
	int low = 1, high = n, ans = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int msq = mid * mid;
		if (msq = n)
		{
			return mid;
		}
		else if (msq > n)
		{
			low = mid + 1;
			ans = mid;
		}
		else
		{
			high = mid - 1;
		}
	}
	return ans;
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
		cin >> n;
		cout << SQRT(n) << endl;
	}

	inputFile.close();
	out.close();
}