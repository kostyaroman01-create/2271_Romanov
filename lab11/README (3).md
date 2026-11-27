<img width="946" height="253" alt="image" src="https://github.com/user-attachments/assets/ad4b6419-288a-4eb4-96e1-998913a7de86" /># Языки программирования
## Лабораторная работа 11

### Задание 1 **(2)**

*Что надо дописать в приведенный пример программы, чтобы она транслировалась без ошибок?
Существующий код нельзя изменять или переставлять.*

```
int foo(int x) {
    return bar(x);
}
int bar(int x) {
    return x+1;
}
int main() {
    foo(0);
    return 0;
}
```
<img width="693" height="175" alt="image" src="https://github.com/user-attachments/assets/23dd2562-77b1-4336-addd-419c238c1745" />

```
int bar(int x); 

int foo(int x) {
    return bar(x);
}
int bar(int x) {
    return x+1;
}
int main() {
    foo(0);
    return 0;
}
```
<img width="946" height="253" alt="image" src="https://github.com/user-attachments/assets/220d8109-e159-4838-854b-4089bb11c7ac" />

### Задание 2 **(1)**

*Функция* **dswap** *должна была обменивать значения своих параметров.* 
*(На выводе должно было получиться* ```3.4 1.5```.)
*В чем ошибка при написании этой функции? Как ее исправить? 
Что передавалось в параметры у исходной функции и у исправленной?* 
```
#include <iostream>
void dswap(double x, double y) {
   double t = x;
   x = y;
   y = t;
}
int main(void) {
   double x = 1.5, y = 3.4;
   dswap(x, y);
   std::cout << x << " " << y << std::endl;
   return 0;
}
```
<img width="428" height="106" alt="image" src="https://github.com/user-attachments/assets/882c4f1c-bac3-4575-a053-3ceb15871a67" />

* ошибка в этой функции в том программа создает копии их, а не сами значения, поэтому нужен & адрес который изменит значения
```
#include <iostream>
#include <vector>

void dswap(double& x, double& y) {
	double t = x;
	x = y;
	y = t;
}
int main(void) {
	double x = 1.5, y = 3.4;
	dswap(x, y);
	std::cout << x << " " << y << std::endl;
	return 0;
}
```
<img width="366" height="102" alt="image" src="https://github.com/user-attachments/assets/73e4d5dc-96b2-4620-9569-1fa65ff161d5" />
* у первой передавались копии значения, но несохранялись
* у второй значения изменялись и сохранялись в оригинале, из-за адреса
### Задание 3 **(3)**

*Известно, что функция* **dosome** *не изменяет значений вектора* **V**.
*Какие из способов объявления функции является правильным с точки зрения 
корректности работы программы? В чем разница между этими способами?*



```
void dosome_1(const std::vector<int> &V);
void dosome_2(std::vector<int> &V);
void dosome_3(const std::vector<int> V);
void dosome_4(std::vector<int> V);
```
*Напишите примеры для этих функций. В качестве примера можно взять нахождение суммы всех элементов
вектора.*

*Выведите адрес нулевого элемента вектора в функции. Объясните результат.*

