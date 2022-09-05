#include "Factory.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"


AccountPtr Factory::create(const std::string& type){
    
    if (type == "savings")
    {
        return std::make_unique<Savings_Account>();
    }
    else if (type == "trust")
    {
        return std::make_unique<Trust_Account>();
    }
    else if (type == "checking")
    {
        return std::make_unique<Checking_Account>();
    }
    return nullptr;
    
}

