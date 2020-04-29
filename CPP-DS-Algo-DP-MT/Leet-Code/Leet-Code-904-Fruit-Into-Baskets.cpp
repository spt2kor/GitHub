#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.com/problems/fruit-into-baskets/submissions/

int totalFruit(vector<int>& tree) {
	int size = tree.size();
	if (size <= 2)
		return size;

	int count = 0, max = -1;
	int t1 = 0, t2 = 0, t2s = -1;
	for (int i = 0; i<size; )
	{
		count = 0;
		t1 = tree[i], t2 = -1, t2s = -1;
		for (int j = i; j<size; ++j)
		{
			if ((t1 == tree[j]) || (tree[j] == t2)) {
				++count;
			}
			else if (t2 == -1) {
				t2 = tree[j]; ++count;
				t2s = j;
			}
			else
				j = size;
		}
		if (count > max)
			max = count;
		if (t2s != -1)
			i = t2s;
		else
			break;
	}
	return max;
}

int main()
{
	vector<int> tree = { 3,3,3,1,2,1,1,2,3,3,4};
	cout << "\n ans = " << totalFruit(tree) << endl;
	return 0;

}