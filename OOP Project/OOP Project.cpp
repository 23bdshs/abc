#include <bits/stdc++.h>
using namespace std;

// Abstract base class for TrafficSignal
class TrafficSignal
{
public:
    virtual void displaySignal()= 0;
};

// Derived classes for specific signals
class RedSignal : public TrafficSignal
{
public:
    void displaySignal()
    {
        cout << "Red Signal - Stop!" << endl;
    } //Override
};

class YellowSignal : public TrafficSignal
{
public:
    void displaySignal()
    {
        cout << "Yellow Signal - Prepare to Stop!" << endl;
    }   //Override
};

class GreenSignal : public TrafficSignal
{
public:
    void displaySignal()
    {
        cout << "Green Signal - Go!" << endl;
    }   //Override
};

// Traffic Controller class
class TrafficController
{
private:
    TrafficSignal* currentSignal;

public:
    TrafficController()
    {
        currentSignal = nullptr;
    }

    void setSignal(TrafficSignal* signal)
    {
        currentSignal = signal;
    }

    void displayCurrentSignal()
    {
        if (currentSignal)
        {
            currentSignal->displaySignal();
        }
        else
        {
            cout << "No signal set." << endl;
        }
    }
};

int main()
{
    TrafficController controller;

    cout << "Auto Traffic Control System" << endl;
    cout << "Enter signal color (R/Y/G): ";

    char input;
    cin >> input;

    TrafficSignal* signal = nullptr;

    switch (input)
    {
    case 'R':
        signal = new RedSignal();
        break;
    case 'Y':
        signal = new YellowSignal();
        break;
    case 'G':
        signal = new GreenSignal();
        break;
    default:
        cout << "Invalid input!" << endl;
        return 1;
    }

    controller.setSignal(signal);
    controller.displayCurrentSignal();

    delete signal;

    return 0;
}
