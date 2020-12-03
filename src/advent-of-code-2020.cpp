#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

void day1A () {
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
	cout << "day1A answer: " << answer << endl;
}

//similar to day1A
void day1B () {
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
	cout << "day1B answer: " << answer << endl;
}

void day2A() {
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
	cout << "day2A answer: " << answer << endl;
}

void day2B() {
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
		if ((!atFirstPos && atLastPos) || (atFirstPos && !atLastPos)){
			answer++;
		}
	}
	cout << "day2B answer: " << answer << endl;
}

void day3A(){
	int answer = 0;
	string line;
	vector<string> tobogganMap;
	//reading input
	while (getline(cin, line)){
		string withoutNewLine = line.substr(0, line.size() - 1);
		tobogganMap.push_back(withoutNewLine);
	}
	//calculate how many times we have to repeat initial map to the right
	int size = (int) tobogganMap.size();
	int lastPos = ((3 * size) - 3) + 1;
	int lineSize = tobogganMap[0].length();
	int repeat = 0;
	int lineSizeCount = 0;
	while(true){
		if ((lineSizeCount <= lastPos) && ((lineSizeCount + lineSize) >= lastPos)){
			break;
		}
		lineSizeCount += lineSize;
		repeat++;
	}
	//creating final map:
	for (int i = 0; i < size; i++){
		string toAppend = tobogganMap[i];
		for (int j = 0; j < repeat; j++){
			tobogganMap[i].append(toAppend);
		}
	}
	//calculating the amount of trees we'd run into:
	int pos = 0;
	for (int i = 1; i < size; i++){
		pos += 3;
		if (tobogganMap[i].at(pos) == '#'){
			answer++;
		}
	}
	cout << "day3A answer: " << answer << endl;
}

void day3B() {
	long long answer = 0;
	string line;
	vector<string> tobogganMap;
	//reading input
	while (getline(cin, line)){
		string withoutNewLine = line.substr(0, line.size() - 1);
		tobogganMap.push_back(withoutNewLine);
	}
	//calculate how many times we have to repeat initial map to the right
	int size = (int) tobogganMap.size();
	int lastPos = ((7 * size) - 7) + 1;
	int lineSize = tobogganMap[0].length();
	int repeat = 0;
	int lineSizeCount = 0;
	while(true){
		if ((lineSizeCount <= lastPos) && ((lineSizeCount + lineSize) >= lastPos)){
			break;
		}
		lineSizeCount += lineSize;
		repeat++;
	}
	//creating final map:
	for (int i = 0; i < size; i++){
		string toAppend = tobogganMap[i];
		for (int j = 0; j < repeat; j++){
			tobogganMap[i].append(toAppend);
		}
	}
	//calculating the amount of trees we'd run into with different paths:
	long long right1down1 = 0;
	long long right3down1 = 0;
	long long right5down1 = 0;
	long long right7down1 = 0;
	long long right1down2 = 0;
	int pos = 0;
	// right 1 down 1 path
	for (int i = 1; i < size; i++){
		pos++;
		if (tobogganMap[i].at(pos) == '#'){
			right1down1++;
		}
	}
	pos = 0;
	// right 3 down 1 path
	for (int i = 1; i < size; i++){
		pos += 3;
		if (tobogganMap[i].at(pos) == '#'){
			right3down1++;
		}
	}
	pos = 0;
	// right 5 down 1 path
	for (int i = 1; i < size; i++){
		pos += 5;
		if (tobogganMap[i].at(pos) == '#'){
			right5down1++;
		}
	}
	pos = 0;
	// right 7 down 1 path
	for (int i = 1; i < size; i++){
		pos += 7;
		if (tobogganMap[i].at(pos) == '#'){
			right7down1++;
		}
	}
	pos = 0;
	// right 1 down 2 path
	for (int i = 2; i < size; i += 2){
		pos++;
		if (tobogganMap[i].at(pos) == '#'){
			right1down2++;
		}
	}
	answer = right1down1 * right3down1 * right5down1 * right7down1 * right1down2;
	cout << "day3B answer: " << answer << endl;
}

int main() {
	//Uncomment the function you want to test!

	//day1A();
	//day1B();
	//day2A();
	//day2B();
	//day3A();
	//day3B();

	return 0;
}
