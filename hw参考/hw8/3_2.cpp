#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;


template <class T>
class CArray3D
{
private:
    int d1, d2, d3;
    T *pool;

    class CArray2D {
    private:
        int d2, d3;
        T *pool;

        class CArray1D {
        private:
            int d3;
            T *pool;

        public:
            CArray1D(int _d3, T *p): d3(_d3), pool(p) {}
            T &operator [](int x) {
                return pool[x];
            }

            operator T*() {
                return pool;
            }
        };
        CArray1D **pointer;

    public:
        CArray2D(int _d2, int _d3, T *p): d2(_d2), d3(_d3), pool(p) {
            pointer = new CArray1D* [d2];
            for (int i = 0; i < d2; ++i)
                pointer[i] = new CArray1D(d3, pool + i * d3);
        }

        CArray1D &operator [](int x) {
            return *pointer[x];
        }

        operator T*() {
            return pool;
        }
    };
    CArray2D **pointer;

public:
    CArray3D(int _d1, int _d2, int _d3): d1(_d1), d2(_d2), d3(_d3) {
        pool = new T[d1 * d2 * d3];
        pointer = new CArray2D* [d1];
        for (int i = 0; i < d1; ++i)
            pointer[i] = new CArray2D(d2, d3, pool + i * d2 * d3);
    }

    CArray2D &operator [](int x) {
        return *pointer[x];
    }

    operator T*() {
        return pool;
    }
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 5; ++k) 
				cout << a[i][j][k] << "," ;
			cout << endl;
		}
	}
}
void PrintB()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k) 
				cout << b[i][j][k] << "," ;
			cout << endl;
		}
	}
}

int main()
{

	int No = 0;
	for( int i = 0; i < 3; ++ i ) {
		a[i];
		for( int j = 0; j < 4; ++j ) {
			a[j][i];
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
			a[j][i][i];	
		}
	}
	PrintA();
	memset(a[1],-1 ,20*sizeof(int));	
	memset(a[1],-1 ,20*sizeof(int));
	PrintA(); 
	memset(a[1][1],0 ,5*sizeof(int));	
	PrintA();

	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 2; ++k )
				b[i][j][k] = 10.0/(i+j+k+1);
	PrintB();
	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;
		
	return 0;
}