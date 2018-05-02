# Variables, Data Types, Statements

## Primitive Datatypes
- int : range (-,+) 2,147,483,648.
	Can write literals in java like this `int myMax = 2_147_483_648;`
- byte : width of 8, range 128

- short : width of 16, range 2^16

- long : width of 64 bits.
	initialise like this `long myLong = 100L;`

### Implicit Java conversion
if you try this, java implicitly converts any type in an init statement to an int
```
>>>>>>> f2d57bb2a9c454cdfe6a3c2574cdcebc7b121a88
byte myByte = 127;
byte myNew = (myByte/2); //Error
//Explicitly cast to byte
byte myNew = (byte)(myByte/2);
```

Implicitly casts up (byte->int) or (int->long) etc

## Floating point
	- float : initialize with 
			` float myFloat = 5.4L;` or `=5L;`
	- double : similar
		Use double because : - most precise - default usage by operations - much faster on most computers

## Char
	- width is 2 bytes
	- unicode character code


## String
	- check source code String class
