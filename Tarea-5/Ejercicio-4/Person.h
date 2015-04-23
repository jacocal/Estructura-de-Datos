#ifndef Tarea_Person_h
#define Tarea_Person_h

#include <iostream>
#include <string>

using namespace std;

class Person
{
    string name;
    bool validateLife = true;
    
    
public:
    Person() {}
    Person(string name);
    
    int deathDate;
    
    void setLife(bool value);
    bool getLife();
    
    void setDate(int date);
    int getDate();
    
    bool operator==(Person p);
    friend std::ostream& operator<<(std::ostream& os, Person& person);
};

Person::Person(string name) : name(name) { }

void Person::setLife(bool value)
{
    validateLife = value;
}

bool Person::getLife()
{
    return validateLife;
}

void Person::setDate(int date)
{
    deathDate = date;
}


int Person::getDate()
{
    return deathDate;
}

bool Person::operator==(Person p)
{
    return name == p.name;
}

std::ostream& operator<<(std::ostream& os, Person& person)
{
    os << person.name;
    return os;
}

#endif
