#include <iostream>
using namespace std;
class MyCin
{
    bool read_eof;
public:
    MyCin() {
        read_eof = false;
    }

    MyCin &operator >>(int &x) {
        cin >> x;
        if (x == -1)
            read_eof = true;
        return *this;
    }

    operator bool() const {
        if (read_eof) return 0;
        return 1;
    }
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}