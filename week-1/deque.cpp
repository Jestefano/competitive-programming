#include<bits/stdc++.h>
using namespace std;

int main(){

	//O(1)
	deque<int> d;

	d.push_front(10);
	d.push_back(13);
	d.push_front(2);
	d.push_back(3);

	cout<<d.front()<<" "<<d.back()<<endl;

	d.pop_front();
	d.pop_back();

	cout<<d.front()<<" "<<d.back()<<endl;

	cout<<d.size()<<endl;

	cout<<d.empty()<<endl;

	cout<<d[1]<<endl;

	return 0;
}