*Проверьте в какие из этих функций можно передать константные вектора. Объясните результат.*
```
dosome({1, 2, 3});
```
```
#include <iostream>
#include <vector>

void dosome_1(const std::vector<int> &V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    V[0] = -1;
    std::cout << "sum = " << s << std::endl;
}

void dosome_2(std::vector<int> &V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    V[0] = -1;
    std::cout << "sum = " << s << std::endl;
}

void dosome_3(const std::vector<int> V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    V[0] = -1;
    std::cout << "sum = " << s << std::endl;
}

void dosome_4(std::vector<int> V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    V[0] = -1;
    std::cout << "sum = " << s << std::endl;
}

int main(){
    std::vector<int> V = {1,2,3,4,5};
    dosome_1(V);
    dosome_2(V);
    dosome_3(V);
    dosome_4(V);

    return 0;
}
```
```
#include <iostream>
#include <vector>

void dosome_1(const std::vector<int> &V){
 int s = 0;
 for(auto x:V){
 s+=x;
 }
 V[0] = -1;
 std::cout << "sum = " << s << std::endl;
}

void dosome_2(std::vector<int> &V){
 int s = 0;
 for(auto x:V){
 s+=x;
 }
 V[0] = -1;
 std::cout << "sum = " << s << std::endl;
}

void dosome_3(const std::vector<int> V){
 int s = 0;
 for(auto x:V){
 s+=x;
 }
 V[0] = -1; 
 std::cout << "sum = " << s << std::endl;
}

void dosome_4(std::vector<int> V){
 int s = 0;
 for(auto x:V){
 s+=x;
 }
 V[0] = -1;
 std::cout << "sum = " << s << std::endl;
}

int main(){
 std::vector<int> V = {1,2,3,4,5};
 dosome_1(V);
 dosome_2(V);
 dosome_3(V);
 dosome_4(V);

 return 0;
}
```
```
#include <iostream>
#include <vector>

void dosome_1(const std::vector<int> &V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    std::cout << "sum = " << s << std::endl;
}

void dosome_2(std::vector<int> &V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    V[0] = -1;
    std::cout << "sum = " << s << std::endl;
}

void dosome_3(const std::vector<int> V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    std::cout << "sum = " << s << std::endl;
}

void dosome_4(std::vector<int> V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    V[0] = -1;
    std::cout << "sum = " << s << std::endl;
}

int main(){
    std::vector<int> V = {1,2,3,4,5};
    dosome_1(V);
    dosome_2(V);
    dosome_3(V);
    dosome_4(V);

    return 0;
}
```
```
#include <iostream>
#include <vector>

void dosome_1(const std::vector<int> &V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    std::cout << "sum = " << s << std::endl;
}

void dosome_2(std::vector<int> &V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    V[0] = -1;
    std::cout << "sum = " << s << std::endl;
}

void dosome_3(const std::vector<int> V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    std::cout << "sum = " << s << std::endl;
}

void dosome_4(std::vector<int> V){
    int s = 0;
    for(auto x:V){
        s+=x;
    }
    V[0] = -1;
    std::cout << "sum = " << s << std::endl;
}

int main(){
    std::vector<int> V = {1,2,3,4,5};
    dosome_1(V);
    dosome_2(V);
    dosome_3(V);
    dosome_4(V);

    dosome_1({1, 2, 3});
    dosome_2({1, 2, 3});
    dosome_3({1, 2, 3});
    dosome_4({1, 2, 3});

    return 0;
}
```
* Самый правильный вариант — первый. Он передается по ссылке и защищен от изменений
### Задание 4 **(2)**

*Напишите программу в которой будет создаваться восемь массивов из 128 целых чисел четырьмя способами,
каждым способом по два массива.
Первые два массива должны быть глобальными, вторые — локальными статическими, третьи — локальными на стеке,
четвертые — локальными в куче. Выведите адреса первого и последнего элемента в каждом массиве.
Сравните, насколько далеко они располагаются друг от друга. Какие выводы можно из этого сделать.*

*В отчет запишите программу и скриншот ее работы.*
```
#include <iostream>

int G1[128] = {0}, G2[128] = {0};

void foo(){
    static int s1[128] = {0}, s2[128] = {0};
    int L1[128] = {0}, L2[128] = {0};
    int *H1 = new int[128];
    int *H2 = new int[128];
    std::cout << "Global   " << &G1[0] << ' ' << &G1[127] << ' ' << &G2[0] << ' ' << &G2[127] << std::endl;
    std::cout << "Static   " << &s1[0] << ' ' << &s1[127] << ' ' << &s2[0] << ' ' << &s2[127] << std::endl;
    std::cout << "Local   " << &L1[0] << ' ' << &L1[127] << ' ' << &L2[0] << ' ' << &L2[127] << std::endl;
    std::cout << "Heap   " << &H1[0] << ' ' << &H1[127] << ' ' << &H2[0] << ' ' << &H2[127] << std::endl;
}

int main(){
    foo();
    return 0;
}
```
<img width="835" height="191" alt="image" src="https://github.com/user-attachments/assets/3d55c046-b824-49d2-97bc-1fa2069fae45" />

