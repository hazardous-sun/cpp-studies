#include <iostream>
#include <cmath>

/*
This project was made to study C++.

References used:
 Bro Code's YouTube video: https://www.youtube.com/watch?v=-TkoO8Z07hI
 Geeks for Geeks "Destructors in C++": https://www.geeksforgeeks.org/destructors-c/
*/

// 3. Namespaces
/*
namespace first{
    int x = 1;
}
namespace second{
    int x = 2;
}
*/

// 4. Typedef
/*
#include <vector>
// typedef std::vector<std::pair<std::string, int>> pairlist_t;
//typedef std::string text_t;
//typedef int number_t;
using text_t = std::string;  // will have the same effect as typedef
using number_t = int;
*/

// 14. User defined functions
/*
double bhaskara(double a, double b, double c, char operation) {
    double delta = pow(b, 2) - 4 * a * c;
    if (delta <= 0) {
        return 0;
    }
    else {
        switch (operation) {
            case '+':
                return (-b + sqrt(delta)) / (2 * a);
            case '-':
                return (-b - sqrt(delta)) / (2 * a);
            default:
                return 0;
        }
    }
}
*/

// 15. Overloaded functions
/*
void bake_pizza() {
    std::cout << "Here is your pizza!" << std::endl;
}
void bake_pizza(std::string topping) {
    std::cout << "Here is your " << topping << " pizza!" << std::endl;
}
void bake_pizza(std::string topping1, std::string topping2) {
    std::cout << "Here is your " << topping1 << " and " << topping2 << " pizza!" << std::endl;
}
*/

// 20. Pass array to a function
/*
double get_total(const double numbers[], int size) {
    double numbers_sum = 0;
    for (int i = 0; i < size; i ++) {
        numbers_sum += numbers[i];
    }
    return numbers_sum;
}
*/

// 21. Search an array for an element
/*
int search_int_array(int array[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;  // Returns -1 if the number can't be found
}

int search_string_array(std::string array[], int size, std::string element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;  // Returns -1 if the number can't be found
}
*/

// 22. Sort an array
/*
void sort(int array[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}
*/

// 27. Pass by VALUE vs pass by REFERENCE
/*

void swap(std::string &x, std::string &y) {
    std::cout << "before swap &x: " << &x << std::endl;
    std::cout << "before swap &y: " << &y << std::endl;
    std::string temp = x;
    x = y;
    y = temp;
    std::cout << "after swap &x: " << &x << std::endl;
    std::cout << "after swap &y: " << &y << std::endl;
}
*/

// 28. Const parameter
/*
void print_info(const std::string &name, const int &age) {
    name = " ";  // will raise errors because a const value can't be modified
    age = 0;  // will raise errors because a const value can't be modified
    std::cout << name << std::endl;
    std::cout << age << std::endl;
}
*/

// 29. Credit card validator program
/*
int get_digit(const int NUMBER) {
    return NUMBER % 10 + (NUMBER / 10 % 10);
}

int sum_odd_digits(const std::string CARD_NUMBER) {
    int sum = 0;

    for (int i = CARD_NUMBER.size() - 1; i >= 0; i -= 2) {
        sum += get_digit(CARD_NUMBER[i] - 0);
    }

    return sum;
}

int sum_even_digits(const std::string CARD_NUMBER) {
    int sum = 0;

    for (int i = CARD_NUMBER.size() - 2; i >= 0; i -= 2) {
        sum += get_digit((CARD_NUMBER[i] - 0) * 2);
    }

    return sum;
}
*/

// 32. Tic-tac-toe game
/*
void draw_board(char *spaces) {
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << std::endl;
    std::cout << "     |     |     " << std::endl;
}

void player_move(char *spaces, char player) {
    int number = 0;
    do {
        std::cout << "Enter a spot to place a marker (1 - 9)";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while (!number > 0 || !number < 8);
}

void computer_move(char *spaces, char computer) {
    int number;
    srand(time(NULL));

    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool check_winner(char *spaces, char player) {
    if ((spaces[0] != ' ') && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
        spaces[0] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((spaces[3] != ' ') && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
        spaces[3] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((spaces[6] != ' ') && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        spaces[6] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((spaces[0] != ' ') && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        spaces[0] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((spaces[2] != ' ') && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
        spaces[2] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((spaces[0] != ' ') && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        spaces[0] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((spaces[1] != ' ') && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
        spaces[1] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else if ((spaces[2] != ' ') && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
        spaces[2] == player ? std::cout << "YOU WIN!" : std::cout << "YOU LOSE!";
    }
    else {
        return false;
    }
    return true;
}

bool check_tie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "IT'S A TIE!";
    return true;
}
*/

