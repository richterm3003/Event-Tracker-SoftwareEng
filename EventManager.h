#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Event {
    string name;
    string date;
    string month;
    string day;
    string year;
    string time;
};
extern vector<string> months31;
extern vector<string> months30;
extern vector<string> monthsFeb;
extern vector<Event> events;

bool validateDate(string month, string day, string year);
void createEvent();
void listEvents();
void sortDates();
void sortNames();
void sortEvents();
void mainMenu();
string toLowerCase(string str);
