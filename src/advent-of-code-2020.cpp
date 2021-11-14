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

void day7AHelper(string search, vector<string> *validBags, map<string, map<string, int>> luggageRules) {
	vector<string> found;
	for (map<string, map<string, int>>::iterator i = luggageRules.begin(); i != luggageRules.end(); i++){
		int check = 0;
		try {
			check = i->second.at(search);
		} catch (std::out_of_range){
			check = 0;
		}
		if (check != 0){
			found.push_back(i->first);
		}
	}
	for (int i = 0; i < (int) found.size(); i++){
		bool alreadyHasValue = false;
		for (int j = 0; j < (int) validBags->size(); j++){
			if (validBags->at(j) == found[i]){
				alreadyHasValue = true;
				break;
			}
		}
		if (!alreadyHasValue){
			validBags->push_back(found[i]);
			day7AHelper(found[i], validBags, luggageRules);
		}
	}
}

void day7A(){
	int answer = 0;
	map<string, map<string, int>> luggageRules;
	//reading input:
	string line;
	while(getline(cin, line)) {
		vector<string> storeWordsInLine;
		size_t pos = 0;
		string delimiter = " ";
		while((pos = line.find(delimiter)) != string::npos){
			string subPart = line.substr(0, pos);
			storeWordsInLine.push_back(subPart);
			line.erase(0, pos + delimiter.length());
		}
		string bagName = storeWordsInLine[0] + storeWordsInLine[1];
		map<string, int> bagsInside;
		if (storeWordsInLine[4].find("no") == 0) {
			luggageRules.insert(pair<string, map<string, int>>(bagName, bagsInside));
		} else {
			for (int i = 4; i < (int) storeWordsInLine.size(); i+= 4){
				int amount = atoi(storeWordsInLine[i].c_str());
				string bagIn = storeWordsInLine[i+1] + storeWordsInLine[i+2];
				bagsInside.insert(pair<string, int>(bagIn, amount));
			}
			luggageRules.insert(pair<string, map<string, int>>(bagName, bagsInside));
		}
	}

	//finding bags that can hold a specific bag:
	vector<string> validBags;
	day7AHelper("shinygold", &validBags, luggageRules);
	answer = (int) validBags.size();
	cout << "day7A answer: " << answer << endl;
}

int day7BHelper(string search, map<string, map<string, int>> luggageRules){
	int answer = 0;
	for (map<string, int>::iterator i = luggageRules.at(search).begin(); i != luggageRules.at(search).end(); i++){
		int specBag = day7BHelper(i->first, luggageRules);
		answer += (i->second + i->second * specBag);
	}
	return answer;
}

void day7B() {
	int answer = 0;
	map<string, map<string, int>> luggageRules;
	//reading input:
	string line;
	while(getline(cin, line)) {
		vector<string> storeWordsInLine;
		size_t pos = 0;
		string delimiter = " ";
		while((pos = line.find(delimiter)) != string::npos){
			string subPart = line.substr(0, pos);
			storeWordsInLine.push_back(subPart);
			line.erase(0, pos + delimiter.length());
		}
		string bagName = storeWordsInLine[0] + storeWordsInLine[1];
		map<string, int> bagsInside;
		if (storeWordsInLine[4].find("no") == 0) {
			luggageRules.insert(pair<string, map<string, int>>(bagName, bagsInside));
		} else {
			for (int i = 4; i < (int) storeWordsInLine.size(); i+= 4){
				int amount = atoi(storeWordsInLine[i].c_str());
				string bagIn = storeWordsInLine[i+1] + storeWordsInLine[i+2];
				bagsInside.insert(pair<string, int>(bagIn, amount));
			}
			luggageRules.insert(pair<string, map<string, int>>(bagName, bagsInside));
		}
	}
	//getting answer:
	answer = day7BHelper("shinygold", luggageRules);
	cout << "day7B answer: " << answer << endl;
}
void day8A() {
	int answer = 0;
	//reading in input:
	string line;
	vector<string> bootCodes;
	vector<bool> visitedBootCodes;
	while(getline(cin, line)){
		bootCodes.push_back(line);
	}
	//walking through boot codes:
	visitedBootCodes.resize((int) bootCodes.size(), false);
	int iterator = 0;
	while (true) {
		string code = bootCodes[iterator];
		if (visitedBootCodes.at(iterator) == true){
			break;
		} else {
			visitedBootCodes.at(iterator) = true;
			int value = atoi(code.substr(4).c_str());
			if (code.find("acc") == 0){
				answer += value;
				iterator++;
			} else if (code.find("jmp") == 0){
				iterator += value;
			} else if (code.find("nop") == 0){
				iterator++;
			}
		}
	}
	cout << "day8A answer: " << answer << endl;
}

