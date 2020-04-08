#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;
int const OFFSET = 26;
int main() {
	ifstream inData;
	ofstream outData;
	
	inData.open("cipher_text.txt");
	outData.open("plain_text.txt");
	if (!inData) {
		cout << "cant find";
		return 1;
	}

	string inputfile;
	getline(inData, inputfile);
	int length = inputfile.length();

	vector<char>cipherText;

	//Convert ciphertext's content into uppercase
	for (int i{ 0 }; i < length - 1; ++i) {
		if (static_cast<int>(inputfile.at(i)) >= 97) {
			cipherText.push_back(inputfile.at(i) - 32);
		}
		else
			cipherText.push_back(inputfile.at(i));
	}
	
	vector<char>plaintext;
	
	// decrypted the ciphertext using shift cipher method
	for (int offset{ 1 }; offset <= OFFSET; ++offset) {
		cout << "offset: " << offset << endl;
		outData << "offset" << offset << endl;
		for (int i{ 0 }; i < length - 1; ++i) {
			char text = cipherText.at(i);
			if (cipherText.at(i) >= 'A' && cipherText.at(i) <= 'Z') {
				text = (text + offset -65) % 26 +65 ;
				plaintext.push_back(text);
			}
			else
				plaintext.push_back(text);
		}
		for (int i{ 0 }; i < plaintext.size(); ++i) {
			cout << plaintext.at(i);
			outData << plaintext.at(i);
		}
		outData << endl;
		cout << endl;
		plaintext.clear();
	}
	inData.close();
	outData.close();
	system("pause");
	return 0;
}