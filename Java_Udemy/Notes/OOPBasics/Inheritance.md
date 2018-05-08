# Inheritance in Java

- to make a class a derived class of a base class, we use the following syntax in Java:
```
public class Animal {
	// Define class...
}

public class Dog extends Animal{
	// Define class...
}
```

- if we use cmd+N to generate a constructor in Dog, IntelliJ idea will create the following function
```
public Dog(String name, int weight, int size) {
        super(name, weight, size);
    }
```

- here, `super` is a reference to the Base class of dog, which is Animal. calling super() is equivalent to calling the constructor of Animal

## Override
- to call a more specialized version of a method already implemented in the super class
- use the `@Override` annotation