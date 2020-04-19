#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int n, m;

// tree[index] = arr[start] ~ arr[end] 까지의 연산 값이다.
int arr[500000];
int* tree;
int* lazy;
int tree_size;

// 수열을 입력받고 tree를 만든다.
void init()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> m;

	int h = ceil(log2(n));
	tree_size = 1 << (h + 1);

	tree = new int[tree_size]{};
	lazy = new int[tree_size]{};	
}

// 수열로 초기 tree를 만든다.
int make_tree(int index, int start, int end)
{
	if (start == end)
		return tree[index] = arr[start];

	int mid = (start + end) / 2;
	return tree[index] = make_tree(index * 2 + 1, start, mid) 
		^ make_tree(index * 2 + 2, mid + 1, end);
}

// lazy propagation, lazy 값을 tree에 반영하고 아래로 전파한다.
void propagation(int index, int start, int end)
{
	if (lazy[index] != 0)
	{
		tree[index] ^= lazy[index] * ((end - start + 1) % 2);

		if (start != end)
		{
			lazy[index * 2 + 1] ^= lazy[index];
			lazy[index * 2 + 2] ^= lazy[index];
		}
		lazy[index] = 0;
	}
}

// left에서 right까지의 xor을 구하여 반환한다.
int get_xor(int index, int start, int end, int left, int right)
{
	propagation(index, start, end);

	if (left > end || right < start)
		return 0;
	else if (left <= start && right >= end)
		return tree[index];
	else
	{
		int mid = (start + end) / 2;
		return get_xor(index * 2 + 1, start, mid, left, right) 
			^ get_xor(index * 2 + 2, mid + 1, end, left, right);
	}
}

// value를 lazy[index]에 넣고 propagation
int update(int index, int start, int end, int left, int right, int value)
{
	propagation(index, start, end);

	if (left > end || right < start)
		return tree[index];
	else if (left <= start && right >= end)
	{
		tree[index] ^= value * ((end - start + 1) % 2);

		if (start != end)
		{
			lazy[index * 2 + 1] ^= value;
			lazy[index * 2 + 2] ^= value;
		}
		return tree[index];
	}
	int mid = (start + end) / 2;

	return tree[index] = update(index * 2 + 1, start, mid, left, right, value)
		^ update(index * 2 + 2, mid+1, end, left, right, value);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	make_tree(0, 0, n - 1);
		
	int query, a, b, c;

	for (int i = 0; i < m; i++)
	{
		cin >> query;
		if (query == 1)
		{
			cin >> a >> b >> c;
			if (a > b) swap(a, b);
			update(0, 0, n - 1, a, b, c);
		}
		else
		{
			cin >> a >> b;
			if (a > b) swap(a, b);
			cout << get_xor(0, 0, n - 1, a, b) << '\n';
		}
	}

	return 0;
}
