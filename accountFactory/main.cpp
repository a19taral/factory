// Section 17
// Unique Pointers
#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"
#include "Factory.h"

class Test
{
private:
    int data;

public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

using namespace std;

int main()
{
    // Test *t1 = new Test {1000};
    //  delete t1;
    //   std::unique_ptr<Test> t1 {new Test{100}};
    //   std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
    //
    //   std::unique_ptr<Test> t3;
    //   t3 = std::move(t1);
    //   if (!t1)
    //       std::cout << "t1 is nullptr" << std::endl;

    Factory factory;


    auto a1 = factory.create("checking");
    a1->setBalance(5000);
    a1->setName("Moe");
    // std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    std::cout << *a1 << std::endl;
    a1->deposit(5000);
    std::cout << *a1 << std::endl;

    std::unique_ptr<Account> a2 = factory.create("savings");
    auto a3 = factory.create("trust");
    // a2->setBalance(4000);
    // a2->setName("Billy");
    // a3->setBalance(6000);
    // a3->setName("Bobby");

    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(factory.create("savings"));
    accounts.push_back(make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back(make_unique<Trust_Account>("Bobby", 5000, 4.5));

    for (const auto &acc : accounts)
        std::cout << *acc << std::endl;
    return 0;
}
