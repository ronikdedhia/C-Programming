#include <stdio.h>
#include <stdlib.h>
/*
write a sentence in a file using fprintf() statement.
*/
int main() {
    char sentence[1000];
    FILE *fptr;
    fptr = fopen("program.txt", "w");
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    fprintf(fptr, "%s", sentence);
    fclose(fptr);
    return 0;
}
