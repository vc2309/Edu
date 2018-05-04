## Classes
- `public class Student` creates a class named Student
- a class is a user defined data type
- it has properties (class members / fields)
- and it has behaviours (member methods/functions)

## Packages
- `com.vishnuchopra` : package com .(subfolder) vishnuchopra/
- contains multiple classes which can access each other if scope is suitable

## Access Specifiers
- public / private / protected
```
public class Car{
	private int VID;
	private String model;
	public void printDetails();
}
```

- Initializing an object comes with some functions inherited from the JAVA Object class
	1. equals(Object obj)
	2. hashCode()
	3. getClass()
	...

## Constructors
- initialize field values of an object