// 34. Recursion
/*
void iterative_walk(int steps) {
    for (int i = 0; i < steps; i++) {
        std::cout << "You take a step!" << std::endl;
    }
}

void recursive_walk(int steps) {
    if (steps > 0) {
        std::cout << "You take a step!" << std::endl;
        recursive_walk(steps - 1);
    }
}

int iterative_factorial(int number) {
    int result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

int recursive_factorial(int number) {
    if (number > 0) {
        return number * recursive_factorial(number - 1);
    }
    return 1;
}
*/

// 35. Function templates
/*
template <typename T, typename U>
auto max(T x, U y) {
    return (x > y) ? x : y;
}
*/

// 36. Structs
/*
struct student{
    std::string name;
    double gpa;
    bool enrolled = true;  // if enrolled is not defined, it'll be true
};
*/

// 37. Pass structs as arguments
/*
struct Car {
    std::string model;
    int year = 0;
    std:: string color;
};

void print_car(const Car& car) {
    std::cout << car.model << ' ' << car.year << ' ' << car.color << std::endl;
}

void paint_car(Car& car) {
    std::string new_color;
    std::cout << "New color for the " << car.model << ' ' << car.year << ' ' << car.color << ": ";
    std::getline(std::cin, new_color);
    car.color = new_color;
}
*/

// 38. Enums
/*
enum Day {
    sunday = 0, monday = 1, tuesday = 2, wednesday = 3, thursday = 4, friday = 5, saturday = 6
};

enum Flavor {
    vanilla, chocolate, strawberry, mint
};

enum Color {
    red, orange, yellow, green, blue, purple
};
*/

// 39. Object Oriented Programming
/*
class Human {
public:
    std::string name;
    std::string occupation;
    int age;

    void eat() {
        std::cout << "This person is eating" << std::endl;
    }

    void drink() {
        std::cout << "This person is drinking" << std::endl;
    }

    void sleep() {
        std::cout << "This person is sleeping" << std::endl;
    }

    void change_id(int number) {
        id = number;
    }

    void display_info() {
        std::cout << name << ' ' << age << ' ' << occupation << ' ' << id;
    }

private:
    int id;
};
*/

// 40. Constructor
/*
class Student {
public:
    std::string name;
    int age;
    double gpa;

    Student(std::string name, int age, double gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
};
*/

// 41. Constructor overloading
/*
class Pizza {
public:
    std::string topping1;
    std::string topping2;

    Pizza() {}

    Pizza(std::string topping1) {
        this->topping1 = topping1;
    }

    Pizza(std::string topping1, std::string topping2) {
        this->topping1 = topping1;
        this->topping2 = topping2;
    }

    void list_toppings() {
        if (!topping1.empty()) {
            std::cout << topping1 << std::endl;
            if (!topping2.empty()) {
                std::cout << topping2 << std::endl;
            }
        } else {
            std::cout << "This pizza has no toppings!" << std::endl;
        }
    }
};
 */

// 42. Getters & setters
/*
class Stove {
private:
    int temperature;
public:

    Stove(int temperature) {
        set_temperature(temperature);
    }

    int get_temperature() {
        return temperature;
    }
    void set_temperature(int temperature) {
        if (temperature < 0) {
            this->temperature = 0;
        } else if (temperature > 10) {
            this->temperature = 10;
        } else {
            this->temperature = temperature;
        }
    }
};
*/

// 43. Inheritance
/*
class Animal {
public:
    bool alive = true;

    void eat() {
        std::cout << "This animal is eating." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "The dog goes woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        std::cout << "The cat goes meow!" << std::endl;
    }
};

class Shape {
public:
    double area;
    double volume;
};

class Cube : public Shape {
public:
    double side;

    Cube(double side) {
        this->side = side;
        this->area = side * side * 6;
        this->volume = side * side * side;
    }
};

class Sphere : public Shape {
public:
    double radius;

    Sphere(double radius) {
        this->radius = radius;
        this->area = 4 * 3.14159 * (radius * radius);
        this->volume = (4 / 3.0) * 3.14159 * (radius * radius * radius);
    }
};
*/

