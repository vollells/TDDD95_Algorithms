#include "iostream"

int main(void) {
    int a, b, c;
    while(std::cin >> a >> b && a != 0 && b != 0){
        int* a_alb = new int[a];
        int* b_alb = new int[b];

        for (int i = 0; i < a; i++) {
            std::cin >> c;
            a_alb [i] = c;
        }
        for (int i = 0; i < b; i++) {
            std::cin >> c;
            b_alb [i] = c;
        }

        unsigned long count=0, index_a=0, index_b=0;
        while(index_a < a && index_b < b) {
            if (a_alb[index_a] == b_alb[index_b]){
                index_a++;
                index_b++;
                count ++;
            } else if (a_alb[index_a] < b_alb[index_b]) {
                index_a++;
            } else if (a_alb[index_a] > b_alb[index_b]) {
                index_b++;
            }
        }

        delete[] a_alb;
        delete[] b_alb;
        std::cout << count << std::endl;
    }
    return 0;
}
