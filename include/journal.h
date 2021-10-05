#ifndef OOP_LAB_1_JOURNAL_H
#define OOP_LAB_1_JOURNAL_H


#include "record.h"
#include <vector>

class Journal {
public:
    Journal(int size);

    Journal(const Journal &journal);

    Journal();

    ~Journal();

    void add(Record* record);

    void add(Record* record, int position);

    void remove(int index);

    void remove();

    void print();

    bool checkDates();

    int size() const;

    Record& operator [](int index);

    Record& get(int index) const;

    void clear();

    void dumpToFile(const std::string& filename) const;

    void loadFromFile(const std::string& filename);

    bool checkDates() const;

    bool checkErrors() const;

    bool operator==(const Journal &otherJournal) const;
private:
    Record **records;

    int capacity;

    int current;

    std::string serializeToString() const;
};

void printJournal(const Journal& journal);

#endif //OOP_LAB_1_JOURNAL_H