* Глобальные и статические переменные хранятся в статической памяти, локальные — в стеке, а динамические — в куче.
```
#include <iostream>

int G1[128] = {0}, G2[128] = {0};

void foo(){
    static int s1[128] = {0}, s2[128] = {0};
    int L1[128] = {0}, L2[128] = {0};
    int *H1 = new int[128];
    int *H2 = new int[128];
    std::cout << "Global   " << &G1[0] << ' ' << &G1[127] << ' ' << &G2[0] << ' ' << &G2[127] << std::endl;
    std::cout << "Static   " << &s1[0] << ' ' << &s1[127] << ' ' << &s2[0] << ' ' << &s2[127] << std::endl;
    std::cout << "Local   " << &L1[0] << ' ' << &L1[127] << ' ' << &L2[0] << ' ' << &L2[127] << std::endl;
    std::cout << "Heap   " << &H1[0] << ' ' << &H1[127] << ' ' << &H2[0] << ' ' << &H2[127] << std::endl;
    G1[0]++;
    s1[0]++;
    H1[0]++;
    L1[0]++;
    std::cout << G1[0] << ' ' << s1[0] << ' ' << H1[0] << ' ' << L1[0] << std::endl;
}

int main(){
    foo();
    foo();
    foo();
    return 0;
}
```
<img width="822" height="449" alt="image" src="https://github.com/user-attachments/assets/9a3b95e5-4998-49b2-962d-ab0def222c95" />


* Глобальные и статические создаются один раз вначале программы, динамические массивы в куче, а локальные в стеке.

```
#include <iostream>

int G1[128] = {0}, G2[128] = {0};

void foo(){
    static int s1[128] = {0}, s2[128] = {0};
    int L1[128] = {0}, L2[128] = {0};
    int *H1 = new int[128];
    int *H2 = new int[128];
    std::cout << "Global   " << &G1[0] << ' ' << &G1[127] << ' ' << &G2[0] << ' ' << &G2[127] << std::endl;
    std::cout << "Static   " << &s1[0] << ' ' << &s1[127] << ' ' << &s2[0] << ' ' << &s2[127] << std::endl;
    std::cout << "Local   " << &L1[0] << ' ' << &L1[127] << ' ' << &L2[0] << ' ' << &L2[127] << std::endl;
    std::cout << "Heap   " << &H1[0] << ' ' << &H1[127] << ' ' << &H2[0] << ' ' << &H2[127] << std::endl;
    G1[0]++;
    s1[0]++;
    H1[0]++;
    L1[0]++;
    std::cout << G1[0] << ' ' << s1[0] << ' ' << H1[0] << ' ' << L1[0] << std::endl;
    delete[] H1;
    delete[] H2;
}

void bar(){
    foo();
}

int main(){
    foo();
    bar();
    bar();
    return 0;
}
```

```
#include <iostream>

int G1[128] = {0}, G2[128] = {0};
int *H1, *H2;

void foo(){
    static int s1[128] = {0}, s2[128] = {0};
    int L1[128] = {0}, L2[128] = {0};
    H1 = new int[128];
    H2 = new int[128];
    std::cout << "Global   " << &G1[0] << ' ' << &G1[127] << ' ' << &G2[0] << ' ' << &G2[127] << std::endl;
    std::cout << "Static   " << &s1[0] << ' ' << &s1[127] << ' ' << &s2[0] << ' ' << &s2[127] << std::endl;
    std::cout << "Local   " << &L1[0] << ' ' << &L1[127] << ' ' << &L2[0] << ' ' << &L2[127] << std::endl;
    std::cout << "Heap   " << &H1[0] << ' ' << &H1[127] << ' ' << &H2[0] << ' ' << &H2[127] << std::endl;
    G1[0]++;
    s1[0]++;
    H1[0]++;
    L1[0]++;
    std::cout << G1[0] << ' ' << s1[0] << ' ' << H1[0] << ' ' << L1[0] << std::endl;
}

void bar(){
    foo();
}

int main(){
    foo();
    bar();
    foo();
    std::cout << H1[0];
    delete[] H1;
    delete[] H2;
    return 0;
}
```
### Задание 5 **(2)**

*Приведенная ниже программа вызывает ошибку. Почему?*

*Что будет, если перенести объявление массива выше функции* **foo**?

*Что будет, если объявить массив с использованием ключевого слова* **static**?

