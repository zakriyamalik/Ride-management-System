#include <iostream>
#include <chrono>
#include<ctime>
#include <vector> 
#include<fstream>
#include<cmath>
#include<string>
#include <algorithm>
#include <stdexcept>
using namespace std;

//class Date
//{
//public:
//    int day;
//    int month;
//    int year;
//
//    Date() {
//        day = 0;
//        month = 0;
//        year = 0;
//    }
//
//    Date(int d, int m, int y) {
//        day = d;
//        month = m;
//        year = y;
//    }
//};
//class mTime {
//public:
//    int hour;
//    int min;
//    int sec;
//
//    mTime() {
//        hour = 0;
//        min = 0;
//        sec = 0;
//    }
//
//    mTime(int h, int m, int s) {
//        hour = h;
//        min = m;
//        sec = s;
//    }
//    // ... (as in your original implementation)
//};
//class Feature {
//public:
//    int fId;
//    char* description;
//    float cost;
//
//    Feature() {
//        fId = 0;
//        description = nullptr;
//        cost = 0.0;
//    }
//
//    Feature(int id, const char* desc, float c) : fId(id), cost(c) {
//        description = new char[strlen(desc) + 1];
//        strcpy(description, desc);
//    }
//
//    ~Feature() {
//        delete[] description;
//    }
//};
//
//class Name {
//public:
//    char* fName;
//    char* lName;
//
//    Name() {
//        fName = nullptr;
//        lName = nullptr;
//    }
//
//    Name(const char* fN, const char* lN) {
//        fName = new char[strlen(fN) + 1];
//        strcpy(fName, fN);
//        lName = new char[strlen(lN) + 1];
//        strcpy(lName, lN);
//    }
//
//    ~Name() {
//        delete[] fName;
//        delete[] lName;
//    }
//    // ... (as in your original implementation)
//};
//
//class Service {
//public:
//    char* source;
//    char* destination;
//    float distance;
//    bool status; // false for pending, true if complete
//    float fuelrate;
//    int cId; // Customer Id who booked the ride
//    int dId; // Driver Id
//    int vId; // Vehicle Id
//    vector<Feature> features; // Features associated with the service
//
//    Service() {
//        source = nullptr;
//        destination = nullptr;
//        distance = 0.0;
//        status = false;
//        fuelrate = 0.0;
//        cId = 0;
//        dId = 0;
//        vId = 0;
//    }
//
//    ~Service() {
//        delete[] source;
//        delete[] destination;
//    }
//    // ... (as in your original implementation)
//};
//
//class Ride : public Service {
//public:
//    int noofPassengers;
//    char* rideType;
//    float driverRanking;
//    float vehicleRanking;
//
//    Ride() {
//        noofPassengers = 0;
//        rideType = nullptr;
//        driverRanking = 0.0;
//        vehicleRanking = 0.0;
//    }
//
//    ~Ride() {
//        delete[] rideType;
//    }
//    // ... (as in your original implementation)
//};
//
//class Delivery : public Service {
//public:
//    float goodsWeight;
//    char* goodsType;
//
//    Delivery() {
//        goodsWeight = 0.0;
//        goodsType = nullptr;
//    }
//
//    ~Delivery() {
//        delete[] goodsType;
//    }
//    // ... (as in your original implementation)
//};
//
//class Person {
//public:
//    Name pName;
//    int Age;
//    int Nid;
//
//    Person() {
//        Age = 0;
//        Nid = 0;
//    }
//
//    ~Person() {
//        // Destructor
//    }
//    // ... (as in your original implementation)
//};
//
//class Customer : public Person {
//public:
//    int cId;
//    vector<Service*> bookingHistory;
//
//    Customer() {
//        cId = 0;
//    }
//
//    ~Customer() {
//        // Destructor
//    }
//    // ... (as in your original implementation)
//};
//
//class Driver : public Person {
//public:
//    int dId;
//    char** LicencesList;
//    int noofLicences;
//    float overallRanking;
//    float salary;
//    int experience;
//    int status; // 1 for free, 2 if booked, and 3 if canceled
//    vector<Service*> serviceHistory;
//
//    Driver() {
//        dId = 0;
//        noofLicences = 0;
//        overallRanking = 0.0;
//        salary = 0.0;
//        experience = 0;
//        status = 1;
//        LicencesList = nullptr;
//    }
//
//    ~Driver() {
//        // Destructor
//    }
//    // ... (as in your original implementation)
//};
//
//class Vehicle {
//public:
//    int vId;
//    int registrationNo;
//    float avgMileage;
//    char* LicenceType;
//    bool status; // false for free, true if booked in a service already
//    char* fueltype;
//    float overallRanking;
//    vector<Feature> list;
//    vector<Service*> serviceHistory;
//
//    Vehicle() {
//        vId = 0;
//        registrationNo = 0;
//        avgMileage = 0.0;
//        status = false;
//        overallRanking = 0.0;
//        LicenceType = nullptr;
//        fueltype = nullptr;
//    }
//
//    ~Vehicle() {
//        delete[] LicenceType;
//        delete[] fueltype;
//    }
//    // ... (as in your original implementation)
//};

class TMS {
private:
  /*  Customer* customers[15];
    Driver* drivers[10];
    Vehicle* vehicles[20];
    Service* services[100];*/ // Assuming a maximum of 100 services

    int customerCount;
    int driverCount;
    int vehicleCount;
    int serviceCount;
	int activeServiceIndex;
	std::chrono::time_point<std::chrono::system_clock> startTime;
	float currentDistance;
    // Add private helper functions here
public:
	TMS()
	{
		 customerCount=0;
		 driverCount=0;
		 vehicleCount=0;
		 serviceCount=0;
		 activeServiceIndex=0;
		std::chrono::time_point<std::chrono::system_clock> startTime;
		 currentDistance=0;
	}
    bool phone_check(char* temp)
    {
        int size = 0;
        for (int i = 0; temp[i] != '\0'; i++)
        {
            size++;
        }
        if (size == 11)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool licence_check(char* temp)
    {
        //\nMotorbike/rickshaw \nLTV \nHTV\nInternational driver's permit"
        int temp_size = 0;
        for (int i = 0; temp[i] != '\0'; i++)
        {
            temp_size++;
        }


        if (temp_size == 18)
        {
            char* temp1 = new char[30];
            temp1[0] = { 'M' };
            temp1[1] = { 'o' };
            temp1[2] = { 't' };
            temp1[3] = { 'o' };
            temp1[4] = { 'r' };
            temp1[5] = { 'b' };
            temp1[6] = { 'i' };
            temp1[7] = { 'k' };
            temp1[8] = { 'e' };
            temp1[9] = { '/' };
            temp1[10] = { 'r' };
            temp1[11] = { 'i' };
            temp1[12] = { 'c' };
            temp1[13] = { 'k' };
            temp1[14] = { 's' };
            temp1[15] = { 'h' };
            temp1[16] = { 'a' };
            temp1[17] = { 'w' };
            int p = 1, q = 1, temp_counter = 1;

            if (temp[0] == temp1[0])
            {
                p = 1, q = 1, temp_counter = 1;
                while (temp[p++] == temp1[q++])
                {
                    temp_counter++;
                }
            }
            if (temp_counter == temp_size)
            {
                cout << "Matched\n";
                return true;
            }
            else
            {
                cout << "You have entered\n";
                for (int i = 0; i < temp_size; i++)
                {
                    cout << temp[i];
                }
                cout << endl;
                cout << "Licence: ";
                for (int i = 0; i < 18; i++)
                {
                    cout << temp1[i];
                }
                return false;
            }


        }
        else if (temp_size == 29)
        {
            char* temp1 = new char[30];
            temp1[0] = { 'I' };
            temp1[1] = { 'n' };
            temp1[2] = { 't' };
            temp1[3] = { 'e' };
            temp1[4] = { 'r' };
            temp1[5] = { 'n' };
            temp1[6] = { 'a' };
            temp1[7] = { 't' };
            temp1[8] = { 'i' };
            temp1[9] = { 'o' };
            temp1[10] = { 'n' };
            temp1[11] = { 'a' };
            temp1[12] = { 'l' };
            temp1[13] = { ' ' };
            temp1[14] = { 'd' };
            temp1[15] = { 'r' };
            temp1[16] = { 'i' };
            temp1[17] = { 'v' };
            temp1[18] = { 'e' };
            temp1[19] = { 'r' };
            temp1[20] = { ' ' };
            temp1[21] = { 'p' };
            temp1[22] = { 'e' };
            temp1[23] = { 'r' };
            temp1[24] = { 'm' };
            temp1[25] = { 'i' };
            temp1[26] = { 't' };


            int p = 1, q = 1, temp_counter = 1;

            if (temp[0] == temp1[0])
            {
                p = 1, q = 1, temp_counter = 1;
                while (temp[p++] == temp1[q++])
                {
                    temp_counter++;
                }
            }
            if (temp_counter == temp_size)
            {
                //cout << "Matched\n";
                return true;
            }
            else
            {
                cout << "You have entered\n";
                for (int i = 0; i < temp_size; i++)
                {
                    cout << temp[i];
                }
                cout << endl;
                cout << "Licence: ";
                for (int i = 0; i < 26; i++)
                {
                    cout << temp1[i];
                }
                return false;
            }


        }
        else if (temp_size == 3)
        {
            //\nMotorbike/rickshaw \nLTV \nHTV\nInternational driver permit"
            if (temp[0] == 'L')
            {
                char* temp1 = new char[5];
                temp1[0] = { 'L' };
                temp1[1] = { 'T' };
                temp1[2] = { 'V' };


                int p = 1, q = 1, temp_counter = 1;

                if (temp[0] == temp1[0])
                {
                    p = 1, q = 1, temp_counter = 1;
                    while (temp[p++] == temp1[q++])
                    {
                        temp_counter++;
                    }
                }
                if (temp_counter == temp_size)
                {
                    //cout << "Matched\n";
                    return true;
                }
                else
                {
                    cout << "You have entered\n";
                    for (int i = 0; i < temp_size; i++)
                    {
                        cout << temp[i];
                    }
                    cout << endl;
                    cout << "Licence: ";
                    for (int i = 0; i < 3; i++)
                    {
                        cout << temp1[i];
                    }
                    return false;
                }

            }
            else if (temp[0] == 'H')
            {
                char* temp1 = new char[5];
                temp1[0] = { 'L' };
                temp1[1] = { 'T' };
                temp1[2] = { 'V' };


                int p = 1, q = 1, temp_counter = 1;

                if (temp[0] == temp1[0])
                {
                    p = 1, q = 1, temp_counter = 1;
                    while (temp[p++] == temp1[q++])
                    {
                        temp_counter++;
                    }
                }
                if (temp_counter == temp_size)
                {
                    //cout << "Matched\n";
                    return true;
                }
                else
                {
                    cout << "You have entered\n";
                    for (int i = 0; i < temp_size; i++)
                    {
                        cout << temp[i];
                    }
                    cout << endl;
                    /*cout << "Licence: ";
                    for (int i = 0; i < 3; i++)
                    {
                        cout << temp1[i];
                    }*/
                    return false;
                }

            }
            else
            {
                cout << "You have  entered\n";
                for (int i = 0; i < temp_size; i++)
                {
                    cout << temp[i];
                }
                return false;
            }
        }
        else
        {
            cout << "You have entered\n";
            for (int i = 0; i < temp_size; i++)
            {
                cout << temp[i];
            }
            return false;
        }
    }
    int addCustomer(/*const char* fName, const char* lName, const Date& DOB, int age, int nid*/)
    {
        char* temp = new char[60];
        char* temp1 = new char[50];
        char* temp2 = new char[30];
        char* temp3 = new char[50];
        int size = 0;
        system("cls");
        ifstream in;
        ofstream out;
        in.open("Customer.txt");
        int linecount = 0;
        string line;
        while (getline(in, line))
        {

            linecount++;
        }
        in.close();
        if (linecount == 15)
        {
            cout << "15 customer have been adaed you cannot add more\n";
            menu();
        }
        out.open("Customer.txt", ios::app);
        out << 'C' << linecount + 1;
        for (int i = 0; i < size; i++)
        {
            out << temp[i];
        }
        out << "\t";
        cout << "Enter full name\n";
        cin.ignore();
        cin.getline(temp, 30);
        for (int i = 0; temp[i] != '\0'; i++)
        {
            size++;
        }
        for (int i = 0; i < size; i++)
        {
            out << temp[i];
        }
        out << "\t";
        cout << "Enter you address\n";
        cin.getline(temp1, 50);
        size = 0;
        for (int i = 0; temp1[i] != '\0'; i++)
        {
            size++;
        }
        for (int i = 0; i < size; i++)
        {
            out << temp1[i];
        }
        out << "\t";
        cout << "Enter you phone no e.g 03325007339\n";
        cin.getline(temp3, 30);
        if (phone_check(temp3))
        {
            cout << "Phone number added\n";
        }
        else
        {
            cout << "Wrong input\nEnter again\n";
            while (!phone_check(temp3))
            {
                cin.ignore();
                cin.getline(temp3, 30);
            }
        }
        size = 0;
        for (int i = 0; temp3[i] != '\0'; i++)
        {
            size++;
        }
        for (int i = 0; i < size; i++)
        {
            out << temp3[i];
        }
        out << "\t";
        out << endl;
        out.close();
        in.open("Customer.txt");
        linecount = 0;
        line = '\0';
        while (getline(in, line))
        {

            linecount++;
        }
        in.close();
        return linecount;
    }

	void addDriver()
	{

		char* temp = new char[60];
		char* temp1 = new char[50];
		char* temp2 = new char[30];
		char* temp3 = new char[50];
		int size = 0;
		ifstream in;
		ofstream out;
		in.open("Driver.txt");
		int linecount = 0;
		string line;
		while (getline(in, line))
		{

			linecount++;
		}
		in.close();
		if (linecount == 10)
		{
			cout << "10 drivers have been added you cannot add more\n";
			menu();
		}
		out.open("Driver.txt", ios::app);
		out << 'D' << linecount + 1;
		for (int i = 0; i < size; i++)
		{
			out << temp[i];
		}
		out << "\t";
		cout << "Enter full name\n";
		cin.ignore();
		cin.getline(temp, 30);
		for (int i = 0; temp[i] != '\0'; i++)
		{
			size++;
		}
		for (int i = 0; i < size; i++)
		{
			out << temp[i];
		}
		out << "\t";
		size = 0; int choice = 0;
		cout << "Enter 1 for 1 licence and Enter 2 for multiple licences\n";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Enter full licence type\nMotorbike/rickshaw \nLTV \nHTV\nInternational driver's permit\n";
			cin.ignore();
			cin.getline(temp, 30);
			if (licence_check(temp))
			{
				int temp_size = 0;
				for (int i = 0; temp[i] != '\0'; i++)
				{
					temp_size++;
				}
				for (int i = 0; i < temp_size; i++)
				{
					out << temp[i];
				}
			}
			else
			{
				while (!licence_check(temp))
				{

					cout << "Wrong input\nEnter again\n";
					cin.ignore();
					cin.getline(temp, 30);
					system("cls");
				}
			}
			out << "\t";
			cout << "Enter you address\n";
			cin.getline(temp1, 50);
			size = 0;
			for (int i = 0; temp1[i] != '\0'; i++)
			{
				size++;
			}
			for (int i = 0; i < size; i++)
			{
				out << temp1[i];
			}
			out << "\t";
			cout << "Enter you phone no e.g 03325007339\n";
			cin.getline(temp3, 30);
			if (phone_check(temp3))
			{
				cout << "Phone number added\n";
			}
			else
			{
				cout << "Wrong input\nEnter again\n";
				while (!phone_check(temp3))
				{
					cin.ignore();
					cin.getline(temp3, 30);
				}
			}
			size = 0;
			for (int i = 0; temp3[i] != '\0'; i++)
			{
				size++;
			}
			for (int i = 0; i < size; i++)
			{
				out << temp3[i];
			}

			out << "\t";
			out << endl;
			out.close();
		}
		else if (choice == 2)
		{
			// Multiple license types
			cin.ignore(); // Ignore newline character from the previous input

			cout << "Enter full license types \nMotorbike/rickshaw \nLTV \nHTV\nInternational driver's permit\n separated by '&&' as LTV&&HTV \n";
			cin.getline(temp, 60);

			// Write license types to the file
			out << temp;
			// Add address
			out << "\t";
			cout << "Enter your address\n";
			cin.getline(temp1, 50);
			out << temp1;

			// Add phone number
			cout << "Enter your phone number, e.g., 03325007339\n";
			cin.getline(temp3, 30);

			if (phone_check(temp3))
			{
				cout << "Phone number added\n";
			}
			else
			{
				cout << "Wrong input\nEnter again\n";
				while (!phone_check(temp3))
				{
					cin.ignore();
					cin.getline(temp3, 30);
				}
			}

			// Add phone number to the file
			out << "\t" << temp3 << "\t" << endl;

			out.close();
		}
    }
  //  void remove_driver()
   // {