// 44. Destructors
/*
int count = 0;

class DestroyableClass {
public:
    DestroyableClass() {
        count++;
        std::cout << "The constructor was called!" << std::endl;
        std::cout << "count = " << count << std::endl;
    }

    ~DestroyableClass() {
        count--;
        std::cout << "The destructor was called!" << std::endl;
        std::cout << "count = " << count << std::endl;
    }
};
*/

int main() {

    // Index:
    /*
     * 1. Variables and basic data types:
     * 2. Constants
     * 3. Namespaces
     * 4. Typedef
     * 5. Type conversion
     * 6. User input
     * 7. Useful math related functions
     * 8. Hypotenuse of a right-angled triangle
     * 9. Switches
     * 10. Ternary operator
     * 11. Useful string methods
     * 12. Random numbers
     * 13. Random event generator
     * 14. User defined functions
     * 15. Overloaded functions
     * 16. Arrays
     * 17. Sizeof() operator
     * 18. Iterate over an array
     * 19. Foreach loop
     * 20. Pass array to a function
     * 21. Search an array for an element
     * 22. Sort an array
     * 23. Fill() function
     * 24. Fill an array with user input
     * 25. Multidimensional arrays
     * 26. Memory addresses
     * 27. Pass by VALUE vs pass by REFERENCE
     * 28. Const parameter
     * 29. Credit card validator program
     * 30. Pointers
     * 31. Null pointers
     * 32. Tic-tac-toe game
     * 33. Dynamic memory
     * 34. Recursion
     * 35. Function templates
     * 36. Structs
     * 37. Pass structs as arguments
     * 38. Enums
     * 39. Object-oriented Programming
     * 40. Constructor
     * 41. Constructor overloading
     * 42. Getters & setters
     * 43. Inheritance
     * 44. Destructors
     */

    // 1. Variables and basic data types:
    /*
    // integer
    int age = 10;
    int y = 6;
    int sum = age + y;

    std::cout << age << std::endl;
    std::cout << y << std::endl;
    std::cout << sum << std::endl;

    // double
    double price = 10.99;
    double gpa = 2.5;
    double temperature = 25.1;

    std::cout << price << std::endl;
    std::cout << gpa << std::endl;
    std::cout << temperature << std::endl;

    // char
    char grade = 'A';
    char dollarSign = '$';
    char charNum = 127;  // max range of char

    std::cout << grade << std::endl;
    std::cout << dollarSign << std::endl;
    std::cout << charNum << std::endl;

    // boolean
    bool student = false;  // false == 0
    bool power = true;  // true == 1

    std::cout << student << std::endl;
    std::cout << power << std::endl;

    // string
    std::string name = "Bro";
    std::string day = "Friday";
    std::string food = "pizza";

    std::cout << name << std::endl;
    std::cout << day << std::endl;
    std::cout << food << std::endl;

    // display text with variables

    std::cout << "Hello " << name << '\n';
    std::cout << "false == 0) == " << (false == 0) << '\n';
    std::cout << "(true == 1) == " << (true == 1) << '\n';
    std::cout << "You are " << age << " years old." << '\n';
    */

    // 2. Constants
    /*
    const double PI = 3.14159;  // PI is a constant, therefore, can't be changed
    const int LIGHT_SPEED = 299792458;
    const int WIDTH = 1920;
    const int HEIGHT = 1080;

    std::cout << PI << std::endl;
    std::cout << LIGHT_SPEED << std::endl;
    std::cout << WIDTH << std::endl;
    std::cout << HEIGHT << std::endl;
    */

    // 3. Namespaces
    /*
    // Namespace = Provides a solution for preventing name conflicts in large projects. Each entity needs a unique name.
    //             A namespace allows for identically named entities as long as the namespaces are diffferent.

//    int x = 0;
//    std::cout << x << std::endl;  // Without specifying which "x" we're referring to, it'll output the static value, 0
//    std::cout << first::x << std::endl;
//    std::cout << second::x << std::endl;

    using namespace first;
    std::cout << x;  // When referring that we're using "first" namespace, it'll  output 1
    */

    // 4. Typedef
    /*
    // typedef = Reserved keyword used to create an additional name (alias) for another data type;
    //           New identifier for an existing type;
    //           Helps with readability and reduces typos;
    //           Use when there is a clear benefit;
    //           Replaced with "using" (works better with templates).

//    pairlist_t pairList;

    text_t firstName = "Bro";
    std::cout << firstName << std::endl;
    number_t age = 30;
    std::cout << age << std::endl;
    */

    // 5. Type conversion
    /*
    // type conversion = Implicit = automatic
    //                   Explicit = Precede value with new data type

//    int x = 3.14;  // implicit
//    std::cout << x << std::endl;  // prints 3

//    double x = (int) 3;  // explicit
//    std::cout << x << std::endl;  // also prints 3

//    char x = 100;
//    std::cout << x << std::endl;  // prints "d"
//    std::cout << (char) 100 << std::endl;  // also prints "d"

    int correct = 8;
    int questions = 10;
    double score = correct / (double) questions * 100;
    std::cout << score << "%";
    */

    // 6. User input
    /*
    // cout << (insertion operator)
    // cin >> (extraction operator)
    std::string name;
    int age;

    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "Name: ";
//    std::cin >> name;  // won't work if the string contains spaces
    std::getline(std::cin >> std::ws, name);  // will get all the value of the line
    // std::ws is the same as fflush() in C, it cleans the buffer and removes left "\n" from previous input

    std::cout << "Hello " << name << ", you are " << age << " years old.";
    */

    // 7. Useful math related functions
    /*
    double x = 3.15, y = 2;

    std::cout << std::max(x, y) << std::endl;
    std::cout << std::min(x, y) << std::endl;
    std::cout << pow(y, x) << std::endl;
    std::cout << sqrt(9) << std::endl;
    std::cout << abs(-3) << std::endl;
    std::cout << round(3.1) << std::endl;
    std::cout << round(3.5) << std::endl;  // x < 0.5 rounds down, x >= 0.5 rounds up
    std::cout << ceil(3.1) << std::endl;  // always rounds up
    */

    // 8. Hypotenuse of a right-angled triangle
    /*
    double a, b, c;

    std::cout << "a: ";
    std::cin >> a;

    std::cout << "b: ";
    std::cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));
    std::cout << "c: " << c;
    */

    // 9. Switches
    /*
    int month;
    std::cout << "Month: ";
    std::cin >> month;

    switch (month) {
        case 1:
            std::cout << "JAN";
            break;
        case 2:
            std::cout << "FEB";
            break;
        case 3:
            std::cout << "MAR";
            break;
        default:
            std::cout << "Cringe month that you chose, bro.";
    }
    */

    // 10. Ternary operator
    /*
    // ternary operator ?: = replacement to an if/else statement
    // condition ? expression1 : expression2

    int grade = 75;

//    if (grade >= 60) {
//        std::cout << "You pass!";
//    }
//    else {
//        std::cout << "You fail";
//    }
    grade >= 60 ? std::cout << "You pass!" << std::endl : std::cout << "You fail!" << std::endl;

    int number = 9;
    number % 2 == 0 ? std::cout << "EVEN" << std::endl : std::cout << "ODD" << std::endl;

    bool hungry = true;

    hungry ? std::cout << "You are hungry" << std::endl : std::cout << "You are full" << std::endl;
    std::cout << (hungry ? "You are hungry" : "You are full");
    */

    // 11. Useful string methods
    /*
    std::string name;
    std::cout << "Name: ";
    std::getline(std::cin, name);

    std::cout << name.length() << std::endl;
        std::cout << name.empty() << std::endl;  // returns a bool value
//    name.clear(); // clears all the chars in the string
//    std::cout << name << std::endl;
    std::cout << name.append("@gmail.com") << std::endl;
    std::cout << name.at(0) << std::endl;
    std::cout << name.find("m") << std::endl;
    std::cout << name.erase(0, 3) << std::endl;
    */

    // 12. Random numbers
    /*
    // pseudo-random = NOT truly random (but close)

    srand(time(NULL));  // Generate a random seed based on the time of the day
    int num = (rand() % 6) + 1;  // rand() will always generate the same result if the same seed is provided, so, we
    std::cout << num << std::endl;  // use time(NULL) to get the current time, which is always changing
    */

    // 13. Random event generator
    /*
    srand(time(NULL));
    int random_number = rand() % 5 + 1;

    switch (random_number) {
        case 1:
            std::cout << "You win a bumper sticker";
            break;
        case 2:
            std::cout << "You win a flute";
            break;
        case 3:
            std::cout << "You win an electric guitar";
            break;
        case 4:
            std::cout << "You win a sandwich";
            break;
        case 5:
            std::cout << "You win a balloon";
            break;
    }
    */

    // 14. User defined functions
    /*
    int a = 9, b = -24, c = 16;
    std::cout << bhaskara(a, b, c, '+') << std::endl;
    std::cout << bhaskara(a, b, c, '-') << std::endl;
    */

    // 15. Overloaded functions
    /*
    // You can have functions with the same name, as long as they accept different parameters
    bake_pizza();
    bake_pizza("Peperoni");
    bake_pizza("Peperoni", "Salmon");
    */

    // 16. Arrays
    /*
    // array = a data structure that can hold multiple values accessed by an index number

    std::string cars[] = {"Corvette", "Mustang", "Camry"};
    // You don't need to define the length of the array if you set the elements when initializing the variable, however,
    // the array will have the size of the amount of items initially set
    // You can't call cars[4] = "Ford GT", because it will be out of bounds
    std::cout << cars << std::endl;  // prints the memory location of the first item of the array


    int numbers[10] = {10, 20};
    numbers[2] = 30;
    numbers[4] = 50;
    for (int i = 0; i < 10 ; i++) {
        std::cout << numbers[i] << std::endl;
    }
    // Could also be written as:
    */

    // 17. Sizeof() operator
    /*
    // sizeof() = determines the size in bytes of a: variable, data type, class, objects, etc.

//    double gpa = 2.5;
//    std::cout << "sizeof(gpa): " << sizeof(gpa) << " bytes" << std::endl;  // 8 bytes
//    std::cout << "sizeof(int): " << sizeof(int) << " bytes" << std::endl;  // 4 bytes
//    std::cout << "sizeof(double): " << sizeof(double) << " bytes" << std::endl;  // 8 bytes
//    std::cout << "sizeof(long): " << sizeof(long) << " bytes" << std::endl;  // 4 bytes
//    std::cout << "sizeof(long int): " << sizeof(long int) << " bytes" << std::endl;  // 4 bytes
//    std::cout << "sizeof(long long): " << sizeof(long long) << " bytes" << std::endl;  // 8 bytes
//    std::cout << "sizeof(long long int): " << sizeof(long long int) << " bytes" << std::endl;  // 8 bytes
//    std::cout << "sizeof(long double): " << sizeof(long double) << " bytes" << std::endl;  // 16 bytes
//
//    std::string name1 = "Bro";
//    std::string name2 = "Bro Code";
//    std::cout << "sizeof(name1): " << sizeof(name1) << " bytes" << std::endl;  // 32 bytes
//    std::cout << "sizeof(name2): " << sizeof(name2) << " bytes" << std::endl;  // 32 bytes
//    std::cout << "sizeof(std::string): " << sizeof(std::string) << " bytes" << std::endl;  // 32 bytes

//    char grades[] = {'A', 'B', 'C', 'D', 'F'};
//    std::cout << "sizeof(char): " << sizeof(char) << " bytes" << std::endl;  // 1 byte
//    std::cout << "sizeof(grades): " << sizeof(grades) << " bytes" << std::endl;  // 5 bytes
//    std::cout << "sizeof(grades[0]): " << sizeof(grades[0]) << " bytes" << std::endl;  // 1 byte

    std::string students[] = {"Adam", "Benicio", "João", "Roberto"};
    std::cout << "sizeof(students): " << sizeof(students) << " bytes" << std::endl;  // 128 bytes

    // Get amount of elements in an array
    std::cout << "sizeof(students)/sizeof(std::string): " << sizeof(students)/sizeof(std::string) << std::endl;  // 4
    */

    // 18. Iterate over an array
    /*
    std::string students[] = {"Adam", "Alan", "Benicio"};
    for (int i = 0; i < sizeof(students)/sizeof(std::string); i++) {
        std::cout << students[i] << std::endl;
    }
    */

    // 19. Foreach loop
    /*
    // foreach loop = loop that eases the traversal over an iterable data set

    std::string cars[] = {"Corvette", "Mustang", "Camry"};
    for (const auto & car : cars) {
        std::cout << car << std::endl;
    }
    // "const" defines that "car" can't be changed
    // "auto" defines the type of the value automatically, but, could be changed to std::string

    int numbers[] = {1, 2, 3, 4, 5};
    int numbers_sum = 0;
    for (int number : numbers) {
        std::cout << numbers_sum << " + " << number << std::endl;
        numbers_sum += number;
    }
    std::cout << numbers_sum << std::endl;
    */

    // 20. Pass array to a function
    /*
    double  prices[] = {49.99, 15.05, 75, 9.99};
    int size = sizeof(prices) / sizeof(prices[0]);
    double total = get_total(prices, size);
    std::cout << "Total price: " << total << std::endl;
    */

    // 21. Search an array for an element
    /*
//    int numbers[] = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10};
//    int size = sizeof(numbers)/sizeof(numbers[0]);
//    int index, chosen_number;
//
//    std::cout << "Choose a number between 1 and 10 to search for: ";
//    std::cin >> chosen_number;
//    index = search_int_array(numbers, size, chosen_number);
//
//    if (index != -1) {
//        std::cout << chosen_number << " was found at index " << index << std::endl;
//    }
//    else {
//        std::cout << chosen_number << " was not found inside the array." << std::endl;
//    }

//    std::string foods[] = {"pizza", "hamburguer", "hotdog"};
//    std::string chosen_food;
//    int size = sizeof(foods)/sizeof(foods[0]);
//
//    std::cout << "Choose a food to search for: ";
//    std::getline(std::cin, chosen_food);
//    int index = search_string_array(foods, size, chosen_food);
//
//    if (index != -1) {
//        std::cout << chosen_food << " was found at index " << index << std::endl;
//    }
//    else {
//        std::cout << chosen_food << " was not found inside the array." << std::endl;
//    }
    */

    // 22. Sort an array
    /*
    // bubble sort = checks element 0 and 1, if 0 > 1, stores 1 in a tempvar, switches 1 for 0, set 0 as tempvar

    int numbers[] = {9, 3, 7, 1, 4, 2, 5, 6, 10, 8};
    int size = sizeof(numbers)/sizeof(numbers[0]);

    std::cout << "Original array:" << std::endl;
    for (int element : numbers) {
        std::cout << element << " ";
    }

    sort(numbers, size);
    std::cout << std::endl << "Sorted array:" << std::endl;
    for (int element : numbers) {
        std::cout << element << " ";
    }
    */

    // 23. Fill() function
    /*
    // fill() = Fills a range of elements with a specified value
    //          fill(begin, end, value)

    std::string foods[100];
    const int SIZE = 100;

    fill(foods, foods + (SIZE / 2), "pizza");
    fill(foods + (SIZE / 2), foods + 100, "hamburger");

    for (const std::string& food : foods) {
        std::cout << food << " ";
    }
    */

    // 24. Fill an array with user input
    /*
    std::string foods[5];
    std::string temp_food;
    int size = sizeof(foods)/sizeof(foods[0]);

    for (int i = 0; i < size; i++) {
        std::cout << "Enter a food you like: ";
        std::getline(std::cin, temp_food);
        if (temp_food == "q") {
            break;
        }
        foods[i] = temp_food;
    }

    std::cout << "You like the following foods: " << std::endl;
    for (int i = 0; !foods[i].empty(); i++) {  // when the value is blank, it breaks the loop
        std::cout << foods[i] << std::endl;
    }
    */

    // 25. Multidimensional arrays
    /*
    // When initializing matrices, you don't need to initialize the amount of lines, but you do need to initialize the
    // amount of columns
    std::string cars[][4] = {
            {"Mustang",    "Escape",  "F-150",     "GT"},
            {"Corvette",   "Equinox", "Silverado"},
            {"Challenger", "Durango", "Ram 15000", "Viper"}
    };

    int rows = sizeof(cars) / sizeof(cars[0]);
    std::cout << "rows = " << rows << std::endl;

    int columns = sizeof(cars[0]) / sizeof(cars[0][0]);
    std::cout << "columns: " << columns << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (cars[i][j].empty()) {
                continue;
            }
            std::cout << "cars[" << i << "][" << j << "] = " << cars[i][j] << std::endl;
        }
    }
    */

    // 26. Memory addresses
    /*
    // memory address = a location in memory where data is stored
    //                  can be accessed with & (address-of operator)

    std::string name = "Bro";
    int age = 21;
    bool student = true;

    std::cout << &name << std::endl;
    std::cout << &age << std::endl;
    std::cout << &student << std::endl;
    */

    // 27. Pass by VALUE vs pass by REFERENCE
    /*
    std::string x = "Kool-Aid";
    std::string y = "Water";

    std::cout << "&x: " << &x << std::endl;
    std::cout << "&y: " << &y << std::endl;

    swap(x, y);

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    */

    // 28. Const parameter
    /*

    // const parameter = parameter that is effectively read-only
    //                   code is more secure and conveys intent
    //                   useful for references and pointers

    std::string name = "Bro";
    int age = 20;

    print_info(name, age);
    */

    // 29. Credit card validator program
    /*
    std::string card_number;
    int result = 0;

    std::cout << "Enter a credit card number: ";
    std::cin >> card_number;

    result = sum_even_digits(card_number) + sum_odd_digits(card_number);

    if (result % 10 == 0) {
        std::cout << "That number is valid!" << std::endl;
    }
    else {
        std::cout << "That number is NOT valid!";
    }
    */

    // 30. Pointers
    /*
    // pointers = variable that stores a memory address of another variable
    //            sometimes it is easier to work with an address

    std::string name = "Bro";
    std::string *p_name = &name;

    std::cout << p_name << std::endl;  // prints the position in memory that it points to
    std::cout << &p_name << std::endl;  // prints p_name position in memory
    std::cout << *p_name << std::endl;  // prints the value in the position in memory that it points to

    int age = 20;
    int *p_age = &age;

    std::cout << p_age << std::endl;  // prints the position in memory that it points to
    std::cout << &p_age << std::endl;  // prints p_name position in memory
    std::cout << *p_age << std::endl;  // prints the value in the position in memory that it points to

    std::string free_pizzas[] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
    std::string *p_free_pizzas = free_pizzas;  // & not needed since free_pizzas already points to the start of the array

    std::cout << p_free_pizzas << std::endl;  // prints the position in memory of the first element of the array
    std::cout << &p_free_pizzas << std::endl;  // prints p_free_pizza position in memory
    std::cout << *p_free_pizzas << std::endl;  // prints the value of the first element in the array
    */

    // 31. Null pointers
    /*

    // null_value = a special value that means something has no value.
    //              when a pointer is holding a null value, that pointer is not pointing at anything (null pointer)

    // nullptr = keyword that represents a null pointer literal
    // nullptrs are helpful when determining if an address was successfully assigned to a pointer

    // When using pointers, be careful that your code isn't referencing null or pointing to free memory, since this
    // will cause undefined behaviour.

    int *pointer = nullptr;
    int x = 123;

    pointer = &x;

    if (pointer == nullptr) {
        std::cout << "address was not assigned!" << std::endl;
    }
    else {
        std::cout << "address was assigned!" << std::endl;
        std::cout << pointer << std::endl;
    }
     */

    // 32. Tic-tac-toe game
    /*
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';

    draw_board(spaces);

    while (true) {
        player_move(spaces, player);
        draw_board(spaces);
        if (check_winner(spaces, player)) {
            break;
        }
        else if (check_tie(spaces)) {
            break;
        }

        computer_move(spaces, computer);
        draw_board(spaces);
        if (check_winner(spaces, player)) {
            break;
        }
        else if (check_tie(spaces)) {
            break;
        }
    }
    std::cout << "Thanks for playing!";
    */

    // 33. Dynamic memory
    /*
    // dynamic memory = Memory that is allocated after the program is already compiled and running.
    //                  Use the "new" operator to allocate memory in the heap rather than the stack.

    // Useful when we don't know how much memory we will need. Makes our programs more flexible, especially when
    // accepting user input.

    char *p_grades;
    int size;

    std::cout << "How many grades to enter in?: ";
    std::cin >> size;

    p_grades = new char[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Enter grade #" << i + 1 << ":";
        std::cin >> p_grades[i];
    }

    for (int i = 0; i < size; i++) {
        std::cout << p_grades[i] << " ";
    }

    delete[] p_grades;  // Clears the address to which p_grades points to in order to prevent memory leaks
    */

    // 34. Recursion
    /*
    // recursion = a programming technique where a function invokes itself from within
    //             break a complex concept into a repeatable single step

    // (iterative vs recursive)

    // advantages = less code and is clear
    //              useful for sorting and searching algorithms

    // disadvantages = uses more memory
    //                 slower

//    iterative_walk(100);
//    recursive_walk(100);
    std::cout << iterative_factorial(5) << std::endl;
    std::cout << recursive_factorial(5) << std::endl;
    */

    // 35. Function templates
    /*
    // function template = describes what a function looks like
    //                     can be used to generate as many overloaded functions as needed,
    //                     each using different data types

    std::cout << max(1, 2) << std::endl;
    std::cout << max(1.5, 2.2) << std::endl;
    std::cout << max('1', '2') << std::endl;

    std::cout << max(1.5, 2) << std::endl;
    */

    // 36. Structs
    /*
    // struct = a structure that groups related variables under one name
    //          structs can contain many differet data types (string, int, double, bool, etc.)
    //          variables in a struct are known as "members"
    //          members can be accessed with "." "Class Member Access Operator"

    student student1;
    student1.name = "Spongebob";
    student1.gpa = 3.2;
    student1.enrolled = true;

    std::cout << student1.name << std::endl;
    std::cout << student1.gpa << std::endl;
    std::cout << student1.enrolled << std::endl;

    student student2;
    student2.name = "Patrick";
    student2.gpa = 5.1;

    std::cout << student2.name << std::endl;
    std::cout << student2.gpa << std::endl;
    std::cout << student2.enrolled << std::endl;  // struct has base value for enrolled == true
    */

    // 37. Pass structs as arguments
    /*
    Car car1;
    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "red";
    print_car(car1);

    Car car2;
    car2.model = "Corvette";
    car2.year = 2000;
    car2.color = "blue";
    print_car(car2);

    paint_car(car1);
    print_car(car1);

    paint_car(car2);
    print_car(car2);
    */

    // 38. Enums
    /*
    // enums = a user-defined data type that consists of paired named-integer constants.
    //         GREAT if you have a set of potential options

    Day today = sunday;
    switch (today) {
        case sunday:
            std::cout << "It is Sunday!";
            break;
        case monday:
            std::cout << "It is Monday!";
            break;
        case 2:
            std::cout << "It is Tuesday!";
            break;
        case 3:
            std::cout << "It is Wednesday!";
            break;
        case thursday:
            std::cout << "It is Thursday!";
            break;
        case friday:
            std::cout << "It is Friday!";
            break;
        case 6:
            std::cout << "It is Saturday!";
            break;
    }
    */

    // 39. Object Oriented Programming
    /*
    // object = A collection of attributes and methods.
    //          They can have characteristics and could perform actions
    //          Can be used to mimic real world items (ex. Phone, Book, Dog)
    //          Created from a class which acts as a "blue-print"

    Human human1;
    human1.name = "Adam";
    human1.age = 20;
    human1.occupation = "CS Student";
    human1.change_id(100);

    human1.eat();
    human1.drink();
    human1.sleep();
    human1.display_info();
    */

    // 40. Constructor
    /*
    // constructor = special method that is automatically called when an object is instantiated
    //               useful for assigning values to attributes as arguments

    Student student1("Spongebob", 25, 3.2);
    std::cout << student1.name << std::endl;
    std::cout << student1.age << std::endl;
    std::cout << student1.gpa << std::endl;

    Student student2("Patrick", 40, 1.5);
    std::cout << student1.name << std::endl;
    std::cout << student1.age << std::endl;
    std::cout << student1.gpa << std::endl;
    */

    // 41. Constructor overloading
    /*
    Pizza pizza1;
    pizza1.list_toppings();

    Pizza pizza2("Pepperoni");
    pizza2.list_toppings();

    Pizza pizza3("Pepperoni", "Pineapple");
    pizza3.list_toppings();
    */

    // 42. Getters & setters
    /*
    // Abstraction = hiding unnecessary data from outside a class
    // getter = function that makes a private attribute READABLE
    // setter = function that makes a private attribute WRITEABLE

    Stove stove1(5);
    std::cout << stove1.get_temperature() << std::endl;

    stove1.set_temperature(100);
    std::cout << stove1.get_temperature() << std::endl;

    stove1.set_temperature(-5);
    std::cout << stove1.get_temperature() << std::endl;
    */

    // 43. Inheritance
    /*

        // inheritance = A class can receive attributes and methods from another class
        //               Children classes inherit from a Parent class
        //               Helps to reuse similar code found within multiple classes
        Dog dog1;
        dog1.eat();
        dog1.bark();

        Cat cat1;
        cat1.eat();
        cat1.meow();

        Cube cube = Cube(10);
        std::cout << cube.side << std::endl;
        std::cout << cube.area << std::endl;
        std::cout << cube.volume << std::endl;

        Sphere sphere = Sphere(5);
        std::cout << sphere.radius << std::endl;
        std::cout << sphere.area << std::endl;
        std::cout << sphere.volume << std::endl;
    */

    // 44. Destructors
    /*
    // destructors = The last function called before an object is destroyed;
    //               An instance member function automatically called whenever an object goes out of scope;
    //               Release the memory space occupied by the objects created by constructor;
    //               Can be defined within or outside a class;
    //               Destructor has the same name as their class name preceded by a tilde (~) symbol;
    //               Neither requires any argument nor returns any value.

    DestroyableClass temp1 = DestroyableClass();
    DestroyableClass temp2, temp3, temp4, temp5;
    */

    return 0;
}
