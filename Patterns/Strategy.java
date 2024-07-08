/*

Стратегия (Strategy) – поведенческий паттерн проектирования, 
который определяет семейство схожих алгоритмов и инкапсулирует 
каждый из них, после чего алгоритмы можно взаимозаменять во 
время исполнения программы. ComputerStategy определяет, 
как будут использоваться различные алгоритмы. Computer 
использует конкретные классы Music, Game, Video реализующие 
интерфейс ComputerStrategy, которые приходят через конструктор 
или сеттер setNewTask, тем самым вызывая необходимый алгоритм.

*/



interface ComputerStrategy {
    void execute();
}

class Music implements ComputerStrategy {
    @Override
    public void execute() {
        System.out.println("Запущена музыка!");
    }
}

class Game implements ComputerStrategy {
    @Override
    public void execute() {
        System.out.println("Запущена игра!");
    }
}

class Video implements ComputerStrategy {
    @Override
    public void execute() {
        System.out.println("Запущено видео!");
    }
}

class Computer {
    private ComputerStrategy strategy;

     public Computer(ComputerStrategy strategy) {
         this.strategy = strategy;
     }

     public void setNewTask(ComputerStrategy strategy) {
         this.strategy = strategy;
     }

     public void run() {
         this.strategy.execute();
     }
}


public class Main {
    public static void main(String[] args) {
        Computer pc = new Computer(new Video());
        pc.run();
        pc.setNewTask(new Music());
        pc.run();
        pc.setNewTask(new Game());
        pc.run();
    }
}
