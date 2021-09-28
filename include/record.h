#ifndef RECORD_H
#define RECORD_H
#include <string>
class Record {
public:
    Record();
    Record(const std::string& date, const std::string& fullName, const std::string& position,
           const std::string& acd_degree, int impact);
    Record(const Record& record);

    const std::string& getDate() const;
    const std::string& getFullName() const;
    const std::string& getPosition() const;
    const std::string& getAcdDegree() const;
    int getImpact() const;

    void setDate(const std::string& newDate);
    void setFullName(const std::string& newName);
    void setPosition(const std::string& newPosition);
    void setAcdDegree(const std::string& newAcdDegree);
    void setImpact(int newImpact);

    const bool checkDate(const std::string& date);

    ~Record() = default;
private:
    std::string date;
    std::string fullName;
    std::string position;
    std::string acd_degree;
    int impact;
};
bool operator==(const Record& r1, const Record& r2);
#endif
