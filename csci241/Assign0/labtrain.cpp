
#include <stdio.h>

int main() {
    unsigned int num = 0x12345678;
    char* ptr = (char*)&num;
    
    if (ptr[0] == 0x78 && ptr[1] == 0x56 && ptr[2] == 0x34 && ptr[3] == 0x12) {
        printf("This machine uses a little-endian byte order.\n");
    } else if (ptr[0] == 0x12 && ptr[1] == 0x34 && ptr[2] == 0x56 && ptr[3] == 0x78) {
        printf("This machine uses a big-endian byte order.\n");
    } else {
        printf("Unknown byte order.\n");
    }
    
    return 0;
}
