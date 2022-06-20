#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <filesystem>

using namespace std;
class Event
{
public:
	string day;
	int duration, start, end, noOfUsers;
	vector<string> users;
};
class User
{
public:
	string name;
	vector<Event> events;
};

int main()
{
	string input;
	ifstream inputFile("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/7.KuddleQuestionCopy/Input.txt");

	ofstream out("F:/new/collegeProjects/DSA/Practice-DSA-GFG/Questions/Course/Sorting/7.KuddleQuestionCopy/Output.txt");

	streambuf *cinbuf = std::cin.rdbuf();
	cin.rdbuf(inputFile.rdbuf());

	streambuf *coutbuf = std::cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int n;
	cin >> n;
	string command;
	unordered_map<string, User> users;
	for (int i = 0; i < n; i++)
	{
		cin >> command;
		if (command == "add-user")
		{
			string username;
			cin >> username;
			vector<Event> events;
			if (users.find(username) == users.end())
			{

				User *newUser = new User();
				newUser->name = username;
				newUser->events = events;
				users[username] = *newUser;
				cout << "success" << endl;
			}
			else
			{
				cout << "failure" << endl;
			}
		}
		else if (command == "create-event")
		{
			string day;
			int duration, start, nOfUsers;
			string user;
			cin >> day >> start >> duration >> nOfUsers;
			string username;
			vector<string> usernames;
			for (int j = 0; j < nOfUsers; j++)
			{
				cin >> user;
				usernames.push_back(user);
			}
			bool canCreate = true;
			for (int j = 0; j < nOfUsers; j++)
			{
				username = usernames[j];

				if (users.find(username) != users.end())
				{

					for (int l = 0; l < users[username].events.size(); l++)
					{

						if (day == users[username].events[l].day)
						{
							if (start > users[username].events[l].start && start < users[username].events[l].end)
							{
								canCreate = false;
								break;
							}
						}
					}
				}
			}
			if (canCreate)
			{
				Event *event = new Event();
				event->start = start;
				event->end = start + duration - 1;
				event->duration = duration;
				event->day = day;
				event->noOfUsers = nOfUsers;
				event->users = usernames;
				for (int j = 0; j < nOfUsers; j++)
				{
					users[usernames[j]].events.push_back(*event);
				}
				cout << "success" << endl;
			}
			else
			{
				cout << "failure" << endl;
			}
		}
		else if (command == "show-events")
		{
			string day, username;
			cin >> day >> username;
			bool haveFound = false;

			if (users.find(username) != users.end())
			{
				for (int k = 0; k < users[username].events.size(); k++)
				{
					if (day == users[username].events[k].day)
					{
						cout << users[username].events[k].start << "-" << users[username].events[k].end + 1 << " ";
						for (int l = 0; l < users[username].events[k].users.size(); l++)
						{
							cout << users[username].events[k].users[l] << " ";
						}
						cout << endl;
					}
					else
					{
						cout << "none" << endl;
					}
				}
				if (users[username].events.size() == 0)
				{
					cout << "none" << endl;
				}
			}
			else
			{
				cout << "failure" << endl;
			}
		}
		else if (command == "suggest-slot")
		{
			string day, username;
			int start, end, duration, noOfUsers;
			cin >> day >> start >> end >> duration >> noOfUsers;
			int slot = start;
			for (int j = 0; j < noOfUsers; j++)
			{
				cin >> username;
				if (users.find(username) != users.end())
				{
					for (int k = 0; k < users[username].events.size(); k++)
					{
						if (slot > end)
						{
							cout << "none" << endl;
						}
						if (users[username].events[k].day == day)
						{

							if ((users[username].events[k].start > start))
							{
								slot = users[username].events[k].start;
								start = users[username].events[k].start;
							}
						}
					}
				}
				cout << slot << endl;
			}
			cin >> day;
		}
		else
		{
			cout << "failure from 5" << endl;
		}
	}

	inputFile.close();
	out.close();
}