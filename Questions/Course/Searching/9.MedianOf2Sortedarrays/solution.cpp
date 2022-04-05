#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
int findI2(int n1, int n2, int i1)
{
	return ((n1 + n2 + 1) / 2) - i1;
}

double Median(vector<int> arr1, int n1, vector<int> arr2, int n2)
{
	int i1, i2;
	int begin1 = 0, end1 = n1;
	while (begin1 <= end1)
	{
		i1 = (begin1 + end1) / 2;
		i2 = findI2(n1, n2, i1);
		int min1 = (i1 == n1) ? INT_MAX : arr1[i1];
		int min2 = (i2 == n2) ? INT_MAX : arr2[i2];

		int max1 = (i1 == 0) ? INT_MIN : arr1[i1 - 1];
		int max2 = (i2 == 0) ? INT_MIN : arr2[i2 - 1];

		// cout << "i1 : " << i1 << " i2 : " << i2 << " min1 :" << min1 << " max 1 : " << max1 << " min2 : " << min2 << " max2 : " << max2 << endl;
		if (max1 <= min2 && max2 <= min1)
		{
			if ((n1 + n2) % 2 == 0)
			{
				return ((double)((max(max1, max2) + min(min1, min2)) / 2));
			}
			else
			{
				return ((double)max(max1, max2));
			}
		}
		else if (max1 > min2)
			end1 = i1 - 1;
		else
			begin1 = i1 + 1;
	}
	return -1;
}
int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/9.MedianOf2Sortedarrays/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Searching/9.MedianOf2Sortedarrays/Output.txt");

	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(inputFile.rdbuf());

	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int t;
	cin >> t;
	while (t--)
	{
		int n1;
		cin >> n1;
		vector<int> arr1(n1);
		for (int i = 0; i < n1; i++)
		{
			cin >> arr1[i];
		}
		int n2;
		cin >> n2;
		vector<int> arr2(n2);
		for (int i = 0; i < n2; i++)
		{
			cin >> arr2[i];
		}
		if (n1 <= n2)
		{
			cout << Median(arr1, n1, arr2, n2) << endl;
		}
		else
		{
			cout << Median(arr2, n2, arr1, n1) << endl;
		}
	}

	inputFile.close();
	out.close();
}