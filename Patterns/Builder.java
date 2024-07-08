/*

Строитель (Builder) – порождающий паттерн проектирования, 
который позволяет пошагово создавать сложные объекты. 
CabrioletBuilder и TruckBuilder – конкретные строители, 
которые устанавливают различные конфигурации объекта Car. 
Порядок шагов устанавливается в Director. Он определяет 
какие шаги строителей нужно вызвать, чтобы получить 
необходимую конфигурацию продукта. Director работает 
через общий интерфейс CarBuilder, что позволяет взаимозаменять 
объекты строителей для получения разных продуктов.

*/


abstract class CarBuilder {
    protected Car car;
    public Car getCar() { return car; }
    public void createNewCar() { this.car = new Car(); }

    public abstract void buildColor();
    public abstract void buildWheels();
    public abstract void buildRoof();
}

class Car {
    public String color;
    public String wheels;
    public String roof;
}
class CabrioletBuilder extends CarBuilder {
    public void buildColor() { car.color = "Красный"; }
    public void buildWheels() { car.wheels = "4"; }
    public void buildRoof() { car.roof = "Складная"; }
}

class TruckBuilder extends CarBuilder {
    public void buildColor() { car.color = "Синий"; }
    public void buildWheels() { car.wheels = "8"; }
    public void buildRoof() { car.roof = "Жесткая"; }
}

class Director {
    private CarBuilder carBuilder;

    public void setCarBuilder(CarBuilder cb) { carBuilder = cb; }
    public Car getCar() { return carBuilder.getCar(); }

    public void constructCar() {
        carBuilder.createNewCar();
        carBuilder.buildColor();
        carBuilder.buildWheels();
        carBuilder.buildRoof();
    }
}



public class Main {
    public static void main(String[] args) {
        Director director = new Director();
        CarBuilder cabrioletCarBuilder = new CabrioletBuilder();
        CarBuilder truckCarBuilder = new TruckBuilder();

        director.setCarBuilder(cabrioletCarBuilder);
        director.constructCar();
        Car car1 = director.getCar();
        System.out.println("Машина 1: колес: " + car1.wheels +
                " крыша: " + car1.roof + " цвет: " + car1.color);

        director.setCarBuilder(truckCarBuilder);
        director.constructCar();
        Car car2 = director.getCar();
        System.out.println("Машина 2: колес: " + car2.wheels +
                " крыша: " + car2.roof + " цвет: " + car2.color);
    }
}
