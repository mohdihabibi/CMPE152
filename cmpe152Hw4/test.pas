PROGRAM ComplexBuiltIn;

TYPE
    mystring = ARRAY[1..3] OF char;

        comp = RECORD
                  re, im : real
              END;
              

VAR
    x, y, z : complex;
    


BEGIN {ComplexTest}
    x.re := 3;    x.im := 3; 
    y.re := 8;    y.im := 8; 
END {ComplexTest}.
