#include<iostream>
using namespace std;

class user
{
private:
    char name[30];
    int age;
public:
    user();
    user(char name[30], int age);
    void get_name();
    void set_name();
    friend ostream& operator<<(ostream& os, const user u);
    friend istream& operator>>(istream& in, user& u);
    ~user();
};

user::user()
{
    for (int i = 0; i < 30; i++)
    {
        this->name[i]='\0';
    }
    this->age=-1;
}
user::user(char n[30], int a)
{
    for (int i = 0; i < 30; i++)
    {
        this->name[i]=n[i];
    }
    this->age=a;
}
void user::set_name()
{
    std::cin >> this->name;
}
void user::get_name()
{
    std::cout << this->name;
}
user::~user()
{
}

ostream& operator<<(ostream& os, const user u)
{
    os << "Your name is " << u.name << " and you are " << u.age << " years old." << std::endl;
    return os;
}
istream& operator>>(istream& is, user& u)
{
    cout << "What is your name?";
    is >> u.name;
    cout << "How old are you?";
    is >> u.age;
    return is;
}

int main() {
    user u;
    cout << "Hello World" << endl;
    cin >> u;
    cout << u;
}