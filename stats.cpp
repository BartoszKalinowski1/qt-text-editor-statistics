#include "stats.h"
#include <QStringList>
#include <QRegularExpression>

stats::stats() {}

void stats::reset()
{
    paragraphs=words=letters=chars=0;
    for (int i=0; i<alphabetSize; ++i)
        frequency[i]=0;
}

void stats::analyze(const QString &text)
{
    reset();

    chars = text.length();
    QStringList listParagraphs = text.split('\n', Qt::SkipEmptyParts);
    paragraphs = listParagraphs.size();
    QStringList listWords = text.split(QRegularExpression("[^\\p{L}]+"), Qt::SkipEmptyParts);
    words = listWords.size();

    for (const QChar &c : text) {
        if (c.isLetter()) {
            letters++;
            QChar lower = c.toLower();
            if (lower.unicode() >= 'a' && lower.unicode() <= 'z')
                frequency[lower.unicode() - 'a']++;
        }
    }
}
QString stats::raport() const
{
    return QString("Paragraphs: %1\nWords: %2\nLetters: %3\nChars: %4").arg(paragraphs).arg(words).arg(letters).arg(chars);
}
