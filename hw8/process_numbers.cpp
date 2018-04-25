#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
	ifstream file("rand_numbers.txt");
	vector<int> nums;
	copy(istream_iterator<int>(file),istream_iterator<int>(),back_inserter(nums));
	sort(nums.begin(),nums.end());
	//for_each(nums.begin(),nums.end(),[](int n){cout << n << endl; });
	ofstream odd("odd.txt");
	ofstream even("even.txt");
	for_each(nums.begin(),nums.end(),[&](int& n){n % 2 == 0? even << n << "\n":odd << n << "\n";});
	return 0;
}
