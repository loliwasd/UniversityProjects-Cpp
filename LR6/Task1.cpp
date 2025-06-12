#include <cstring>
#include <iostream>
using namespace std;

struct Boots {
    int size;
    double sm_size;
    bool isWaterproof;
    char gender;
    char brand[10];
    int other_sizes[3];
};

int main()
{
    Boots myBoots;
    cout << "Enter size\n";
    cin >> myBoots.size;
    cout << "Enter size in santimeters\n";
    cin >> myBoots.sm_size;
    cout << "Enter waterproofness (1 - is waterproof, 0 - not)\n";
    cin >> myBoots.isWaterproof;
    cout << "Enter gender (m/f/o)\n";
    cin >> myBoots.gender;
    cout << "Enter brandname\n";
    cin >> myBoots.brand;
    cout << "Enter othersizes (3 of them)\n";
    for (int i = 0; i < 3; ++i)
    {
        cin >> myBoots.other_sizes[i];
    }

    cout << "Size = " << myBoots.size << " | in SM = " << myBoots.sm_size << " | Is waterproof" << myBoots.isWaterproof
         << " | Gender = " << myBoots.gender << " | Brand name = " << myBoots.brand << " | Other sizes = " << myBoots.other_sizes[0] << "\n";


    Boots* ptrBoots = new Boots{42, 40.7, 1, 'm', "Coolboot", {40, 41, 43}};
    cout << "Size = " << ptrBoots->size << " | in SM = " << ptrBoots->sm_size << " | Is waterproof = " <<ptrBoots->isWaterproof
         << " | Gender = " << ptrBoots->gender << " | Brand name = " << ptrBoots->brand << " | Other sizes = " << ptrBoots->other_sizes[0] << "\n";
    delete ptrBoots;
    return 0;
}
