#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	bool upper = true;
	string sarcasm;
	for (int i = 1; i < argc; i++) {
		string word = argv[i];
		for (int i2 = 0; i2 <= word.length(); i2++) {
			if (upper) {
				sarcasm.push_back(toupper(word[i2]));
			}
			else {
				sarcasm.push_back(tolower(word[i2]));
			}
			upper = not upper;
		}
		if (i + 1 != argc) {
			sarcasm.push_back(' ');
		}
	}
	cout << "\"" << sarcasm << "\"";
	return 0;
}