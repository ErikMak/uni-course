from fastapi import FastAPI, status, HTTPException
from fastapi.responses import JSONResponse
from sqlalchemy import create_engine
from sqlalchemy.orm import DeclarativeBase
from sqlalchemy.orm import sessionmaker, Session
from sqlalchemy import Column, Integer, String

# БД
SQLALCHEMY_DATABASE_URL = "sqlite:///./cars.db"

engine = create_engine(
    SQLALCHEMY_DATABASE_URL, connect_args={"check_same_thread": False}
)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)


class Base(DeclarativeBase): pass
class Car(Base):
	__tablename__ = "cars"

	id = Column(Integer, primary_key=True)
	name = Column(String)

Base.metadata.create_all(bind=engine)



SessionLocal = sessionmaker(autoflush=False, bind=engine)
db = SessionLocal()

# API
app = FastAPI()


@app.get('/cars')
def get_all_cars():
	return db.query(Car).all()

@app.post('/cars')
def create_car(id, name):
	car = Car(id=int(id), name=name)
	db.add(car)
	db.commit()
	db.refresh(car)

	return JSONResponse(status_code=201, content={
		"msg": f"Машина добавлена!"
	})

@app.get('/cars/{id}') 
def get_car_by_id(id):
	id = int(id)
	car = db.query(Car).filter(Car.id == id).first()
	if car is None:
		return JSONResponse(status_code=404, content={
			"msg": f"Машина с id: {id} не найдена"
		})

	return car


@app.put('/cars')
def update_car(id, name):
	id = int(id)
	car = db.query(Car).filter(Car.id == id).first()
	if car is None:
		return JSONResponse(status_code=404, content={
			"msg": f"Машина с id: {id} не найдена"
		})

	car.id = id
	car.name = name

	db.commit()
	db.refresh(car)

	return car

@app.delete('/cars/{id}')
def delete_car(id):
	id = int(id)
	car = db.query(Car).filter(Car.id == id).first()

	if car is None:
		return JSONResponse(status_code=404, content={
			"msg": f"Машина с id: {id} не найдена"
		})

	db.delete(car)
	db.commit()