#include <iostream>
#include "graph.h"
#include "io.h"
using namespace seneca;
// prints samples error message
void samplesFirst() {
    cout << "Number of Samples must be set first!" << endl;
}

int main(void) {
    int noOfSamples = 0;
    int samples[seneca::MAX_NO_OF_S] = { 0 };
    bool done = false;
    seneca::labelLine(33, "Welcome to SeneGraph");
    while (!done) {
        switch (menu(noOfSamples)) {
        case 1:
            cout << "Enter number of available samples: ";
            noOfSamples = seneca::getInt(1, seneca::MAX_NO_OF_S);
            break;
        case 2:
            if (noOfSamples == 0) {
                samplesFirst();
            }
            else {
                cout << "Please enter the sample values: " << endl;
                getSamples(samples, noOfSamples);
            }
            break;
        case 3:
            if (noOfSamples == 0) {
               samplesFirst();
            }
            else if (samples[0] == 0) {
                cout << "Samples missing. Please enter the sample values!" << endl;
            }
            else {
                printGraph(samples, noOfSamples, " SeneGraph ");
            }
            break;
        case 0:
            cout << "Thanks for using SeneGraph" << endl;
            done = true;
        }
    }
    return 0;
}
