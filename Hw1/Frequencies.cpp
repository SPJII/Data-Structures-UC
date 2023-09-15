#include "Frequencies.h"
#include <fstream>
#include <string>

/* 
 * Author: Ally Oh
 * Function letterFreq combs through an open text file with flag std::ios::in, keeps a count 
 * of how often each character occurs and how many letters there are total, and calculates their frequencies.
 * It returns a pointer to a float array of size 26 containing the frequencies for each letter in 
 * alphabetical order.
 */
float * const Frequencies::letterFreq(std::fstream& text) {
	int total = 0;
	static float letFreqs[26] = { 0 };

	while (!text.eof()) {

		char a = text.get();

		// If lowercase, capitalize
		if (a > 90)
			a -= 32;

		// Add current char to the tally, using number representations of chars 
		// (65-90 for uppercase and 97-122 for lowercase) in a for loop
		for (char i = 65; i <= 90; i++) {
			if (i == a) {
				letFreqs[i - 65]++;
				total++;
				break;
			}
		}

	}
	// Calculate the frequencies.
	for (int i = 0; i < 26; i++) {
		letFreqs[i] /= total;
	}

	return letFreqs;
}

/*
 * Author: Ally Oh
 * Create a nicely formatted string to be used to display letter frequencies.
 */
std::string const Frequencies::letFreqString(float freqs[], std::string title) {
	std::string str = title + " letter frequency:\n";

	for (char a = 65; a <= 90; a++) {
		str = str + a + ": " + std::to_string(freqs[a - 65]) + "%\n";
	}
	return str;
}

//int main() {
//	//test those methods out
//	std::fstream stream;
//	stream.open("test.txt", std::ios::in);
//	float f[26] = { 0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.0,
//				   0.11,0.12,0.13,0.14,0.15,0.16,0.17,0.18,0.19,0.2,
//				   0.21,0.22,0.23,0.24,0.25,0.26 };
//	std::cout << letFreqString(letterFreq(stream), "Moby Dick");
//}
