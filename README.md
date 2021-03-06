# Лабораторная работа 5

    Имя функции и тип возвращаемого значения должны соответствовать примерам.
    Примеры к заданиям являются только иллюстрацией и не всегда являются рабочим кодом.

    Если какой-то из аргументов вам нужно изменить в функции, или передаваемое значение
    имеет большой размер, не забывайте передавать его по ссылке. 

    Не забывайте добавлять const к аргументу, если не собираетесь его изменять в функции.
    Иначе при тестировании может возникать ошибка такого плана:
    error: binding reference of type ‘Point&’ to ‘const Point’ discards qualifiers

```
Предположим, что вы хотите отправить решение к задаче а1.
Для этого вам нужно открыть папку solutions, найти файл, который называется a1.h,
и вставить туда ваше решение.
 
#pragma once удалять не надо!
```
```
Нажав на крестик вы сможете увидеть какие тесты ваша программа прошла, а какие нет.
```
![img_2.png](images/img_2.png)![img.png](images/img.png)

### Сложность A
        (1 балл за задание)
Задания части А, связанные с перегрузкой операторов матрицы, необходимо выполнять в порядке их следования в лабораторной, т.к. 
в последующих заданиях предполагается наличие методов из предыдущих.
Старайтесь использовать уже написанные методы и операторы при реализации новых 
(например, оператор <code>+</code> можно реализовать через оператор <code>+=</code> и наоборот).
Матрица должна хранить целые числа.
Также в таких заданиях запрещено использовать массивы из стандартной библиотеки <code>std::vector, std::deque, std::array и т.д.</code>
<ol>

<li>
Данным заданием мы начнём описывать класс матрицы <code>Matrix</code>. 
Вам необходимо реализовать:
<ul>
<li>Конструктор по умолчанию, т.е не принимающий аргументов. Должен создавать матрицу нулевого размера. </li>
<li>Конструктор принимающий размеры матрицы <code>size_t height, size_t width</code>. Должен создавать матрицу указанного размера
и заполнять её нулями. </li>
<li>Константные методы <code>GetHeight()</code> и <code>GetWidth()</code> возвращающие высоту и ширину матрицы соответственно.</li>
<li>Оператор <code><<</code> позволяющий выводить матрицу в поток.
Например, матрицу <code>{{1, 2}, {3, 4}}</code> оператор должен вывести в поток в виде <code>1 2\n3 4</code></li>

<li>Деструктор.</li>
</ul>

```c++
Matrix empty;
cout << empty.GetWidth(); // 0
cout << empty.GetHeight(); // 0

Matrix zeroes(2, 2);
cout << zeroes.GetWidth() << " " << zeroes.GetHeight(); // 2 2
```

</li>

<li>
Продолжим описывать класс матрицы. Реализуйте:
<ul>
<li>Конструктор копирования. Должен создать матрицу равную матрице переданной в качестве аргумента.</li>
<li>Оператор <code>>></code> позволяющий вводить матрицу из потока. Оператор сначала должен запросить 
размеры матрицы (сначала высоту, потом ширину), а потом её элементы.</li>
<li>Оператор <code>==</code>. Должен возвращать <code>true</code>, если матрицы равны и <code>false</code>, если матрицы не равны.</li>
<li>Оператор присваивания <code>=</code>.
Должен копировать матрицу аргумент в текущий объект. Оператор присваивания должен
возвращать объект по ссылке, чтобы иметь возможность написать <code>a = b = c = d</code>.

<a href="https://ru.wikipedia.org/wiki/%D0%9E%D0%BF%D0%B5%D1%80%D0%B0%D1%86%D0%B8%D1%8F_%D0%BF%D1%80%D0%B8%D1%81%D0%B2%D0%B0%D0%B8%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F_%D0%B2_%D0%A1%2B%2B">Операция присваивания в С++</a>:

    Операция присваивания копированием отличается от конструктора копирования тем, что должна очищать члены-данные цели
    присваивания (и правильно обрабатывать самоприсваивание), тогда как конструктор копирования присваивает значения 
    неинициализированным членам-данным. Например:

```c++
My_Array first;           // инициализация конструктором по умолчанию
My_Array second = first;  // инициализация конструктором копирования
second = first;           // присваивание операцией присваивания копированием
```
</li>
</ul>

