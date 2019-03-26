
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author: Mariam Ahmad Amin
// sources : Dr. Mohammad El-Ramly 's  base code to read the image
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
void loadImage ();
void saveImage ();

void merge_();
void darken();
void lighten();
void shri();
void blur();


int main()

{
int ans ;
cout<<"choose: \nif merge two pictures enter 1 \nif darken enter 2 \nif lighten enter 3 \nif shrink enter 4\n if Blur effect enter 5"<<endl;
loadImage();


if (ans==1)
    merge_();
 else if (ans==2)
    darken ();
else if (ans==3)
    lighten();
else if (ans==4)
    shri();

else if (ans==5)
    blur ();

else (cout<<"unvalid number " <<endl;)

saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image 1 file name
   cout << "Enter the source image 1 file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);

}


//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//_________________________________________
 void merge_() {

   char image2FileName[100];

   // Get gray scale image 2 file name
   cout << "Enter the source image 2 file name: ";
   cin >> image2FileName;

   // Add to it .bmp extension and load image
   strcat (image2FileName, ".bmp");
   readGSBMP(image2FileName, image2);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

  image[i][j]=((image[i][j]+image2[i][j])/2.0);
}
}
}
void darken(){


 for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
    if(image[i][j] <=64)
    image[i][j] =0;
    else
    image[i][j] -= 64;
}
}
}
void lighten(){

for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
    if(image[i][j] >=192)
    image[i][j] =255;
    else
    image[i][j] += 64;
}
}
}

void shri (){
cout<<"if you want to to shrink the image dimensions to 1/2 , enter 1 \n  1/3 enter 2 \n or 1/4 enter 3 ? ";
int ans2 ;
cin>>ans2 ;
if (ans2==1){

int f=0;
for(int i=0 ; i<SIZE ; i+=2){
int g = 0 ;
for(int j=0 ; j<SIZE ; j+=2){

image[f][g]=((image[i][j]+image[i+1][j]+image[i][j+1]+image[i+1][j+1])/4.0) ;
g+=1;
}
f+=1;
}

for(int i=0 ; i<SIZE ; i+=1){

for(int j=0 ; j<SIZE ; j+=1){
if ((i>=SIZE/2.0)||(j>=SIZE/2.0))
image[i][j]=255;
}}}
else if(ans2==2){
int f=0;
for(int i=0 ; i<SIZE ; i+=3){
int g = 0 ;
for(int j=0 ; j<SIZE ; j+=3){

image[f][g]=((image[i][j]+image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i][j+2]+image[i+2][j]+image[i+2][i+2]+image[i+1][j+2]+image[i+2][j+1])/9.0) ;
g+=1;
}
f+=1;
}

for(int i=0 ; i<SIZE ; i+=1){

for(int j=0 ; j<SIZE ; j+=1){
if ((i>=SIZE/3.0)||(j>=SIZE/3.0))
image[i][j]=255;
}}}
if (ans2==3){
int f=0;
for(int i=0 ; i<SIZE ; i+=4){
int g = 0 ;
for(int j=0 ; j<SIZE ; j+=4){

image[f][g]=((image[i][j]+image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i][j+2]+image[i+2][j]+image[i+2][j+1]+image[i+1][i+2]+image[i+2][i+2]+image[i][j+3]+image[i+1][j+3]+image[i+2][j+3]+image[i+3][j+3]+image[i+3][j]+image[i+3][j+1]+image[i+3][j+2])/16.0) ;
g+=1;
}
f+=1;
}

for(int i=0 ; i<SIZE ; i+=1){

for(int j=0 ; j<SIZE ; j+=1){
if ((i>=SIZE/4.0)||(j>=SIZE/4.0))
image[i][j]=255;
}}}
}
void blur () {
char aver;
for (int i=0 ; i<SIZE ; i+=2){
for (int j=0 ; j<SIZE ; j+=2){
aver=((image[i][j]+image[i+1][j]+image[i][j+1]+image[i+1][j+1]+image[i][j+2]+image[i+2][j]+image[i+2][i+2]+image[i+1][j+2]+image[i+2][j+1])/9.0);
image[i][j]=aver;
image[i+1][j]=aver;
image[i][j+1]=aver;
image[i+1][j+1]=aver;
image[i][j+2]=aver;
image[i+2][j]=aver;
image[i+2][i+2]=aver;
image[i+1][j+2]=aver;
image[i+2][j+1]=aver;

}}
}
