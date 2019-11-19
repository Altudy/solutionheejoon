#include <iostream>	// 백준 1188
using namespace std;

int main()
{
	float fsausage, fpeople, cut(0);
	int sausage, people;
	float eat, rest(1);
	cin >> fsausage >> fpeople;

	eat = fsausage / fpeople;

	sausage = static_cast <int> (fsausage);
	people = static_cast <int> (fpeople);

	sausage %= people;		// 소시지를 인당 한 개 이상 먹는거면 일단 한 개씩 나눠줌.
	
	if (sausage == people) {
		cout << cut;
		return 0;
	}

	while (people > 1) {
		while (rest > eat) {			// 자르고 나눠줌
			cut += sausage;
			people -= sausage;
			rest -= eat;
		}
		while (sausage > people) {		// 하나씩 나눠줌
			sausage -= people;
			eat -= rest;
		}
		if (sausage == people) break;
	}	
	cout << cut;
	return 0;
}
