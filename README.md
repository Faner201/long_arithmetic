# long_arithmetic

To build tests, call the gcc compiler in the src folder with this command

```
 g++ -fsanitize=address -Wall -Werror -std=c++17 TestCase.cpp -o called_file_name
```

Then you call 

```
./called_file_name
```
