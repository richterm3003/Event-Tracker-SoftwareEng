#include "EventManager.h"
#include <cctype>

vector<string> months31 = {"01", "03", "05", "07", "08", "10", "12"};
vector<string> months30 = {"04", "06", "09", "11"};
vector<string> monthsFeb = {"02"};

vector<Event> events;


bool validateDate(string month, string day, string year) {
    for (int i = 0; i < 2; i++)
    {
        if (!isdigit(month[i]))
        {
            cout << "Invalid month. Please enter a 2-digit month." << endl;
            return false;
        }
        if (!isdigit(day[i]))
        {
            cout << "Invalid day. Please enter a 2-digit day." << endl;
            return false;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (!isdigit(year[i]))
        {
            cout << "Invalid year. Please enter a 4-digit year." << endl;
            return false;
        }
    }
     
    if(month.length() != 2 || day.length() != 2 || year.length() != 4) {
        cout << "Invalid date format. Please use MM DD YYYY." << endl;
        return false;
    }
    else if(month < "01" || month > "12") {
        cout << "Invalid month. Please enter a value between 01 and 12." << endl;
        return false;
    }
    else if(day < "01" || day > "31") {
        cout << "Invalid day. Please enter a value between 01 and 31." << endl;
        return false;
    }
    else if(year < "2026" || year > "2100") {
        cout << "Invalid year. Please enter a value between 2026 and 2100." << endl;
        return false;
    }



    // Check for months with 30 days
    for(int i=0; i<months30.size(); i++) {
        if(month == months30[i] && day == "31") {
            cout << "Invalid date. " << month << " has only 30 days." << endl;
            return false;
        }
    }
    // Checking for February and leap years
    if(month == "02" && day > "28") {
        int yearNumber = stoi(year);
        if(yearNumber % 4 == 0 && (yearNumber % 100 != 0 || yearNumber % 400 == 0)) {
            if(day == "29") {
                return true; // Leap year
            } else {
                cout << "Invalid date. February has only 29 days in a leap year." << endl;
                return false;
            }
        }
        cout << "Invalid date. February has only 28 days." << endl;
        return false;
    }

    return true;
}

void createEvent()
{ 
    std::cout << "Enter the event name: ";
    string eventName;
    cin.ignore();
    getline(cin, eventName);
    std::cout << "Enter the event date (MM DD YYYY): ";
    string month, day, year;
    cin >> month >> day >> year;
    string eventDate = month + "/" + day + "/" + year;
    string eventDay = day;
    string eventMonth = month;
    string eventYear = year;
    while (!validateDate(month, day, year)) {
        std::cout << "Enter the event date (MM DD YYYY): ";
        cin >> month >> day >> year;
        eventDate = month + "/" + day + "/" + year;
        validateDate(month, day, year);
    }
    std::cout << "Enter the event time in military format (HH:MM): ";
    string eventTime;
    cin >> eventTime;
    std::cout << "Event '" << eventName << "' has been created." << std::endl;
    events.push_back({eventName, eventDate, eventDay, eventMonth, eventYear, eventTime});
    mainMenu();
}
void listEvents()
{
    if (events.empty())
    {
        cout << "No events to display." << endl;
    } 
    else
    {
        for (const auto& event : events)
        {
            cout << "Event: " << event.name << ", Date: " << event.date << ", Time: " << event.time << endl;
        }
    }
    sortEvents();
}
void sortDates() {
bool swapped = true;
            while(swapped)
            {
                swapped = false;
                for (int i = 0; i < events.size(); i++)
                {
                    int j = i + 1;
                    if (j < events.size()) 
                    {
                        if (events[i].year > events[j].year)
                        {
                            cout << "Swapping events: " << events[i].name << " and " << events[j].name << endl;
                            swap(events[i], events[j]);
                            
                            swapped = true;
                        }
                        else if (events[i].year == events[j].year) 
                        {
                            if (events[i].month > events[j].month)
                            {
                                cout << "Swapping events: " << events[i].name << " and " << events[j].name << endl;
                                swap(events[i], events[j]);

                                swapped = true;
                            }
                            else if (events[i].month == events[j].month) 
                            {
                                if (events[i].day > events[j].day)
                                {
                                    cout << "Swapping events: " << events[i].name << " and " << events[j].name << endl;
                                    swap(events[i], events[j]);
                                    swapped = true;
                                }
                                else if (events[i].day == events[j].day) 
                                {
                                    if (events[i].time > events[j].time)
                                    {
                                        cout << "Swapping events: " << events[i].name << " and " << events[j].name << endl;
                                        swap(events[i], events[j]);
                                        swapped = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for (const auto& event : events)
            {
                cout << "Event: " << event.name << ", Date: " << event.date << ", Time: " << event.time << endl;
            }
            sortEvents();
        }

void sortNames() {
            cout << "Enter name of event: " << endl;
                    string eventName;
                    string lowerCaseEventName;
                    cin.ignore();
                    getline(cin, eventName);        
                    lowerCaseEventName = toLowerCase(eventName);
                    bool found = false;
                    for(int i = 0; i < events.size(); i++)
                    {
                        if(toLowerCase(events[i].name) == lowerCaseEventName)
                        {
                            cout << "Event: " << events[i].name << ", Date: " << events[i].date << ", Time: " << events[i].time << endl;
                            found = true;
                            sortEvents();
                        }
                        
                    }
                    if(!found)
                    {
                        cout << "Event not found." << endl;
                        sortEvents();
                    }
                }
void sortEvents() {

        cout << "Sort Events by 'Date' or 'Name'?, 'Edit' an event, 'Delete' an event, or 'Exit' to return to the main menu." << endl;
        string input;
        cin >> input;
        if(input == "Date" || input == "date")
        {
            cout << "Sorting events by date..." << endl;
            sortDates();
        }
        else if(input == "Name" || input == "name")
        {
            cout << "Sorting events by name..." << endl;
            sortNames();
        }
        else if(input == "Edit" || input == "edit")
        {
            editEvent();
        }
        else if(input == "Delete" || input == "delete")
        {
            deleteEvent();
        }
        else if(input == "Exit" || input == "exit")
        {
            cout << "Back to main menu..." << endl;
            mainMenu();
        }
        else if(input == "Edit" || input == "edit")
        {
            cout << "Editing an event..." << endl;
            editEvent();
        }
        else if(input == "Delete" || input == "delete")
        {
            cout << "Deleting an event..." << endl;
            deleteEvent();
        }
        else if(input == "Exit" || input == "exit")
        {
            cout << "Back to main menu..." << endl;
            mainMenu();
        }
        else 
        {
            cout << "Invalid input. Please try again." << endl;
            sortEvents();
        }
}


void mainMenu() 
{
    while(events.empty())
    {
    events.push_back({"Test1", "02/02/2027", "02", "02", "2027", "12:00"});
    events.push_back({"Test2", "02/02/2026", "02", "02", "2026", "12:00"});
    events.push_back({"Test3", "02/01/2026", "02", "01", "2026", "12:30"});
    events.push_back({"Test4", "02/01/2026", "02", "01", "2026", "12:00"});
    events.push_back({"Test5", "03/01/2026", "03", "01", "2026", "02:30"});
    }
    std::cout << "Type 'Create' to make an event, 'List' to see all events, or 'Exit' to quit." << std::endl;
    std::string input;
    std::cin >> input;
    if(input == "Create" || input == "create")
    {
        createEvent();
        
    }
    else if(input == "List" || input == "list")
    {
        std::cout << "Listing all events..." << std::endl;

        listEvents();
        
    }
    else if(input == "Exit" || input == "exit")
    {
        std::cout << "Exiting the program." << std::endl;
        return;
    }
    else
    {
        std::cout << "Invalid input. Please try again." << std::endl;
        mainMenu();
    }


}

string toLowerCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void editEvent() {
cout << "Enter name of the event to edit: " << endl;
                    string eventName;
                    string lowerCaseEventName;
                    cin.ignore();
                    getline(cin, eventName);        
                    lowerCaseEventName = toLowerCase(eventName);
                    bool found = false;
                    for(int i = 0; i < events.size(); i++)
                    {
                        if(toLowerCase(events[i].name) == lowerCaseEventName)
                        {
                            bool finishedEditing = false;
                            while(finishedEditing == false) {
                            cout << "Event: " << events[i].name << ", Date: " << events[i].date << ", Time: " << events[i].time << endl;
                            found = true;
                            cout << "What would you like to edit? ('Name', 'Date', 'Time' or 'Done' to finish)" << endl;
                            string editChoice;
                            cin >> editChoice;
                            if(editChoice == "Name" || editChoice == "name") {
                                cout << "Enter new name: " << endl;
                                string newName;
                                cin.ignore();
                                getline(cin, newName);
                                events[i].name = newName;
                            }
                            else if(editChoice == "Date" || editChoice == "date") {
                                cout << "Enter new date (MM DD YYYY): " << endl;
                                string newMonth, newDay, newYear;
                                cin >> newMonth >> newDay >> newYear;
                                while (!validateDate(newMonth, newDay, newYear)) {
                                    cout << "Enter new date (MM DD YYYY): " << endl;
                                    cin >> newMonth >> newDay >> newYear;
                                    validateDate(newMonth, newDay, newYear);
                                }
                                events[i].date = newMonth + "/" + newDay + "/" + newYear;
                                events[i].month = newMonth;
                                events[i].day = newDay;
                                events[i].year = newYear;
                            }
                            else if(editChoice == "Time" || editChoice == "time") {
                                cout << "Enter new time (HH:MM): " << endl;
                                string newTime;
                                cin >> newTime;
                                events[i].time = newTime;
                            }
                            else if (editChoice == "Done" || editChoice == "done") {
                                finishedEditing = true;
                                cout << "Finished editing event." << endl;
                                listEvents();
                            }
                            else {
                                cout << "Invalid choice. Try again." << endl;
                            }
                        }
                    }
                        
                    }
                    if(!found)
                    {
                        cout << "Event not found." << endl;
                        listEvents();
                    }
}
void deleteEvent() {
cout << "Enter name of the event to delete: " << endl;
                    string eventName;
                    string lowerCaseEventName;
                    cin.ignore();
                    getline(cin, eventName);        
                    lowerCaseEventName = toLowerCase(eventName);
                    bool found = false;
                    for(int i = 0; i < events.size(); i++)
                    {
                        if(toLowerCase(events[i].name) == lowerCaseEventName)
                        {
                            cout << "Event: " << events[i].name << ", Date: " << events[i].date << ", Time: " << events[i].time << endl;
                            found = true;
                            cout << "Are you sure you want to delete this event? ('Yes', 'No')" << endl;
                            string confirmation;
                            cin >> confirmation;
                            if(confirmation == "yes" || confirmation == "Yes") {
                                events.erase(events.begin() + i);
                                cout << "Event deleted." << endl;
                                listEvents();
                            } else {
                                cout << "Event not deleted." << endl;
                                listEvents();
                            }
                        }
                        
                    }
                    if(!found)
                    {
                        cout << "Event not found." << endl;
                        listEvents();
                    }
}