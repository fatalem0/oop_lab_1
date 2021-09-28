#ifndef RECORD_H
#define RECORD_H
#include <string>
#define DATE "13:00:41"
#define FULL_NAME "Kyro Sao"
#define POSITION "Director"
#define ACD_DEGREE "PHD"
#define IMPACT 5
#define DATE_1 "22:11:21"
#define FULL_NAME_1 "Ilya Vibe"
#define POSITION_1 "Engineer"
#define ACD_DEGREE_1 "MCS"
#define IMPACT_1 3
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

    ~Record() {

    } ;
private:
    std::string date;
    std::string fullName;
    std::string position;
    std::string acd_degree;
    int impact;
};
bool operator==(const Record& r1, const Record& r2);
#endif
