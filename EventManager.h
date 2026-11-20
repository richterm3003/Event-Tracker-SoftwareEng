#pragma once
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
    string description;
};
extern vector<string> months31;
extern vector<string> months30;
extern vector<string> monthsFeb;
extern vector<Event> events;

bool validateDate(string month, string day, string year);
void createEvent();
void listEvents();
void sortDates();
void deleteEvent();
void editEvent();
void sortNames();
void sortEvents();
void mainMenu();
string shortenDescription(string description);
string toLowerCase(string str);