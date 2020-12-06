#include <iostream>
#include <vector>
#include <map>
#include <ctype.h>
#include <math.h>
#include <algorithm>
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

void day4A(){
	int answer = 0;
	//reading input:
	vector<map<string, string>> allPassports;
	string line;
	map<string, string> passport;
	string delimiter1 = " ";
	string delimiter2 = ":";
	while(getline(cin, line)){
		if (line.find(delimiter2) == string::npos){
			allPassports.push_back(passport);
			passport.clear();
		} else {
			size_t pos = 0;
			string pairPart;
			while((pos = line.find(delimiter1)) != string::npos){
				pairPart = line.substr(0, pos);
				string key = pairPart.substr(0, pairPart.find(delimiter2));
				string value = pairPart.erase(0, pairPart.find(delimiter2));
				value.erase(0, 1);
				passport.insert(pair<string, string>(key, value));
				line.erase(0, pos + delimiter1.length());
			}
			string key = line.substr(0, line.find(delimiter2));
			string value = line.erase(0, line.find(delimiter2));
			value.erase(0, 1);
			value.erase(value.length()-1);
			passport.insert(pair<string, string>(key, value));
		}
	}
	allPassports.push_back(passport);
	//counting which passports are valid:
	bool hasBYR = false;
	bool hasIYR = false;
	bool hasEYR = false;
	bool hasHGT = false;
	bool hasHCL = false;
	bool hasECL = false;
	bool hasPID = false;
	int size = (int) allPassports.size();
	for (int i = 0; i < size; i++){
		if (allPassports[i].count("byr") == 1){
			hasBYR = true;
		}
		if (allPassports[i].count("iyr") == 1){
			hasIYR = true;
		}
		if (allPassports[i].count("eyr") == 1){
			hasEYR = true;
		}
		if (allPassports[i].count("hgt") == 1){
			hasHGT = true;
		}
		if (allPassports[i].count("hcl") == 1){
			hasHCL = true;
		}
		if (allPassports[i].count("ecl") == 1){
			hasECL = true;
		}
		if (allPassports[i].count("pid") == 1){
			hasPID = true;
		}
		if (hasBYR && hasIYR && hasEYR && hasHGT && hasHCL && hasECL && hasPID){
			answer++;
		}
		hasBYR = false;
		hasIYR = false;
		hasEYR = false;
		hasHGT = false;
		hasHCL = false;
		hasECL = false;
		hasPID = false;
	}
	cout << "day4A answer: " << answer << endl;
}

