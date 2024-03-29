#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v;

	v.push_back(21);		// 마지막 원소 뒤에 21을 삽입합니다.
	v.push_back(32);		// 마지막 원소 뒤에 32을 삽입합니다.
	v.push_back(53);		// 마지막 원소 뒤에 53을 삽입합니다.
	v.push_back(64);		// 마지막 원소 뒤에 64을 삽입합니다.
	v.push_back(15);		// 마지막 원소 뒤에 15을 삽입합니다.


	// ex1) 멤버형식 size_type 이용한 반복.
	cout << "ex1-1 [v.at(i)] size_type: ";
	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl << endl;

    // ex2) int i 를 이용한 반복.
    cout << "ex2-1) [v.at(i)] int : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "ex2-2) [ v[i] ] int : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;


    // ex3) 반복자 iterator를 이용한 반복. 
    cout << "ex3) [*iter] iterator : ";
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << endl << endl;


    return 0;
}