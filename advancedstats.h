#ifndef ADVANCEDSTATS_H
#define ADVANCEDSTATS_H

#include "stats.h"
#include "node.h"

class advancedstats : public stats
{
public:
    advancedstats();
    ~advancedstats();

    void analyze(const QString &text) override;
    QString raport() const override;

private:
    node* head = nullptr;
    void addWord(const QString &word);
    void clearList();
};

#endif // ADVANCEDSTATS_H