*Что будет, если создать массив такого же размера с использованием* **new**?
```
#include <iostream>
int foo() {
    int x[100010001];
    return x[100010000];
}
int main() {
    std::cout << foo();
    return 0;
}
```
* вызовет ошибку переполнения, потому что в функции размер от 1мб - 8мб а массив занимает 400мб
* масив станет глобальной переменной
* массив также будет храниться в статической области, а не в стеке, поэтому переполнение стека не произойдёт. Статические локальные переменные имеют время жизни до завершения программы, инициализируются только при первом входе в функцию, и при последующих вызовах сохраняют предыдущее значение.
* программа не упадет если в компьютере есть достаточно памяти
### Задание 6 **(3)**

*Запишите следующую программу. Выполните ее трансляцию с нулевым оровнем оптимизации.
Нарисуйте схематично расположение переменных в памяти в момент вызова при \verb*|a=0|. 
Отметьте кадры стека.*

```
#include <iostream>
long long foo(long long a, long long b) {
   if (a == 0) 
      return 0;
   else {
      long long x, y;
      std::cout << "Enter a=" << a << ", b=" << b << std::endl;
      std::cout << "Ptrs " << &a << ' ' << &b <<' '<< &x<<' '<<&y << std::endl;
      x = a * b;
      y = foo(a - 1, b + 1);
      return x + y;
   }
}
int main() {
   foo(5, 5);
   return 0;
}
```
<img width="727" height="362" alt="image" src="https://github.com/user-attachments/assets/634b8914-604b-4ce7-a6c0-e07123e6fc4a" />

Адреса растут сверху вниз (стек растёт вниз)

Высокие адреса
┌─────────────────────────────────────┐
│  main:                              │
│    возвращаемый адрес, ...          │
├─────────────────────────────────────┤  ← кадр foo(5,5)
│  foo(a=5, b=5):                     │
│    b = 5                            │
│    a = 5                            │
│    x (не инициализировано)          │
│    y (не инициализировано)          │
│    адрес возврата, сохранённый rbp  │
├─────────────────────────────────────┤  ← кадр foo(4,6)
│  foo(a=4, b=6):                     │
│    b = 6                            │
│    a = 4                            │
│    x, y                             │
│    адрес возврата, сохранённый rbp  │
├─────────────────────────────────────┤  ← кадр foo(3,7)
│  foo(a=3, b=7):                     │
│    b = 7                            │
│    a = 3                            │
│    x, y                             │
│    адрес возврата, сохранённый rbp  │
├─────────────────────────────────────┤  ← кадр foo(2,8)
│  foo(a=2, b=8):                     │
│    b = 8                            │
│    a = 2                            │
│    x, y                             │
│    адрес возврата, сохранённый rbp  │
├─────────────────────────────────────┤  ← кадр foo(1,9)
│  foo(a=1, b=9):                     │
│    b = 9                            │
│    a = 1                            │
│    x, y                             │
│    адрес возврата, сохранённый rbp  │
├─────────────────────────────────────┤  ← кадр foo(0,10)  ← ВЕРШИНА СТЕКА
│  foo(a=0, b=10):                    │
│    b = 10                           │
│    a = 0                            │
│    x, y                             │
│    адрес возврата, сохранённый rbp  │
├─────────────────────────────────────┤  ← rsp (указатель стека)
Низкие адреса
### Задание 7 **(3)**

*Рассмотрите следующую программу. Выполните ее трансляцию, используя  компилятор g++ без
оптимизации (уровень оптимизации 0). Объясните ее работу.*
```
#include <iostream>
double &choose(double &a, bool flg) {
    double pi = 3.14;
    double &r = flg ? pi : a;
    return r;
}

int main(void)
{
    double a = 2.7;
    double &pi = choose(a, true);
    std::cout << pi << std::endl;
    double &e = choose(a, false);
    std::cout << e << std::endl;
    std::cout << pi << std::endl;
    return 0;
}
```
<img width="575" height="248" alt="image" src="https://github.com/user-attachments/assets/75d0d935-8152-4ab7-873b-fde098d4dc63" />
Вызов 1: choose(a, true)
В кадре choose создаётся локальная pi = 3.14.

r ссылается на эту локальную pi.

Функция возвращает ссылку на уже уничтоженную локальную переменную.

В main: double &pi = choose(a, true); — pi ссылается на мёртвую область стека.

