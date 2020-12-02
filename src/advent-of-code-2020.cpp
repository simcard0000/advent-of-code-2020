#include <iostream>
#include <vector>
#include <ctype.h>
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

int day2A() {
	int answer = 0;
	vector<string> passwords;
	//reading in the input:
	string line;
	while (getline(cin, line)){
		passwords.push_back(line);
	}
	//counting the number of valid passwords:
	int size = (int) passwords.size();
	for (int i = 0; i < size; i++){
		int placeholder = 0;
		int low;
		int high;
		char letter;
		string password;
		string create;

		while (isdigit(passwords[i].at(placeholder))){
			create += passwords[i].at(placeholder);
			placeholder++;
		}
		low = atoi(create.c_str());
		placeholder++;
		create.clear();
		while (isdigit(passwords[i].at(placeholder))){
			create += passwords[i].at(placeholder);
			placeholder++;
		}
		high = atoi(create.c_str());
		placeholder++;

		letter = passwords[i].at(placeholder);
		placeholder += 3;
		password = passwords[i].substr(placeholder).c_str();

		int length = (int) password.length();
		int counter = 0;
		for (int j = 0; j < length; j++){
			if (password.at(j) == letter){
				counter++;
			}
		}
		if (counter >= low && counter <= high){
			answer++;
		}
	}
	return answer;
}

int day2B() {
	int answer = 0;
	vector<string> passwords;
	//reading in the input:
	string line;
	while (getline(cin, line)){
		passwords.push_back(line);
	}
	//counting the number of valid passwords:
	int size = (int) passwords.size();
	for (int i = 0; i < size; i++){
		int placeholder = 0;
		int firstPos;
		int lastPos;
		char letter;
		string password;
		string create;

		while (isdigit(passwords[i].at(placeholder))){
			create += passwords[i].at(placeholder);
			placeholder++;
		}
		firstPos = atoi(create.c_str());
		placeholder++;
		create.clear();
		while (isdigit(passwords[i].at(placeholder))){
			create += passwords[i].at(placeholder);
			placeholder++;
		}
		lastPos = atoi(create.c_str());
		placeholder++;

		letter = passwords[i].at(placeholder);
		placeholder += 3;
		password = passwords[i].substr(placeholder).c_str();

		firstPos--;
		lastPos--;
		bool atFirstPos = false;
		bool atLastPos = false;
		if (password.at(firstPos) == letter){
			atFirstPos = true;
		}
		if (password.at(lastPos) == letter){
			atLastPos = true;
		}
		if ((!atFirstPos && atLastPos) || (atFirstPos && !atLastPos) ){
			answer++;
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
	//int day2A_answer = day2A();
	//int day2B_answer = day2B();
	//cout << "day1A answer: " + to_string(day1A_answer) << endl;
	//cout << "day1B answer: " + to_string(day1B_answer) << endl;
	//cout<< "day2A answer: " + to_string(day2A_answer) << endl;
	//cout << "day2B answer: " + to_string(day2B_answer) << endl;
	return 0;
}
