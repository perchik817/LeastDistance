#include <iostream>
#include <cmath>

using namespace std;

// Function to compute the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    // Input parameters
    double a, b, c, r1, r2;
    cout << "Enter a, b, c, r1, r2: ";
    cin >> a >> b >> c >> r1 >> r2;

    // Find least distant point
    double x, y, y0, min_distance = INFINITY;
    for (double xi = r1; xi <= r2; xi += 0.01) {
        double yi = cos(3 * xi) * sin(2 * xi);
        if (yi < 0) {
            y0 = -(a * xi + c) / b;
            double t = (yi - y0) / (a * sin(3 * xi) - b * cos(3 * xi));
            x = xi - t * b;
            y = yi + t * a;
            double d = distance(a * x + b * y + c, 0, x, y);
            if (d < min_distance) {
                min_distance = d;
            }
        }
    }

    // Find most distant point
    double max_distance = 0;
    for (double xi = r1; xi <= r2; xi += 0.01) {
        double yi = cos(3 * xi) * sin(2 * xi);
        if (yi < 0) {
            double d = abs((b * cos(3 * xi) - a * sin(3 * xi)) * yi / sqrt(a * a + b * b));
            if (d > max_distance) {
                max_distance = d;
                x = xi;
                y = yi;
            }
        }
    }

    // Output results
    cout << "Least distance: " << min_distance << endl;
    cout << "Least distant point: (" << x << ", " << y << ")" << endl;
    cout << "Most distance: " << max_distance << endl;
    cout << "Most distant point: (" << x << ", " << y << ")" << endl;

    return 0;
}
