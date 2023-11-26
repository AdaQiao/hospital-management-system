using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "./../include/global.hh"
#include "./../include/ward.hh"
#include "./../include/hospital.hh"

ward::ward()
{
    roomId = 0;
    patient1Id = 0;
    patient2Id = 0;
    patient3Id = 0;
}

void ward::fillMap()
{
    fstream f;
    f.open("./data/wards.csv", ios::in);
    string temp;
    getline(f >> ws, temp);
    while (getline(f >> ws, temp))
    {
        ward a;
        stringstream s(temp);
        string s1, s2, s3, s4;
        getline(s, s1, ',');
        getline(s, s2, ','); 
        getline(s, s3, ',');
        getline(s, s4, ',');
        a.roomId = strToNum(s1);
        a.patient1Id = strToNum(s2);
        a.patient2Id = strToNum(s3);
        a.patient3Id = strToNum(s4);
        hospital::wardsList[a.roomId] = a;
    }
    f.close();
    return;
}

void ward::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    f << "roomId,patient1Id,patient2Id,patient3Id\n";
    for (auto i : hospital::wardsList)
        f << i.second.roomId << "," << i.second.patient1Id << "," << i.second.patient2Id
          << "," << i.second.patient3Id << endl;
    f.close();
    remove("./data/wards.csv");
    rename("./data/temp.csv", "./data/wards.csv");
    return;
}