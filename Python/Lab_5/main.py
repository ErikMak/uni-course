""" 
Парсер -- программа, которая преобразует текстовое выражение в 
абстрактное синтаксическое дерево.
https://ru.wikipedia.org/wiki/Абстрактное_синтаксическое_дерево

Прочитайте листинг ниже. Это парсер простых выражений включаящих скобки,
операции +, -, *, /, ** постфиксные и префиксные ++, -- и постфиксный !. Текущая
версия 0.0 поддерживает только выражения без скобок с операциями с одинаковым
приоритетом.  Доработайте парсер за 4 шага, чтобы он обладал всеми
перечисленными выше возможностями.  Для каждой из версий есть тестовое выражение
в конце листинга. Прежде чем переходить к следующему шагу, проверьте, что
программа обрабатывает соответствующее тестовое выражение корректно.
Если вы будете писать собственные примеры, учтите, что операнды, операторы и скобки
должны быть разделены пробелами, иначе программа будет работать некорректно.

Версия 0.1 -- Приоритеты:
Необходимо модифицировать метод parse_xpr.  Мы можем сохранять приоритет
последней найденной операции, передавая его как аргумент функции при рекурсивном
вызове. Такую операцию можно назвать ожидающей. В зависимости от того, выше или
ниже приоритет следующей найденной операции по отношению к ожидающей, можно
решить, нужно ли уже вернуть первый операнд выражения, или продолжить
рекурсивный спуск. Модифицируйте код следующим образом:

1. Получите приоритет текущей операции (переменная op), запросив его из словаря
self.priorities.

2. Проверьте, не больше ли он приоритета предыдущей, "ожидающей" операции. Если
он меньше или равен приоритету ожидающей, верните первый операнд (переменная
left). Попробуйте вставить соотетствующий код перед вызовом и после вызова
self.consume(). Почему в одном случае программа работает, а в другом нет?
Если перед это может привести к тому, что предыдущая операция будет завершена, когда ожидался следующий токен для ее выполнения.
(текущий токен, который будет обработан в следующей итерации, будет относиться к следующей операции)
Если после - корректно определится, нужно ли вернуть первый операнд текущей операции или продолжить анализ выражения

3. Иначе передайте полученный приоритет в рекурсивный вызов parse_xpr.

Версия 0.2 -- Скобки:
Добавьте в parse_xpr проверку того, является ли левый операнд на самом деле
не операндом, а открывающей скобкой '('. Если да, можно считать, что
выражение внутри скобки и есть первый операнд (либо самостоятельное выражение).

1. Проверьте, не является ли left открывающей скобкой. Если это так, нужно
рекурсивно вызвать parse_xpr и обновить left полученным значением. Затем нужно
потребить следующий токен и проверить, чтобы он был равен закрывающей скобке.
Используйте для этого оператор языка Python assert.

2. В условии цикла теперь необходимо проверить, что оператор op не является
закрывающей скобкой, т.к. это также будет означать конец текущего выражения, как
и None. Обе проверки (на None и на скобку) должны работать одновременно.

Версия 0.3 -- Постфиксные операторы:
Постфиксные операторы проще всего искать в самом начале тела цикла. Проверяем
уже имеющийся оператор, не является ли он префиксным, если да, то потребляем
токен, переписываем left на (op, left, None), обновляем op через self.peek и
вызываем continue.  Чтобы убрать op = self.peek() перед циклом, в его конце и
перед continue, можно обновлять его прямо в условии, используя моржовый
оператор: while (op := self.peek()) not in ...
Подробнее о моржовом операторе:
https://habr.com/ru/companies/otus/articles/555924/

Версия 0.4 -- Перфиксные операторы:
left может быть не только операдном или скобкой, но еще и префиксным оператором.
Казалось бы, left достаточно заменить на применение оператора к left.  Однако,
префиксный оператор также может быть применен к выражению в скобках.  Идея
состоит в следующем: проверить, не является ли следующий токен префиксным
оператором, и если он таковым является, сделать рекурсивный вызов parse_xpr,
передав в него приоритет, соответствующий этому оператору. Из значения, которое
вернется (назовем его right), и оператора, можно создать новый первый операнд:
left = (op, None, right).  Используйте метод peek чтобы проверить, не является
ли следующий токен префиксным оператором.

Если это так, то:
1. Потребите токен, используя метод consume;

2. Вызовите parse_xpr с приоритетом операнда;

3. Результат вызова функции вместе с оператором присвойте первому операнду: left
= (op, None, right);

4. Убедитесь, что проверка на открывающую скобку является альтернативной веткой
(elif), а не последовательной (if). Например: x = self.peek()
    if x in self.prefix: ...
    elif x == '(': ...
    else: ...

"""


