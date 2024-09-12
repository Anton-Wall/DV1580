int main(void)
{
    int arr[10];
    arr[0] = 5;
    arr[9] = 123;

    int ar2[5] = {1, 2}; // the rest of the elements are initialized to 0

    int arr3[] = {1, 2, 3, 4, 5};
    int arr4[] = {[3] = 22, [2] = 5};

    char charArr[] = {66, 84, 72, 0}; // BTH

    char hexArr[] = {0x42, 0x54, 0x48, 0x0}; // BTH

    char message[4] = {'B', 'T', 'H', 0};
    char otherMessage[] = "BTH";

    return 0;
}