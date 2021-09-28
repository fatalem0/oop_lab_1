#include <iostream>
#include "../include/record.h"
#include <cassert>

int main() {
    std::cout << "start tests" << std::endl;

    Record defaultRecord = Record();
    Record record = Record("13:00:41", "Kyro Sao", "Director", "PHD", 5);
    Record copyRecord = Record(record);

    assert(defaultRecord.getDate() == "");
    assert(defaultRecord.getFullName() == "");
    assert(defaultRecord.getPosition() == "");
    assert(defaultRecord.getAcdDegree() == "");
    assert(defaultRecord.getImpact() == 0);
    std::cout << "default constructor test was done" << std::endl;

    assert(record.getDate() == "13:00:41");
    assert(record.getFullName() == "Kyro Sao");
    assert(record.getPosition() == "Director");
    assert(record.getAcdDegree() == "PHD");
    assert(record.getImpact() == 5);
    std::cout << "initialization constructor test was done" << std::endl;

    assert(copyRecord.getDate() == "13:00:41");
    assert(copyRecord.getFullName() == "Kyro Sao");
    assert(copyRecord.getPosition() == "Director");
    assert(copyRecord.getAcdDegree() == "PHD");
    assert(copyRecord.getImpact() == 5);
    std::cout << "copy constructor test was done" << std::endl;

    assert(record == copyRecord);
    std::cout << "independence after copy constructor test was done" << std::endl;

    copyRecord.setDate("22:11:21");
    assert(copyRecord.getDate() == "22:11:21");
    copyRecord.setFullName("Ilya Vibe");
    assert(copyRecord.getFullName() == "Ilya Vibe");
    copyRecord.setPosition("Engineer");
    assert(copyRecord.getPosition() == "Engineer");
    copyRecord.setAcdDegree("MCS");
    assert(copyRecord.getAcdDegree() == "MCS");
    copyRecord.setImpact(3);
    assert(copyRecord.getImpact() == 3);
    std::cout << "getter and setter test was done" << std::endl;

    std::cout << "All tests completed without errors" << std::endl;
    return 0;
}