void day8B() {
	int answer = 0;
	//reading in input:
	string line;
	vector<string> bootCodes;
	vector<bool> visitedBootCodes;
	while(getline(cin, line)){
		bootCodes.push_back(line);
	}
	//walking through boot codes:
	visitedBootCodes.resize((int) bootCodes.size(), false);
	int iterator = 0;
	int looped = 0;
	vector<pair<string, int>> prevCodes;
	bool cementCodes = false;
	string ogCode;
	int ogIt;
	while (true) {
		if (iterator >= (int) bootCodes.size()){
			break;
		}
		string code = bootCodes[iterator];
		if (visitedBootCodes.at(iterator) == true){
			looped++;
			if (looped >= 2){
				bootCodes[ogIt] = ogCode;
			} else if (looped == 1){
				cementCodes = true;
			}
			string switchTo;
			int getIt;
			while (true){
				getIt = prevCodes[prevCodes.size() - looped].second;
				if (prevCodes[prevCodes.size() - looped].first.find("jmp") == 0) {
					switchTo = "nop";
					break;
				} else if (prevCodes[prevCodes.size() - looped].first.find("nop") == 0){
					switchTo = "jmp";
					break;
				} else if (prevCodes[prevCodes.size() - looped].first.find("acc") == 0){
					looped++;
				}
			}
			ogCode = bootCodes[getIt];
			ogIt = getIt;
			bootCodes[getIt] = switchTo + bootCodes[getIt].substr(3);
			iterator = 0;
			answer = 0;
			visitedBootCodes.clear();
			visitedBootCodes.resize((int) bootCodes.size(), false);
		} else {
			if (!cementCodes){
				prevCodes.push_back(pair<string, int>(code, iterator));
			}
			visitedBootCodes.at(iterator) = true;
			int value = atoi(code.substr(4).c_str());
			if (code.find("acc") == 0){
				answer += value;
				iterator++;
			} else if (code.find("jmp") == 0){
				iterator += value;
			} else if (code.find("nop") == 0){
				iterator++;
			}
		}
	}
	cout << "day8B answer: " << answer << endl;
}

void day9A() {
	int answer = 0;
	vector<int> XMASinput;
	vector<int> preamble;
	preamble.resize(25);
	//getting input
	string line;
	while(getline(cin, line)){
		XMASinput.push_back(atoi(line.c_str()));
	}
	//setting up preamble
	for (int i = 0; i < 25; i++){
		preamble[i] = XMASinput[i];
	}
	//checking rest of XMASinput after preamble
	int size = (int) XMASinput.size();
	for (int i = 25; i < size; i++){
		int value = XMASinput[i];
		bool checkVal = false;
		for (int j = 0; j < 25; j++) {
			int k = j+1;
			while (k != 25){
				if ((preamble[j] + preamble[k]) == value && (preamble[j] != preamble[k])){
					checkVal = true;
					break;
				}
				k++;
			}
			if (checkVal) {
				break;
			}
		}
		if (!checkVal){
			answer = value;
			break;
		} else {
			//shifting preamble over
			for (int l = 0; l < 25; l++){
				if (l == 24){
					preamble[l] = value;
				} else {
					preamble[l] = preamble[l+1];
				}
			}
		}
	}
	cout << "day9A answer: " << answer << endl;
}

