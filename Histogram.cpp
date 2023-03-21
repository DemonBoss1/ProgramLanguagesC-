#include "main.h"

void createHistogram(char* str) {
    vector <char> words;
    char* techstr = str;
    while (*techstr != '\0')
    {
        if (find(words.begin(), words.end(), *techstr) == words.end()) words.push_back(*techstr);
        techstr++;
    }
    vector <int> histogram;
    techstr = str;
    histogram.resize(words.size());
    for (int i = 0; i < words.size(); i++)
        histogram[i] = 0;
    while (*techstr != '\0')
    {
        int i = 0;
        while (*techstr != words[i]) {
            i++;

        }
        histogram[i]++;
        techstr++;
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