void day4B() {
	int answer = 0;
	//reading input:
	vector<map<string, string>> allPassports;
	string line;
	map<string, string> passport;
	string delimiter1 = " ";
	string delimiter2 = ":";
	while(getline(cin, line)){
		if (line.find(delimiter2) == string::npos){
			allPassports.push_back(passport);
			passport.clear();
		} else {
			size_t pos = 0;
			string pairPart;
			while((pos = line.find(delimiter1)) != string::npos){
				pairPart = line.substr(0, pos);
				string key = pairPart.substr(0, pairPart.find(delimiter2));
				string value = pairPart.erase(0, pairPart.find(delimiter2));
				value.erase(0, 1);
				passport.insert(pair<string, string>(key, value));
				line.erase(0, pos + delimiter1.length());
			}
			string key = line.substr(0, line.find(delimiter2));
			string value = line.erase(0, line.find(delimiter2));
			value.erase(0, 1);
			value.erase(value.length()-1);
			passport.insert(pair<string, string>(key, value));
		}
	}
	allPassports.push_back(passport);
	//counting which passports are valid:
	bool hasBYR = false;
	bool validBYR = false;
	bool hasIYR = false;
	bool validIYR = false;
	bool hasEYR = false;
	bool validEYR = false;
	bool hasHGT = false;
	bool validHGT = false;
	bool hasHCL = false;
	bool validHCL = false;
	bool hasECL = false;
	bool validECL = false;
	bool hasPID = false;
	bool validPID = false;
	int size = (int) allPassports.size();
	for (int i = 0; i < size; i++){
		if (allPassports[i].count("byr") == 1){
			hasBYR = true;
			int num = atoi(allPassports[i].at("byr").c_str());
			if ((num >= 1920) && (num <= 2002)){
				validBYR = true;
			}
		}
		if (allPassports[i].count("iyr") == 1){
			hasIYR = true;
			int num = atoi(allPassports[i].at("iyr").c_str());
			if ((num >= 2010) && (num <= 2020)){
				validIYR = true;
			}
		}
		if (allPassports[i].count("eyr") == 1){
			hasEYR = true;
			int num = atoi(allPassports[i].at("eyr").c_str());
			if ((num >= 2020) && (num <= 2030)){
				validEYR = true;
			}
		}
		if (allPassports[i].count("hgt") == 1){
			hasHGT = true;
			string units = allPassports[i].at("hgt").substr(allPassports[i].at("hgt").length() - 2);
			int num = atoi(allPassports[i].at("hgt").substr(0, allPassports[i].at("hgt").length() - 2).c_str());
			if (units == "cm"){
				if (num >= 150 && num <= 193){
					validHGT = true;
				}
			} else if (units == "in"){
				if (num >= 59 && num <= 76){
					validHGT = true;
				}
			}
		}
		if (allPassports[i].count("hcl") == 1){
			hasHCL = true;
			string hair = allPassports[i].at("hcl");
			int charCount = 0;
			bool hasHashtag = false;
			if (hair[0] == '#') {
				hasHashtag = true;
			}
			for (int i = 1; i < (int)hair.length(); i++){
				if (isalnum(hair[i])){
					charCount++;
				}
			}
			if (charCount == ((int)hair.length() - 1) && hasHashtag){
				validHCL = true;
			}
		}
		if (allPassports[i].count("ecl") == 1){
			hasECL = true;
			string eyeColour = allPassports[i].at("ecl");
			if (eyeColour == "amb" || eyeColour == "blu" || eyeColour == "brn"
					|| eyeColour == "gry" || eyeColour == "grn"
		            || eyeColour == "hzl" || eyeColour == "oth"){
				validECL = true;
			}
		}
		if (allPassports[i].count("pid") == 1){
			hasPID = true;
			string numPID = allPassports[i].at("pid");
			int countChar = 0;
			int length = (int) numPID.length();
			for (int i = 0; i < length; i++){
				if (isdigit(numPID[i])){
					countChar++;
				}
			}
			if ((length == 9) && (countChar == length)){
				validPID = true;
			}
		}
		if (hasBYR && hasIYR && hasEYR && hasHGT && hasHCL && hasECL && hasPID
				&& validBYR && validIYR && validEYR && validHGT && validHCL && validECL && validPID){
			answer++;
		}
		hasBYR = false;
		validBYR = false;
		hasIYR = false;
		validIYR = false;
		hasEYR = false;
		validEYR = false;
		hasHGT = false;
		validHGT = false;
		hasHCL = false;
		validHCL = false;
		hasECL = false;
		validECL = false;
		hasPID = false;
		validPID = false;
	}
	cout << "day4B answer: " << answer << endl;
}

void day5A(){
	int answer = 0;
	vector<string> seats;
	//reading input:
	string line;
	while(getline(cin, line)){
		seats.push_back(line);
	}
	//finding highest seat ID:
	int size = (int) seats.size();
	for (int i = 0; i < size; i++){
		int maxRow = 127;
		int minRow = 0;
		int maxCol = 7;
		int minCol = 0;
		for (int j = 0; j < 10; j++){
			if (seats[i][j] == 'F'){
				maxRow = minRow + ((maxRow - minRow)/2);
			} else if (seats[i][j]== 'B'){
				minRow += (int) ceil((double)(maxRow - minRow)/2);
			} else if (seats[i][j] == 'L'){
				maxCol = minCol + ((maxCol - minCol)/2);
			} else if (seats[i][j] == 'R'){
				minCol += (int) ceil((double)(maxCol - minCol)/2);
			}
		}
		int seatID = (maxRow * 8) + maxCol;
		if (seatID > answer){
			answer = seatID;
		}
	}
	cout << "day5A answer: " << answer << endl;
}