# ВЕРСИЯ 0.0
class BasicParser:
    priorities = {
        "+": 50,
        "-": 50,
        "*": 100,
        "*": 100,
        "**": 500,
        "++": 1000,
        "--": 1000,
        "!": 1000,
    }
    prefix = ["++", "--"]
    postfix = ["++", "--", "!"]

    def __init__(self, string: str):
        self.tokens = string.split()
        self.i = 0

    def peek(self):
        if self.i >= len(self.tokens):
            return None
        return self.tokens[self.i]

    def consume(self):
        t = self.peek()
        self.i += 1
        return t

    def parse_xpr(self, priority=-999):
        left = self.consume()
        op = self.peek()
        while op:
            self.consume()
            right = self.parse_xpr()
            left = (op, left, right)
            op = self.peek()
        return left

print(BasicParser("3 + 4 - 5").parse_xpr())  # v 0.0

# ВЕРСИЯ 0.1
class Parser_01(BasicParser):
    def parse_xpr(self, priority=-999):
      left = self.consume()
      op = self.peek()
      while op:
          # Сравнение текущей операции с ожидающей
          current_priority = self.priorities.get(op, -999)
          if current_priority <= priority:
              break
          self.consume()
          right = self.parse_xpr(current_priority)
          left = (op, left, right)
          op = self.peek()
      return left

print(Parser_01("3 + 4 * 5").parse_xpr())  # v 0.1
print(Parser_01("3 + 4 - 5").parse_xpr())  # v 0.1

# ВЕРСИЯ 0.2
class Parser_02(BasicParser):
  def parse_xpr(self, priority=-999):
        left = self.consume()
        # Если попалась открывающаяся скобка
        if left == '(':
            # Читается выражение внутри скобок
            left = self.parse_xpr()
            assert self.consume() == ')'

        op = self.peek()
        # Завершать обработку на закрывающей скобке
        while op and op != ')' and op != None:
            current_priority = self.priorities.get(op, -999)
            if current_priority <= priority:
                break
            self.consume()
            right = self.parse_xpr(current_priority)
            left = (op, left, right)
            op = self.peek()
        return left

print(Parser_02("3 + ( 4 * 5 ) - 6").parse_xpr())  # v 0.2
print(Parser_02("( ( 3 + 4 ) * 5 ) ** 6").parse_xpr())  # v 0.2

# ВЕРСИЯ 0.3
class Parser_03(BasicParser):
  def parse_xpr(self, priority=-999):
      left = self.consume()
      if left == '(':
          left = self.parse_xpr()
          assert self.consume() == ')'

      while (op := self.peek()) not in [None, ')']:
          # Обработка постфиксных операторов
          if op in self.postfix:
              self.consume()
              left = (op, left, None)
              continue

          current_priority = self.priorities.get(op, -999)
          if current_priority <= priority:
              break
          self.consume()
          right = self.parse_xpr(current_priority)
          left = (op, left, right)

      return left


print(Parser_03("3 * ( 4 ! + 5 )").parse_xpr())  # v 0.3

# ВЕРСИЯ 0.4
class Parser_04(BasicParser):
  def parse_xpr(self, priority=-999):
      left = self.consume()

      if left in self.prefix:
        right = self.parse_xpr(self.priorities.get(left, -999))
        left = (left, None, right)
      elif left == '(':
          left = self.parse_xpr()
          assert self.consume() == ')'



      while (op := self.peek()) not in (')', None):
        # Обработка постфиксных операторов
          if op in self.postfix:
              self.consume()
              left = (op, left, None)
              continue
          op_priority = self.priorities.get(op, -999)
          if op_priority <= priority:
              return left
          self.consume()
          right = self.parse_xpr(op_priority)
          left = (op, left, right)
      return left

print(Parser_04("-- 3 * ++ ( 4 ! + 5 )").parse_xpr())  # v 0.4