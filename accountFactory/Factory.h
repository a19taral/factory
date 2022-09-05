# pragma once
#include <string>
#include "Account.h"

class Factory {

//friend class Account;
public:
enum class objectType {SAVINGS, TRUST, CHECKING};

static AccountPtr create1(objectType type);
static AccountPtr create(const std::string &type);

};