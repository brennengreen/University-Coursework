// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> reverse(const vector<int>& v)
{
	vector<int> vR;
	for (int i = 0; i < v.size(); i++)
	{
		int buf = v.pop_back();
		vR.push_back(buf);
	}
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int> vR = reverse(v);

	system("PAUSE");
	return 0;
}
