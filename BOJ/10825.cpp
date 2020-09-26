#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Student {
public:
	string name;
	int kor;
	int eng;
	int math;
};

bool comp(Student a, Student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) return a.name < b.name;
			else return a.math > b.math;
		}
		else return a.eng < b.eng;
	}
	return a.kor > b.kor;
}

int main() {
	int N;
	cin >> N;
	vector<Student> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}
	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++) {
		cout << v[i].name << '\n';
	}

	return 0;
}