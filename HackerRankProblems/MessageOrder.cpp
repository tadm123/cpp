/*
  Problem: https://www.hackerrank.com/challenges/messages-order/problem
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

namespace my_external_vars
{
    int external_counter{0};
}


class Message 
{
    std::string m_text{};
    int m_counter{0};
public: 
    Message()  = default;
    
    //getter function
    const std::string& get_text() {return m_text;}
    
    //setter function
    void set_text(const std::string& text) {m_text = text;}
    
    //overloading < for fix_order() function 
    bool operator<(Message const& a)
    {
        return this->m_counter < a.m_counter;
    }
    
    //increase counter of Message to the external count
    void set_increase_counter()
    {
        my_external_vars::external_counter +=1;
        m_counter = my_external_vars::external_counter;
    }

};

class MessageFactory 
{
public:
    MessageFactory()= default;
    
    //function that will create a text and return Message with this text
    Message create_message(const std::string& text) 
    {
        Message my_message; //initializing Message class "my_message"
        my_message.set_text(text); //set text 
        
        //increasing the counter
        my_message.set_increase_counter();
        
        return my_message;
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
