#include <stdio.h>
#include <math.h>
// A simple 3D point with x, y, z coordinates
typedef struct {
    float x, y, z;
} Point3D;

// Display a 3D point
void showPoint(Point3D p) {
    printf("(%.1f, %.1f, %.1f)\n", p.x, p.y, p.z);
}
// Move the point by given amounts
Point3D movePoint(Point3D p, float move_x, float move_y, float move_z) {
    p.x += move_x;
    p.y += move_y;
    p.z += move_z;
    return p;
}
// Rotate point around X-axis by angle (in degrees)
Point3D turnX(Point3D p, float angle) {
    float rad = angle * (3.14159 / 180); // Convert to radians
    float new_y = p.y * cos(rad) - p.z * sin(rad);
    float new_z = p.y * sin(rad) + p.z * cos(rad);
    p.y = new_y;
    p.z = new_z;
    return p;
}
// Rotate point around Y-axis by angle (in degrees)
Point3D turnY(Point3D p, float angle) {
    float rad = angle * (3.14159 / 180);
    float new_x = p.x * cos(rad) + p.z * sin(rad);
    float new_z = -p.x * sin(rad) + p.z * cos(rad);
    p.x = new_x;
    p.z = new_z;
    return p;
}
// Rotate point around Z-axis by angle (in degrees)
Point3D turnZ(Point3D p, float angle) {
    float rad = angle * (3.14159 / 180);
    float new_x = p.x * cos(rad) - p.y * sin(rad);
    float new_y = p.x * sin(rad) + p.y * cos(rad);
    p.x = new_x;
    p.y = new_y;
    return p;
}

// Change size of point by given factors
Point3D resizePoint(Point3D p, float scale_x, float scale_y, float scale_z) {
    p.x *= scale_x;
    p.y *= scale_y;
    p.z *= scale_z;
    return p;
}

int main() {
    printf("Compiled by Sarfraj Alam\n"); 
    // Our starting point
    Point3D myPoint = {1.0, 1.0, 1.0};
    printf("Starting point: ");
    showPoint(myPoint);
    // Move the point
    myPoint = movePoint(myPoint, 2.0, 1.0, 0.5);
    printf("\nAfter moving by (2, 1, 0.5): ");
    showPoint(myPoint);
    // Rotate around X-axis
    myPoint = turnX(myPoint, 45);
    printf("\nAfter 45° X-rotation: ");
    showPoint(myPoint);
    // Rotate around Y-axis
    myPoint = turnY(myPoint, 30);
    printf("\nAfter 30° Y-rotation: ");
    showPoint(myPoint);
    // Change size
    myPoint = resizePoint(myPoint, 2.0, 0.5, 1.0);
    printf("\nAfter resizing by (2, 0.5, 1): ");
    showPoint(myPoint);
    return 0;
}

