#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Tyre
{
private:
    char compound;
    char style;
    double CurWear;
    double UsableD;
    double dist;

public:
    void get()
    {
        cout << "Enter S/s for Soft tyre Compound\nM/m for Medium tyre Compound\nH/h for Hard tyre Compound: ";
        cin >> compound;
    }
    double baseWear()
    {
        if (compound == 'S' || compound == 's')
        {
            return 0.005;
        }
        else if (compound == 'M' || compound == 'm')
        {
            return 0.003;
        }
        else if (compound == 'H' || compound == 'h')
        {
            return 0.002;
        }
        return 0.003;
    }
    void accept()
    {
        cout << "Enter A/a for Aggresive Driving\nN/n for Normal Driving\nC/c for Careful Driving: ";
        cin >> style;
    }
    double Style()
    {
        if (style == 'A' || style == 'a')
        {
            return 1.3;
        }
        else if (style == 'N' || style == 'n')
        {
            return 1;
        }
        else if (style == 'C' || style == 'c')
        {
            return 0.8;
        }
        return 1;
    }
    double FinalWear()
    {
        return baseWear() * Style();
    }
    void input()
    {
        cout << "Enter your Current Tread depth: ";
        cin >> CurWear;
    }
    string condition()
    {
        if (CurWear <= 1.5)
        {
            return "CRITICAL";
        }
        else if (CurWear <= 3.0)
        {
            return "WARNING";
        }
        else
        {
            return "Good";
        }
    }
    double Wear()
    {
        if (CurWear <= 1.5)
        {
            return -1;
        }
        else
        {
            UsableD = CurWear - 1.5;
            dist = UsableD / FinalWear();
            cout << "You should change the tyres after: ";
            return dist;
        }
    }
};
int main()
{
    Tyre t;
    double result;
    int choice;

    do
    {
        cout << "---------------Tyre Wear System------------" << endl;
        cout << "Enter 1 to check\n2 to View History\n3 to exit\nEnter Choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:{
            t.get();
            t.accept();
            t.input();

            result = t.Wear();

            cout << "\nTyre Condition: " << t.condition() << endl;

            if (result == -1)
            {
                cout << "Estimated Life left: 0km\n";
                cout << "Recommendation Change Tyre Immediately" << endl;
            }
            else
            {
                cout << "Estimated Life left:" << result << " KM\n";

                if (t.condition() == "WARNING")
                {
                    cout << "Recommendation Change Tyre soon\n";
                }
                else
                {
                    cout << "Tyre is safe for now\n";
                }
            }

            ofstream file("tyre_data.txt", ios::app);
            file << "Condition: " << t.condition() << "|";
            if (result == -1)
            {
                file << "Life Left:0KM | Change Immediately\n";
            }
            else
            {
                file << "Life Left: " << result << "KM\n";
            }
            file.close();
            break;
        }

        case 2:{
            ifstream file("tyre_data.txt");

            if(!file){
                cout<<"No history Found.\n";
                break;
            }

            cout<<"-------------Tyre History------------\n";
            string line;
            while(getline(file,line)){
                cout<<line<<endl;
            }
            file.close();
            break;
        }

        case 3:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
