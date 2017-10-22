PROGRAM ComplexBuiltIn;

TYPE
    mystring = ARRAY[1..3] OF char;            

VAR
    x, y, z : complex;
    
PROCEDURE print(expr : mystring; VAR z : complex);
    BEGIN
        write(expr, ' = (', z.re:0:5, ', ', z.im:0:5, ') ');
    END;

BEGIN {ComplexTest}
    x.re := 3; x.im := 2;  print('  x', x);
    y.re := 8; y.im := -5; print('  y', y);
END {ComplexTest}.
