# SquareSolver
Данная программа решает квадратное уравнение.
## Как работает программа
В начале вас спросят хотите ли вы протестировать программу. Если да, то она протестируется, если нет пойдёт дальше.\
![](https://github.com/OFFlinea/SquareSolver/blob/main/pictures/test.png)\
Затем попросит ввести вас _коэффициенты_ квадратного уравнения, после ввода вам выведутся *корни* уравнения.\
![](https://github.com/OFFlinea/SquareSolver/blob/main/pictures/solver.png)
## Первый запуск
Открываете командную строку (win + r -> cmd) и вводите следующее:\
cd _Путь к папке с файлами_ (Пример: cd C:\CodeBlocks\SquareSolver)\
make\
Теперь можете запускать файл Square.exe из вашей папки или создать ярлык и запускать с рабочего стола\
## Неправильный ввод
Программа не заработает, пока вы не введёте корректные данные.\
_Примеры неправильного ввода_:\
![](https://github.com/OFFlinea/SquareSolver/blob/main/pictures/input.PNG)
## Главная функция программы
```
int main() {

    introduction();
    test_question();

    struct Roots roots = {};
    struct SquareTrinomial coeffs = {};

    square_input(&coeffs);
    square_solver(&coeffs, &roots);
    square_print(&roots);

    return 0;
}
```
