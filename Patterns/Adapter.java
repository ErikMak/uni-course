/* 

Адаптер (Adapter) – структурный паттерн проектирования, 
который позволяет объектам с несовместимыми интерфейсами 
взаимодействовать друг с другом. Применяется, когда необходимо 
использовать существующий класс с несовместимым интерфейсом.
Класс Runner использует классы, реализующие интерфейс Road. 
Требуется использовать класс DirtRoad в качестве Road, 
однако он не реализует интерфейс Road. Для этого создается 
адаптер DirtRoadAdapter, реализующий необходимый интерфейс 
и содержащий объект класса DirtRoad. 

*/

interface Road {
    void run();
}

class Runner {
    private Road road;

    public Runner(Road road) {
        this.road = road;
    }
    public void runOnRoad() {
        System.out.println("Старт");
        road.run();
        System.out.println("Финиш");
    }
}

class DirtRoad {
    void walk() {
        System.out.println("Иду по проселочной дороге");
    };
}

class DirtRoadAdapter implements Road {
    private DirtRoad road;

    public DirtRoadAdapter() {
        this.road = new DirtRoad();
    }

    public void run() {
        road.walk();
    }
}



public class Main {
    public static void main(String[] args) {
        Runner runner = new Runner(new DirtRoadAdapter());
        runner.runOnRoad();
    }
}
