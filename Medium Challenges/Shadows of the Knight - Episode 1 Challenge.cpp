#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// bool container for string source and character keys
bool contains(const string& source, char key) {
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == key) {
            return true;
        }
    }
    return false;
}

int main() {

    int w, h; // width of the building & height of the building.
    cin >> w >> h; cin.ignore(); // cin.ignore clears one or more characters form input buffer
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x, y; // integers for output
    cin >> x >> y; cin.ignore();
    
    //vector storing on value per bit for h and w
    vector<vector<int> > building(h, vector<int>(w, 0)); // added integers for the 2D vectors and changed table to building for compliance
    int x0 = 0;
    int x1 = w;
    int y0 = 0;
    int y1 = h;

    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        // cerr; The cerr object in C++ is used to print error messages. It is defined in the iostream header file.
        cerr << x << ' ' << y << endl;
        cerr << x0 << ' ' << x1 << endl;
        cerr << y0 << ' ' << y1 << endl;

        // if-else if loops to find characters in bomb_dir strings
        if (contains(bomb_dir, 'U')) {
            y1 = y;
        }

        else if (contains(bomb_dir, 'D')) {
            y0 = y;
        }

        if (contains(bomb_dir, 'L')) {
            x1 = x;
        }
        else if (contains(bomb_dir, 'R')) {
            x0 = x;
        }

        // (x, y) set to update on upper/lower bounds defined in loop
        x = x0 + (x1 - x0) / 2;
        y = y0 + (y1 - y0) / 2;

        // the location of the next window Batman should jump to.
        cout  << x << ' ' << y << endl;
    
    }
}
