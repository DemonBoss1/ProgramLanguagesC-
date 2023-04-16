#include "main.h"

void createHistogram(string str) {
    vector <char> words;
    string techstr = str;
    int j = 0;
    while (techstr[j] != '\0')
    {
        if (find(words.begin(), words.end(), techstr[j]) == words.end()) words.push_back(techstr[j]);
        j++;
    }
    vector <int> histogram;
    techstr = str;
    histogram.resize(words.size());
    for (int i = 0; i < words.size(); i++)
        histogram[i] = 0;
    j = 0;
    while (techstr[j] != '\0')
    {
        int i = 0;
        while (techstr[j] != words[i]) {
            i++;

        }
        histogram[i]++;
        j++;
    }
    vector <string> histogramString;
    histogramString.resize(histogram.size());
    for (int i = 0; i < histogram.size(); i++) {
        int length = histogram[i];
        histogramString[i] = "";
        for (int j = 0; j < length; j++)
            histogramString[i] += 2;
    }
    for (int i = 0; i < words.size(); i++)
        cout << words[i] << " " << histogramString[i] << endl;
}