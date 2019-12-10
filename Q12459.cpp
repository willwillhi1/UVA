#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count = 0,len;
	int i,j,num_ancestor;
	while(scanf("%d",&num_ancestor))
	{
		if(num_ancestor == 0) break;
		vector<int> a;
		a.push_back(1);
		for(i = 1;i < num_ancestor;i++)
		{
			len = a.size();
			for(j = 0;j < len;j++)
			{
				if(a[0] == 0)
				{
					a.erase(a.begin());
					a.push_back(1);
				}
				else if(a[0] == 1)
				{
					a.erase(a.begin());
					a.push_back(0);
					a.push_back(1);
				}
			}
		}
		cout << a.size() << endl;
	}
}
