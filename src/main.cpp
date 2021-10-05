#include <iostream>
#include "../include/record.h"
#include "../include/journal.h"
#include <cassert>

int main() {
    std::cout << "start tests" << std::endl;

    Record defaultRecord = Record();
    Record record = Record(DATE, FULL_NAME, POSITION, ACD_DEGREE, IMPACT);
    Record copyRecord = Record(record);

    assert(defaultRecord.getDate() == "");
    assert(defaultRecord.getFullName() == "");
    assert(defaultRecord.getPosition() == "");
    assert(defaultRecord.getAcdDegree() == "");
    assert(defaultRecord.getImpact() == 0);
    std::cout << "default constructor test was done" << std::endl;

    assert(record.getDate() == DATE);
    assert(record.getFullName() == FULL_NAME);
    assert(record.getPosition() == POSITION);
    assert(record.getAcdDegree() == ACD_DEGREE);
    assert(record.getImpact() == IMPACT);
    std::cout << "initialization constructor test was done" << std::endl;

    assert(copyRecord.getDate() == DATE);
    assert(copyRecord.getFullName() == FULL_NAME);
    assert(copyRecord.getPosition() == POSITION);
    assert(copyRecord.getAcdDegree() == ACD_DEGREE);
    assert(copyRecord.getImpact() == IMPACT);
    std::cout << "copy constructor test was done" << std::endl;

    assert(record == copyRecord);
    std::cout << "independence after copy constructor test was done" << std::endl;

    copyRecord.setDate(DATE_1);
    assert(copyRecord.getDate() == DATE_1);
    copyRecord.setFullName(FULL_NAME_1);
    assert(copyRecord.getFullName() == FULL_NAME_1);
    copyRecord.setPosition(POSITION_1);
    assert(copyRecord.getPosition() == POSITION_1);
    copyRecord.setAcdDegree(ACD_DEGREE_1);
    assert(copyRecord.getAcdDegree() == ACD_DEGREE_1);
    copyRecord.setImpact(IMPACT_1);
    assert(copyRecord.getImpact() == IMPACT_1);
    std::cout << "getter and setter test was done" << std::endl;

    Journal journal = Journal(5);
    journal.add(new Record("22:55:55", "Ivan Ivanov", "headteacher", "bachelor", 3));
    journal.dumpToFile("example.txt");
    Journal another = Journal();
    another.loadFromFile("example.txt");
    printJournal(another);
    std::cout << "All tests completed without errors" << std::endl;
    return 0;
}
