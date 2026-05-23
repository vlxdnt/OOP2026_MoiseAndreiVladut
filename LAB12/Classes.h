#pragma once

#include <string>
#include <vector>
#include <stdexcept>

struct Date {
    int Day;
    int Month;
    int Year;
};

enum class ContactType {
    Friend,
    Acquaintance,
    Colleague
};

class Contact {
    protected:
        std::string Name;

    public:
        Contact(std::string name) : Name(name) {}
        virtual ContactType GetType() const = 0;
        virtual ~Contact() = default;
        void SetName(const std::string& name) {
            this->Name = name;
        }

        std::string GetName() const {
            return this->Name;
        }
};

class Friend : public Contact {
    private:
        Date Birthday;
        std::string PhoneNumber;
        std::string Address;

    public:
        Friend(std::string name) : Contact(name) {}

        ContactType GetType() const override {
            return ContactType::Friend;
        }

        void SetBirthday(const Date& birthday) {
            this->Birthday = birthday;
        }

        Date GetBirthday() const {
            return this->Birthday;
        }

        void SetPhoneNumber(const std::string& phoneNumber) {
            this->PhoneNumber = phoneNumber;
        }

        std::string GetPhoneNumber() const {
            return this->PhoneNumber;
        }

        void SetAddress(const std::string& address) {
            this->Address = address;
        }

        std::string GetAddress() const {
            return this->Address;
        }
};

class Acquaintance : public Contact {
    private:
        std::string PhoneNumber;
    
    public:
        Acquaintance(std::string name) : Contact(name) {}

        ContactType GetType() const override {
            return ContactType::Acquaintance;
        }

        void SetPhoneNumber(const std::string& phoneNumber) {
            this->PhoneNumber = phoneNumber;
        }

        std::string GetPhoneNumber() const {
            return this->PhoneNumber;
        }
};

class Colleague : public Contact {
    private:
        std::string PhoneNumber;
        std::string Company;
        std::string Address;

    public:

        Colleague(std::string name) : Contact(name) {}

        ContactType GetType() const override {
            return ContactType::Colleague;
        }

        void SetPhoneNumber(const std::string& phoneNumber) {
            this->PhoneNumber = phoneNumber;
        }

        std::string GetPhoneNumber() const {
            return this->PhoneNumber;
        }

        void SetCompany(const std::string& company) {
            this->Company = company;
        }

        std::string GetCompany() const {
            return this->Company;
        }

        void SetAddress(const std::string& address) {
            this->Address = address;
        }

        std::string GetAddress() const {
            return this->Address;
        }
};

class AddressBook {
    private:
        std::vector<Contact*> Contacts;

    public:

        AddressBook() = default;

        ~AddressBook() {
            for (Contact* contact : Contacts) {
                delete contact; 
            }
        }

        void AddContact(Contact* contact) {
            Contacts.push_back(contact);
        }

        std::vector<Contact*> GetFriends() const {
            std::vector<Contact*> friends;
            for (int i = 0; i < Contacts.size(); i++) {
                if (Contacts[i]->GetType() == ContactType::Friend) {
                    friends.push_back(Contacts[i]);
                }
            }
            return friends;
        }

        Contact* SearchByName(const std::string& name) const {
            for (int i = 0; i < Contacts.size(); i++) {
                if (Contacts[i]->GetName() == name) {
                    return Contacts[i];
                }
            }
            return nullptr;
        }

        void DeleteByName(const std::string& name) {
            for (int i = 0; i < Contacts.size(); i++) {
                if (Contacts[i]->GetName() == name) {
                    delete Contacts[i];
                    Contacts.erase(Contacts.begin() + i);
                    return;
                }
            }
            throw std::runtime_error("Contact not found");
        }
};