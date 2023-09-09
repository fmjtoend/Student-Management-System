#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date(const string& dateStr) {
        istringstream iss(dateStr);
        char delimiter;
        iss >> year >> delimiter >> month >> delimiter >> day;
    }

    bool isAdult() const {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);
        struct tm timeinfo;
        localtime_s(&timeinfo, &currentTime);
        int currentYear = timeinfo.tm_year + 1900;

        int age = currentYear - year;

        // ����·ݺ������Ƿ��ѹ�
        if (timeinfo.tm_mon + 1 < month || (timeinfo.tm_mon + 1 == month && timeinfo.tm_mday < day)) {
            age--;
        }

        return age >= 18;
    }

    int calculateAge() const {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);
        struct tm timeinfo;
        localtime_s(&timeinfo, &currentTime);
        int currentYear = timeinfo.tm_year + 1900;

        int age = currentYear - year;

        // ����·ݺ������Ƿ��ѹ�
        if (timeinfo.tm_mon + 1 < month || (timeinfo.tm_mon + 1 == month && timeinfo.tm_mday < day)) {
            age--;
        }

        return age;
    }
};