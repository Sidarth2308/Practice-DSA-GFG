#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;

int FindRepeat(vector<int> arr, int n)
{
	int slow = arr[0] + 1, fast = arr[0] + 1;
	do
	{
		slow = arr[slow] + 1;
		fast = arr[arr[fast] + 1] + 1;

	} while (slow != fast);
	slow = arr[0] + 1;
	while (slow != fast)
	{
		slow = arr[slow] + 1;
		fast = arr[fast] + 1;
	}
	return slow - 1;
}
int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/10.RepeatingElement/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/10.RepeatingElement/Output.txt");

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
		cout << FindRepeat(arr, n) << endl;
	}

	inputFile.close();
	out.close();
}