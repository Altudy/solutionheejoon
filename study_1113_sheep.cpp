#include <iostream>			// 백준 16437
using namespace std;

struct node
{
	int sheep;
	int wolf;
	int parent;
};

void go(node island[], int c);

long long save(0);			// 구할 수 있는 양의 수
long long final(0);
int p;						// 부모 노드.

int main()
{
	ios::sync_with_stdio(false);

	int island_num;				// 섬의 수
	char animal;				// w, s 구별 위한 변수

	cin >> island_num;

	node* island = new node[island_num + 1]{};
	bool* tail = new bool[island_num + 1]{};		// 누군가를 자신을 부모노드로 지정하면 true.

	for (int i = 2; i <= island_num; i++)			// 입력받기.
	{
		cin >> animal;
		if (animal == 'S')
		{
			cin >> island[i].sheep;
			island[i].wolf = 0;
			cin >> island[i].parent;
			tail[island[i].parent] = true;
		}
		else
		{
			cin >> island[i].wolf;
			island[i].sheep = 0;
			cin >> island[i].parent;
			tail[island[i].parent] = true;
		}
	}

	for (int i = 2; i <= island_num; i++)
	{
		if (tail[i] == false)
		{
			save = 0;
			go(island, i);
		}
	}

	cout << final;

	return 0;
}

void go(node island[], int c)
{
	if (c == 1)
	{
		final += save;
		return;
	}

	p = island[c].parent;
	save += island[c].sheep;
	island[c].sheep = 0;

	if (island[p].wolf > save)
	{
		island[p].wolf -= save;
		save = 0;
	}
	else
	{
		save -= island[p].wolf;
		island[p].wolf = 0;
	}
	go(island, p);
	return;
}

/*
	for (int i = 2; i <= island_num; i++)
		cout << island[i].sheep << "\t" << island[i].wolf << "\t" << island[i].parent << endl;
*/
