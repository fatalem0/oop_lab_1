#include "../include/record.h"

Record::Record() {
    date = "";
    fullName = "";
    position = "";
    acd_degree = "";
    impact = 0;
}

Record::Record(const std::string& date, const std::string& fullName, const std::string& position,
               const std::string& acd_degree, int impact) {
    if (not Record::checkDate(date)) {
        throw std::exception();
    }
    this->date = date;
    this->fullName = fullName;
    this->position = position;
    this->acd_degree = acd_degree;
    this->impact= impact;
}

Record::Record(const Record& record) {
    date = record.date;
    fullName = record.fullName;
    position = record.position;
    acd_degree = record.acd_degree;
    impact = record.impact;
}

const std::string& Record::getDate() const {
    return this->date;
}

const std::string& Record::getFullName() const {
    return this->fullName;
}

const std::string& Record::getPosition() const {
    return this->position;
}

const std::string& Record::getAcdDegree() const {
    return this->acd_degree;
}

int Record::getImpact() const {
    return this->impact;
}

void Record::setDate(const std::string& newDate) {
    if (not checkDate(newDate)) {
        throw std::exception();
    }
    this->date = newDate;
}

void Record::setFullName(const std::string& newName) {
    this->fullName = newName;
}

void Record::setPosition(const std::string& newPosition) {
    this->position = newPosition;
}

void Record::setAcdDegree(const std::string& newAcdDegree) {
    this->acd_degree = newAcdDegree;
}

void Record::setImpact(int newImpact) {
    this->impact = newImpact;
}

const bool Record::checkDate(const std::string& date) {
    if (date.length() != 8) {
        return false;
    }
    int hour = std::stoi(date.substr(0,2));
    if (hour < 0 || hour > 23) {
        return false;
    }
    int minute = std::stoi(date.substr(3, 2));
    if (minute < 0 || minute > 59) {
        return false;
    }
    int second = std::stoi(date.substr(6, 2));
    if (second < 0 || second > 59) {
        return false;
    }
    return true;
}

std::string Record::toString() const {
    return date + ';' + fullName + ';' + position + ';' + acd_degree + ';' + std::to_string(impact);
}

std::string Record::getType() const {
    return "Record";
}

bool operator==(const Record& r1, const Record& r2) {
    return r1.getImpact() == r2.getImpact()
           && r1.getDate() == r2.getDate()
           && r1.getFullName() == r2.getFullName()
           && r1.getPosition() == r2.getPosition()
           && r1.getAcdDegree() == r2.getAcdDegree();
}