#include "advancedstats.h"
#include <QStringList>
#include <QRegularExpression>

advancedstats::advancedstats() {}

advancedstats:: ~advancedstats() {
    clearList();
}

void advancedstats::clearList()
{
    node*curr = head;
    while (curr != nullptr) {
        node *next = curr -> next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}

void advancedstats::addWord(const QString &word)
{
    QString s = word.toLower();

    node *act = head;
    node *prev = nullptr;
    while (act != nullptr) {
        if (act -> word == s) {
            act -> count++;
            return;
        }
        prev = act;
        act = act -> next;
    }
    node *new_ = new node(s);
    if  (prev != nullptr) prev -> next = new_;
    else head = new_;
}

void advancedstats::analyze(const QString &text)
{
    stats::analyze(text);
    clearList();
    QStringList wordsList = text.split(QRegularExpression("[^\\p{L}]+"), Qt::SkipEmptyParts);
    for (const QString &w : wordsList)
        addWord(w);
}

QString advancedstats::raport() const
{
    QString base = stats::raport();
    QString duplicatedWords = "\n\nRepeating words (2 times or more): \n";
    node *act = head;
    while (act != nullptr) {
        if (act -> count >= 2)
            duplicatedWords += QString("Word: %1 - Times: %2\n").arg(act->word).arg(act->count);
    act = act -> next;
    }
    return base + duplicatedWords;
}