   //     char* temp = new char[300];
   //     char* temp1 = new char[500];
   //     char* temp2 = new char[300];
   //     char* temp3 = new char[500];
   //     int size = 0, temp_size = 0;
   //     int counter = 0;
   //    
   //         ifstream in;
   //         ofstream out;
   //         in.open("Driver.txt");
   //         int linecount = 0;
   //         string line;
   //         while (getline(in, line))
   //         {

   //             linecount++;
   //         }
   //         in.close();
   //         if (linecount == 0)
   //         {
   //             cout << "No driver has yet been added you cannot remove one\n";
   //             menu();
   //         }
   //         else
			//{
   //             char** u_id = new char* [linecount];
   //             char** driver = new char* [linecount];
   //             int* sizes = new int[linecount];
   //             int size1 = 0;
   //             int number = 0;

   //             for (int i = 0; i < linecount; i++)
   //             {
   //                 u_id[i] = new char[5];
   //             }


   //             ifstream inn;
   //             inn.open("Driver.txt");
   //             for (int i = 0; i < linecount; i++)
   //             {
   //                 size1 = 0;
   //                 inn.getline(temp1, 250);
   //                 for (int i = 0; temp1[i] != '\0'; i++)
   //                 {
   //                     size1++;
   //                 }
   //                 sizes[i] = size1;
   //                 driver[i] = new char[size1 + 1];
   //                 int j = 0;
   //                 for (; j < size1; j++)
   //                 {
   //                     driver[i][j] = temp1[j];
   //                 }
   //                 driver[i][j] = '\0';
   //             }
   //             inn.close();


   //             cout << "Enter ID\n";
   //             cin.ignore();
   //             cin.getline(temp, 30);
   //             for (int i = 0; temp[i] != '\0'; i++)
   //             {
   //                 temp_size++;
   //             }


   //             size1 = 0;
   //             ifstream in;
   //             in.open("Driver.txt", ios::app);
   //             for (int i = 0; i < linecount; i++)
   //             {
   //                 number++;
   //                 size1 = 0;
   //                 in.getline(temp1, 250);
   //                 for (int i = 0; temp1[i] != '\0'; i++)
   //                 {
   //                     size1++;
   //                 }
   //                 int q = 1, r = 1;
   //                 int j = 0;
   //                 for (; temp1[j] != '\t'; j++)
   //                 {
   //                     u_id[i][j] = temp1[j];
   //                 }

   //                 if (u_id[i][0] == temp[0])
   //                 {
   //                     counter = 1;
   //                     while (u_id[i][q++] == temp[r++])
   //                     {
   //                         counter++;
   //                     }
   //                     if (counter == temp_size)
   //                     {
   //                         cout << "\nID matched\n";
   //                        /* cout << "Your record is\n";
   //                         for (int i = 0; i < size1; i++)
   //                         {
   //                             cout << temp[i];
   //                         }*/

   //                      /*   for (int i = number; i < linecount; i++)
   //                         {
   //                             for (int j = 0; j < sizes[i]; j++)
   //                             {
   //                                 driver[i][j] = driver[i + 1][j];
   //                             }

   //                         }
   //                         out.open("Driver.txt");
   //                         for (int i = 0; i < linecount; i++)
   //                         {
   //                             for (int j = 0; j < sizes[i]; j++)
   //                             {
   //                                 out << driver[i][j];
   //                             }
   //                             out << endl;
   //                         }
   //                         out.close();*/
			//				//for (int i = number; i < linecount - 1; i++)
			//				//{
			//				//	for (int j = 0; j < sizes[i + 1]; j++)
			//				//	{
			//				//		driver[i][j] = driver[i + 1][j];
			//				//	}
			//				//}

			//				//// Write back the modified content to the file
			//				//out.open("Driver.txt", ios::trunc);  // Open in trunc mode to clear existing content
			//				//for (int i = 0; i < linecount - 1; i++)
			//				//{
			//				//	out << driver[i] << endl;
			//				//}
			//				//out.close();

			//				//int matchedIndex = -1;
			//				//for (int i = 0; i < linecount; i++)
			//				//{
			//				//	if (strcmp(u_id[i], temp) == 0)
			//				//	{
			//				//		matchedIndex = i;
			//				//		break;
			//				//	}
			//				//}

			//				//// If the matched driver was found, exclude it from writing to the file
			//				//if (matchedIndex != -1)
			//				//{
			//				//	for (int i = 0; i < linecount; i++)
			//				//	{
			//				//		if (i != matchedIndex)
			//				//		{
			//				//			out << driver[i] << endl;
			//				//		}
			//				//	}
			//				//}
			//				//else
			//				//{
			//				//	cout << "Error: Matched driver not found.\n";
			//				//}

			//				//out.close();
			//				if (counter == temp_size)
			//				{
			//					cout << "\nID matched\n";

			//					// ... (Your other code remains unchanged)

			//					// Identify the index of the matched driver
			//					int matchedIndex = -1;
			//					for (int i = 0; i < linecount; i++)
			//					{
			//						if (strcmp(u_id[i], temp) == 0)
			//						{
			//							matchedIndex = i;
			//							break;
			//						}
			//					}

			//					// If the matched driver was found, exclude it from writing to the file
			//					if (matchedIndex != -1)
			//					{
			//						out.open("Driver.txt", ios::trunc);  // Open in trunc mode to clear existing content

			//						for (int i = 0; i < linecount; i++)
			//						{
			//							if (i != matchedIndex)
			//							{
			//								out << driver[i] << endl;
			//							}
			//						}

			//						out.close();
			//					}
			//					else
			//					{
			//						cout << "Error: Matched driver not found.\n";
			//					}
			//				}

