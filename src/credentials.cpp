#include "secrets.h"
#include "credentials.h"
#include <iostream>


std::string combinedCreds()
{
    std::string db_name = DB_NAME;
    std::string host_addr = HOST_ADDR;
    std::string port_number = PORT_NUMBER;
    std::string user_name = USER_NAME;
    std::string pass_word = PASS_WORD;

    std::string combine="dbname=";
    combine += db_name;
    combine += " user=";
    combine += user_name;
    combine += " password=";
    combine += pass_word;
    combine += " hostaddr=";
    combine += host_addr;
    combine += " port=";
    combine += port_number;

    return combine;
};
