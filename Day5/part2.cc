
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> IntRow;
typedef vector<IntRow> IntMatrix;

const int FIELD_SIZE = 1000;

struct Point {
    int x, y;
};

struct Line {
    Point p1, p2;
};

void interchange(int& a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

// pre: line is horizontal
// post: the line is added to the field
void add_h_line(IntMatrix& field, const Line& line) {
    int x1, x2, y;
    y = line.p1.y;

    if (line.p1.x < line.p2.x) {
        x1 = line.p1.x;
        x2 = line.p2.x;
    } else {
        x1 = line.p2.x;
        x2 = line.p1.x;
    }

    for (int x = x1; x <= x2; ++x) {
        ++field[x][y];
    }
}

// pre: line is vertical
// post: the line is added to the field
void add_v_line(IntMatrix& field, const Line& line) {
    int x, y1, y2;
    x = line.p1.x;
    
    if (line.p1.y < line.p2.y) {
        y1 = line.p1.y;
        y2 = line.p2.y;
    } else {
        y1 = line.p2.y;
        y2 = line.p1.y;
    }

    for (int y = y1; y <= y2; ++y) {
        ++field[x][y];
    }
}

// pre: line is diagonal (45 deg)
// post: the line is added to the field
void add_d_line(IntMatrix& field, const Line& line) {
    Point p1, p2;
    if (line.p1.x < line.p2.x) {
        p1 = line.p1;
        p2 = line.p2;
    } else {
        p1 = line.p2;
        p2 = line.p1;
    }

    int x1 = p1.x;
    int x2 = p2.x;
    int y = p1.y;
    
    if (p1.y < p2.y) {
        for (int x = x1; x <= x2; ++x) {
            ++field[x][y];
            ++y;
        }
    } else {
        for (int x = x1; x <= x2; ++x) {
            ++field[x][y];
            --y;
        }
    }
}

// pre: ---
// post: the line is added to the field
void add_line(IntMatrix& field, const Line& line) {
    if (line.p1.y == line.p2.y) add_h_line(field, line);
    else if (line.p1.x == line.p2.x) add_v_line(field, line);
    else add_d_line(field, line);
}

int main() {
    IntMatrix field(FIELD_SIZE, IntRow(FIELD_SIZE, 0));

    Line l;
    char dummy;
    while (cin >> l.p1.x >> dummy >> l.p1.y >> dummy >> dummy >> l.p2.x >> dummy >> l.p2.y) {
        add_line(field, l);
    }
    
    int result = 0;
    for (int i = 0; i < FIELD_SIZE; ++i) {
        for (int j = 0; j < FIELD_SIZE; ++j) {
            if (field[i][j] >= 2) ++result;
        }
    }

    cout << result << endl;
}
