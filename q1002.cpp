#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T; // number of test case
    int x1, y1, r1, x2, y2, r2;

    cin >> T;

    int* num_ans = new int[T]; // array that stores answers

    for(int i=0; i<T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        // count the number of intersection(s) of circles: 
        // with radius r1 and center (x1, y1), with radius r2 and center (x2, y2)
        
        double d; // distance between (x1, y1) and (x2, y2)
        d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        
        // infinite intersections- if the two circles are exactly the same
        if(d == 0 && r1 == r2) { num_ans[i] = -1; }
        
        // one intersection
        else if(d == r1+r2 || d == abs(r1-r2)) { num_ans[i] = 1; }
        
        // two intersections- if d, r1, r2 forms a triangle
        else if(d < r1+r2 && d > abs(r1-r2)) { num_ans[i] = 2; }

        // zero intersection
        else { num_ans[i] = 0; }

        cout << num_ans[i] << endl;
    }

    num_ans = nullptr;
    delete[] num_ans;
}