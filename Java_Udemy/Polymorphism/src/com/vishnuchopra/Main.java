package com.vishnuchopra;

class Movie {
    private String name;

    public Movie(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public String plot()
    {
        return "No plot";
    }
}

class Jaws extends Movie {
    public Jaws() {
        super("Jaws");
    }

    @Override
    public String plot()
    {
        return "Shark eats people";
    }
}

class IndependenceDay extends Movie{
    public IndependenceDay()
    {
        super("Independence Day");
    }

    @Override
    public String plot(){
        return "Aliens invade earth" ;
    }
}

class StarWars extends Movie{
    public StarWars()
    {
        super("Star Wars");
    }

    @Override
    public String plot(){
        return "Yoda" ;
    }
}

class Forgettable extends Movie{
    public Forgettable() {
        super("Forgettable");
    }
}

public class Main {
    public static void main(String[] args) {

        for (int i = 0; i < 10; i++) {
            Movie m = randomMovie();
            System.out.println("Movie #"+ i + " : "+m.getName()+"\n"+"Plot : "+m.plot());
        }

    }
    public static Movie randomMovie(){
        int randomNo = (int) (Math.random()*5) +1;
        System.out.println("Random no is:" + randomNo);
        switch (randomNo){
            case 1 : return new Jaws();
            case 2 : return new IndependenceDay();
            case 3 : return new StarWars();
            case 4 : return new Forgettable();
            default: return new Jaws();
        }


    }
}
