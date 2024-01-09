#include <stdio.h>     // Include the standard input/output header file.
int main() {
    float rec_width;         /* Declare variable 'rec_width' to store the width of the rectangle */
    float rec_height;        /* Declare variable 'rec_height' to store the height of the rectangle */
    float rec_perimeter;     /* Declare variable 'rec_perimeter' to store the perimeter (to be computed) */

    // Prompt the user to input the height of the rectangle.
    printf("Input the height of the Rectangle : ");
    scanf("%f", &rec_height);  // Read the value of 'rec_height' from the user.

    // Prompt the user to input the width of the rectangle.
    printf("Input the width of the Rectangle : ");
    scanf("%f", &rec_width);  // Read the value of 'rec_width' from the user.

    // Calculate the perimeter of the rectangle using the formula: perimeter = 2 * ( width + height )
    rec_perimeter = 2.0 * (rec_height + rec_width);

    // Print the calculated perimeter of the rectangle.
    printf("Perimeter of the Rectangle is : %f\n", rec_perimeter);

    return 0;  // Indicate successful program execution.
}