			//			}
   //                 }
   //             }
   //             in.close();
   //         }
   // }
	
void remove_driver()
{
	char* temp = new char[30];  // Adjust the size accordingly
	int temp_size = 0;
	int counter = 0;

	ifstream in;
	ofstream out;
	in.open("Driver.txt");
	int linecount = 0;
	string line;

	// Count the number of lines in the file
	while (getline(in, line))
	{
		linecount++;
	}
	in.close();

	if (linecount == 0)
	{
		cout << "No driver has yet been added; you cannot remove one\n";
		menu();  // Assuming there is a menu() function
	}
	else
	{
		char** u_id = new char* [linecount];
		char** driver = new char* [linecount];

		for (int i = 0; i < linecount; i++)
		{
			u_id[i] = new char[6];  // Assuming ID is 5 characters long
		}

		// Read data from the file
		ifstream inn("Driver.txt");
		for (int i = 0; i < linecount; i++)
		{
			inn.getline(u_id[i], 6, '\t');
			inn.getline(temp, 30, '\t');
			int size1 = strlen(temp);
			driver[i] = new char[size1 + 1];
			for (int j = 0; j < size1; j++)
			{
				driver[i][j] = temp[j];
			}
			driver[i][size1] = '\0';
		}
		inn.close();

		// Get the ID to be removed
		cout << "Enter ID to remove\n";
		cin.ignore();
		cin.getline(temp, 30);

		// Identify the index of the matched driver
		int matchedIndex = -1;
		for (int i = 0; i < linecount; i++)
		{
			if (strcmp(u_id[i], temp) == 0)
			{
				matchedIndex = i;
				break;
			}
		}

		// If the matched driver was found, exclude it from writing to the file
		if (matchedIndex != -1)
		{
			out.open("Driver.txt", ios::trunc);  // Open in trunc mode to clear existing content

			for (int i = 0; i < linecount; i++)
			{
				if (i != matchedIndex)
				{
					out << u_id[i] << '\t' << driver[i] << endl;
				}
			}

			out.close();
			cout << "Driver with ID " << temp << " removed successfully\n";
		}
		else
		{
			cout << "Error: Matched driver not found.\n";
		}

		// Deallocate memory
		for (int i = 0; i < linecount; i++)
		{
			delete[] u_id[i];
			delete[] driver[i];
		}
		delete[] u_id;
		delete[] driver;
	}
}
    bool name_check(char* temp)
    {
        int temp_size = 0;
        for (int i = 0; temp[i] != '\0'; i++)
        {
            temp_size++;
        }
        if (temp_size == 8)
        {
            return true;
        }
        else if (temp_size == 4)
        {
            return true;
        }
        else if (temp_size == 4)
        {
            return true;
        }
        else if (temp_size == 7)
        {
            return true;
        }
        else if (temp_size == 5)
        {
            return true;
        }
        else if (temp_size == 6)
        {
            return true;
        }
        else if (temp_size == 3)
        {
            return true;
        }
        else if (temp_size == 12)
        {
            return true;
        }
        else if (temp_size == 15)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int addVehicle(/*int registrationNo, float avgMileage, const char* licenceType, const char* fuelType, const Date& manufacturingDate*/)
    {

        char* temp = new char[30];
        char* temp1 = new char[50];
        char* temp2 = new char[30];
        char* temp3 = new char[50];
        char* temp4 = new char[50];
        int size = 0;
        int flage = 0;

      
            int temp_size = 0, counter = 0;
            ifstream in;
            ofstream out;
            in.open("Vahicle.txt", ios::app);
            int linecount = 0;
            string line;
            while (getline(in, line))
            {

                linecount++;
            }
            in.close();
            if (linecount == 20)
            {
                cout << "20 vahicles have been adaed you cannot add more\n";
                menu();
            }
            out.open("Vahicle.txt", ios::app);
            out << 'V' << linecount + 1;
            for (int i = 0; i < size; i++)
            {
                out << temp[i];
            }
            out << "\t";
            size = 0;
            cout << "Enter vahicle name\nSelect from the chart\n";
            cout << "Rickshaw\nBike\nShahzor\nMazda\nTruck\nTractor-Trailor\nCar\nTanker_Truck\n";
            cin.ignore();
            cin.getline(temp1, 50);
            while (!name_check(temp1))
            {
                system("cls");
                cout << "\nWrong input!!!\nEnter again\n";
                cout << "Rickshaw\nBike\nShahzor\nMazda\nTruck\nTractor-Trailor\nCar\nTanker_truck\n";
                cin.getline(temp1, 50);
            }

            for (int i = 0; temp1[i] != '\0'; i++)
            {
                size++;
            }
            for (int i = 0; i < size; i++)
            {
                out << temp1[i];
            }
            out << "\t";
            ////////////////////////////////////////////////////////////////////////////////////////////

            cout << "Enter vahicle driver id\n";
            cin.getline(temp4, 40);
            ifstream in1;
            ofstream out1;
            in1.open("Driver.txt");
            int linecount1 = 0;
            while (getline(in1, line))
            {

                linecount1++;
            }
            in1.close();
            char** u_id = new char* [linecount1];
            char** driver = new char* [linecount1];
            int* sizes = new int[linecount1];
            int size1 = 0;
            int number = 0;

            for (int i = 0; i < linecount1; i++)
            {
                u_id[i] = new char[5];
            }


            ifstream inn;
            inn.open("Driver.txt");
            for (int i = 0; i < linecount1; i++)
            {
                size1 = 0;
                inn.getline(temp1, 250);
                for (int i = 0; temp1[i] != '\0'; i++)
                {
                    size1++;
                }
                sizes[i] = size1;
                driver[i] = new char[size1 + 1];
                int j = 0;
                for (; j < size1; j++)
                {
                    driver[i][j] = temp1[j];
                }
                driver[i][j] = '\0';
            }
            inn.close();

            for (int i = 0; temp4[i] != '\0'; i++)
            {
                temp_size++;
            }
            char* licence = new char[250];
            int counter1 = 0;
            size1 = 0;
            ifstream in2;
            in2.open("Driver.txt", ios::app);
            for (int i = 0; i < linecount1; i++)
            {
                number++;
                size1 = 0;
                in2.getline(temp1, 250);
                for (int i = 0; temp1[i] != '\0'; i++)
                {
                    size1++;
                }
                int q = 1, r = 1;
                int j = 0;
                int licence_size = 0;
                for (; temp1[j] != '\t'; j++)
                {
                    u_id[i][j] = temp1[j];
                }

                if (u_id[i][0] == temp4[0])
                {
                    counter = 1;
                    while (u_id[i][q++] == temp4[r++])
                    {
                        counter++;
                    }
                    if (counter == temp_size)
                    {
                        cout << "\nID matched\n";
                        cout << "Your record is\n";

                        for (int i = 0; i < size1; i++)
                        {
                            cout << temp1[i];
                        }
                        cout << endl;
                        for (int i = 0; i < size1; i++)
                        {
                            if (temp1[i] == '\t')
                            {
                                counter1++;
                            }
                            if (counter1 == 2)
                            {
                                int a = 0;
                                int b = i + 1;

                                for (int i = b; temp1[i] != '\t'; i++)
                                {
                                    licence[a++] = temp1[i];
                                    licence_size++;
                                }
                                break;
                            }
                        }
                        cout << "Licence of driver is\n";
                        for (int i = 0; i < licence_size; i++)
                        {
                            cout << licence[i];
                        }
                        cout << endl;
                    }
                    else
                    {
                        flage = 1;
                        continue;
                    }
                }
                if (flage == 1)
                {
                    cout << "NO ID matched\n";
                    menu();
                }
                //////////////////////////////////////////////////////////////////////////////////////////////////////////
                //////////////////////////////////////////////////////////////////////////////////////////////////////////
                /////////////////////////////////////////////////////////////////////////////////////////////////////////

                if (size == 18)
                {
                    char* temp1 = new char[30];
                    temp1[0] = { 'M' };
                    temp1[1] = { 'o' };
                    temp1[2] = { 't' };
                    temp1[3] = { 'o' };
                    temp1[4] = { 'r' };
                    temp1[5] = { 'b' };
                    temp1[6] = { 'i' };
                    temp1[7] = { 'k' };
                    temp1[8] = { 'e' };
                    temp1[9] = { '/' };
                    temp1[10] = { 'r' };
                    temp1[11] = { 'i' };
                    temp1[12] = { 'c' };
                    temp1[13] = { 'k' };
                    temp1[14] = { 's' };
                    temp1[15] = { 'h' };
                    temp1[16] = { 'a' };
                    temp1[17] = { 'w' };
                    int p = 1, q = 1, temp_counter = 1;

                    if (temp[0] == temp1[0])
                    {
                        p = 1, q = 1, temp_counter = 1;
                        while (temp[p++] == temp1[q++])
                        {
                            temp_counter++;
                        }
                    }
                    if (temp_counter == licence_size)
                    {
                        cout << "Matched\n";
                    }
                    else
                    {
                        cout << "Not matched\n";
                    }


                }
                else if (size == 29)
                {
                    char* temp1 = new char[30];
                    temp1[0] = { 'I' };
                    temp1[1] = { 'n' };
                    temp1[2] = { 't' };
                    temp1[3] = { 'e' };
                    temp1[4] = { 'r' };
                    temp1[5] = { 'n' };
                    temp1[6] = { 'a' };
                    temp1[7] = { 't' };
                    temp1[8] = { 'i' };
                    temp1[9] = { 'o' };
                    temp1[10] = { 'n' };
                    temp1[11] = { 'a' };
                    temp1[12] = { 'l' };
                    temp1[13] = { ' ' };
                    temp1[14] = { 'd' };
                    temp1[15] = { 'r' };
                    temp1[16] = { 'i' };
                    temp1[17] = { 'v' };
                    temp1[18] = { 'e' };
                    temp1[19] = { 'r' };
                    temp1[20] = { ' ' };
                    temp1[21] = { 'p' };
                    temp1[22] = { 'e' };
                    temp1[23] = { 'r' };
                    temp1[24] = { 'm' };
                    temp1[25] = { 'i' };
                    temp1[26] = { 't' };


                    int p = 1, q = 1, temp_counter = 1;

                    if (temp[0] == temp1[0])
                    {
                        p = 1, q = 1, temp_counter = 1;
                        while (temp[p++] == temp1[q++])
                        {
                            temp_counter++;
                        }
                    }
                    if (temp_counter == licence_size)
                    {
                        cout << "Matched\n";
                    }
                    else
                    {
                        cout << "Not matched\n";
                    }


                }
                else if (size == 3)
                {
                    //\nMotorbike/rickshaw \nLTV \nHTV\nInternational driver permit"
                    if (temp[0] == 'L')
                    {
                        char* temp1 = new char[5];
                        temp1[0] = { 'L' };
                        temp1[1] = { 'T' };
                        temp1[2] = { 'V' };


                        int p = 1, q = 1, temp_counter = 1;

                        if (temp[0] == temp1[0])
                        {
                            p = 1, q = 1, temp_counter = 1;
                            while (temp[p++] == temp1[q++])
                            {
                                temp_counter++;
                            }
                        }
                        if (temp_counter == licence_size)
                        {
                            cout << "Matched\n";

                        }
                        else
                        {
                            cout << "Not matched\n";
                        }

                    }
                    else if (temp[0] == 'H')
                    {
                        char* temp1 = new char[5];
                        temp1[0] = { 'L' };
                        temp1[1] = { 'T' };
                        temp1[2] = { 'V' };


                        int p = 1, q = 1, temp_counter = 1;

                        if (temp[0] == temp1[0])
                        {
                            p = 1, q = 1, temp_counter = 1;
                            while (temp[p++] == temp1[q++])
                            {
                                temp_counter++;
                            }
                        }
                        if (temp_counter == licence_size)
                        {
                            cout << "Matched\n";
                            //return true;
                        }
                        else
                        {
                            cout << "Not matched\n";
                        }

                    }
                    else
                    {
                        cout << "Not matched\n";
                        cout << "You have entered\n";
                        for (int i = 0; i < licence_size; i++)
                        {
                            cout << temp[i];
                        }
                    }
                }
                else
                {
                    cout << "Not matched\n";
                    cout << "You have entered\n";
                    for (int i = 0; i < licence_size; i++)
                    {
                        cout << temp[i];
                    }
                }





                ////////////////////////////////////////////////////////////////////
            }
            in2.close();
            cout << "Enter vahicle number\n";
            cin.getline(temp2, 50);
            size = 0;
            for (int i = 0; temp2[i] != '\0'; i++)
            {
                size++;
            }
            for (int i = 0; i < size; i++)
            {
                out << temp2[i];
            }
            out << "\t";
            cout << "Enter vahicle model\n";
            cin.getline(temp3, 30);
            for (int i = 0; temp3[i] != '\0'; i++)
            {
                out << temp3[i];
            }
            out << endl;
            out.close();
            in.open("Vahicle.txt");
            linecount = 0;
            line = '\0';
            while (getline(in, line))
            {

                linecount++;
            }
            in.close();
            return linecount;
    }
	void remove_vahicle()
	{
		char* temp = new char[30];
		char* temp1 = new char[250];  // Adjust the size accordingly
		int temp_size = 0;
		int counter = 0;
		int size = 0;

		ifstream in;
		ofstream out;
		in.open("Vahicle.txt");
		int linecount = 0;
		string line;

		// Count the number of lines in the file
		while (getline(in, line))
		{
			linecount++;
		}
		in.close();

		if (linecount == 0)
		{
			cout << "No Vehicle has yet been added; you cannot remove one\n";
			menu();  // Assuming there is a menu() function
		}
		else
		{
			char** u_id = new char* [linecount];
			char** driver = new char* [linecount];

			for (int i = 0; i < linecount; i++)
			{
				u_id[i] = new char[6];  // Assuming ID is 5 characters long
			}

			// Read data from the file
			ifstream inn("Vahicle.txt");
			for (int i = 0; i < linecount; i++)
			{
				inn.getline(temp1, 250);
				int size1 = strlen(temp1);
				driver[i] = new char[size1 + 1];
				for (int j = 0; j < size1; j++)
				{
					driver[i][j] = temp1[j];
				}
				driver[i][size1] = '\0';

				int j = 0;
				for (; temp1[j] != '\t'; j++)
				{
					u_id[i][j] = temp1[j];
				}
				u_id[i][j] = '\0';
			}
			inn.close();

			// Get the ID to be removed
			cout << "Enter ID to remove\n";
			cin.ignore();
			cin.getline(temp, 30);

			// Identify the index of the matched vehicle
			int matchedIndex = -1;
			for (int i = 0; i < linecount; i++)
			{
				if (strcmp(u_id[i], temp) == 0)
				{
					matchedIndex = i;
					break;
				}
			}

			// If the matched vehicle was found, exclude it from writing to the file
			if (matchedIndex != -1)
			{
				out.open("Vahicle.txt", ios::trunc);  // Open in trunc mode to clear existing content

				for (int i = 0; i < linecount; i++)
				{
					if (i != matchedIndex)
					{
						out << driver[i] << endl;
					}
				}

				out.close();
				cout << "Vehicle with ID " << temp << " removed successfully\n";
			}
			else
			{
				cout << "Error: Matched vehicle not found.\n";
			}

			// Deallocate memory
			for (int i = 0; i < linecount; i++)
			{
				delete[] u_id[i];
				delete[] driver[i];
			}
			delete[] u_id;
			delete[] driver;
		}
	}
  /*  void remove_vahicle()
    {
        char* temp = new char[30];
        char* temp1 = new char[50];
        char* temp2 = new char[30];
        char* temp3 = new char[50];
        char* temp4 = new char[50];
        int temp_size = 0;
        int counter = 0;
        int size = 0;
        int flage = 0;
        size = 0, temp_size = 0;
        counter = 0;
        ifstream in;
        ofstream out;
        in.open("Vahicle.txt");
        int linecount = 0;
        string line;
        while (getline(in, line))
        {

            linecount++;
        }
        in.close();
        if (linecount == 0)
        {
            cout << "No Vahicle has yet been added you cannot remove one\n";
            menu();
        }
        else
        {
            char** u_id = new char* [linecount];
            char** driver = new char* [linecount];
            int* sizes = new int[linecount];
            int size1 = 0;
            int number = 0;

            for (int i = 0; i < linecount; i++)
            {
                u_id[i] = new char[5];
            }


            ifstream inn;
            inn.open("Vahicle.txt");
            for (int i = 0; i < linecount; i++)
            {
                inn.getline(temp1, 250);
                for (int i = 0; temp1[i] != '\0'; i++)
                {
                    size1++;
                }
                sizes[i] = size1;
                driver[i] = new char[size1 + 1];
                int j = 0;
                for (; j < size1; j++)
                {
                    driver[i][j] = temp1[j];
                }
                driver[i][j] = '\0';
            }
            inn.close();


            cout << "Enter ID\n";
            cin.ignore();
            cin.getline(temp, 30);
            for (int i = 0; temp[i] != '\0'; i++)
            {
                temp_size++;
            }


            size1 = 0;
            ifstream in;
            in.open("Vahicle.txt", ios::app);

            for (int i = 0; i < linecount; i++)
            {
                number++;
                size1 = 0;
                in.getline(temp1, 250);
                for (int i = 0; temp1[i] != '\0'; i++)
                {
                    size1++;
                }
                int q = 1, r = 1;
                int j = 0;
                for (; temp1[j] != '\t'; j++)
                {
                    u_id[i][j] = temp1[j];
                }

                if (u_id[i][0] == temp[0])
                {
                    counter = 1;
                    while (u_id[i][q++] == temp[r++])
                    {
                        counter++;
                    }
                    if (counter == temp_size)
                    {
                        cout << "\nID matched\n";
                        cout << "Your record is\n";
                        for (int i = 0; i < size1; i++)
                        {
                            cout << temp1[i];
                        }
                        if (linecount == 1)
                        {
                            out.open("Vahicle.txt");
                            out.close();
                        }
                        else
                        {
                            int x = 0;
                            for (int i = number; i <= linecount; i++)
                            {
                                driver[x][j] = driver[x + 1][j];
                                x++;
                            }
                            linecount--;
                            out.open("Vahicle.txt");
                            for (int i = 0; i < linecount; i++)
                            {
                                for (int j = 0; j < sizes[i]; j++)
                                {
                                    out << driver[i][j];
                                }
                                out << endl;
                            }
                            out.close();
                        }
                    }
                }
            }
            in.close();
        }
    }*/
    void printAllCustomers() const
    {
        int size1 = 0;
        int number = 0;
        char* temp1 = new char[100];


        ifstream in;
        ofstream out;
        in.open("Customer.txt");
        int linecount = 0;
        string line;
        while (getline(in, line))
        {

            linecount++;
        }
        in.close();
        char** customer = new char* [linecount];
        int* sizes = new int[linecount];

        ifstream inn;
        inn.open("Customer.txt");
        for (int i = 0; i < linecount; i++)
        {
            inn.getline(temp1, 250);
			size1 = 0;
            for (int i = 0; temp1[i] != '\0'; i++)
            {
                size1++;
            }
            sizes[i] = size1;
            customer[i] = new char[size1 + 1];
            int j = 0;
            for (; j < size1; j++)
            {
                customer[i][j] = temp1[j];
            }
            customer[i][j] = '\0';
        }
        inn.close();
        cout << "\nList of customers is \n";
        for (int i = 0; i < linecount; i++)
        {
            for (int j = 0; j < sizes[i]; j++)
            {
                cout << customer[i][j];
            }
            cout << endl;
        }
    }
    void printAllDrivers() const
    {
        int size1 = 0;
        int number = 0;
        char* temp1 = new char[100];


        ifstream in;
        ofstream out;
        in.open("Driver.txt");
        int linecount = 0;
        string line;
        while (getline(in, line))
        {

            linecount++;
        }
        in.close();
        char** drivers = new char* [linecount];
        int* sizes = new int[linecount];

        ifstream inn;
        inn.open("Driver.txt");
        for (int i = 0; i < linecount; i++)
        {
            inn.getline(temp1, 250);
			size1 = 0;
            for (int i = 0; temp1[i] != '\0'; i++)
            {
                size1++;
            }
            sizes[i] = size1;
            drivers[i] = new char[size1 + 1];
            int j = 0;
            for (; j < size1; j++)
            {
                drivers[i][j] = temp1[j];
            }
            drivers[i][j] = '\0';
        }
        inn.close();
        cout << "\nList of drivers is \n";
        for (int i = 0; i < linecount; i++)
        {
            for (int j = 0; j < sizes[i]; j++)
            {
                cout << drivers[i][j];
            }
            cout << endl;
        }
    }
    void printAllVehicles() const
    {
        int size1 = 0;
        int number = 0;
        char* temp1 = new char[100];


        ifstream in;
        ofstream out;
        in.open("Vahicle.txt");
        int linecount = 0;
        string line;
        while (getline(in, line))
        {

            linecount++;
        }
        in.close();
        char** Vahicles = new char* [linecount];
        int* sizes = new int[linecount];

        ifstream inn;
        inn.open("Vahicle.txt");
        for (int i = 0; i < linecount; i++)
        {
            inn.getline(temp1, 250);
			size1 = 0;
            for (int i = 0; temp1[i] != '\0'; i++)
            {
                size1++;
            }
            sizes[i] = size1;
            Vahicles[i] = new char[size1 + 1];
            int j = 0;
            for (; j < size1; j++)
            {
                Vahicles[i][j] = temp1[j];
            }
            Vahicles[i][j] = '\0';
        }
        inn.close();
        cout << "\nList of vahicles is \n";
        for (int i = 0; i < linecount; i++)
        {
            for (int j = 0; j < sizes[i]; j++)
            {
                cout << Vahicles[i][j];
            }
            cout << endl;
        }
    }
    //void printVehicleDetails() const
    //{
    //    char* temp = new char[300];
    //    char* temp1 = new char[500];
    //    char* temp2 = new char[300];
    //    char* temp3 = new char[500];
    //    int size = 0, temp_size = 0;
    //    int counter = 0;
    //    ifstream inn;
    //    ofstream out;
    //    inn.open("Vahicle.txt");
    //    int linecount = 0;
    //    string line;
    //    while (getline(inn, line))
    //    {

    //        linecount++;
    //    }
    //    inn.close();
    //    char** u_id = new char* [linecount];
    //    char** driver = new char* [linecount];
    //    int* sizes = new int[linecount];
    //    int size1 = 0;
    //    int number = 0;

    //    ///////////////////////////////

    //    cout << "Enter ID\n";
    //    cin.getline(temp, 30);
    //    for (int i = 0; temp[i] != '\0'; i++)
    //    {
    //        temp_size++;
    //    }


    //    size1 = 0;
    //    ifstream in;
    //    in.open("Vahicle.txt");
    //    for (int i = 0; i < linecount; i++)
    //    {
    //        number++;
    //        size1 = 0;
    //        in.getline(temp1, 250);
    //        for (int i = 0; temp1[i] != '\0'; i++)
    //        {
    //            size1++;
    //        }
    //        int q = 1, r = 1;
    //        int j = 0;
    //        for (; temp1[j] != '\t'; j++)
    //        {
    //            u_id[i][j] = temp1[j];
    //        }

    //        if (u_id[i][0] == temp[0])
    //        {
    //            counter = 1;
    //            while (u_id[i][q++] == temp[r++])
    //            {
    //                counter++;
    //            }
    //            if (counter == temp_size)
    //            {
    //                cout << "\nID matched\n";
    //                cout << "Your record is\n";
    //                for (int i = 0; i < size; i++)
    //                {
    //                    cout << temp[i];
    //                }

    //            }
    //        }
    //    }
    //    in.close();

    //}
	void printVehicleDetails()
	{
		char* temp = new char[30];
		char* temp1 = new char[250];
		int temp_size = 0;
		int counter = 0;

		ifstream in;
		in.open("Vahicle.txt");
		int linecount = 0;
		string line;

		while (getline(in, line))
		{
			linecount++;
		}
		in.close();

		if (linecount == 0)
		{
			cout << "No Vehicle has yet been added; cannot print details\n";
			menu();
		}
		else
		{
			char** u_id = new char* [linecount];
			char** driver = new char* [linecount];

			for (int i = 0; i < linecount; i++)
			{
				u_id[i] = new char[6];
			}

			cout << "Enter ID to print details\n";
			cin.ignore();
			cin.getline(temp, 30);

			ifstream inn("Vahicle.txt");
			for (int i = 0; i < linecount; i++)
			{
				inn.getline(temp1, 250);
				int size1 = strlen(temp1);
				driver[i] = new char[size1 + 1];
				for (int j = 0; j < size1; j++)
				{
					driver[i][j] = temp1[j];
				}
				driver[i][size1] = '\0';

				int j = 0;
				for (; temp1[j] != '\t'; j++)
				{
					u_id[i][j] = temp1[j];
				}
				u_id[i][j] = '\0';

				if (strcmp(u_id[i], temp) == 0)
				{
					cout << "\nID matched\n";
					cout << "Your record is\n";
					cout << temp1 << endl;
					break;
				}
			}
			inn.close();

			for (int i = 0; i < linecount; i++)
			{
				delete[] u_id[i];
				delete[] driver[i];
			}
			delete[] u_id;
			delete[] driver;
		}
	}
	bool driver_name_check(char* temp)
	{
		int temp_size = 0;

		for (int i = 0; temp[i] != '\0'; i++)
		{
			temp_size++;
		}
		ifstream in;
		in.open("Driver.txt");
		int linecount = 0;
		string line;
		while (getline(in, line))
		{

			linecount++;
		}
		in.close();
		char** names = new char* [linecount];
		int name_counter = 0, size1 = 0;
		int flage = 0;
		int matched_counter = 0, p = 0, q = 0;
		char* temp1 = new char[256];
		if (linecount == 0)
		{
			cout << "No driver has been added yet\n";
			menu();
		}
		else
		{
			ifstream inn;
			inn.open("Driver.txt");
			for (int i = 0; i < linecount; i++)
			{
				size1 = 0;
				inn.getline(temp1, 250);
				for (int i = 0; temp1[i] != '\t'; i++)
				{
					size1++;
				}
				names[i] = new char[size1 + 1];
				int j = 0;
				for (; j < size1; j++)
				{
					names[i][j] = temp1[j];
					cout << names[i][j];
				}
				cout << endl;
				names[i][j] = '\0';
			}
			inn.close();
			for (int i = 0; i < linecount; i++)
			{
				if (temp[0] == names[i][0])
				{
					matched_counter = 1;
					p = 1, q = 1;
					while (temp[p++] == names[i][q++])
					{
						matched_counter++;
					}
				}
				if (matched_counter - 1 == temp_size)
				{
					flage = 1;
				}
			}
			if (flage == 1)
			{
				system("cls");
				cout << "Id matched\n";
				return true;
			}
			else
			{
				system("cls");
				cout << "Id does't match\n";
				return false;
			}
		}
	}
	bool getcounter(char* temp3, int* sizes, char** names, char c)
	{
		if (c == '1')
		{
			int counter2 = 0, temp_c = 0, name_c = 0;
			int name_counter = 0;
			ifstream in;
			ofstream out;
			in.open("Vahicle.txt");
			int linecount = 0;
			string line;
			while (getline(in, line))
			{
				linecount++;
			}
			in.close();


			for (int i = 0; i < linecount; i++)
			{
				for (int j = 0; j < sizes[i]; j++)
				{
					if (temp3[j] == '\t')
					{
						int k = j + 1;
						if (temp3[k] == names[name_counter][0])
						{
							temp_c = k + 1, name_c = 1;
							counter2 = 1;
							while (temp3[temp_c++] == names[name_counter][name_c++])
							{
								counter2++;
							}
						}
						name_counter++;
						if (counter2 != 8)
						{
							return false;
						}
						else
						{
							return true;
						}
					}
				}
			}
		}
		else if (c == '2')
		{
			int counter2 = 0, temp_c = 0, name_c = 0;
			int flage = 0;
			ifstream in;
			ofstream out;
			int name_counter = 0;
			in.open("Vahicle.txt");
			int linecount = 0;
			string line;
			while (getline(in, line))
			{
				linecount++;
			}
			in.close();
			for (int i = 0; i < linecount; i++)
			{
				for (int j = 0; j < sizes[i]; j++)
				{
					if (temp3[j] == '\t')
					{
						int k = j + 1;
						//////////////////////////////////
						if (temp3[k] == names[i][0])
						{
							temp_c = k + 1, name_c = 1;
							counter2 = 1;
							while (temp3[temp_c++] == names[i][name_c++])
							{
								counter2++;
							}
						}
						if (counter2 == 4)
						{
							flage = 1;
						}

					}
				}
			}
			if (flage != 1)
			{
				return false;
			}
			else
			{
				return true;
			}

		}
		else if (c == '3')
		{
			int counter2 = 0, temp_c = 0, name_c = 0, flage = 0;
			ifstream in;
			ofstream out;
			in.open("Vahicle.txt");
			int linecount = 0;
			string line;
			while (getline(in, line))
			{
				linecount++;
			}
			in.close();
			for (int i = 0; i < linecount; i++)
			{
				for (int j = 0; j < sizes[i]; j++)
				{
					if (temp3[j] == '\t')
					{
						int k = j + 1;
						//////////////////////////////////
						if (temp3[k] == names[i][0])
						{
							temp_c = k + 1, name_c = 1;
							counter2 = 1;
							while (temp3[temp_c++] == names[i][name_c++])
							{
								counter2++;
							}
						}
						if (counter2 == 7)
						{
							flage = 1;
						}

					}
				}
			}
			if (flage != 1)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else if (c == '4')
		{
			int counter2 = 0, temp_c = 0, name_c = 0;
			ifstream in;
			ofstream out;
			int flage = 0;
			char* temp = new char[8];
			temp[0] = { 'M' };
			temp[1] = { 'a' };
			temp[2] = { 'z' };
			temp[3] = { 'd' };
			temp[4] = { 'a' };
			in.open("Vahicle.txt");
			int linecount = 0;
			string line;
			while (getline(in, line))
			{
				linecount++;
			}
			in.close();


			for (int i = 0; i < linecount; i++)
			{
				for (int j = 0; j < sizes[i]; j++)
				{
					if (temp3[j] == '\t')
					{
						int k = j + 1;
						int zz = k;
						//////////////////////////////////
						if (temp3[k] == names[i][0])
						{
							temp_c = k + 1, name_c = 1;
							counter2 = 1;
							while (temp3[temp_c++] == names[i][name_c++])
							{
								counter2++;
							}
						}
						int count_n = 0;
						if (counter2 != 5)
						{
							flage = 0;
							break;
						}
						else
						{


							for (int i = 0; i < 5; i++)
							{

								if (temp3[zz++] == temp[i])
								{

									count_n++;
								}
							}
							if (count_n == 5)
							{
								flage = 1;
								break;
							}
							else
							{
								flage = 0;
								break;
							}
						}
					}

				}
			}
			if (flage == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (c == '5')
		{
			int counter2 = 0, temp_c = 0, name_c = 0;
			ifstream in;
			ofstream out;
			int flage2 = 0;
			int flage = 0;
			int zz = 0;
			int count_n = 0;
			char* temp = new char[8];
			temp[0] = { 'T' };
			temp[1] = { 'r' };
			temp[2] = { 'u' };
			temp[3] = { 'c' };
			temp[4] = { 'k' };
			in.open("Vahicle.txt");
			int linecount = 0;
			string line;
			while (getline(in, line))
			{
				linecount++;
			}
			in.close();
			for (int i = 0; i < linecount; i++)
			{
				for (int j = 0; j < sizes[i]; j++)
				{
					if (temp3[j] == '\t')
					{
						int k = j + 1;
						int zz = k;
						//////////////////////////////////
						if (temp3[k] == names[i][0])
						{
							temp_c = k + 1, name_c = 1;
							counter2 = 1;
							while (temp3[temp_c++] == names[i][name_c++])
							{
								counter2++;
							}
						}
						int count_n = 0;
						if (counter2 != 5)
						{
							flage = 0;
							break;
						}
						else
						{
							for (int i = 0; i < 5; i++)
							{

								if (temp3[zz++] == temp[i])
								{
									count_n++;
								}
							}
							if (count_n == 5)
							{

								flage = 1;
								flage2 = 1;
								break;
							}
							else
							{
								flage = 0;
								break;
							}
						}
					}

				}
			}
			if (flage == 1 || flage2 == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (c == '6')
		{
			int counter2 = 0, temp_c = 0, name_c = 0;
			ifstream in;
			ofstream out;
			int flage = 0;
			in.open("Vahicle.txt");
			int linecount = 0;
			string line;
			while (getline(in, line))
			{
				linecount++;
			}
			in.close();
			for (int i = 0; i < linecount; i++)
			{
				for (int j = 0; j < sizes[i]; j++)
				{
					if (temp3[j] == '\t')
					{
						int k = j + 1;
						//////////////////////////////////
						if (temp3[k] == names[i][0])
						{
							temp_c = k + 1, name_c = 1;
							counter2 = 1;
							while (temp3[temp_c++] == names[i][name_c++])
							{
								counter2++;
							}
						}
						if (counter2 != 15)
						{
							flage = 0;
						}
						else
						{
							flage = 1;
						}
					}
				}
			}
			if (flage == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (c == '7')
		{
			int counter2 = 0, temp_c = 0, name_c = 0;
			ifstream in;
			ofstream out;
			int flage = 0;
			in.open("Vahicle.txt");
			int linecount = 0;
			string line;
			while (getline(in, line))
			{
				linecount++;
			}
			in.close();
			for (int i = 0; i < linecount; i++)
			{
				for (int j = 0; j < sizes[i]; j++)
				{
					if (temp3[j] == '\t')
					{
						int k = j + 1;
						//////////////////////////////////
						if (temp3[k] == names[i][0])
						{
							temp_c = k + 1, name_c = 1;
							counter2 = 1;
							while (temp3[temp_c++] == names[i][name_c++])
							{
								counter2++;
							}
						}
						if (counter2 != 3)
						{
							flage = 0;
						}
						else
						{
							flage = 1;
						}
					}
				}
			}
			if (flage == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (c == '8')
		{
			int counter2 = 0, temp_c = 0, name_c = 0;
			ifstream in;
			int flage = 0;
			ofstream out;
			in.open("Vahicle.txt");
			int linecount = 0;
			string line;
			while (getline(in, line))
			{
				linecount++;
			}
			in.close();
			for (int i = 0; i < linecount; i++)
			{
				for (int j = 0; j < sizes[i]; j++)
				{
					if (temp3[j] == '\t')
					{
						int k = j + 1;
						//////////////////////////////////
						if (temp3[k] == names[i][0])
						{
							temp_c = k + 1, name_c = 1;
							counter2 = 1;
							while (temp3[temp_c++] == names[i][name_c++])
							{
								counter2++;
							}
						}
						if (counter2 == 12)
						{
							flage = 1;
						}
						else
						{
							flage = 0;
						}
					}
				}
			}
			if (flage == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			cout << "\nInvalid input\n";
		}
	}
    int addServiceRequest()
    {

		int choice = 0;
		int choice2 = 0;
		int weight = 0, distance = 0, rickshaw_fair = 0, bike_fair, choice1 = 0;
		char* temp1 = new char[256];
		int size1 = 0;
		system("cls");
		cout << "Enter 1 for delivery\nEnter 2 for ride\n";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			cout << "Enter 1 for intercity\nEnter 2 for out of city\n";
			cin >> choice2;
			if (choice2 == 1)
			{
				system("cls");
				cout << "Enter the weight of the good\n";
				cin >> weight;
				if (weight <= 70)
				{
					system("cls");
					cout << "As weight is less than 70 kg\n";
					cout << "The available vahicles are\nRickshaw\nBike\n";
					cout << "Enter distance in km\n";
					cin >> distance;
					system("cls");
					bike_fair = distance * 20 + weight * 3;
					rickshaw_fair = distance * 30 + weight * 5;
					cout << "The rickshaw fair is \t" << rickshaw_fair << endl;
					cout << "The bike fair is \t" << bike_fair << endl;
					cout << "Enter 1 to book rickshaw\nEnter 2 to book bike\n";
					cin >> choice1;
					system("cls");
					if (choice1 == 1)
					{
						char* temp = new char[8];
						temp[0] = { 'R' };
						temp[1] = { 'i' };
						temp[2] = { 'c' };
						temp[3] = { 'k' };
						temp[4] = { 's' };
						temp[5] = { 'h' };
						temp[6] = { 'a' };
						temp[7] = { 'w' };
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						//int matched_choice = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							iff.getline(temp3, 256);
							char c = '1';
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						iff.close();
						cout << "The available rikshaws are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
									int size = 0;
									for (int i = 0; driver_id[i] != '\0'; i++)
									{
										size++;
									}
									for (int i = 0; i < size; i++)
									{
										output << temp[i];
									}
									output << "\t";
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name
								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}
					else if (choice1 == 2)
					{
						/////////////////////////////////////////////////////////

						char* temp = new char[8];
						temp[0] = { 'B' };
						temp[1] = { 'i' };
						temp[2] = { 'k' };
						temp[3] = { 'e' };
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						cout << "\nNames are\n";
						for (int i = 0; i < linecount; i++)
						{
							for (int l = 0; l < counters[i]; l++)
							{
								cout << names[i][l];
							}
							cout << endl;

						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}

						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							char c = '2';
							iff.getline(temp3, 256);
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available bikes are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
									int size = 0;
									for (int i = 0; driver_id[i] != '\0'; i++)
									{
										size++;
									}
									for (int i = 0; i < size; i++)
									{
										output << temp[i];
									}
									output << "\t";
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}
					else
					{
						cout << "Wrong input\n";
					}
				}
				else if (weight > 70)
				{
					cout << "\nAs weight as greater then 70\n";
					cout << "The available vahicles are Shahzoor and Mazda_Titan\n ";
					cout << "Enter distance in km\n";
					cin >> distance;
					int shahzoor_fair = distance * 60 + weight * 6;
					int mazda_fair = distance * 70 + weight * 7;
					cout << "The shahzoor fair is \t" << shahzoor_fair << endl;
					cout << "The mazda fair is \t" << mazda_fair << endl;
					cout << "Enter 1 to book shahzor\nEnter 2 to book mazda\n";
					cin >> choice1;
					if (choice1 == 1)
					{
						char* temp = new char[8];
						temp[0] = { 'S' };
						temp[1] = { 'h' };
						temp[2] = { 'a' };
						temp[3] = { 'h' };
						temp[4] = { 'z' };
						temp[5] = { 'o' };
						temp[6] = { 'r' };
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							iff.getline(temp3, 256);
							char c = '3';
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available shahzors are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}
					else if (choice1 == 2)
					{
						//////////////////////////////////

						char* temp = new char[8];
						temp[0] = { 'M' };
						temp[1] = { 'a' };
						temp[2] = { 'z' };
						temp[3] = { 'd' };
						temp[4] = { 'a' };
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							char c = '4';
							iff.getline(temp3, 256);
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available mazdas are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
									int size = 0;
									for (int i = 0; driver_id[i] != '\0'; i++)
									{
										size++;
									}
									for (int i = 0; i < size; i++)
									{
										output << temp[i];
									}
									output << "\t";
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
						///////////////////////////////////
					}
					else
					{
						cout << "Wrong input\n";
					}
				}

			}
			else if (choice2 == 2)
			{
				choice1 = 0;
				cout << "The available vahicles are Trucks, Tractor-Trailor, Car-Transporter, Tanker-Truck\n ";
				cout << "\nEnter weight of good/goods\n";
				cin >> weight;

				cout << "Enter distance in km\nDistance must be greater than 50 km for out of city\n";
				cin >> distance;
				while (distance <= 50)
				{
					system("cls");
					cout << "Distance must be greater than 50\nEnter again\n";
					cin >> distance;
				}
				int trucks_fair = distance * 80 + weight * 9;
				int Tractor_trailor_fair = distance * 95 + weight * 7;
				int car_transportor_fair = distance * 65 + weight * 9;
				int tanker_truck_fair = distance * 95 + weight * 6;

				if (weight <= 800)
				{
					system("cls");
					cout << "As weight is below 800 kg Car service is also available\n";
					cout << "The trucks fair is \t" << trucks_fair << endl;
					cout << "The tracktor_trailor fair is \t" << Tractor_trailor_fair << endl;
					cout << "The car_transportor fair is \t" << car_transportor_fair << endl;
					cout << "The tanker_truck fair is \t" << tanker_truck_fair << endl;
					cout << "Enter 1 to book Trucks\nEnter 2 to book Tractor-Trailor\nEnter 3 to book Car-Transporter\nEnter 4 to book Tanker-Truck\n ";
					cin >> choice1;
					if (choice1 == 1)
					{
						char* temp = new char[8];
						temp[0] = { 'T' };
						temp[1] = { 'r' };
						temp[2] = { 'u' };
						temp[3] = { 'c' };
						temp[4] = { 'k' };
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							iff.getline(temp3, 256);
							char c = '5';
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;


								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available trucks are\n";

						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
									int size = 0;
									for (int i = 0; driver_id[i] != '\0'; i++)
									{
										size++;
									}
									for (int i = 0; i < size; i++)
									{
										output << temp[i];
									}
									output << "\t";
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}
					else if (choice1 == 2)
					{
						//Tractor-Trailor
						char* temp = new char[20];
						temp[0] = { 'T' };
						temp[1] = { 'r' };
						temp[2] = { 'a' };
						temp[3] = { 'c' };
						temp[4] = { 't' };
						temp[5] = { 'o' };
						temp[6] = { 'r' };
						temp[7] = { '_' };
						temp[8] = { 'T' };
						temp[9] = { 'r' };
						temp[10] = { 'a' };
						temp[11] = { 'i' };
						temp[12] = { 'l' };
						temp[13] = { 'o' };
						temp[14] = { 'r' };///////////////////////////////////////////////////////// 
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];
									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							iff.getline(temp3, 256);
							char c = '6';
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available Tractor-Trailor are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
								}
								int size = 0;
								for (int i = 0; driver_id[i] != '\0'; i++)
								{
									size++;
								}
								for (int i = 0; i < size; i++)
								{
									output << temp[i];
								}
								output << "\t";
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}
					else if (choice1 == 3)
					{
						//Car-Transporter
						char* temp = new char[8];
						temp[0] = { 'C' };
						temp[1] = { 'a' };
						temp[2] = { 'r' };

						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							iff.getline(temp3, 256);
							char c = '7';
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available Car-Transporter are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
									int size = 0;
									for (int i = 0; driver_id[i] != '\0'; i++)
									{
										size++;
									}
									for (int i = 0; i < size; i++)
									{
										output << temp[i];
									}
									output << "\t";
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}
					else if (choice1 == 4)
					{
						//Tanker-Truck
						char* temp = new char[18];
						temp[0] = { 'T' };
						temp[1] = { 'a' };
						temp[2] = { 'n' };
						temp[3] = { 'k' };
						temp[4] = { 'e' };
						temp[5] = { 'r' };
						temp[6] = { '_' };
						temp[7] = { 'T' };
						temp[8] = { 'r' };
						temp[9] = { 'u' };
						temp[10] = { 'c' };
						temp[11] = { 'k' };
						///////////////////
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							iff.getline(temp3, 256);
							char c = '8';
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available Tanker-Truck are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
									int size = 0;
									for (int i = 0; driver_id[i] != '\0'; i++)
									{
										size++;
									}
									for (int i = 0; i < size; i++)
									{
										output << temp[i];
									}
									output << "\t";
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}

					else
					{
						cout << "Wrong input\n";
					}
				}
				else if (weight > 800)
				{
					cout << "The trucks fair is \t" << trucks_fair << endl;
					cout << "The tracktor_trailor fair is \t" << Tractor_trailor_fair << endl;
					cout << "The tanker_truck fair is \t" << tanker_truck_fair << endl;
					cout << "Enter 1 to book Trucks\nEnter 2 to book Tractor_Trailor\nEnter 3 to book Tanker_Truck\n ";
					cin >> choice1;
					if (choice1 == 1)
					{
						char* temp = new char[8];
						temp[0] = { 'T' };
						temp[1] = { 'r' };
						temp[2] = { 'u' };
						temp[3] = { 'c' };
						temp[4] = { 'k' };
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							iff.getline(temp3, 256);
							char c = '5';
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available trucks are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
									int size = 0;
									for (int i = 0; driver_id[i] != '\0'; i++)
									{
										size++;
									}
									for (int i = 0; i < size; i++)
									{
										output << temp[i];
									}
									output << "\t";
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}
					else if (choice1 == 2)
					{
						char* temp = new char[20];
						temp[0] = { 'T' };
						temp[1] = { 'r' };
						temp[2] = { 'a' };
						temp[3] = { 'c' };
						temp[4] = { 't' };
						temp[5] = { 'o' };
						temp[6] = { 'r' };
						temp[7] = { '-' };
						temp[8] = { 'T' };
						temp[9] = { 'r' };
						temp[10] = { 'a' };
						temp[11] = { 'i' };
						temp[12] = { 'l' };
						temp[13] = { 'o' };
						temp[14] = { 'r' };
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							char c = '6';
							iff.getline(temp3, 256);
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available tracktor_trailors are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
									int size = 0;
									for (int i = 0; driver_id[i] != '\0'; i++)
									{
										size++;
									}
									for (int i = 0; i < size; i++)
									{
										output << temp[i];
									}
									output << "\t";
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}
					else if (choice1 == 3)
					{
						char* temp = new char[18];
						temp[0] = { 'T' };
						temp[1] = { 'a' };
						temp[2] = { 'n' };
						temp[3] = { 'k' };
						temp[4] = { 'e' };
						temp[5] = { 'r' };
						temp[6] = { '_' };
						temp[7] = { 'T' };
						temp[8] = { 'r' };
						temp[9] = { 'u' };
						temp[10] = { 'c' };
						temp[11] = { 'k' };
						ifstream in;
						ofstream out;
						in.open("Vahicle.txt");
						int linecount = 0;
						string line;
						while (getline(in, line))
						{

							linecount++;
						}
						in.close();
						int* sizes = new int[linecount];
						int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
						int* counters = new int[linecount];
						char** names = new char* [linecount];
						int y = 0, z = 0, zz = 0;
						ifstream innnn;
						innnn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							size1 = 0;
							innnn.getline(temp1, 250);
							for (int i = 0; temp1[i] != '\0'; i++)
							{
								size1++;
							}
							sizes[i] = size1;
						}
						innnn.close();
						ifstream innn;
						innn.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							innn.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									for (int k = j + 1; temp1[k] != '\t'; k++)
									{
										counter++;
									}

									counters[i] = counter;
									names[i] = new char[counter];


									break;
								}
							}
						}
						innn.close();
						ifstream iin;
						iin.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							counter = 0;
							iin.getline(temp1, 250);
							for (int j = 0; j < sizes[i]; j++)
							{
								if (temp1[j] == '\t')
								{
									int k = j + 1;
									for (int l = 0; l < counters[i]; l++)
									{
										names[i][counter++] = temp1[k++];
									}
									names[i][counter] = '\0';
									break;
								}
							}
						}
						iin.close();
						int temp_c = 1, name_c = 1;
						int pp = 0;
						char temp3[256];
						int matched_ind[10]; int mathced_ind_counter = 0;
						int counter2 = 0; matched_counter = 0;;
						for (int i = 0; i < linecount; i++)
						{
							if (temp[0] == names[i][0])
							{
								temp_c = 1, name_c = 1;
								counter2 = 1;
								while (temp[temp_c++] == names[i][name_c++])
								{
									counter2++;
								}
							}
							if (counter2 == counters[pp++])
							{
								matched_ind[mathced_ind_counter++] = i;
								cout << "\nMatched\n";
								matched_counter++;
							}
						}
						if (matched_counter == 0)
						{
							cout << "\nYou have to add vahicle first\n";
							menu();
							return 0;
						}
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						/*for (int i = 0; i < linecount; i++)
						{
							if (counters[i] !=8 )
							{
								for (int j = i + 1; j < linecount; j++)
								{
									counters[i] = counters[j];
								}
								linecount--;
							}
						}*/
						cout << "\nMatched indexes are\n";
						for (int i = 0; i < linecount; i++)
						{
							cout << counters[i] << endl;
						}
						char** vahicle_info = new char* [matched_counter];
						int* new_sizes = new int[matched_counter];
						ifstream iff;
						int s = 0;
						pp = 0;
						int new_sizes_c = 0;
						int vahicle_info_c = 0;
						ofstream off;
						iff.open("Vahicle.txt");
						for (int i = 0; i < linecount; i++)
						{
							char c = '8';
							iff.getline(temp3, 256);
							if (getcounter(temp3, sizes, names, c))
							{
								new_sizes_c = 0;
								for (int i = 0; temp3[i] != '\0'; i++)
								{
									new_sizes_c++;
								}
								new_sizes[s++] = new_sizes_c;
								vahicle_info[vahicle_info_c] = new char[new_sizes_c];
								for (int k = 0; k < new_sizes_c; k++)
								{
									vahicle_info[vahicle_info_c][k] = temp3[k];
								}
								vahicle_info_c++;
								continue;
							}
							else
							{
								continue;
							}
						}
						vahicle_info_c = 0;
						system("cls");
						cout << "The available tanker_trucks are\n";
						for (int i = 0; i < matched_counter; i++)
						{

							for (int j = 0; j < new_sizes[i]; j++)
							{
								cout << vahicle_info[vahicle_info_c][j];
							}
							vahicle_info_c++;
							cout << endl;
						}
						ofstream output;
						output.open("Vahicle_Travel_History.txt");
						output.close();
						int matched_choice = 0;
						char* driver_id = new char[256];
						cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
						cin >> matched_choice;
						while (matched_choice<0 && matched_choice>matched_counter)
						{
							cout << "Wrong input\nEnter again\n";
							cin >> matched_choice;
						}
						output.open("Vahicle_Travel_History.txt", ios::app);
						for (int i = 0; i < matched_counter; i++)
						{
							if (i == matched_choice - 1)
							{
								for (int j = 0; j < new_sizes[i]; j++)
								{
									output << vahicle_info[i][j];
								}
								//////////////////////////////////////

								std::time_t now = std::time(0);
								tm localtime = {};
								if (localtime_s(&localtime, &now) != 0)
								{
									return 1;
								}
								int year = localtime.tm_year + 1900;
								int month = localtime.tm_mon + 1;
								int day = localtime.tm_mday;

								output << "\t" << day << "/" << month << "/" << year;
								cout << "Enter driver id\n";
								cin.ignore();
								cin.getline(driver_id, 256);
								if (driver_name_check(driver_id))
								{

								}
								else
								{
									while (!driver_name_check(driver_id))
									{
										//system("cls");
										cout << "Enter again!!!\n";
										cin.ignore();
										cin.getline(driver_id, 256);
									}
									int size = 0;
									for (int i = 0; driver_id[i] != '\0'; i++)
									{
										size++;
									}
									for (int i = 0; i < size; i++)
									{
										output << temp[i];
									}
									output << "\t";
								}
								/////////////////////////////////
								output << endl;
								const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

								addService_two(distance, historyFileName);
							}

						}
						output.close();
					}
					else
					{
						cout << "Wrong input\n";
					}
				}

			}
		}
		else if (choice == 2)
		{
			cout << "The available vahicles are\nRickshaw\nBike\n";
			cout << "Enter distance in km\n";
			cin >> distance;
			bike_fair = distance * 20;
			rickshaw_fair = distance * 30;
			cout << "The rickshaw fair is \t" << rickshaw_fair << endl;
			cout << "The bike fair is \t" << bike_fair << endl;
			cout << "Enter 1 to book rickshaw\nEnter 2 to book bike\n";
			cin >> choice1;
			if (choice1 == 1)
			{
				char* temp = new char[18];
				temp[0] = { 'R' };
				temp[1] = { 'i' };
				temp[2] = { 'c' };
				temp[3] = { 'k' };
				temp[4] = { 's' };
				temp[5] = { 'h' };
				temp[6] = { 'a' };
				temp[7] = { 'w' };
				ifstream in;
				ofstream out;
				in.open("Vahicle.txt");
				int linecount = 0;
				string line;
				while (getline(in, line))
				{

					linecount++;
				}
				in.close();
				int* sizes = new int[linecount];
				int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
				int* counters = new int[linecount];
				char** names = new char* [linecount];
				int y = 0, z = 0, zz = 0;
				ifstream innnn;
				innnn.open("Vahicle.txt");
				for (int i = 0; i < linecount; i++)
				{
					size1 = 0;
					innnn.getline(temp1, 250);
					for (int i = 0; temp1[i] != '\0'; i++)
					{
						size1++;
					}
					sizes[i] = size1;
				}
				innnn.close();
				ifstream innn;
				innn.open("Vahicle.txt");
				for (int i = 0; i < linecount; i++)
				{
					counter = 0;
					innn.getline(temp1, 250);
					for (int j = 0; j < sizes[i]; j++)
					{
						if (temp1[j] == '\t')
						{
							for (int k = j + 1; temp1[k] != '\t'; k++)
							{
								counter++;
							}

							counters[i] = counter;
							names[i] = new char[counter];


							break;
						}
					}
				}
				innn.close();
				ifstream iin;
				iin.open("Vahicle.txt");
				for (int i = 0; i < linecount; i++)
				{
					counter = 0;
					iin.getline(temp1, 250);
					for (int j = 0; j < sizes[i]; j++)
					{
						if (temp1[j] == '\t')
						{
							int k = j + 1;
							for (int l = 0; l < counters[i]; l++)
							{
								names[i][counter++] = temp1[k++];
							}
							names[i][counter] = '\0';
							break;
						}
					}
				}
				iin.close();
				int temp_c = 1, name_c = 1;
				int pp = 0;
				char temp3[256];
				int matched_ind[10]; int mathced_ind_counter = 0;
				int counter2 = 0; matched_counter = 0;;
				for (int i = 0; i < linecount; i++)
				{
					if (temp[0] == names[i][0])
					{
						temp_c = 1, name_c = 1;
						counter2 = 1;
						while (temp[temp_c++] == names[i][name_c++])
						{
							counter2++;
						}
					}
					if (counter2 == counters[pp++])
					{
						matched_ind[mathced_ind_counter++] = i;
						cout << "\nMatched\n";
						matched_counter++;
					}
				}
				if (matched_counter == 0)
				{
					cout << "\nYou have to add vahicle first\n";
					menu();
					return 0;
				}
				cout << "\nMatched indexes are\n";
				for (int i = 0; i < linecount; i++)
				{
					cout << counters[i] << endl;
				}
				/*for (int i = 0; i < linecount; i++)
				{
					if (counters[i] !=8 )
					{
						for (int j = i + 1; j < linecount; j++)
						{
							counters[i] = counters[j];
						}
						linecount--;
					}
				}*/
				cout << "\nMatched indexes are\n";
				for (int i = 0; i < linecount; i++)
				{
					cout << counters[i] << endl;
				}
				char** vahicle_info = new char* [matched_counter];
				int* new_sizes = new int[matched_counter];
				ifstream iff;
				int s = 0;
				pp = 0;
				int new_sizes_c = 0;
				int vahicle_info_c = 0;
				ofstream off;
				iff.open("Vahicle.txt");
				for (int i = 0; i < linecount; i++)
				{
					iff.getline(temp3, 256);
					char c = '1';
					if (getcounter(temp3, sizes, names, c))
					{
						new_sizes_c = 0;
						for (int i = 0; temp3[i] != '\0'; i++)
						{
							new_sizes_c++;
						}
						new_sizes[s++] = new_sizes_c;
						vahicle_info[vahicle_info_c] = new char[new_sizes_c];
						for (int k = 0; k < new_sizes_c; k++)
						{
							vahicle_info[vahicle_info_c][k] = temp3[k];
						}
						vahicle_info_c++;
						continue;
					}
					else
					{
						continue;
					}
				}
				vahicle_info_c = 0;
				system("cls");
				cout << "The available rikshaws are\n";
				for (int i = 0; i < matched_counter; i++)
				{

					for (int j = 0; j < new_sizes[i]; j++)
					{
						cout << vahicle_info[vahicle_info_c][j];
					}
					vahicle_info_c++;
					cout << endl;
				}
				ofstream output;
				output.open("Vahicle_Travel_History.txt");
				output.close();
				int matched_choice = 0;
				char* driver_id = new char[256];
				cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
				cin >> matched_choice;
				while (matched_choice<0 && matched_choice>matched_counter)
				{
					cout << "Wrong input\nEnter again\n";
					cin >> matched_choice;
				}
				output.open("Vahicle_Travel_History.txt", ios::app);
				for (int i = 0; i < matched_counter; i++)
				{
					if (i == matched_choice - 1)
					{
						for (int j = 0; j < new_sizes[i]; j++)
						{
							output << vahicle_info[i][j];
						}
						//////////////////////////////////////

						std::time_t now = std::time(0);
						tm localtime = {};
						if (localtime_s(&localtime, &now) != 0)
						{
							return 1;
						}
						int year = localtime.tm_year + 1900;
						int month = localtime.tm_mon + 1;
						int day = localtime.tm_mday;

						output << "\t" << day << "/" << month << "/" << year;
						cout << "Enter driver id\n";
						cin.ignore();
						cin.getline(driver_id, 256);
						if (driver_name_check(driver_id))
						{

						}
						else
						{
							while (!driver_name_check(driver_id))
							{
								//system("cls");
								cout << "Enter again!!!\n";
								cin.ignore();
								cin.getline(driver_id, 256);
							}
							int size = 0;
							for (int i = 0; driver_id[i] != '\0'; i++)
							{
								size++;
							}
							for (int i = 0; i < size; i++)
							{
								output << temp[i];
							}
							output << "\t";
							const char* historyFileName = "Vahicle_Travel_History.txt";  
							addService_two(distance, historyFileName);
						}
						/////////////////////////////////
						output << endl;
					}

				}
				output.close();
			}
			else if (choice1 == 2)
			{
				char* temp = new char[8];
				temp[0] = { 'B' };
				temp[1] = { 'i' };
				temp[2] = { 'k' };
				temp[3] = { 'e' };
				ifstream in;
				ofstream out;
				in.open("Vahicle.txt");
				int linecount = 0;
				string line;
				while (getline(in, line))
				{

					linecount++;
				}
				in.close();
				int* sizes = new int[linecount];
				int counter = 0, counter1 = 0, name_counter = 1, matched_counter = 0;
				int* counters = new int[linecount];
				char** names = new char* [linecount];
				int y = 0, z = 0, zz = 0;
				ifstream innnn;
				innnn.open("Vahicle.txt");
				for (int i = 0; i < linecount; i++)
				{
					size1 = 0;
					innnn.getline(temp1, 250);
					for (int i = 0; temp1[i] != '\0'; i++)
					{
						size1++;
					}
					sizes[i] = size1;
				}
				innnn.close();
				ifstream innn;
				innn.open("Vahicle.txt");
				for (int i = 0; i < linecount; i++)
				{
					counter = 0;
					innn.getline(temp1, 250);
					for (int j = 0; j < sizes[i]; j++)
					{
						if (temp1[j] == '\t')
						{
							for (int k = j + 1; temp1[k] != '\t'; k++)
							{
								counter++;
							}

							counters[i] = counter;
							names[i] = new char[counter];


							break;
						}
					}
				}
				innn.close();
				ifstream iin;
				iin.open("Vahicle.txt");
				for (int i = 0; i < linecount; i++)
				{
					counter = 0;
					iin.getline(temp1, 250);
					for (int j = 0; j < sizes[i]; j++)
					{
						if (temp1[j] == '\t')
						{
							int k = j + 1;
							for (int l = 0; l < counters[i]; l++)
							{
								names[i][counter++] = temp1[k++];
							}
							names[i][counter] = '\0';
							break;
						}
					}
				}
				iin.close();
				int temp_c = 1, name_c = 1;
				int pp = 0;
				char temp3[256];
				int matched_ind[10]; int mathced_ind_counter = 0;
				int counter2 = 0; matched_counter = 0;;
				for (int i = 0; i < linecount; i++)
				{
					if (temp[0] == names[i][0])
					{
						temp_c = 1, name_c = 1;
						counter2 = 1;
						while (temp[temp_c++] == names[i][name_c++])
						{
							counter2++;
						}
					}
					if (counter2 == counters[pp++])
					{
						matched_ind[mathced_ind_counter++] = i;
						cout << "\nMatched\n";
						matched_counter++;
					}
				}
				if (matched_counter == 0)
				{
					cout << "\nYou have to add vahicle first\n";
					menu();
					return 0;
				}
				cout << "\nMatched indexes are\n";
				for (int i = 0; i < linecount; i++)
				{
					cout << counters[i] << endl;
				}
				cout << "\nMatched indexes are\n";
				for (int i = 0; i < linecount; i++)
				{
					cout << counters[i] << endl;
				}
				char** vahicle_info = new char* [matched_counter];
				int* new_sizes = new int[matched_counter];
				ifstream iff;
				int s = 0;
				pp = 0;
				int new_sizes_c = 0;
				int vahicle_info_c = 0;
				ofstream off;
				iff.open("Vahicle.txt");
				for (int i = 0; i < linecount; i++)
				{
					char c = '2';
					iff.getline(temp3, 256);
					if (getcounter(temp3, sizes, names, c))
					{
						new_sizes_c = 0;
						for (int i = 0; temp3[i] != '\0'; i++)
						{
							new_sizes_c++;
						}
						new_sizes[s++] = new_sizes_c;
						vahicle_info[vahicle_info_c] = new char[new_sizes_c];
						for (int k = 0; k < new_sizes_c; k++)
						{
							vahicle_info[vahicle_info_c][k] = temp3[k];
						}
						vahicle_info_c++;
						continue;
					}
					else
					{
						continue;
					}
				}
				vahicle_info_c = 0;
				system("cls");
				cout << "The available bikes are\n";
				for (int i = 0; i < matched_counter; i++)
				{

					for (int j = 0; j < new_sizes[i]; j++)
					{
						cout << vahicle_info[vahicle_info_c][j];
					}
					vahicle_info_c++;
					cout << endl;
				}
				ofstream output;
				output.open("Vahicle_Travel_History.txt");
				output.close();
				int matched_choice = 0;
				char* driver_id = new char[256];
				cout << "Out of " << matched_counter << " enter you choice to select vahicle\n";
				cin >> matched_choice;
				while (matched_choice<0 && matched_choice>matched_counter)
				{
					cout << "Wrong input\nEnter again\n";
					cin >> matched_choice;
				}
				output.open("Vahicle_Travel_History.txt", ios::app);
				for (int i = 0; i < matched_counter; i++)
				{
					if (i == matched_choice - 1)
					{
						for (int j = 0; j < new_sizes[i]; j++)
						{
							output << vahicle_info[i][j];
						}
						//////////////////////////////////////

						std::time_t now = std::time(0);
						tm localtime = {};
						if (localtime_s(&localtime, &now) != 0)
						{
							return 1;
						}
					/*	int year = localtime.tm_year + 1900;
						int month = localtime.tm_mon + 1;
						int day = localtime.tm_mday;

						output << "\t" << day << "/" << month << "/" << year;*/

						int year = localtime.tm_year + 1900;
						int month = localtime.tm_mon + 1;
						int day = localtime.tm_mday;

						output << "\t";

						
						if (day < 10) {
							output << "0";
						}
						output << day << "/";

				
						if (month < 10) {
							output << "0";
						}
						output << month << "/" << year;
						cout << "Enter driver id\n";
						cin.ignore();
						cin.getline(driver_id, 256);
						if (driver_name_check(driver_id))
						{

						}
						else
						{
							while (!driver_name_check(driver_id))
							{
								//system("cls");
								cout << "Enter again!!!\n";
								cin.ignore();
								cin.getline(driver_id, 256);
							}
							int size = 0;
							for (int i = 0; driver_id[i] != '\0'; i++)
							{
								size++;
							}
							for (int i = 0; i < size; i++)
							{
								output << temp[i];
							}
							output << "\t";
						}
						/////////////////////////////////
						output << endl;
						const char* historyFileName = "Vahicle_Travel_History.txt";  // Replace with the actual file name

						addService_two(distance, historyFileName);
					}

				}
				output.close();
			}
			else
			{
				cout << "Wrong input\n";
			}

		}
    }
	void printVehicleHistory(const char* vehicleIdToCheck)
	{
		ifstream inputFile("Vahicle_Travel_History.txt");

		if (!inputFile.is_open()) {
			cout << "Error opening file!" << endl;
			return;
		}

		string line;
		cout << "Vehicle Travel History:" << endl;

		while (getline(inputFile, line)) {
			size_t found = line.find(vehicleIdToCheck);

			if (found != string::npos) {
				cout << line << endl;
			}
		}

		inputFile.close();
	}
	/*void printMultiLicenseDrivers() const
	{
		ifstream inputFile("Driver.txt");

		if (!inputFile.is_open()) {
			cout << "Error opening file!" << endl;
			return;
		}
		string line;
		cout << "Drivers with Two Licences:" << endl;

		while (getline(inputFile, line)) {
			size_t found = line.find("D");

			if (found != string::npos) {
				size_t pos = line.find('\t');
				string driverId = line.substr(0, pos);
				line = line.substr(pos + 1);

				pos = line.find('\t');
				string name = line.substr(0, pos);
				line = line.substr(pos + 1);

				pos = line.find('\t');
				string licences = line.substr(0, pos);

				if (licences.find('&') != string::npos) {
					cout << "Driver ID: " << driverId << "\tName: " << name << "\tLicences: " << licences << endl;
				}
			}
		}

		inputFile.close();
	}*/

	void printMultiLicenseDrivers() const {
		ifstream inputFile("Driver.txt");

		if (!inputFile.is_open()) {
			cout << "Error opening file!" << endl;
			return;
		}

		string line;
		cout << "Drivers with Two Licences:" << endl;

		while (getline(inputFile, line)) {
			size_t found = line.find("D");

			if (found != string::npos) {
				size_t pos = line.find('\t');
				string driverId = line.substr(0, pos);
				line = line.substr(pos + 1);

				pos = line.find('\t');
				string name = line.substr(0, pos);
				line = line.substr(pos + 1);

				pos = line.find('\t');
				string licences = line.substr(0, pos);

				if (licences.find("&&") != string::npos) {
					cout << "Driver ID: " << driverId << "\tName: " << name << "\tLicences: " << licences << endl;
				}
			}
		}

		inputFile.close();
	}
	void printHighRankedDrivers() const 
	{
		std::ifstream completeserviceFile("completeservice.txt");
		if (!completeserviceFile.is_open()) {
			std::cerr << "Error: Unable to open completeservice.txt\n";
			return;
		}

		struct DriverInfo {
			string id; 
			int rating;
		};

		std::vector<DriverInfo> drivers;

		std::string line;
		while (std::getline(completeserviceFile, line)) 
		{
			char serviceID[20], vehicleType[20], date[20], driverId[20], ratingStr[20];

			if (sscanf_s(line.c_str(), "%9s %19s %19s %9s %9s", serviceID, vehicleType, date, driverId, ratingStr) == 5)
			{

				int rating;
				try
				{
					rating = std::stoi(ratingStr);
				}
				catch (const std::invalid_argument& e)
				{
					std::cerr << "Error converting rating to integer: " << ratingStr << std::endl;
					continue;
				}

				drivers.push_back({ driverId, rating });
			}
			else {
				std::cerr << "Error reading line: " << line << std::endl;
			}
		}

		completeserviceFile.close();
		sort(drivers.begin(), drivers.end(), [](const DriverInfo& a, const DriverInfo& b) {
			return a.rating > b.rating;
			});

		for (const auto& driver : drivers) {
			std::cout << "Driver: " << driver.id << ", Rating: " << driver.rating << std::endl;
		}
	}

	void updateDriverSalaries()
	{
		std::ifstream completeserviceFile("completeservice.txt");
		if (!completeserviceFile.is_open()) {
			std::cerr << "Error: Unable to open completeservice.txt\n";
			return;
		}

		std::ofstream updatedDriverFile("updateddrivers.txt");
		if (!updatedDriverFile.is_open()) {
			std::cerr << "Error: Unable to create updateddrivers.txt\n";
			completeserviceFile.close();
			return;
		}
		system("cls");
		while (!completeserviceFile.eof()) {
			string serviceID, vehicleType, date, driverId, ratingStr;

			completeserviceFile >> serviceID >> vehicleType >> date >> driverId >> ratingStr; 
		
			if (!completeserviceFile.fail())
			{
				int rating = stoi(ratingStr);

				int salary = calculateSalary(rating);  
				
			/*	cout << "Service ID: " << serviceID << "\t"<< "Vehicle Type: " << vehicleType << "\t"<< "Date: " << date << "\t"<< "Driver ID: " << driverId << "\t"<< "Rating: " << ratingStr << "\t"<< "Salary: " << salary << "\n";
				*/
				
				cout << serviceID << "\t" << vehicleType << "\t" << date << "\t"
					<< driverId << "\t" << ratingStr << "\t" << salary << "\n";
				
				
				
				updatedDriverFile << serviceID << "\t" << vehicleType << "\t" << date << "\t"
					<< driverId << "\t" << ratingStr << "\t" << salary << "\n"; 
			}
		}

		completeserviceFile.close();
		updatedDriverFile.close();
	}
	int calculateSalary(int rating) const 
	{
		const int baseSalary = 2000;  // Set your base salary
		const int bonusPerRatingPoint = 100;  // Set your bonus per rating point

		// Calculate salary: Base Salary + Bonus (based on rating)
		int salary = baseSalary + (rating * bonusPerRatingPoint);

		return salary;
	}
   //void printCustomersSameVehicleRide(int vId, const Date& date) const;
	void printDriversSameDayDelivery(const string date) const
	{
			ifstream inputFile("Vahicle_Travel_History.txt");

			if (!inputFile.is_open()) {
				cout << "Error opening file!" << endl;
				return;
			}

			string line;
			cout << "Completed Rides on " << date << ":" << endl;

			while (getline(inputFile, line)) {
				size_t pos = line.find('\t');
				string vehicleId = line.substr(0, pos);
				line = line.substr(pos + 1);

				pos = line.find('\t');
				string type = line.substr(0, pos);
				line = line.substr(pos + 1);

				pos = line.find('\t');
				string registrationNo = line.substr(0, pos);
				line = line.substr(pos + 1);

				// Extracting the date from the format "26/7/2023"
				pos = line.find('\t');
				string rideDate = line.substr(pos + 1);

				// Check if the ride was completed on the given date
				if (rideDate == date) {
					cout << "Vehicle ID: " << vehicleId << "\tType: " << type << "\tRegistration No: " << registrationNo
						<< "\tDate: " << rideDate << endl;
				}
			}

			inputFile.close();
	}
    void addService_two(float distance, const char* vehicleHistoryFileName)
	{
		
		startRide(distance, vehicleHistoryFileName);

		 while (true) {
			std::cout << "Enter 1 to complete the ride\nEnter 2 to cancel the ride\n";
			int choice;
			std::cin >> choice;

			switch (choice) {
			case 1:
				// Complete the ride
				completeService();
				cout << "Ride completed!\n";
				return;
			case 2:
				// Cancel the ride
				cancelService();
				cout << "Ride canceled!\n";
				return;
			default:
				cout << "Invalid choice. Please enter 1 or 2.\n";
			}

			checkTimerAndPerformActions(vehicleHistoryFileName);
		}
	}

	void startRide(float distance, const char* vehicleHistoryFileName) {
		using namespace std::chrono;

		startTime = system_clock::now();
		currentDistance = distance;

		std::ofstream historyFile(vehicleHistoryFileName, std::ios::app);
		if (historyFile.is_open()) {
			std::time_t startTime_t = system_clock::to_time_t(startTime);
			std::tm startTime_tm;
			localtime_s(&startTime_tm, &startTime_t);
			char buffer[80];
			std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &startTime_tm);
			historyFile << "Start Time: " << buffer << "\n";
			historyFile << "Distance: " << currentDistance << " km\n";
			historyFile.close();
		}
	}

	void checkTimerAndPerformActions(const char* vehicleHistoryFileName) {
		auto currentTime = chrono::system_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::minutes>(currentTime - startTime).count();

		const int maxAllowedMinutes = static_cast<int>(currentDistance);

		if (elapsedTime >= maxAllowedMinutes) {
			ifstream historyFile(vehicleHistoryFileName);
			string lastLine;
			while (getline(historyFile, lastLine)) {
			}
			historyFile.close();

			if (lastLine.find("Completed") == string::npos && lastLine.find("Canceled") == string::npos) {
				ofstream pendingFile("pendingrides.txt", ios::app);
				if (pendingFile.is_open()) {
					pendingFile << lastLine << "Pending\n";
					pendingFile.close();
				}
			}

			startTime = chrono::system_clock::now();
			currentDistance = 0.0;
			activeServiceIndex = -1;  // Reset to an invalid index
		}
	}

	void cancelService() {
		if (activeServiceIndex != -1) {
		std::ofstream historyFile("canceledservice.txt", ios::app);
			if (historyFile.is_open()) {
				historyFile << "Service Canceled\n";
				std::ifstream originalHistoryFile("Vahicle_Travel_History.txt");
				if (originalHistoryFile.is_open()) {
					historyFile << originalHistoryFile.rdbuf();
					originalHistoryFile.close();
				}
				historyFile.close();
			}

			activeServiceIndex = -1;
			startTime = chrono::system_clock::now();
			currentDistance = 0.0;
		}
	}

	void completeService() 
	{
		if (activeServiceIndex != -1)
		{
			std::ofstream historyFile("completeservice.txt", ios::app);
			if (historyFile.is_open())
			{
				historyFile << "Service Completed\n";
				std::ifstream originalHistoryFile("Vahicle_Travel_History.txt");
				if (originalHistoryFile.is_open()) {
					historyFile << originalHistoryFile.rdbuf();
					originalHistoryFile.close();
				}
				int rating;
				std::cout << "Enter customer rating (1 to 5): ";
				std::cin >> rating;
				while (rating < 1 || rating > 5) {
					std::cout << "Invalid rating. Please enter a rating between 1 and 5: ";
					std::cin >> rating;
				}
				historyFile << "Rating: " << rating << "\n";
				historyFile.close();
			}

			activeServiceIndex = -1;
			startTime = chrono::system_clock::now();
			currentDistance = 0.0;
		}
	}
    void menu()
    {
        int choice = 0, choice1 = 0;

        cout << "Enter 1 to use application as administrator\nEnter 2 to use application as customer\n";
        cin >> choice1;
        system("cls");
        if (choice1 == 1)
        {
            system("cls");
            cout << "Enter 1 to add customer\nEnter 2 to add driver\nEnter 3 to remove driver\nEnter 4 to add vahicle\nEnter 5 to remove vahicle\nEnter 6 to print list of all customers\nEnter 7 to print list of all driver\nEnter 8 to print list of all Vehicle\nEnter 9 to print history of a particular vahicle\nEnter 10 to update salaries of the drivers\nEnter 11 to print the Driver's Same Day Delivery\nEnter 12 to print drivers with multiple licences\nEnter 13 to print higher ranked drivers ";
            cin >> choice;
            if (choice == 1)
            {
                system("cls");
                char c = '1';
                int linecount = input(c);
                cout << linecount << " out of 15 customer/s has/have been added\n";

            }
            else if (choice == 2)
            {
                system("cls");
                char c = '2';
                int linecount = input(c);
                cout << linecount << " out of 10 driver/s have/has been added\n";

            }
            else if (choice == 3)
            {
                system("cls");
                char c = '3';
                 remove(c);
            }
            else if (choice == 4)
            {
                system("cls");
                char c = '3';
                int linecount = addVehicle();
                cout << linecount << " out of 20 vahicle/vahicle(s) have/has been added\n";
            }
            else if (choice == 5)
            {
                system("cls");
                char c = '5';
                remove(c);
            }
            else if (choice == 6)
            {
                system("cls");
                char c = '1';
                print(c);
            }
            else if (choice == 7)
            {
                system("cls");
                char c = '2';
                print(c);
            }
            else if (choice == 8)
            {
                system("cls");
                char c = '3';
                print(c);
            }
            else if (choice == 9)
            {
                system("cls");
                char c = '1';
                printVehicleDetails();
            }
			else if (choice == 10)
			{
				updateDriverSalaries();
			}
			else if (choice == 11)
			{
				string temp;
				int size = 0;

					while (true) {
						std::cout << "Enter date in format DD/MM/YYYY: ";
						std::cin >> temp;

						if (isValidDate(temp)) {
							std::cout << "Date entered correctly: " << temp <<endl;
							break;  
						}
						else {
							std::cout << "Invalid date format. Please re-enter.\n";
						}
					}			
				printDriversSameDayDelivery(temp);
			}
			else if (choice == 12)
			{
				printMultiLicenseDrivers();
			}
			else if (choice == 13)
			{
				printHighRankedDrivers();
			}
        }
        if (choice1 == 2)
        {
			addServiceRequest();

        }
		
    }
	bool isValidDate(string& date)
	{
		int date_size = date.length();

		if (date.length() != 10) {
			return false;
		}
		if (date[2] != '/' || date[5] != '/') {
			return false;
		}

		for (int i = 0; i < 10; ++i) {
			if (i != 2 && i != 5 && !isdigit(date[i])) {
				return false;
			}
		}

		return true;
	}
    /////////////////////////////////////////////////////////////////////

    int input(char c)
    {

        char* temp = new char[60];
        char* temp1 = new char[50];
        char* temp2 = new char[30];
        char* temp3 = new char[50];
        int size = 0;
        int linecount = 0;
        if (c == '1')
        {
           return linecount = addCustomer();
           
        }
        else if (c == '2')
        {
           addDriver();
        }
        else if (c == '3')
        {
           int l= addVehicle();
           return l;
        }
    }
    void remove(char c)
    {
        if (c=='3')
        {
            remove_driver();
        }
        else if (c == '5')
        {
             remove_vahicle();
        }
    }
    void print(int c)
    {
        if (c=='1')
        {
            //c
            printAllCustomers();
        }
        else if(c=='2')
        {
            //d
            printAllDrivers();
        }
        else if(c=='3')
        {
            //v
            printAllVehicles();
        }
    }

};

int main()
{
    TMS tsm;
    char** customer = new char* [15];
    char** driver = new char* [10];
    char** vehical = new char* [20];
    tsm.menu();
    return 0;
}