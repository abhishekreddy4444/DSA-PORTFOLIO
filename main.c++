#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int PNR = 17082005;

void pnrCount()
{
    PNR++;
}

class FlightManagementSystem
{
public:
    int pnr, from, to, age, paym, pin, bnk;
    long long int dateOfJourney, cnum, crdnum;
    string expdate, cvv, userid, pass;
    char gender;
    int flino;
    string at, dt;
    string mode;
    string flight;
    int enterPNR, one;
    int cost;
};

class BookingInfo : public FlightManagementSystem
{
public:
    void domesticFlight()
    {
        cout << endl;
        cout << "Enter Date of journey (DDMMYYYY): " << endl;
        cin >> dateOfJourney;
        cout << endl;
        cout << "(1) CHENNAI (2) VIZAG (3) BANGALORE (4) DELHI" << endl
             << endl;
        cout << "Enter from city: ";
        cin >> from;
        cout << endl;
        cout << "Enter Destination city: ";
        cin >> to;
        cout << endl
             << endl
             << endl;

        // Add flight details based on from and to locations as before
        // ...

        if (from == to)
        {
            cout << "From city and Destination city should not be the same !!! " << endl;
            domesticFlight();
        }
        else
        {
            cout << "You entered the wrong input !!! " << endl;
            domesticFlight();
        }
    }
};

class PassengerDetails : public BookingInfo
{
public:
    string lsname, frname, email;

    void getData()
    {
        cout << "Enter Passenger Details" << endl;
        cout << "Enter First name: ";
        cin >> frname;
        cout << "Enter Last name: ";
        cin >> lsname;
        cout << "Gender (m for Male / f for Female): ";
        cin >> gender;
        cout << "Age: ";
        cin >> age;
        cout << "Email-id: ";
        cin >> email;
        cout << "Contact No.: ";
        cin >> cnum;
        cout << endl
             << endl;
    }
};

class PaymentDetails : public PassengerDetails
{
public:
    void payment()
    {
        cout << "How would you like to pay?" << endl
             << endl;
        cout << "1. Debit Card" << endl;
        cout << "2. Credit Card" << endl;
        cout << "3. Net Banking" << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> paym;

        if (paym == 1 || paym == 2)
        {
            cout << "Enter Card No.: ";
            cin >> crdnum;
            cout << "Enter Expiry Date: ";
            cin >> expdate;
            cout << "Enter CVV: ";
            cin >> cvv;
            cout << "Enter PIN: ";
            cin >> pin;

            mode = (paym == 1) ? "Debit Card" : "Credit Card";
        }
        else if (paym == 3)
        {
            cout << "1. HDFC BANK" << endl;
            cout << "2. IDFC BANK" << endl;
            cout << "3. ICICI BANK" << endl;
            cout << "4. DCB BANK" << endl;
            cout << endl
                 << endl;
            cout << "Enter your Bank: ";
            cin >> bnk;
            cout << endl;
            cout << "Enter User ID: ";
            cin >> userid;
            cout << "Enter Password: ";
            cin >> pass;

            mode = "Net Banking";
        }
    }
};

class EndDetails : public PaymentDetails
{
public:
    int cnc = 1;

    void endTag()
    {
        cout << "Your payment was successful!!!" << endl
             << endl;
        cout << "Payment mode: " << mode << endl;
        cout << "Ticket Details:" << endl;
        cout << "PNR: " << PNR << endl;
    }
};

class CancelTicket : public EndDetails
{
public:
    void cancel()
    {
        cout << "Enter PNR number: ";
        cin >> enterPNR;
        cout << endl
             << endl
             << "Enter 1 to cancel the ticket" << endl;
        cin >> one;
        cout << endl << "Successfully canceled the ticket. Money will be refunded in a week!" << endl;
        cnc = 0;
    }
};

void showData()
{
    cout << "Entry to file" << endl;
    ofstream fout;
    fout.open("flightManagementData.txt", ios::out | ios::app | ios::binary);
    PassengerDetails objGlob;
    objGlob.getData();
    fout.write(reinterpret_cast<char *>(&objGlob), sizeof(objGlob));
    fout.close();
}

int main()
{
    EndDetails obj1;
    CancelTicket obj2;
    int option, select, sel, input;

    do
    {
        system("CLS");
        cout << "Welcome To Flight Reservation System" << endl;
        cout << "******************************************" << endl;
        cout << "Book your Flight tickets at affordable prices!!!" << endl;
        cout << "******************************************" << endl;
        cout << endl
             << endl;
        cout << "1. Book a flight" << endl;
        cout << "2. Cancel Flight" << endl;
        cout << "3. Check Ticket" << endl;
        cout << "4. Exit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            system("CLS");
            cout << endl
                 << endl << "1. Domestic Flights" << endl << "2. International Flights" << endl;
            cout << endl << "Please enter your option: ";
            cin >> select;

            switch (select)
            {
            case 1:
                pnrCount();
                obj1.domesticFlight();
                showData();
                obj1.payment();
                obj1.endTag();
                break;
            case 2:
                cout << "No International Flights available at this moment" << endl;
                break;
            }
            break;

        case 2:
            system("CLS");
            obj2.cancel();
            break;

        case 3:
            system("CLS");
            cout << endl
                 << endl << "1. Domestic Flights" << endl << "2. International Flights" << endl;
            cout << endl << "Please enter your option: ";
            cin >> sel;

            switch (sel)
            {
            case 1:
                showData();
                break;
            case 2:
                cout << "No International Flights available at this moment" << endl;
            }
            break;

        case 4:
            system("CLS");
            cout << "END OF THE CODE";
            return 0;

        default:
            return main();
        }

        cout << endl << endl << "Do you wish to continue: " << endl;
        cout << "Press 1 to continue, Press 0 to exit" << endl;
        cin >> input;
    } while (input == 1);

    return 0;
}
