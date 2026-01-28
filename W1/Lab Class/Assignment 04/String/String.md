# **Using String in C++ Standard Template Library (STL)**

## **1. Introduction**

The `std::string` is a container in the C++ STL used to store and manipulate sequences of characters. It provides a safer and more flexible alternative to traditional C-style character arrays. Strings manage memory dynamically and offer many built-in functions for modification and access.

## **2. Setup and initialization**

To use strings in C++, we must include the `<string>` header.
```cpp
#include <string>
```

To declare a string, use this syntax:
```cpp
std::string <string name>;
```

Ex:
```cpp
std::string daughter = "Alice";
```
## **3. Core operations**
### **3.1 Adding and modifying content**

`append(str)`: Adds text to the end of the string (O(n) time complexity, with n is the size of str).

`push_back(char)`: Adds a single character to the end (O(1) time complexity).

Ex:
```cpp
std::string s = "Hello"

s.append(" World") -> "Hello World"
s.push_back('!')   -> "Hello World!"
```
### **3.2 Accessing characters**

Let s be the name of the string, then:

`s[i]`: Fast access without bounds checking.

`s.at(i)`: Safe access with bounds checking (throws exception if out of range).

Ex:
```cpp
std::string s = "Hello"

s[1] = 'e'
s.at(4) = 'o'
```

Accessing out of bounds results in undefined behavior for `s[i]`.

### **3.3 Removing content**

`pop_back():` Removes the last character (O(1) time complexity).

`erase(pos, len):` Removes a portion of the string (O(n) time complexity, with n = len).

Ex:
```cpp
std::string s = "Hello World"

s.pop_back() -> "Hello Worl"
s.erase(5, 6) -> "Hello"
```
## **4. Status operations**

`size()`: Returns the number of characters in the string.

`empty()`: Returns **true** if the string is empty.

`clear()`: Removes all characters from the string.

## **5. Conclusion**

The `std::string` container is essential for:

- Text processing

- Input/output operations

- Safer character handling than C-style strings

It provides powerful and convenient built-in functions, efficient memory management and ease of use, making it the preferred way to handle text in modern C++, compare to the old text in C-style, which is array of characters.