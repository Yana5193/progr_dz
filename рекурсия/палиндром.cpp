#include <iostream>
#include<string>
using namespace std;
bool palindrom(string s, int left, int right) {
	if (left >= right)
		return true;
	if (s[left] != s[right])
		return false;
	return palindrom(s, left + 1, right - 1);

}
int main()
{
	string s;
	getline(cin, s);
	if (palindrom(s, 0, s.length() - 1))
		cout<< "YES";
	else
	cout << "NO";
	return 0;
}

