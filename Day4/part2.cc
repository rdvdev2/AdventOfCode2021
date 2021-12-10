
#include <iostream>
#include <vector>

using namespace std;


typedef vector<int> IntRow;
typedef vector<IntRow> IntMatrix;

typedef vector<bool> BoolRow;
typedef vector<BoolRow> BoolMatrix;

struct Board {
    IntMatrix numbers;
    BoolMatrix marks;
};

typedef vector<Board> Boards;


const int NUMBER_COUNT = 100;
const int BOARD_SIZE = 5;


// pre: n strict positive
// post: returns a int vector with n elements from stdin
vector<int> get_numbers(int n) {
    vector<int> ret(n, 0);

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        ret[i] = val;
        if (i != n-1) {
            char comma;
            cin >> comma;
        }
    }

    return ret;
}

// pre: n strict positive
// post: returns a n by n board as read from stdin
Board get_board(int n) {
    Board b;
    b.numbers = IntMatrix(n, IntRow(n));
    b.marks = BoolMatrix(n, BoolRow(n, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            b.numbers[i][j] = val;
        }
    }

    return b;
}

// pre: b is an n by n board, 0<=x,y<n
// post: returns true if b has won
// note: for efficency, only row x and column y are checked
bool check_win(const Board& b, int x, int y, int n) {
    bool win = true;

    // Check row x
    for (int i = 0; i < n; ++i) {
        win = win and b.marks[x][i];
    }
    if (win) return true;
    else win = true;

    // Check column y
    for (int i = 0; i < n; ++i) {
        win = win and b.marks[i][y];
    }
    return win;
}

// pre: call is the called number, n is the size of the boards, boards isn't
// empty
// post: boards get the called number marked, and the index of the winning
// boards are returned
vector<int> calculate_round(int call, int n, Boards& boards) {
    int num_boards = boards.size();
    vector<int> winners;

    for (int i = 0; i < num_boards; ++i) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (boards[i].numbers[x][y] == call) {
                    boards[i].marks[x][y] = true;
                    if (check_win(boards[i], x, y, n)) {
                        winners.push_back(i);
                    }
                }
            }
        }
    }

    return winners;
}

// pre: b is a n by n winning board, last_call is the last called number
// post: returns the score of the board
int board_score(const Board& b, int n, int last_call) {
    int score = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (not b.marks[i][j]) {
                score += b.numbers[i][j];
            }
        }
    }

    score *= last_call;
    return score;
}

int main() {
    vector<int> numbers = get_numbers(NUMBER_COUNT);

    Boards boards;
    while (not cin.eof()) {
        boards.push_back(get_board(BOARD_SIZE));
    }

    int i = 0;
    Board last;
    while (boards.size() != 0 and i < NUMBER_COUNT) {
        vector<int> winners = calculate_round(numbers[i], BOARD_SIZE, boards);

        for (int i = winners.size()-1; i >= 0; --i) {
            last = boards[winners[i]];
            boards.erase(boards.begin() + winners[i]);
        }
        ++i;
    }

    int score = board_score(last, BOARD_SIZE, numbers[i-1]);

    cout << "The last winner's score is " << score << endl;
}
