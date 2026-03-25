#include<iostream>
using namespace std;

class Tyre{
    private:
    char compound;
    char style;
    double CurWear;
    double UsableD;
    double dist;
    public:
    void get(){
         cout<<"Enter S/s for Soft tyre Compound\nM/m for Medium tyre Compound\nH/h for Hard tyre Compound: ";
         cin>>compound;
    }
    double baseWear(){
        if(compound=='S'||compound=='s'){
           return 0.005; 
        }
        else if(compound=='M'||compound=='m'){
           return 0.003; 
        }
        else if(compound=='H'||compound=='h'){
           return 0.002; 
        }
        return 0.003;
    }
    void accept(){
        cout<<"Enter A/a for Aggresive Driving\nN/n for Normal Driving\nC/c for Careful Driving: ";
        cin>>style;
    }
    double Style(){
         if(style=='A'||style=='a'){
           return 1.3; 
        }
        else if(style=='N'||style=='n'){
           return 1; 
        }
        else if(style=='C'||style=='c'){
           return 0.8; 
        }
        return 1;
    }
    double FinalWear(){
        return baseWear()*Style();
    }
    void input(){
        cout<<"Enter your Current Thread depth: ";
        cin>>CurWear;
    }
    double Wear(){
        if(CurWear<=1.5){
           return -1;
        }
        else{
            UsableD=CurWear-1.5;
            dist=UsableD/FinalWear();
            cout<<"You should change the tyres after: ";
            return dist;
        }
    }
};
int main() {
    Tyre t;
    double result;

    t.get();      
    t.accept();   
    t.input();    

    result = t.Wear();   

    if (result == -1) {
        cout << "Change tyres immediately.\n";
    } else {
        cout << result << " KM\n";
    }

    return 0;
}
