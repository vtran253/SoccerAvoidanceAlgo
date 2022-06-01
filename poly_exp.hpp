///////////////////////////////////////////////////////////////////////////////
// poly_exp.hpp
//
// Declarations for two algorithms:
//
// soccer_exhaustive
// soccer_dyn_prog
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <vector>

namespace algorithms {

  // Each of these functions solves the *soccer opponent avoidance problem*.
  //
  // soccer_exhaustive uses exhaustive search and takes exponential time.
  // soccer_dyn_prog uses dynamic programming and takes quadratic time.
  //
  // field is a vector of strings that defines a play field.
  //   So field[i] is row i, and field[i][j] is the cell at row i, column j.
  //   Each character must be '.' (passable) or 'X' (impassable).
  //   The number of rows and columns must both be positive.
  //   All rows must have the same number of columns.
  //
  // Returns the number of valid paths that start at the top-left corner at
  // (0, 0) and end at the bottom-right corner.
  //
  // Throws std::invalid_argument if field is invalid (empty, misshapen, or
  // contains invalid characters).
  //
  // In addition, soccer_exhaustive throws std::invalid_argument if n > 31,
  // where n = r + c - 2.
  soccer_dyn_prog(F):
  //  # corner case: initial cell is impassible
  int A[][];
    if( F[0][0]==X)
        {return 0;}
    A = new r⨉c matrix;
    //# base case
    A[0][0] = 1;
    //# general cases
    for (int i = 0; i <=  r-1 ; i++)
        for (int j = 0; j <= c-1; j++)
            if (F[i][j]==X){
                A[i][j]=0;
                }
            int above, from_left, left;
            //WTF is above and fromleft?
            above = from_left = 0;
            if (i>0 && F[i-1][j]== '.')'
                {above = A[i-1][j];}
            if (j>0 and F[i][j-1]== '.')
                {left = A[i][j-1];}
            A[i][j] = above + left ;
    return A[r-1][c-1];




  int soccer_exhaustive(const std::vector<std::string> field);

  int soccer_dyn_prog(const std::vector<std::string> field);

}
soccer_dyn_prog(F):
  # corner case: initial cell is impassible
  if F[0][0]==X:
      return 0
  A = new r⨉c matrix
  # base case
  A[0][0] = 1
  # general cases
  for i from 0 to r-1 inclusive:
      for j from 0 to c-1 inclusive:
          if F[i][j]==X:
              A[i][j]=0
              continue
          above = from_left = 0
          if i>0 and F[i-1][j]==.:
              above = A[i-1][j]
          if j>0 and F[i][j-1]==.:
              left = A[i][j-1]
          A[i][j] = above + left
  return A[r-1][c-1]
