//
// Created by student on 23.03.23.
//
#include <boost/test/unit_test.hpp>
#include "model/Client.h"

struct TestSuiteClientFixture {
    const std::string testFirstName1 = "Witold";
    const std::string testLastName1 = "Nowak";
    const std::string testPersonalID1 = "010101";

    const std::string testFirstName2 = "Grazyna";
    const std::string testLastName2= "Kowalska";
    const std::string testPersonalID2 = "111111";

    Address *testAddress1;
    Address *testAddress2;

    TestSuiteClientFixture() {
        testAddress1 = new Address("Lodz", "Ulica Piotrkowska", "153");
        testAddress2 = new Address("London", "Baker Street", "221b");
    }

    ~TestSuiteClientFixture() {
        delete testAddress1;
        delete testAddress2;
    }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(clientConstructorTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1);
        BOOST_TEST(client.getFirstName() == testFirstName1);
        BOOST_TEST(client.getLastName() == testLastName1);
        BOOST_TEST(client.getPersonalId() == testPersonalID1);
        BOOST_TEST(client.getAddress() == testAddress1);
    }

    BOOST_AUTO_TEST_CASE(clientSetFirstNameTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1);
        client.setFirstName(testFirstName2);
        BOOST_TEST(client.getFirstName() == testFirstName2);
    }

    BOOST_AUTO_TEST_CASE(clientSetFirstNameTest_Negative) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1);
        client.setFirstName("");
        BOOST_TEST(client.getFirstName() == testFirstName1);
    }

    BOOST_AUTO_TEST_CASE(clientSetLastNameTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1);
        client.setLastName(testLastName2);
        BOOST_TEST(client.getLastName() == testLastName2);
    }

    BOOST_AUTO_TEST_CASE(clientSetLastNameTest_Negative) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1);
        client.setLastName("");
        BOOST_TEST(client.getLastName() == testLastName1);
    }
    BOOST_AUTO_TEST_CASE(clientSetAddressTest_Positive) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1);
        client.setAddress(testAddress2);
        BOOST_TEST(client.getAddress() == testAddress2);
    }

    BOOST_AUTO_TEST_CASE(clientSetAddressTest_Negative) {
        Client client(testFirstName1, testLastName1, testPersonalID1, testAddress1);
        client.setAddress(nullptr);
        BOOST_TEST(client.getAddress() == testAddress1);
    }

BOOST_AUTO_TEST_SUITE_END()