void day9B() {
	int answer = 0;
	int invalid = 0;
	vector<int> XMASinput;
	vector<int> preamble;
	preamble.resize(25);
	//getting input
	string line;
	while(getline(cin, line)){
		XMASinput.push_back(atoi(line.c_str()));
	}
	//setting up preamble
	for (int i = 0; i < 25; i++){
		preamble[i] = XMASinput[i];
	}
	//checking rest of XMASinput after preamble
	int size = (int) XMASinput.size();
	for (int i = 25; i < size; i++){
		int value = XMASinput[i];
		bool checkVal = false;
		for (int j = 0; j < 25; j++) {
			int k = j+1;
			while (k != 25){
				if ((preamble[j] + preamble[k]) == value && (preamble[j] != preamble[k])){
					checkVal = true;
					break;
				}
				k++;
			}
			if (checkVal) {
				break;
			}
		}
		if (!checkVal){
			invalid = value;
			break;
		} else {
			//shifting preamble over
			for (int l = 0; l < 25; l++){
				if (l == 24){
					preamble[l] = value;
				} else {
					preamble[l] = preamble[l+1];
				}
			}
		}
	}
	//finding a contiguous set of numbers that sum to the invalid number
	int testNum = 0;
	vector<int> inRange;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			testNum += XMASinput[i + j];
			inRange.push_back(XMASinput[i + j]);
			if (testNum == invalid){
				sort(inRange.begin(), inRange.end());
				answer = inRange[0] + inRange[inRange.size() - 1];
				break;
			} else if (testNum > invalid){
				inRange.clear();
				testNum = 0;
				break;
			}
		}
		if (answer != 0){
			break;
		}
	}
	cout << "day9B answer: " << answer << endl;
}

void day10A(){
	int answer = 0;
	vector<int> adapters;
	int deviceJoltage = 0;
	int count1Diff = 0;
	int count3Diff = 0;
	//reading input:
	string line;
	while (getline(cin, line)){
		adapters.push_back(atoi(line.c_str()));
	}
	//adding charging outlet to list:
	adapters.push_back(0);
	//finding the device built-in joltage:
	sort(adapters.begin(), adapters.end());
	deviceJoltage = adapters[adapters.size() - 1] + 3;
	adapters.push_back(deviceJoltage);
	//counting the differences:
	int size = (int) adapters.size();
	for (int i = 0; i < size - 1; i++){
		int diff = (adapters[i + 1] - adapters[i]);
		if (diff == 1){
			count1Diff++;
		} else if (diff == 3){
			count3Diff++;
		}
	}
	answer = count1Diff * count3Diff;
	cout << "day10A answer: " << answer << endl;
}

//not that efficient:
long long day10BHelper1(vector<int> adapters, int iterator) {
	int answer = 0;
	int valAt = adapters[iterator];
	if (iterator == (int) adapters.size() - 1){
		return 1;
	} else {
		for (int i = 1; i <= 3; i++){
			int nextVal;
			try {
				nextVal = adapters.at(iterator + i);
			} catch (std::out_of_range) {
				nextVal = 0;
			}
			int difference = nextVal - valAt;
			if (difference == 1 || difference == 2 || difference == 3){
				answer += day10BHelper1(adapters, iterator + i);
			}
		}
		return answer;
	}
}

//DP: based on digtydoo's Python solution here: https://www.reddit.com/r/adventofcode/comments/ka8z8x/2020_day_10_solutions/
long long day10BHelper2(vector<int> adapters) {
	long long answer = 0;
	map<int, long long> paths;
	int size = (int) adapters.size();
	int max = adapters[adapters.size() - 1];
	for (int i = 0; i <= max; i++){
		paths.insert(pair<int, int>(i, 0));
	}
	paths.at(0) = 1;
	for (int i = 0; i < size; i++){
		for (int j = 1; j <= 3; j++){
			int next = adapters[i] + j;
			bool isInside = false;
			for (int k = 0; k < size; k++){
				if (adapters[k] == next){
					isInside = true;
					break;
				}
			}
			if (isInside){
				paths.at(next) += paths.at(adapters[i]);
			}
		}
	}
	answer = paths.at(max);
	return answer;
}

