/*

Наблюдатель (Observer) – поведенческий паттерн проектирования, 
который позволяет объектам оповещать другие объекты об изменениях 
своего состояния. Наблюдатели могут подписываться и отписываться 
от оповещений. Наблюдатель применяется, когда необходимо, 
чтобы отдельные компоненты реагировали на события, происходящие 
в других компонентах. Owner – конкретный наблюдатель, реализующий 
интерфейс Observer. Он подписывается на оповещение об изменениях 
в субъекте Dog, который вызывает метод уведомления call. 

*/

open class Subject {
    private var observers = mutableListOf<Observer>()

    fun addSubscriber(observer: Observer) {
        observers.add(observer)
    }

    fun deleteSubscriber(observer: Observer) {
        observers.remove(observer)
    }

    fun call() {
        for(observer in observers) observer.update()
    }
}

interface Observer {
    fun update()
}

class Dog : Subject() {
    fun bark() {
        println("ГАВ")
        call()
    }
}

class Owner(
    val pet: Dog
) : Observer {
    init {
        pet.addSubscriber(this)
    }

    override fun update() {
        println("Реагирует на лай")
    }
}



fun main(args: Array<String>) {
    val pug = Dog()
    val man = Owner(pug)

    pug.bark()
}
