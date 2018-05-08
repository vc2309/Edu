# java.lang.Object
- in Java, every single class implictly extends java's inbuilt class Object.
- this is equivalent to declaring every class as `public class Main extends Object`

## Properties
- since every class you can create in Java is implictly a subclass of Object, it gets properties of Object as well
- this include the following
	1. public final native Class<?> getClass(); // Returns the runtime class of this object
	2. public boolean equals(Object obj) {
        return (this == obj);
    }	// tests for equality duh
    3. public String toString(); //Returns a string representation of the object.
    4. public final native void notify(); // Wakes any one thread waiting for this obj