
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> IntRow;
typedef vector<IntRow> IntMatrix;

const int FIELD_SIZE = 1000;

int main() {
    IntMatrix field(FIELD_SIZE, IntRow(FIELD_SIZE, 0));
    int result = 0;

    int x1, y1, x2, y2;
    char dummy;
    while (cin >> x1 >> dummy >> y1 >> dummy >> dummy >> x2 >> dummy >> y2) {
        cout << "(" << x1 << "," << y1 << ") -> (" << x2 << "," << y2 << ")" << endl;
        if (x1 == x2) {
            if (y1 > y2) {
                int aux = y1;
                y1 = y2;
                y2 = aux;
            }
            for (int y = y1; y <= y2; ++y) {
                ++field[x1][y];
                if (field[x1][y] == 2) ++result;
            }
        } else if (y1 == y2) {
            if (x1 > x2) {
                int aux = x1;
                x1 = x2;
                x2 = aux;
            }
            for (int x = x1; x <= x2; ++x) {
                ++field[x][y1];
                if (field[x][y1] == 2) ++result;
            }
        }
    }

    cout << result << endl;
}
