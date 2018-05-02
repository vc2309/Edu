import java.io.IOException;

public class Main {

    public static void main(String [] args)throws IOException
    {
        boolean gameOver = true;
        int score = 800;
        int levelCompleted = 5;
        int bonus = 100;
        int highScore = calculateScore(gameOver,score,levelCompleted,bonus);
        System.out.println(highScore);

        score+=200;
        levelCompleted+=3;
        bonus+=100;
        highScore=calculateScore(gameOver,score,levelCompleted,bonus);
        System.out.println(highScore);

        displayHighScorePosition("Vishnu", calculateHighScorePosition(1500));


    }

    public static int calculateScore(boolean gameOver,int score,int levelCompleted,int bonus)
    {
       int finalScore =  gameOver? (score+(levelCompleted*bonus))+2000 :  - 1;
       return finalScore;

    }

    public static void displayHighScorePosition(String name, int pos)
    {
        System.out.println(name+" managed to get into position "+pos+" on the high score table");
    }

    public static int calculateHighScorePosition(int score)
    {
        if (score>=1000)
            return 1;
        else if(score>=500)
            return 2;
        else if(score>1=00)
            return 3;
        else return 4;
    }
}
