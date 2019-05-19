#include "intArray.h"
#include <iostream>
#include <iomanip>
#include "string.h"
#include <fstream>
#include <stdlib.h>

using namespace std;
/**
 *  Program #5
 *  This program runs test 1-20 given by another file. It overloads multiple operators
 *  CS320
 *  11/18/2018
 *  @author  Youssef Iraqi cssc0525
 */
IntArray::IntArray(){
    size=10;
    pA = new int[size];
    hi= 9;
    lo=0;
}

 IntArray::IntArray(int max){
     lo=0;
     hi=max-1;
     size=max;
     pA = new int[size];
 }


 IntArray::IntArray(int min, int max){
    
     if(min<max){
         lo = min;
         hi = max;
         size = max-min+1;
        pA = new int[max];
     }
     else if(min==max){
         lo = min;
         hi = max;
         size =1;
         pA = new int[max];
     }
     else{
         lo = min;
         hi = max;
         size = 0;
         pA = new int[max];
        
     }
 }

 IntArray::IntArray(const IntArray& array){
    lo=array.lo;
    hi=array.hi;
    size=array.size;
    int i;
    for(i=lo;i<=hi;i++){
        pA[i] = array.pA[i];
    }

 }

     IntArray::~IntArray() {
   
          pA = NULL;

}

int IntArray::operator==(const IntArray& array){
    if (size == array.size) {
        int i;
        for (i = 0; i < array.size; i++) {
            if (pA[lo+i] != array.pA[array.lo+i]) {
                return 0;
        }
        }
        return 1;
    } else return 0;
}




int IntArray::operator!=(const IntArray& array){
    if(size == array.size){
        int i;
        for(i=lo;i<=hi;i++){
            if(pA[lo+i-1] != array.pA[array.lo+i]){
                return true;
            }

        }
        return false;
    }
    else{
        return true;
    }
}




 int& IntArray::operator[] (int val){
     if(val<lo || val>hi){
         cout<<"Error in & IntArray::operator[]"<<endl;
         
     }
     
     return pA[val];
 }

IntArray& IntArray::operator=(const IntArray& array){
    
    if(size == array.size){
        int i;
        for(i=0;i<size;i++){
            pA[i+lo]= array.pA[array.lo+i];
        }
        return *this;
    }
    
        return *this;
    
}

IntArray IntArray::operator+(const IntArray& array){
    
    IntArray sum(array.size);
    if(size ==array.size){
         int i;
        for(i=0;i<=sum.size;i++){
        sum[i]= pA[i+1] + array.pA[array.lo+i];
    }
    }
    return sum;
}

IntArray& IntArray::operator+=(const IntArray& array){
    IntArray sum;
    int i,j;
    for(i=lo,j=array.lo;j<=array.hi;i++,j++){
        sum.pA[i]= array.pA[j];
    }
    for(i=lo;i<=hi;i++){
        pA[i]+=sum.pA[i];
    }
    return *this;
}



 ostream& operator<<(ostream& os, const IntArray& array){
     if(array.lo == array.hi){
         int i = array.lo;
         os<<array.name<<"[" << i << "] = " << array.pA[i]<<endl;
     }
     else{
         int i;
         for(i=array.lo;i<=array.hi;i++){
           os<<array.name<<"["<<i<<"] = " <<array.pA[i]<<endl;
         }
     }
     return os;

 }

 void IntArray::setName(char *name){
     this->name =name;
 }

void IntArray::getName(){
  cout<<name<<endl;
  
}

int  IntArray::high(){
    return hi;
}

int  IntArray::low(){
    return lo;
}