void day5B() {
	int answer = 0;
	vector<string> seats;
	vector<int> seatIDs;
	//reading input:
	string line;
	while(getline(cin, line)){
		seats.push_back(line);
	}
	//finding highest seat ID:
	int size = (int) seats.size();
	for (int i = 0; i < size; i++){
		int maxRow = 127;
		int minRow = 0;
		int maxCol = 7;
		int minCol = 0;
		for (int j = 0; j < 10; j++){
			if (seats[i][j] == 'F'){
				maxRow = minRow + ((maxRow - minRow)/2);
			} else if (seats[i][j]== 'B'){
				minRow += (int) ceil((double)(maxRow - minRow)/2);
			} else if (seats[i][j] == 'L'){
				maxCol = minCol + ((maxCol - minCol)/2);
			} else if (seats[i][j] == 'R'){
				minCol += (int) ceil((double)(maxCol - minCol)/2);
			}
		}
		int seatID = (maxRow * 8) + maxCol;
		seatIDs.push_back(seatID);
	}
	sort(seatIDs.begin(), seatIDs.end());
	for (int i = 0; i < (int) seatIDs.size(); i++){
		if (seatIDs[i + 1] - seatIDs[i] == 2){
			answer = seatIDs[i] + 1;
			break;
		}
	}
	cout << "day5B answer: " << answer << endl;
}

void day6A(){
	int answer = 0;
	map<char, bool> questions;
	for (int i = 0; i < 26; i++){
		questions.insert(pair<char, bool>(static_cast<char>(97+i), false));
	}
	vector<vector<string>> groupAnswers;
	vector<string> group;
	string line;
	//reading input:
	while(getline(cin, line)){
		if (!isalpha(line[0])){
			groupAnswers.push_back(group);
			group.clear();
		} else {
			group.push_back(line);
		}
	}
	groupAnswers.push_back(group);
	int size = (int) groupAnswers.size();
	//counting questions answered yes in each group:
	for (int i = 0; i < size; i++){
		int groupSize = (int) groupAnswers[i].size();
		int counter = 0;
		for (int j = 0; j < groupSize; j++){
			int lineSize = (int) groupAnswers[i][j].length();
			for (int k = 0; k < lineSize; k++){
				char ans = groupAnswers[i][j][k];
				if (isalpha(ans)){
					if (questions.at(ans) == false){
						questions.at(ans) = true;
						counter++;
					}
				}
			}
		}
		answer += counter;
		questions.clear();
		for (int j = 0; j < 26; j++){
			questions.insert(pair<char, bool>(static_cast<char>(97+j), false));
		}
	}
	cout << "day6A answer: " << answer << endl;
}

void day6B() {
	int answer = 0;
	map<char, int> questions;
	for (int i = 0; i < 26; i++){
		questions.insert(pair<char, bool>(static_cast<char>(97+i), 0));
	}
	vector<vector<string>> groupAnswers;
	vector<string> group;
	string line;
	//reading input:
	while(getline(cin, line)){
		if (!isalpha(line[0])){
			groupAnswers.push_back(group);
			group.clear();
		} else {
			group.push_back(line);
		}
	}
	groupAnswers.push_back(group);
	int size = (int) groupAnswers.size();
	//counting questions answered yes in each group:
	for (int i = 0; i < size; i++){
		int groupSize = (int) groupAnswers[i].size();
		int counter = 0;
		for (int j = 0; j < groupSize; j++){
			int lineSize = (int) groupAnswers[i][j].length();
			for (int k = 0; k < lineSize; k++){
				char ans = groupAnswers[i][j][k];
				if (isalpha(ans)){
					questions.at(ans) += 1;
				}
			}
		}
		for (int j = 0; j < 26; j++){
			if (questions.at(static_cast<char>(97 + j)) == groupSize){
				counter++;
			}
		}
		answer += counter;
		questions.clear();
		for (int j = 0; j < 26; j++){
			questions.insert(pair<char, bool>(static_cast<char>(97+j), false));
		}
	}
	cout << "day6B answer: " << answer << endl;
}

int main() {
	//Uncomment the function you want to test!

	//day1A();
	//day1B();
	//day2A();
	//day2B();
	//day3A();
	//day3B();
	//day4A();
	//day4B();
	//day5A();
	//day5B();
	//day6A();
	//day6B();

	return 0;
}
