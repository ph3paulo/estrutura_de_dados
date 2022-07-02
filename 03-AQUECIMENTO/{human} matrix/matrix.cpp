#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Pos {
    int l, c;
    Pos(int l, int c) {
        this->l = l;
        this->c = c;
    }  
    bool operator==(Pos pos) {
        return l == pos.l && c == pos.c;
    }
    bool operator!=(Pos pos) {
        return l != pos.l || c != pos.c;
    }
    string str() {
        stringstream convert;
        convert << "(" << l << ", " << c << ")";
        return convert.str();
    }
};
ostream &operator<<(ostream &os, Pos pos) {
    return os << pos.str();
}
template <class T>
class matrix {
    int nl{0}, nc{0};
    vector<vector<T>> data;

public:
    matrix(int nl, int nc) {
        this->nl = nl;
        this->nc = nc;
        data.resize(nl);
        for (int i = 0; i < nl; i++) {
            data[i].resize(nc);
        }
    }
    matrix(int nl, int nc, T def) {
        this->nl = nl;
        this->nc = nc;
        data.resize(nl);
        for (int i = 0; i < nl; i++) {
            data[i].resize(nc);
            for (int j = 0; j < nc; j++) {
                data[i][j] = def;
            }
        }
    } 
    int nlines() {
        return nl;
    }
    int ncols() {
        return nc;
    }
    T& at(Pos pos) {
        return data[pos.l][pos.c];
    }
    T& operator[](Pos pos) {
        return data[pos.l][pos.c];
    }
    vector<T> &operator[](int l) {
        return data[l];
    }
    bool inside(Pos pos) {
        return pos.l >= 0 && pos.l < nl && pos.c >= 0 && pos.c < nc;
    }
    bool is_value(Pos pos, char value) {
        if (inside(pos)) {
            return data[pos.l][pos.c] == value;
        }
        return false;
    }
    string str() {
        stringstream convert;
        for (int i = 0; i < nl; i++) {
            for (int j = 0; j < nc; j++) {
                convert << data[i][j] << " ";
            }
            convert << endl;
        }
        return convert.str();
    }
};
template <>
    string matrix<char>::str() {
        stringstream convert;
        for (int i = 0; i < nl; i++) {
            for (int j = 0; j < nc; j++) {
                convert << data[i][j];
            }
            convert << endl;
        }
    return convert.str();
}
template <class T>
    ostream& operator<<(ostream& os, matrix<T>& m) {
        return os << m.str();
}

int main() {
    {
        matrix<int> m(3, 4, 5);
        cout << m;
    }
    {
        matrix<char> m(3, 4, 'a');
        cout << m;
    }
    {
        matrix<int> m(3, 4);
        m[0][0] = 1; //acesso via vetor secundário
        m[{2, 2}] = 2; //acesso via posicao
        cout << m;
        cout << m.inside({-1, 2}) << '\n';  //nao existe
        cout << m.is_value({2, 2}, 2) << '\n';  //se eh esse valor
        cout << m.is_value({-1, 2}, 0) << '\n';
    }

    return 0;

}