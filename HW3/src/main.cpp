#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "shape.h"
#include "sort.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

 int main(int argc, char *argv[]){
   string exe = argv[0];
   string in = argv[1];
   string out = argv[2];
   string method = argv[3];
   string order = argv[4];
   cout << exe << endl;
   cout << in << endl;
   cout << out << endl;
   cout << method <<endl;
   cout << order << endl;



   ifstream inFile(argv[1]);
   vector <string>arr;
   string token;
   int l = 0;


   while(getline(inFile,token)){
     arr.push_back(token);
     l++;
   }
   vector<Shape*>* array = new vector<Shape*>;


   for(int j=0;j<l;j++){
     int pos = arr[j].find_first_of(" ",0);

     if(pos==6){
       int n = arr[j].find_first_of(")",0);
       //cout << arr[j].substr(0,pos) << endl;
       //cout << arr[j].substr(pos+2,n-pos-2) << endl;
       string a = arr[j].substr(pos+2,n-pos-2);
       double circler = atof(a.c_str());
       array->push_back(new Circle (circler));


     }
     else if(pos==9){
       int n = arr[j].find_first_of(",",pos+2);
       int o = arr[j].find_first_of(")",n+1);
       //cout << arr[j].substr(0,pos) << endl;
       //cout << arr[j].substr(pos+2,n-pos-2) << endl;
       //cout << arr[j].substr(n+1,o-n-1) << endl;
       string b = arr[j].substr(pos+2,n-pos-2);
       string c = arr[j].substr(n+1,o-n-1);
       double rectanglex = atof(b.c_str());
       double rectangley = atof(c.c_str());
       array->push_back(new Rectangle (rectanglex,rectangley));
     }
     else{
       //cout<<arr[j][pos+1]<<endl;
       int current = pos+1;
       string d[6];
       double trianglet[6];

       trianglet[0] = current;
       int next=0,i=0;
       next = arr[j].find_first_of(",",current);
       d[i] = arr[j].substr(current+1,next-current-1);
       trianglet [i] = atof(d[i].c_str());
       current = next + 1;
        //cout<<d[i]<<endl;
       i++;
       //cout << arr[j].substr(0,pos) << endl;
       while(next!=-1){
           next = arr[j].find_first_of(",",current);
           //cout << arr[j].substr(current,next-current)<<endl;
           d[i] = arr[j].substr(current,next-current);
           trianglet [i] = atof(d[i].c_str());
           current = next + 1;
           i++;
           if(i==5){
             next = arr[j].find_first_of(")",current);
             //cout << arr[j].substr(current,next-current)<<endl;
             d[i] = arr[j].substr(current,next-current);
             trianglet [i] = atof(d[i].c_str());
             next=-1;
           }
       }

       array->push_back(new Triangle (trianglet[0],trianglet[1],trianglet[2],trianglet[3],trianglet[4],trianglet[5]));
     }

   }

   inFile.close();




   string ss[l];
   fstream file;
   Sort s(array);
   file.open(argv[2],ios::out);
   if (!strcmp(argv[3],"perimeter")){
     if(!strcmp(argv[4],"dec")){
        s.sortPerimeter(perimeterDescendingComparison);
        file << "[";
        for (int ak=0;ak<l;ak++){
          //ss[ak]=to_string((*array)[ak]->perimeter());
          if(ak!=l-1)
            file << (*array)[ak]->perimeter()<<",";
          else
            file << (*array)[ak]->perimeter();
        }
        file<<"]";

      }
     else if(!strcmp(argv[4],"inc")){
        s.sortPerimeter(perimeterAscendingComparison);
        file << "[";
        for (int ak=0;ak<l;ak++){
          //ss[ak]=to_string((*array)[ak]->perimeter());
          if(ak!=l-1)
            file << (*array)[ak]->perimeter()<<",";
          else
            file << (*array)[ak]->perimeter();
        }
        file<<"]";
     }
   }
   else if (!strcmp(argv[3],"area")){
     if(!strcmp(argv[4],"dec")){
        s.sortArea(areaDescendingComparison);
        file << "[";
        for (int ak=0;ak<l;ak++){
          //ss[ak]=to_string((*array)[ak]->perimeter());
          if(ak!=l-1)
            file << (*array)[ak]->area()<<",";
          else
            file << (*array)[ak]->area();
        }
        file<<"]";
     }
     else if(!strcmp(argv[4],"inc")){
        s.sortArea(areaAscendingComparison);
        file << "[";
        for (int ak=0;ak<l;ak++){
          //ss[ak]=to_string((*array)[ak]->perimeter());
          if(ak!=l-1)
            file << (*array)[ak]->area()<<",";
          else
            file << (*array)[ak]->area();
        }
        file<<"]";
     }
   }

   file.close();

   return 0;
 }
