#pragma once
#include <string>

std::string sha256(const std::string& input);   // exposed so tests can check it

bool registerUser(const std::string& username, const std::string& password);
bool login(const std::string& username, const std::string& password);
void logout();
bool isLoggedIn();
std::string currentUsername();
void clearUsers();      // used by tests to reset state
bool loginPrompt();     // console UI; returns true if the user ended up logged in