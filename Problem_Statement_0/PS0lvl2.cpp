#include <bits/stdc++.h>
using namespace std;
int returnSmaller(int a,int b){
    if (a>=b){
        return b;
    }
    else{
        return a;
    }
}
vector <int> mergeThem(vector <int> sorted_left, vector <int> sorted_right){
    int dummy_l = 0;
    vector <int> toreturn;
    int l = 0;
    int k = 0;
    while ( l< sorted_left.size()){
        if (dummy_l == sorted_right.size()){
            k = 1;
            break;}
        toreturn.push_back(returnSmaller(sorted_left[l],sorted_right[dummy_l]));
        if (returnSmaller(sorted_left[l],sorted_right[dummy_l]) == sorted_right[dummy_l]){
            l--;
            dummy_l++;
            }
        l++;}
    if (k==0){
        for (int p = dummy_l; p < sorted_right.size(); p++ ){
            toreturn.push_back(sorted_right[p]);
        }
    }
    else{
             for (int o = l; o < sorted_left.size(); o++){
            toreturn.push_back(sorted_left[o]);
        }

    }
    return toreturn;}
vector <int> mergeSort(vector <int> zahlen){
    if (zahlen.size() <= 1){
        return zahlen;
        }
    vector <int> left_half(zahlen.begin(),zahlen.begin()+ zahlen.size()/2);
    vector <int> right_half(zahlen.begin()+zahlen.size()/2,zahlen.end());
    left_half  = mergeSort(left_half);
     right_half = mergeSort(right_half);
     return mergeThem(left_half,right_half);}
vector <int> reportPrint(vector <int>&Cargo, int& c, int& n, int p){
         int onecargo;
     int sum = 0;
     int prevmax = 0;
     int prevmin = 0;
     int check_var1 = 0;
     int check_var2 = 0;
     ifstream file("input.txt");
    if (p == 0){
    cin >> c;
     cin >> n;
    }
    else {
        file >> c;
        file >> n;
    }
     for (int i = 0; i<n; i++){
        if (p == 0){
        cin >> onecargo;}
        else{
            file >> onecargo;
        }
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
     file.close();
     cout << "Shipment Report!!!" << "\n \n";
     cout << "Total Shipment Weight: " << sum << "\n";
     cout << "Average Container Weight: "<< sum/ n<< "\n";
     cout << "Heaviest Container: "<< prevmax<< "\n";
     cout << "Lightest Container: "<< prevmin<< "\n";
     cout << "Classsification: ";
     if (sum >= 200){
        cout << "Heavy"<< "\n";
        check_var1 = 1;
     }
     else{
        cout << "Light"<< "\n";
        check_var1 = 0;
     }
     cout << "Port Capacity: " << c<< "\n";
     cout << "Status: ";
     if ( sum > c){
        cout << "Shipment exceeds port capacity"<< "\n"<<endl;
        check_var2 = 1;
     }
     else{
            check_var2 = 0;
        cout << "Shipment can be unloaded"<< "\n"<<endl;
     }
     return {sum, prevmax,prevmin,check_var1,check_var2};
}
void starPrinter(int o){
    for ( int y = 0; y<o; y++){
        cout << "*";
    }
}
void barChart( vector <int> Cargo){
    for (int g = 0; g< Cargo.size(); g++){
        cout << "Container "<< g+1<< ": ";
        starPrinter(Cargo[g]/5);
        cout << "\n";
    }
}
int main() {
    int c = 0;
    int n = 0;
    vector <int> Cargo ={};
    bool loop_var = true;
    while (loop_var){
    cout << "Do you want to manually add input(type 0) or give input from a input.txt file(type 1)?"<<endl;
    int x;
    cin >> x;
    vector <int> lis;
    if (x == 0){
            cout<< "Type the capacity, number of containers and weight of each container."<<endl;
            lis = reportPrint(Cargo,c,n,0);
    }
    else{
        lis = reportPrint(Cargo,c,n,1);
    }
    int ans;
        int v  = 0;
        while (v == 0){
        cout<< "\n" << "\n"<< "What feature do you want to use?"<< "\n";
        cout << "Sort: 1 \n"<< "Bar Chart: 2 \n" << "Save Report: 3 \n"<< "Search: 4 \n"<< "Kth Heaviest: 5 \n"<<"New Shipment Report: 6 \n" <<" Quit: 0 \n";
        cin >> ans;
        switch (ans){
            case 0:{
            loop_var = false;
            v = 1;
            break;}
            case 1:{
            vector <int> sorted_ans = mergeSort(Cargo);
            cout << "Sorted List: \n";
            for ( int  u =0; u<n;u++){
                cout << u+1<< ". " << sorted_ans[u]<< "\n";
            }
            break;}
            case 2: {
                barChart(Cargo);
                break;}
            case 3:{
                cout << "Saving File ..."<<endl;
                ofstream file("report.txt",ios::app);
                file << "Shipment Report!!!" << "\n \n";
                file << "Total Shipment Weight: " << lis[0] << "\n";
                file << "Average Container Weight: "<< lis[0]/ n<< "\n";
                file << "Heaviest Container: "<< lis[1]<< "\n";
                file << "Lightest Container: "<< lis[2]<< "\n";
                file << "Classsification: ";
                if (lis[3] == 1)
                file << "Heavy"<<endl;
                else{
                    file<< "Light"<<endl;
                }
                file << "Port Capacity: " << c<< "\n";
                file << "Status: ";
                if (lis[4]  == 1){ file<< "Shipment exceeds port capacity"<<endl;} else{file<< "Shipment can be loaded"<<endl;}
            cout << "File Saved"<<endl;
            file.close();
            break;
            }
            case 4:{
            int container_tosearch;
            cout <<"For which container do you want to search?"<< endl;
            cin>> container_tosearch;
            int check_var3 =1;
            for (int i = 0; i < Cargo.size();i++){
                if (Cargo[i] == container_tosearch){
                    cout << "Container found!" <<endl;
                    cout << "Container "<< i+1 << " has weight "<< container_tosearch<<endl;
                    i = Cargo.size();
                    check_var3 = 0;
                }

            }
                        if (check_var3 == 1){
                cout<< "No such container found"<< endl;
            }
            break;
            }
            case 5: {
                vector <int> kth_heaviest_list = mergeSort(Cargo);
                cout<< "Enter the value of K please. " << endl;
                bool invalid = true;
                int k;
                while (invalid){
                cin >> k;
                if (kth_heaviest_list.size()< k){
                    cout<< "Invalid K, please re-enter.";}
                else{
                cout << kth_heaviest_list[kth_heaviest_list.size()-k];
                invalid = false;}}
                break;
            }
            case 6:{v = 1;
                break;
            }
        }
        }
    }
}
