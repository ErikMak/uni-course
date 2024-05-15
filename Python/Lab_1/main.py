import numpy as np
import pandas as pd
from sklearn.ensemble import RandomForestClassifier

# Загрузка данных
trainData = pd.read_csv('train.csv')
trainData.columns
features = ['Pclass', 'Sex', 'Parch', 'SibSp', 'Age', 'Fare', 'Embarked']
x = pd.get_dummies(trainData[features])
y = trainData['Survived']

# Тренировка модели
model = RandomForestClassifier()
model.fit(x,y)

# Получить предсказания
pred_y = model.predict(x)

np.average(np.asarray(y) == pred_y)
gender_submission = pd.read_csv('gender_submission.csv')
np.average(np.asarray(x['Sex_female'] == np.asarray(y)))
test_data = pd.read_csv('test.csv')
x_test = pd.get_dummies(test_data[features])
# Получить предсказания
y_test = model.predict(x_test)
gender_submission['Survived'] = y_test
gender_submission.to_csv('my_submisson.csv', index=False)