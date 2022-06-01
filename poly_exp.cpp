///////////////////////////////////////////////////////////////////////////////
// poly_exp.cpp
//
// Definitions for two algorithms:
//
// soccer_exhaustive
// soccer_dyn_prog
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
#include <stdio.h>
#include "poly_exp.hpp"

using namespace std;

int algorithms::soccer_exhaustive(const std::vector<std::string> field) {
  if (field.empty()){throw invalid_argument("invalid_argument");}
  if (field.size() == 0){throw invalid_argument("invalid_argument");}
  if (field[0].size() == 0){throw invalid_argument("invalid_argument");}
  if (field.size() > 31){throw invalid_argument("invalid_argument");  }
  if (field[0][0] == 'X'){return 0;}
  
  int r = field.size();
  int c = field[0].size();


//  if (r == 0 || c == 0){throw invalid_argument("invalid_argument");}
  if (r > 17) {throw invalid_argument("invlaid_argument");}
  if (c > 17) {throw invalid_argument("invalid_argument");}

  int len = r + c -2;
  int counter = 0;

  /*for( int h =0; h<field.size(); h++)
  {
    if(field.size() != r || field[h].size() != c){
      throw invalid_argument("invalid");
    }
    for (int g = 0; g<field[0].size(); g++){
      if((field[h][g] != 'X') && field[h][g] !='.'){
        throw invalid_argument("invalid");
      }
    }
  }*/
  for(int g = 0; g < field.size(); g++)
    {
      if(field.size() != r || field[g].size() != c)
        throw invalid_argument("invalid");

      for(int h = 0; h < field[0].size(); h++)
      {
        if(field[g][h] != 'X' && field[g][h] != '.')
          throw invalid_argument("invalid");
      }
    }

  for (int bits = 0; bits <=pow(2, len-1); bits ++)
  {

    int temprow = 0;
    int tempcollumn = 0;
    vector<char> candidate;
    for(int k = 0; k <=(len-1); k++)
    {
        int bit =( (bits >> k ) & 1);
        if (bit == 1){candidate.push_back('r');}
        else {candidate.push_back('d')  ;}
      }
      bool tempfail = false;
    for(int i =0; i <candidate.size(); i++){
      if( candidate[i] =='r' && temprow < r){temprow++;}
      if( candidate[i] =='d' && tempcollumn < c){tempcollumn++;}
      if( temprow >= r || tempcollumn >= c){tempfail = true; break;}
     }
     if(!tempfail){
            if(field[temprow][tempcollumn] == '.'){counter ++;} }
    }

    return counter;
}

int algorithms::soccer_dyn_prog(const std::vector<std::string> field) {

if (field.empty())
    {
    	throw invalid_argument("invalid_argument");
    }
     
    
    //Initial Variables
    int r = field.size();
    int c = field[0].size();
   
   
   //Vector A
   vector<vector<int>> A(r, vector<int>(c));
   
   
   if (r == 0) { throw invalid_argument("invalid_argument");} 
   if (c == 0) { throw invalid_argument("invalid_argument");}
     
    A[0][0] = 1;
    
     for(int p = 0; p < field.size(); p++)
    {
      if(field.size() != r) //|| field[p].size() != c)
      {
        throw invalid_argument("invalid_argument");
      }
      
      if (field[p].size() != c)
      {
        throw invalid_argument("invalid_argument");
      }
      
      
      for(int l = 0; l < field[0].size(); l++)
      {
        if(field[p][l] != 'X' && field[p][l] != '.')
        {
          throw invalid_argument("invalid_argument");
          
        }
        
      }  
      
    }
      
    
    //general cases
    for( int i =0; i<=r-1; i++)
    {
       
      for(int j = 0; j<=(c-1);j++)
      {
      
      	
       if(field[i][j] == 'X')
        {
          A[i][j] = 0;
          continue;
        }
        
        int above = 0;
        int left = 0;
               
        if( i>0 && (field[i-1][j] == '.'))
        {
         
          above = A[i-1][j];
        }
        
        if(j>0 && (field[i][j-1] == '.'))
        {
   	  
           left = A[i][j-1];
        }
        
        A[i][j] += (above+left);  
            
      }
      
    }   
    
    return A[r-1][c-1];
};
