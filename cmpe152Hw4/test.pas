PROGRAM ComplexBuiltIn;

TYPE
    mystring = ARRAY[1..3] OF char;

VAR
    x, y, z : complex;
    test : real;

PROCEDURE print(expr : mystring; VAR z : complex);
    BEGIN
        write(expr, ' = (', z.re:0:5, ', ', z.im:0:5, ') ');
    END;

BEGIN {ComplexTest}
	test := 7;
    x.re := 3; x.im := 2;  print('  X', x);
    y.re := 8; y.im := -5;   print('  Y', y);
END {ComplexTest}.
