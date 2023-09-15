#ifndef Frequencies_h
#define Frequencies_h
#include <fstream>

class Frequencies {
    
public:
    /*
     * Author: Ally Oh
     * Function letterFreq combs through an open text file with flag std::ios::in, keeps a count
     * of how often each character occurs and how many letters there are total, and calculates their frequencies.
     * It returns a pointer to a float array of size 26 containing the frequencies for each letter in
     * alphabetical order.
     */
    float * const letterFreq(std::fstream&);

    /*
     * Author: Ally Oh
     * Create a nicely formatted string to be used to display letter frequencies.
     */
    std::string const letFreqString(float[], std::string);
};

#endif