```c++
Matrix matr(3,3);
cin >> matr;
cout << matr; // 1 2 3
              // 4 5 6
              // 7 8 9
Matrix matr1;
matr1 = matr;
cout << (matr1 == matr); // 1
```
</li>


<li>
Продолжим описывать класс матрицы. На этот раз реализуйте:

<ul>
<li>
Операторы <code>+=</code> и <code>-=</code> для выполнения операций сложения и вычитания матриц друг с другом. 
Матрицы складываются и вычитаются поэлементно. Операторы <code>+=</code> и <code>-=</code> для сложения и вычитания матрицы с числом и наоборот. 
Добавляя число к матрице оператор должен добавлять это число к каждому элементу матрицы.
</li>
<li>
Постфиксные и префиксные операторы <code>++</code> и <code>--</code>. Должны добавлять или отнимать 1 от каждого элемента матрицы. 
</li>
<li>Операторы <code>+</code> и <code>-</code> выполняющие соответствующие операции с двумя матрицами. 
Операторы должны возвращать новую матрицу полученную в результате выполнения операции над матрицами-аргументами.</li>
<li>Операторы <code>+</code> и <code>-</code> умеющие складывать матрицу с числом и наоборот.</li>
        
    Чтобы реализовать сложение числа с матрицей нужно написать отдельный дружественный оператор.
</ul>

```c++
Matrix matr(2, 2);
matr += 5;
matr+=matr;
--matr;
cout << matr; // 9 9
              // 9 9
Matrix matr2 = matr + matr;
cout << matr2; // 18 18
               // 18 18
cout << matr; // 9 9
              // 9 9
```

</li>

<li>
Продолжим описывать класс матрицы. А на этот раз реализуйте:
<ul>
<li>Оператор <code>*=</code> умножающий текущий объект матрицы на матрицу-аргумент. Умножение осуществляется по 
правилам умножения матриц. Если умножение невозможно, должно быть выброшено исключение 
<code>std::invalid_argument</code>.</li>
<li>Оператор <code>*</code> перемножающий две матрицы. 
Оператор должен возвращать новую матрицу полученную в результате выполнения операции над матрицами-аргументами. Умножение осуществляется по 
правилам умножения матриц. Если умножение невозможно, должно быть выброшено исключение 
std::invalid_argument.</li>
<li>Оператор <code>[]</code> позволяющий обратиться к элементу матрицы по индексу. Например, <code>my_matr[2][3]</code>. 
Реализуйте этот оператор двумя способами: первый должен позволять изменять полученный элемент матрицы, а второй нет.</code>.
</li>
</ul>

```c++
Matrix matr;
cin >> matr;
cout << matr; // 1 2 3
              // 4 5 6
              // 7 8 9
cout << matr * matr; // 30 36 42
                     // 66 81 96
                     // 102 126 150
matr[2][2] = 42;
cout << matr[2][2]; // 42
```

</li>

<li>
Одним из этапов расшифровки текста зашифрованного методом простой подстановки является подсчёт частот, 
с которыми в нём встречается та или иная n-грамма (слово состоящее из n символов). 
Напишите функцию, которая возвращает <code>std::map</code>, в котором ключом является 3-грамма, а значением количество раз, с которым
она встретилось в тексте. Перед подсчётом частот удалите все разделители (любые символы не являющиеся частью английского алфавита), 
а также приведите текст к верхнему регистру.

```c++
GetFrequencies("aaa") -> {"AAA": 1}
GetFrequencies("aaabbb") -> {"AAA": 1, "AAB": 1, "ABB": 1, "BBB": 1}
GetFrequencies("aba!,. b.a") -> {"ABA": 2, "BAB": 1}
```

</li>


</ol>


### Бонусные задания сложности A
        (1 балл за задание)

<ol>

<li>
</li>

</ol>


### Сложность B
        (1.5 балла за задание)
<ol>

<li>
</li>

</ol>


### Бонусные задания сложности B
        (1.5 балла за задание)

<ol>

<li>
</li>

</ol>

### Сложность C
        (2 балла за задание)

<ol>
<li>
</li>
</ol>

### Бонусные задания сложности C
        (2 балла за задание)

<ol>
<li>
</li>
</ol>