void day10B() {
	long long answer = 0;
	vector<int> adapters;
	int deviceJoltage = 0;
	//reading input:
	string line;
	while (getline(cin, line)){
		adapters.push_back(atoi(line.c_str()));
	}
	//adding charging outlet to list:
	adapters.push_back(0);
	//finding the device built-in joltage:
	sort(adapters.begin(), adapters.end());
	deviceJoltage = adapters[adapters.size() - 1] + 3;
	adapters.push_back(deviceJoltage);
	//finding the total amount of possibilities of connection:
	answer = day10BHelper2(adapters);
	cout << "day10B answer: " << answer << endl;
}

long long day11AHelper(vector<vector<char>> seatingPlan) {
	vector<pair<pair<int, int>, char>> coordinates;
	//changing the seat grid:
	bool compare = false;
	int occupiedAdjacentCounter = 0;
	pair<int, int> nums(0 , 0);
	while (!compare) {
		for (int i = 0; i < (int) seatingPlan.size(); i++) {
			for (int j = 0; j < (int) seatingPlan[i].size(); j++) {
				occupiedAdjacentCounter = 0;
				if (i != 0) {
					if (j != 0 && seatingPlan.at(i-1).at(j-1) == '#'){
						occupiedAdjacentCounter++;
					}
					if (seatingPlan.at(i-1).at(j) == '#') {
						occupiedAdjacentCounter++;
					}
					if (j != (int) seatingPlan[i].size() - 1 && seatingPlan.at(i-1).at(j+1) == '#') {
						occupiedAdjacentCounter++;
					}
				}
				if (j != 0) {
					if (seatingPlan.at(i).at(j-1) == '#') {
						occupiedAdjacentCounter++;
					}
					if (i != (int) seatingPlan.size() - 1 && seatingPlan.at(i+1).at(j-1) == '#') {
						occupiedAdjacentCounter++;
					}
				}
				if (j != (int) seatingPlan[i].size() - 1 && seatingPlan.at(i).at(j+1) == '#') {
					occupiedAdjacentCounter++;
				}

				if (i != (int) seatingPlan.size() - 1 && seatingPlan.at(i+1).at(j) == '#') {
					occupiedAdjacentCounter++;
				}
				if (i != (int) seatingPlan.size() - 1 && j != (int) seatingPlan[i].size() - 1 && seatingPlan.at(i+1).at(j+1) == '#') {
					occupiedAdjacentCounter++;
				}
				nums.first = i;
				nums.second = j;
				if (occupiedAdjacentCounter >= 4 && seatingPlan.at(i).at(j) == '#') {
					coordinates.push_back(pair<pair<int, int>, char>(nums, 'L'));
				} else if (occupiedAdjacentCounter == 0 && seatingPlan.at(i).at(j) == 'L'){
					coordinates.push_back(pair<pair<int, int>, char>(nums, '#'));
				}
			}
		}
		cout << "we get here" << endl;
		if (coordinates.empty()) {
			compare = true;
		} else {
			for (int i = 0; i < (int) coordinates.size(); i++) {
				seatingPlan.at(coordinates.at(i).first.first).at(coordinates.at(i).first.second) = coordinates.at(i).second;
			}
		}
		coordinates.clear();
	}
	//counting the number of occupied seats:
	long long occupiedCounter = 0;
	for (int i = 0; i < (int) seatingPlan.size(); i++) {
		for (int j = 0; j < (int) seatingPlan[i].size(); j++) {
			if (seatingPlan.at(i).at(j) == '#') {
				occupiedCounter++;
			}
		}
	}
	return occupiedCounter;
}

void day11A() {
	long long answer = 0;
	//reading input:
	vector<vector<char>> seatingPlan;
	vector<char> seatingLine;
	string line;
	while (getline(cin, line)){
		for (int i = 0; i < (int) line.length(); i++){
			seatingLine.push_back(line[i]);
		}
		seatingPlan.push_back(seatingLine);
		seatingLine.clear();
	}
	//calling helper function:
	answer = day11AHelper(seatingPlan);
	cout << "day11A answer: " << answer << endl;
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
	//day7A();
	//day7B();
	//day8A();
	//day8B();
	//day9A();
	//day9B();
	//day10A();
	//day10B();
	day11A();

	return 0;
}
