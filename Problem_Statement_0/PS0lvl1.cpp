#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     int c;
     cin >> c;
     int n;
     cin >> n;
     vector <int> Cargo;
     int onecargo;
     int sum = 0;
     int prevmax = 0;
     int prevmin = 0;
     for (int i = 0; i<n; i++){
        cin >> onecargo;
        Cargo.push_back(onecargo);
        sum += onecargo;
        if (prevmax< onecargo){
            prevmax = onecargo;
        }
        if (prevmin == 0){
            prevmin = onecargo;
        }
        if (prevmin> onecargo){
            prevmin = onecargo;
        }
     }
     cout << "Total Shipment Weight: " << sum << "\n";
     cout << "Average Container Weight: "<< sum/ n<< "\n";
     cout << "Heaviest Container: "<< prevmax<< "\n";
     cout << "Lightest Container: "<< prevmin<< "\n";
     cout << "Classsification: ";
     if (sum >= 200){
        cout << "Heavy"<< "\n";
     }
     else{
        cout << "Light"<< "\n";

     }
     cout << "Port Capacity: " << c<< "\n";
     cout << "Status: ";
     if ( sum > c){
        cout << "Shipment exceeds port capacity";

     }
     else{
        cout << "Shipment can be unloaded";
     }
    }
