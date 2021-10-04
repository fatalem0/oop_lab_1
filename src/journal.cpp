#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <sstream>
#include "../include/journal.h"

std::vector<std::string> split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::move(item));
    }
    return elems;
}

int compareDates(const std::string& firstDate, const std::string& secondDate) {
    // if left is later than right it returns 1
    // if right is later than left it returns -1
    // otherwise it returns 0
    if (firstDate == secondDate) {
        return 0;
    }
    int firstYear = std::stoi(firstDate.substr(6, 4));
    int secondYear = std::stoi(secondDate.substr(6, 4));
    if (firstYear > secondYear) {
        return 1;
    }
    if (secondYear > firstYear) {
        return -1;
    }
    int firstMonth = std::stoi(firstDate.substr(3, 2));
    int secondMonth = std::stoi(secondDate.substr(3, 2));
    if (firstMonth > secondMonth) {
        return 1;
    }
    if (secondMonth > firstMonth) {
        return -1;
    }
    int firstDay = std::stoi(firstDate.substr(0, 2));
    int secondDay = std::stoi(secondDate.substr(0, 2));
    if (firstDay > secondDay) {
        return 1;
    }
    if (secondDay > firstDay) {
        return -1;
    }
    return 0;
}

int determineWeek(const int& day) {
    if (day <= 28 && day >= 22) {
        return 4;
    }
    if (day <= 21 && day >= 15) {
        return 3;
    }
    if (day >= 8 && day <= 14) {
        return 2;
    }
    return 1;
}

Journal::Journal(int size) {
    records = new Record*[size];
    current = 0;
    capacity = size;
}

Journal::Journal(const Journal& journal) {
    records = new Record*[journal.size()];
    for (int i = 0; i < journal.size(); i++) {
        records[i] = new Record(journal.get(i));
    }
    capacity = journal.size();
    current = journal.size();
}

Journal::Journal() {
    capacity = 2;
    records = new Record*[2];
    current = 0;
}

Journal::~Journal() {
    delete[] records;
}

void Journal::add(Record* record) {
    if (current == capacity) {
        Record** temporary = new Record*[2 * capacity];
        for (int i = 0; i < capacity; i++) {
            temporary[i] = records[i];
        }
        delete[] records;
        capacity *= 2;
        records = temporary;
    }
    records[current] = record;
    current++;
}

void Journal::add(Record* record, int index) {
    if (current == capacity) {
        Record** temporary = new Record*[2 * capacity];
        for (int i = 0; i < capacity; i++) {
            temporary[i] = records[i];
            delete[] records[i];
        }
        delete[] records;
        capacity *= 2;
        records = temporary;
    }
    if (index > current) {
        add(record);
        return;
    }
    for (int i = current; i >= index - 1; i--) {
        records[i + 1] = records[i];
    }
    current++;
    this->records[index] = record;
}

void Journal::remove() {
    this->current--;

}

void Journal::remove(int index) {
    if (index > current - 1) {
        return;
    }
    for (int i = index; i < current - 1; i++) {
        records[i] = records[i + 1];
    }
    current--;
}

int Journal::size() const {
    return current;
}

Record& Journal::operator[](int index) {
    return (*(records[index]));
}

Record& Journal::get(int index) const {
    return *(records[index]);
}

void Journal::clear() {
    current = 0;
}

void Journal::print() {
    for (int i = 0; i < current; i++) {
        std::cout << records[i]->toString() << std::endl;
    }
}

void Journal::dumpToFile(const std::string& filename) const {
    std::ofstream outfile;
    outfile.open(filename);
    outfile << serializeToString();
    outfile.close();
}

void Journal::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> elems = split(line, ';');
            Record* record = new Record(elems[1], elems[2], elems[3], elems[4], std::stoi(elems[5]));
            std::cout << record->toString() << std::endl;
            add(record);
        }
        file.close();
    }
}

bool Journal::checkDates() {
    if (current == 0 || current == 1) {
        return true;
    }
    for (int i = 1; i < this->current; i++) {
        std::string firstDate = records[i]->getDate();
        std::string secondDate = records[i - 1]->getDate();
        int dateDiff = compareDates(firstDate, secondDate);
        if (dateDiff == -1) {
            return false;
        }
    }
    return true;
}

bool Journal::checkErrors() const {

    return true;
}
std::string Journal::serializeToString() const {
    std::string result = "";
    for (int i = 0; i < current; i++) {
        result += records[i]->getType();
        result += ";";
        result += records[i]->toString();
        if (i < current - 1) {
            result += "\n";
        }
    }
    return result;
}

bool Journal::operator==(const Journal &otherJournal) const {
    if (size() != otherJournal.size()) {
        return false;
    }
    for(int i = 0; i < this->size(); i++) {
        if (!(get(i) == otherJournal.get(i))) {
            return false;
        }
    }
    return true;
}

void printJournal(const Journal& journal) {
    for (int i = 0; i < journal.size(); i++) {
        std::cout << journal.get(i).toString() << std::endl;
    }
}