#include <iostream>
#include <vector>
using namespace std;

int day1A () {
	int answer = 0;
	vector<int> entries;
	//reading in the input:
	string line;
	while (getline(cin, line)){
		entries.push_back(atoi(line.c_str()));
	}
	//finding the two entries that sum to 2020:
	int size = (int) entries.size();
	for (int i = 0; i < size; i++) {
		int j = i+1;
		while (j != size){
			if ((entries[i] + entries[j]) == 2020){
				answer = entries[i] * entries[j];
				break;
			}
			j++;
		}
		if (answer != 0){
			break;
		}
	}
	return answer;
}

//similar to day1A
int day1B () {
	int answer = 0;
	vector<int> entries;
	//reading in the input:
	string line;
	while (getline(cin, line)){
		entries.push_back(atoi(line.c_str()));
	}
	//finding the three entries that sum to 2020:
	int size = (int) entries.size();
	for (int i = 0; i < size; i++) {
		vector<int> subset = entries;
		subset.erase(subset.begin()+i);
		int size2 = (int) subset.size();
		for (int j = 0; j < size2; j++){
			int k = j+1;
			while (k != size2){
				if ((entries[i] + subset[j] + subset[k]) == 2020){
					answer = entries[i] * subset[j] * subset[k];
					break;
				}
				k++;
			}
			if (answer != 0){
				break;
			}
		}
		if (answer != 0){
			break;
		}
	}
	return answer;
}

int main() {
	/* Functions for printing answers out,
	 * comment out function and print statements
	 * respectively.
	 */

	//int day1A_answer = day1A();
	//int day1B_answer = day1B();
	//cout << "day1A answer: " + to_string(day1A_answer) << endl;
	//cout << "day1B answer: " + to_string(day1B_answer) << endl;
	return 0;
}
