#include <gtest/gtest.h>
#include "EventManager.h"
#include "Auth.h"

// ---------- Hashing ----------
TEST(HashTest, MatchesKnownSha256Vectors) {
    EXPECT_EQ(sha256("abc"),
        "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
    EXPECT_EQ(sha256(""),
        "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
}

// ---------- Auth ----------
class AuthTest : public ::testing::Test {
protected:
    void SetUp() override { clearUsers(); }   // fresh state for every test
};

TEST_F(AuthTest, RegisterThenLoginSucceeds) {
    EXPECT_TRUE(registerUser("alice", "pw1"));
    EXPECT_TRUE(login("alice", "pw1"));
    EXPECT_TRUE(isLoggedIn());
    EXPECT_EQ(currentUsername(), "alice");
}

TEST_F(AuthTest, WrongPasswordFails) {
    registerUser("alice", "pw1");
    EXPECT_FALSE(login("alice", "wrong"));
    EXPECT_FALSE(isLoggedIn());
}

TEST_F(AuthTest, UnknownUserFails) {
    EXPECT_FALSE(login("nobody", "pw"));
    EXPECT_FALSE(isLoggedIn());
}

TEST_F(AuthTest, DuplicateRegistrationRejected) {
    EXPECT_TRUE(registerUser("alice", "pw1"));
    EXPECT_FALSE(registerUser("alice", "pw2"));
}

TEST_F(AuthTest, EmptyCredentialsRejected) {
    EXPECT_FALSE(registerUser("", "pw"));
    EXPECT_FALSE(registerUser("alice", ""));
}

TEST_F(AuthTest, LogoutClearsSession) {
    registerUser("alice", "pw1");
    login("alice", "pw1");
    logout();
    EXPECT_FALSE(isLoggedIn());
    EXPECT_EQ(currentUsername(), "");
}

TEST_F(AuthTest, CannotLoginWhileAlreadyLoggedIn) {
    registerUser("alice", "pw1");
    registerUser("bob", "pw2");
    login("alice", "pw1");
    EXPECT_FALSE(login("bob", "pw2"));
    EXPECT_EQ(currentUsername(), "alice");
}

TEST_F(AuthTest, LoginStillWorksWithHashing) {
    registerUser("alice", "pw1");
    EXPECT_TRUE(login("alice", "pw1"));
    logout();
    EXPECT_FALSE(login("alice", "PW1"));   // case-sensitive
}

// ---------- Date tests (Nick's area: left commented out) ----------
// TEST(DateTest, HandlesBroadInvalidDates) {
//     EXPECT_FALSE(validateDate("13", "01", "2026"));
//     EXPECT_FALSE(validateDate("0", "01", "2026"));
//     EXPECT_FALSE(validateDate("06", "50", "2026"));
//     EXPECT_FALSE(validateDate("06", "0", "2026"));
//     EXPECT_FALSE(validateDate("06", "12", "1900"));
//     EXPECT_FALSE(validateDate("06", "12", "3000"));
//     EXPECT_TRUE(validateDate("06", "12", "2026"));
// }
// TEST(DateTest, HandlesDaysInMonths) {
//     for (const std::string& month : months31) {
//         EXPECT_TRUE(validateDate(month, "31", "2026"));
//     }
//     for (const std::string& month : months30) {
//         EXPECT_TRUE(validateDate(month, "30", "2026"));
//         EXPECT_FALSE(validateDate(month, "31", "2026"));
//     }
//     EXPECT_TRUE(validateDate("02", "28", "2026"));
//     EXPECT_FALSE(validateDate("02", "29", "2026"));
// }