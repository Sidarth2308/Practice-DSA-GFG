#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
// bool compare(vector<int> &arr1, vector<int> &arr2)
// {
// 	return (arr1[0] < arr2[0]);
// }
int MeetMaxGuests(vector<int> &arrival, vector<int> &departure, int n)
{
	sort(arrival.begin(), arrival.end());
	sort(departure.begin(), departure.end());
	int i = 1, j = 0, res = 1, curr = 1;
	while (i < n && j < n)
	{
		if (arrival[i] <= departure[j])
		{
			curr++;
			i++;
		}
		else
		{
			curr--;
			j++;
		}
		res = max(res, curr);
	}
	return res;
}

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/8.MeetMaximumGuests/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/8.MeetMaximumGuests/Output.txt");

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
		vector<int> arrival(n);
		vector<int> departure(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arrival[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> departure[i];
		}
		cout << MeetMaxGuests(arrival, departure, n) << endl;
	}

	inputFile.close();
	out.close();
}