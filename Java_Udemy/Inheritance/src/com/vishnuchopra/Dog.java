package com.vishnuchopra;

public class Dog extends Animal {
    private String coatColour;
    private String breed;

    public Dog(String name, int weight, int size, String coatColour, String breed) {
        super(name, weight, size);
        this.coatColour = coatColour;
        this.breed = breed;
    }

    public Dog(String name, int weight, int size) {
        super(name, weight, size);

    }

    @Override
    public void talk()
    {
        System.out.print("Woof");
        super.talk();
    }

    public String getBreed() {
        return breed;
    }

    @Override
    public void eat()
    {
        System.out.print(this.getName()+" the "+this.getBreed());
        super.eat();
    }

}
