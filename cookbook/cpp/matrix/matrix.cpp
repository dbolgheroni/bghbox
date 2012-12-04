#include <vector>

using namespace std;

int main() {
    int i = 0;
    vector<vector<double> > matrix;

    // initialize matrix
    matrix.resize(10000);
    for (int i = 0; i < 500; ++i) {
        matrix[i].resize(500, 0);
    }

    matrix[0][0] = 1.0;

    printf("matrix[][] = %lf\n", matrix[2][2]);
}
