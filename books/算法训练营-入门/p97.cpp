#include <iostream>
#include <map>

using namespace std;

/* 优先级、客户标识 */
map<int, int> mp;

void add(void)
{
	int id;
	int priority;

	cin >> id >> priority;

	mp.insert(make_pair(priority, id));
}
void del_max()
{
	if (mp.empty()) {
		cout << "ans: " << 0 << endl;
		return;
	}
	cout << "ans: " << mp.rbegin()->second << endl;
	mp.erase(mp.rbegin()->first);
}
void del_min()
{
	if (mp.empty()) {
		cout << "ans: " << 0 << endl;
		return;
	}
	cout << "ans: " << mp.begin()->second << endl;
	mp.erase(mp.begin()->first);
}

int main()
{
	int op;
	while (true) {
		cin >> op;
		switch (op) {
			case 1:
				add();
				break;
			case 2:
				del_max();
				break;
			case 3:
				del_min();
				break;
			case 0:
			default:
				break;

		}
	}
}
