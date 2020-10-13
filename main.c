/*
PASSWORD STRENGTH TESTER
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
  char p[50];
  char specials[32]="~`!@#$%^&*()-_+[]{}|/<>?/;:'\"";

  printf("Password: ");
  scanf("%s",p);

  //score deciding variables.

  int s=100,nc=0,sc=0,lac=0,uac=0;

  //iterating the string

  for(int i=0;i<strlen(p);i++){

    if(islower(p[i])) lac++; 

    else if(isupper(p[i])) uac++;

    else if(isdigit(p[i])) nc++;

    else{
      for(int j=0;j<strlen(specials);j++){
        if(p[i]==specials[j]) sc++;
      }
    }
  }

  if(strlen(p)<=3) s-=100;

  else if(strlen(p)<=5) s-=50;

  else if(strlen(p)<=8) s-=20;

  if(nc<3) s-=10;

  if(lac<3) s-=10;

  if(uac<3) s-=10;

  if(sc<3) s-=10;

  if(s<0) s=0;

  printf("\nPassword Strength: %d/100\n",s);
  printf("Strength Bar:\n");
  for(int i=0;i<=s/10;i++) printf("=");

  if(s<100){

   printf("\nFactors: \n");
  
   if(strlen(p)<=3) printf("Super Insecure, Too short\n");

   else if(strlen(p)<=5) printf("Very Insecure, Too small\n");

   else if(strlen(p)<=8) printf("Little Insecure, Could be made Longer\n");

   if(nc<3) printf("Less amount of digits\n");

   if(lac<3) printf("Less amount of Lower case Alphabets\n");

   if(uac<3) printf("Less amount of Upper case Alphabets\n");

   if(sc<3) printf("Less amount of Special Characters\n");

  }
  printf("\nPurposes: \n");
  if(s>=90){
    printf("Confidential And Security Purposes\n");
  }
  if(s>=70){
    printf("Banking And Office Purposes\n");
  }
  if(s>=65){
    printf("General Purposes\n");
  }
  if(s<=65){
    printf("Not Necessary/Informal Purposes\n");
  }
  return 0;
}