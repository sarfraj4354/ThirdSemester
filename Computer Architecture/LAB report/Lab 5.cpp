#include <stdio.h>
void print_binary(int num, int bits) {
    int i;
    for (i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}
void print_step(int step, const char* op, int A, int Q, int bits) {
    printf("| %2d | %-12s | ", step, op);
    print_binary(A, bits);
    printf(" | ");
    print_binary(Q, bits);
    printf(" |\n");
}
int main() {
    int dividend, divisor;
    int bits = 4;
    int A, Q, M;
    int step;
    printf("**Restoring Algorithm By Sarfraj Alam**\n");
    printf("Restoring Division Algorithm (4-bit)\n");
    printf("Enter dividend (0-15): ");
    scanf("%d", &dividend);
    printf("Enter divisor (0-15): ");
    scanf("%d", &divisor);
    A = 0;
    Q = dividend;
    M = divisor;
    step = bits;
    printf("\n+----+--------------+--------+--------+\n");
    printf("|Step| Operation    | A      | Q      |\n");
    printf("+----+--------------+--------+--------+\n");
    print_step(step, "Initial", A, Q, bits);

    for (step = bits; step > 0; step--) {
        // Shift AQ left
        A = (A << 1) | ((Q >> (bits-1)) & 1);
        Q <<= 1;
        print_step(step, "Shift AQ", A, Q, bits);

        // Subtract M from A
        A -= M;
        print_step(step, "A = A - M", A, Q, bits);

        if (A < 0) {
            A += M; // Restore
            print_step(step, "Restore A", A, Q, bits);
        } else {
            Q |= 1; // Set LSB
            print_step(step, "Set Q0=1", A, Q, bits);
        }
    }

    printf("+----+--------------+--------+--------+\n");
    printf("\nResult: Quotient = %d, Remainder = %d\n", Q & 0xF, A & 0xF); // Mask to 4 bits
    return 0;
}

