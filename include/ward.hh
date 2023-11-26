#ifndef WARD
#define WARD
using namespace std;

class ward
{
public:
    int roomId;
    int patient1Id;
    int patient2Id;
    int patient3Id;
    ward();
    void fillMap();
    void saveMap();
};
#endif