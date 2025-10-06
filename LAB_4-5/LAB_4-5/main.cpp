#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Battery {
    double cap;
    double volt;
    string mat;

public:
    Battery(): cap(0), volt(0), mat("Unknown") {}
    Battery(double c,double v,string m){ setData(c,v,m); }
    Battery(const Battery& b){ cap=b.cap; volt=b.volt; mat=b.mat; cout<<"copied "<<mat<<"\n"; }
    Battery& operator=(const Battery& b){ if(this!=&b){ cap=b.cap; volt=b.volt; mat=b.mat; } return *this; }
    ~Battery(){ cout<<"deleted "<<mat<<"\n"; }

    void setData(double c,double v,string m){
        if(c<=0||v<=0){ cerr<<"bad data\n"; cap=0; volt=0; mat="Unknown"; return; }
        cap=c; volt=v; mat=m;
    }

    void print() const { cout<<mat<<" "<<cap<<"mAh "<<volt<<"V\n"; }

    bool matchMat(const string& m) const{ return mat==m; }
    bool highVolt(double v) const{ return volt>=v; }
};

int main() {
    vector<Battery> batteries;
    batteries.emplace_back(3000, 3.7, "Li-ion");
    batteries.emplace_back(2500, 3.6, "NiMH");
    batteries.emplace_back(4000, 3.8, "Li-ion");

    cout << "All batteries:\n";
    for (const auto& b : batteries) {
        b.print();
    }

    cout << "\nCopying first battery:\n";
    Battery copyBattery = batteries[0];
    copyBattery.print();

    cout << "\nBatteries with material 'Li-ion':\n";
    for (const auto& b : batteries) {
        if (b.matchMat("Li-ion")) {
            b.print();
        }
    }

    cout << "\nBatteries with voltage >= 3.7V:\n";
    for (const auto& b : batteries) {
        if (b.highVolt(3.7)) {
            b.print();
        }
    }

    cout << "\n---Creating new battery---\n";
    double cap, volt;
    string mat;
    cout << "Enter capacity (mAh): ";
    cin >> cap;
    cout << "Enter Current (V): ";
    cin >> volt;
    cout << "Enter Material: ";
    cin >> mat;

    Battery userBattery(cap, volt, mat);
    cout << "Created battery: ";
    userBattery.print();

    return 0;
}
