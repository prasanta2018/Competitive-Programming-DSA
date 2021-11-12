#include<stdio.h>
// Reverse Sentence
// Input: This is Juniper
// Outpur: Juniper is This

int getLength(char* str) {
    int count=0;
    while(str[count] != '\0') {
        count++;
    }
    return count;
}

void reverse(char* str, int start, int end) {
    // int start = 0, end = getLength(str);
    char c;
    // printf("actual string: %s\n", str);
    // printf("String length is: %d\n", end);
    end--;
    while(start < end) {
        // printf("%d ----- %d\n", start, end);
        c = str[start];
        str[start] = str[end];
        str[end] = c;
        start++;end--;
    }
    // printf("reverse string: %s\n", str);
}

void reverse_sentence(char* str) {
    int i=0, s=0;
    while(str[i] != '\0') {
        if(str[i] == ' ') {
            reverse(str, s, i);
            s = i+1;
        }
        i++;
    }
    // Last word
    reverse(str, s, getLength(str));
    // reverse the sentence
    reverse(str, 0, getLength(str));
    printf("Reverse sentence: %s\n", str);
}

int main() {
    char str[16] = "this is juniper";
    printf("Input sentence: %s\n", str);
    reverse_sentence(str);