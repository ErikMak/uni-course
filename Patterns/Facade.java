/*

Фасад (Facade) – структурный паттерн проектирования, 
который предоставляет простой интерфейс к сложной 
системе. Применяется, когда необходимо скрыть сложную 
подсистему от прямого доступа клиента, предоставив 
упрощенный вариант.  Фасад Application агрегирует
классы Frontend и Backend, реализующие функциональность 
подсистемы, и аккумулирует набор операций для работы 
с данной подсистемой в единый метод open.

*/

class Backend {
    public void connectToDB() {
        System.out.println("Подключение к БД");
    }

    public void getData() {
        System.out.println("Получение данных");
    }
}

class Frontend {
    public void drawComponents() {
        System.out.println("Отрисовка компонентов");
    }

    public void loadData() {
        System.out.println("Загрузка данных");
    }
}

class Application {
    private Backend backend;
    private Frontend frontend;

    public Application() {
        this.backend = new Backend();
        this.frontend = new Frontend();
    }

    public void open() {
        backend.connectToDB();
        frontend.drawComponents();
        backend.getData();
        frontend.loadData();
    }
}



public class Main {
    public static void main(String[] args) {
        Application gosuslugi = new Application();
        gosuslugi.open();
    }
}
