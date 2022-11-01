#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#include <string.h>

#define CHARS 100
#define HEADERS 10

typedef struct Pixel{
    int r;
    int g;
    int b;
}Pixel;


int main(int argc, char** argv){

                                   // printf("DEBUG\n");
    //load a file

    //open the file.
    if(argc<2){
        printf("Make sure you give the filename for the image you want to convert!");
        return -1;
    }

    //load a file
    else{
        FILE *fp;
        char p3[3];
        int height,width,maxval;
        int* hp=&height;
        int* wp=&width;
        int* maxp=&maxval;
        char trashcan[20];
        Pixel* pixels[height*width*sizeof(Pixel)]; 
        fp=fopen(argv[1],"r");
        int result=fscanf(fp,"%s %d %d %d",p3,hp,wp,maxp);
        //fread(height,3,1,fp);
        //fread(width,3,1,fp);
        
        printf("{%s}, height{%d} width{%d} max{%d}",p3,height,width,maxval);
        printf("[%d]",result);
        
        printf("DEBUG NO SEG FAULT YET\n");

    //load a file
        int red,green,blue;
        int* rp=&red;
        int* gp=&green;
        int* bp=&blue;
        int i =0;
        //read until EOF

    //load a file
        
           printf("\n???\n");
           if(i<(height*width)){
           printf("yep");}
        while(fscanf(fp,"%d %d %d",rp,gp,bp)!=EOF&& i<(height*width)){
            printf("no seg fault yet...%d\n",i); 
            //make a pointer for struct,
            Pixel *pixelPointer;
            pixelPointer=malloc(sizeof(Pixel));
            //insert pointer into an array for the pointers that point to pixels.
            //printf("%d ",i); 
            pixelPointer->r=*rp;
            pixelPointer->g=*gp;
            pixelPointer->b=*bp;

            //wtf line below
            pixels[i]=(Pixel*)pixelPointer;
            //WHY....

            i++;
        }
        int numPixels=i;
        //this number is end of array index + 1.
        printf("finished reading input from file! with %d iterations (%d expected )\n",i,(width*height));
        fclose(fp);


        return 0;

        
    }

    //ppm starts with a line containing "P3"
    //second line contains two integers separated by a space
    //width and height^
    //third line contains one int with max color val.
    //typically this val is 255, the largest value for an
    //unsigned byte.

    //the rest of the file is 3*W*H values for color data
    //one set of three vals for each pixel (RGB)
    //color values separated by whitespace.

    //modify the image locally


    //save the blurred image to a new file.
}