Строка (1) std::cout << pi читает память по этому «мёртвому» адресу. При -O0 эта память скорее всего ещё не перезаписана (функция только что вышла, стек не успел измениться), поэтому вы, вероятно, увидите 3.14. Но это случайность, а не гарантия — поведение не определено.

Вызов 2: choose(a, false)
r ссылается на a (переменную из main).

Возвращается корректная ссылка на a.

e ссылается на a, значение a = 2.7.

Строка (2) std::cout << e выведет 2.7 — это корректно.

Строка (3): снова std::cout << pi
pi по-прежнему ссылается на «мёртвую» область стека, которая могла быть перезаписана вторым вызовом choose (он использовал тот же участок стека под свои локальные переменные, в т.ч. под свою pi = 3.14). Поэтому здесь возможны варианты:

снова 3.14 (если память не изменилась),

другое значение (если второй вызов записал туда что-то иное),

вплоть до мусора.

Именно поэтому поведение программы непредсказуемо и зависит от компилятора, уровня оптимизации и состояния стека.
### Задание 8 **(3)**

*Объясните работу приведенной ниже программы.
Какие ошибки в ней имеются? (Виды ошибок смотрите в лекции.)*
```
#include <iostream>
int main() {
    int *p = new int [10];
    int *q = new int [10];
    for (int i = 0; i <= 10; i++)
        p[i] = i;
    q = p;
    delete[] p;
    for (int i = 0; i <= 10; i++)
        std::cout << q[i] <<" ";
    delete[] q;
    return 0;
}
```
Что программа делает по шагам
int *p = new int[10]; — выделяет в куче массив из 10 int (индексы 0..9).

int *q = new int[10]; — выделяет второй массив из 10 int.

Цикл for (int i = 0; i <= 10; i++) p[i] = i; — заполняет p[0..10] значениями 0..10.

q = p; — указатель q теперь указывает на тот же массив, что и p. Второй массив, выделенный на шаге 2, потерян (утечка памяти).

delete[] p; — освобождает массив, на который указывает p (и q, т.к. они теперь равны).

Цикл for (int i = 0; i <= 10; i++) std::cout << q[i] << " "; — читает q[0..10], но массив уже освобождён → обращение к освобождённой памяти (use-after-free). Кроме того, q[10] — выход за границы массива (индексы 0..9).

delete[] q; — повторное освобождение той же памяти (double free), т.к. q == p, а p уже был освобождён на шаге 5.
1. Выход за границы массива (out-of-bounds)
2. Утечка памяти (memory leak)
3. Обращение к освобождённой памяти (use-after-free)
4. Повторное освобождение (double free)
5. (Связанная проблема) «Висячие» указатели после delete[]

## Дополнительные задания

### Задание 1 **(2)**

*В чем ошибка данного примера? Будет ли он работать при замене типа* **double** на **int**
*в функции bar?*
```
#include <iostream>
int foo(int x) {return x+1;}
double bar(double x) {return x-1;}
int main () {
    decltype(foo) *pf;
    pf = bar;
    std::cout << pf(0);
    return 0;
}

```

### Задание 2 **(10)**

*С использованием стандартных функций сортировки напишите на Java, C++ и Python программу
для сортировки вещественных чисел по возрастанию целой части числа и убыванию дробной.
Например, правильный порядок чисел после сортировки будет выглядеть так:*
```1.9; 1.32; 1.0; 5.8; 5.1; 12.6; 13.2; 13.1.``` 

*При реализации требуется использовать лямбда-функции.*

### Задание 3 **(4)**
*Напишите фрагмент программы вместо многоточия, 
в котором в начало массива* **data** *будет вставляться новый элемент* **t**. *Существующие
элементы при этом должны сместиться назад. Другие исправления вносить нельзя.
Для этого потребуется выделить новый участок памяти и перенести в него все элементы.*
```
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    *data = new int [n];
    for (int i=0; i<n; i++)
        std::cin >> data[i];
     int t;
     std::cin >> t;
     ...
     for (int i=0;i<n+1;i++)
         std::cout << data[i] <<' '; 
     return 0;
}
```

### Задание 4 **(4)**
*Напишите программу, которая создаст в памяти треугольник Паскаля размера* **n**.
*Размер должен вводиться во время работы программы. 
В программе не должна выделяться память для несуществующих элементов. В программе требуется использовать 
массив указателей.* 

