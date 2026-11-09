#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Event {
    string name;
    string date;
    string time;
};
std::vector<string> months31 = {"01", "03", "05", "07", "08", "10", "12"};
std::vector<string> months30 = {"04", "06", "09", "11"};
std::vector<string> monthsFeb = {"02"};

vector<Event> events;
// Function to validate the date input by the user
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
    // Check if year is a 4-digit number
    for (int i = 0; i < 4; i++)
    {
        if (!isdigit(year[i]))
        {
            cout << "Invalid year. Please enter a 4-digit year." << endl;
            return false;
        }
    }
     
    // Checks if the month, day, and year are within valid ranges
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
    // Check for February
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
    // Prompts the user for event details
    std::cout << "Enter the event name: ";
    string eventName;
    cin.ignore();
    getline(cin, eventName);

    // Prompts the user for event date and validate it
    std::cout << "Enter the event date (MM DD YYYY): ";
    string month, day, year;
    cin >> month >> day >> year;

    // Validates the date and keeps prompting until a valid date is entered
    string eventDate = month + "/" + day + "/" + year;
    while (!validateDate(month, day, year)) {
        std::cout << "Enter the event date (MM DD YYYY): ";
        cin >> month >> day >> year;
        eventDate = month + "/" + day + "/" + year;
        validateDate(month, day, year);
    }

    // Prompts the user to enter the event time
    std::cout << "Enter the event time in military format (HH:MM): ";
    string eventTime;
    cin >> eventTime;
    
    // Creates the event and adds it to the list of events
    std::cout << "Event '" << eventName << "' has been created." << std::endl;
    events.push_back({eventName, eventDate, eventTime});
}
void listEvents()
{
    // Lists all events in the events vector
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
    
}
int main() {
    // Main loop for the event tracker program
    std::cout << "Type 'Create' to make an event, 'List' to see all events, or 'Exit' to quit." << std::endl;
    std::string input;
    std::cin >> input;

    // Handle user input and call the appropriate functions
    if(input == "Create" || input == "create")
    {
        createEvent();
        main();
    }
    else if(input == "List" || input == "list")
    {
        std::cout << "Listing all events..." << std::endl;

        listEvents();
        main();
    }
    else if(input == "Exit" || input == "exit")
    {
        std::cout << "Exiting the program." << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Invalid input. Please try again." << std::endl;
        main();
    }

    return 1;
}