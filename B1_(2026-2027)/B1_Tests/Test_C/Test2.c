#include "header.h"


int max_reach = 1337;
int min = 1;
int max = 26;


int main() {
    int i = 0;
    while (i < max_reach) {
      int random = min + rand() % (max - min + 1);  
      if (random == 1) {
        printf("®");
      } else if (random == 2) {
        printf("©");
      } else if (random == 3) {
        printf("℗");
      } else if (random == 4) {
        printf("™");
      } else if (random == 5) {
        printf("℠");
      } else if (random == 6) {
        printf("№");
      } else if (random == 7) {
        printf("ª");
      } else if (random == 8) {
        printf("º");
      } else if (random == 9) {
        printf("℔");
      } else if (random == 10) {
        printf("℥");
      } else if (random == 11) {
        printf("ℨ");
      } else if (random == 12) {
        printf("ℬ");
      } else if (random == 13) {
        printf("ℊ");
      } else if (random == 14) {
        printf("µ");
      } else if (random == 15) {
        printf("Ω");
      } else if (random == 16) {
        printf("ℹ︎");
      } else if (random == 17) {
        printf("ℌ");
      } else if (random == 18) {
        printf("ℑ");
      } else if (random == 19) {
        printf("℞");
      } else if (random == 20) {
        printf("ℳ");
      } else if (random == 21) {
        printf("℃");
      } else if (random == 22) {
        printf("℉");
      } else if (random == 23) {
        printf("℀");
      } else if (random == 24) {
        printf("℁");
      } else if (random == 25) {
        printf("℅");
      } else if (random == 26) {
        printf("℆");
      }
        i++;
    }
}