#include "io.h"
#include "graph.h"
#include "StMark.h"

// prints a graph comparing the sample values visually 
void seneca::printGraph(int samples[], int noOfSamples, const char* label) {
    int max = findMax(samples, noOfSamples);
    labelLine(GRAPH_WIDTH + 14, label);
    for (int i = 0; i < noOfSamples; i++) {
        printRange(noOfSamples - i);
        printBar(samples[i], max);
    }
    line(GRAPH_WIDTH + 14);
}

// prints the int value in width of fieldWidth
void seneca::printInt(int value, int fieldWidth) {
    cout << value;
    for (int i = 0; i < fieldWidth - intDigits(value); i++) {
        cout << " ";
    }
}

// if the user enters non digit values, the function will hang in an endless loop.
int seneca::getInt(int min, int max) {
    int val = min - 1;
    bool done = false;
    while (!done) {
        cin >> val;
        if (val < min || val > max) {
            cout << "Invalid value!" << endl << "The value must be between " << min << " and " << max << ": ";
        }
        else {
            done = true;
        }
    }
    return val;
}

// moves the cursor backwards
void seneca::goBack(int n) {
    for (int i = 0; i < n; cout << "\b", i++);
}

// displays the user interface menu
int seneca::menu(int noOfSamples) {
    line(28);
    cout << "| No Of Samples: ";
    printInt(noOfSamples, 5);
    cout << "     |" << endl;
    line(28);
    cout << "| 1- Set Number of Samples |" << endl;
    cout << "| 2- Enter Samples         |" << endl;
    cout << "| 3- Graphs                |" << endl;
    cout << "| 0- Exit                  |" << endl;
    cout << "\\ >                        /";
    goBack(24);

    return getInt(0, 3);
}

// prints a scaled bar relevant to the maximum value in samples array
void seneca::printBar(int val, int max) {
    int i;
    int barlength = GRAPH_WIDTH * val / max;
    cout << "| ";
    for (i = 0; i < barlength; i++) {
        cout << "*";
    }
    cout << " ";
    printInt(val, (GRAPH_WIDTH + 6 - barlength));
    cout << "|" << endl;
}

// draw line
void seneca::labelLine(int n, const char* label) {
    cout << "+";
    for (int i = 0; i < n - 2; cout << "-", i++);
    cout << "+";
    if (label) {
        goBack(n - 4);
        cout << label;
    }
    cout << endl;
}

// draws a line
void seneca::line(int n) {
    cout << "+";
    for (int i = 0; i < n - 2; cout << "-", i++);
    cout << "+";
    cout << endl;
}

// display formattedd students data
void seneca::displayStdData(struct StMark* stdArray, int size) {

    for (int i = 0; i < size; i++) {
        if (i + 1 < 10) {
            std::cout << i + 1 << "  :" << " " << "[" << stdArray[i].mark;
            if (stdArray[i].mark == 100) {
                std::cout << "] " << stdArray[i].name << " " << stdArray[i].surname << std::endl;
            }
            else if (stdArray[i].mark < 100) {
                std::cout << " ] " << stdArray[i].name << " " << stdArray[i].surname << std::endl;
            }
        }
        else if (i + 1 >= 100) {
            // organize to display aligned
            if (stdArray[i].mark < 10) {
                std::cout << i + 1 << ":" << " " << "[" << stdArray[i].mark << "  ] " << stdArray[i].name << " " << stdArray[i].surname << std::endl;
            }
            else {
                std::cout << i + 1 << ":" << " " << "[" << stdArray[i].mark << " ] " << stdArray[i].name << " " << stdArray[i].surname << std::endl;
            }
        }
        else {
            std::cout << i + 1 << " :" << " " << "[" << stdArray[i].mark << " ] " << stdArray[i].name << " " << stdArray[i].surname << std::endl;
        }
    }
}

// print range reference before print stars
void seneca::printRange(int index) {
    if (index < 10) {
        cout << (index * 10) << "  ";
    }
    else if (index >= 10 && index < 100) {
        cout << index * 10 << " ";
    }
    else {
        cout << index * 10;
    }
}

