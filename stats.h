#ifndef STATS_H
#define STATS_H

#include <QString>

class stats
{  
protected:
    int paragraphs = 0;
    int words = 0;
    int letters = 0;
    int chars = 0;
    static const int alphabetSize = 26;
    int frequency[alphabetSize] = {0};
    void reset();

public:
    stats();
    virtual void analyze(const QString &text);
    virtual ~stats() {};
    int paragraphsCount() const {
        return paragraphs;
    }
    int wordsCount() const {
        return words;
    }
    int lettersCount() const {
        return letters;
    }
    int charsCount() const {
        return chars;
    }

    const int* lettersFreq() const {
        return frequency;
    }
    virtual QString raport() const;
};


#endif // STATS_H
