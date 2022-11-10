# Introduction

<!-- TODO -->
Esse projeto tem como objetivo criar uma "corrida" de gráfico de barras, a qual nós damos um arquivos com os dados a serem apresentados e o programa faz toda a leitura e apresentação de forma dinâmica apresentando as diferenças entre os dados em forma de uma "corrida".

# Author(s)

<!-- TODO -->
Paulo Vitor Fernandes Andrade

# Problems found or limitations

<!-- TODO -->

# Grading

<!-- TODO -->

Item     | Valor máximo   | Valor esperado
-------- | :-----: | :-----:
Read, validate, and process command line arguments | 5 | 5
Program runs with default values, if no options are provided | 5 | 5
Read the input data file and store the information in memory    | 10 | 10
Display a summary of the data read from the input file _before_ the animation starts | 5 | 5
Display a summary of the running options (set by the user or default values) _before_ the animation starts | 5 | 5
The project contains at least two classes | 10 | 10
Create individual bar charts containing all data items for a single date | 10 | 10
Run the bar chart animation at the correct speed | 10  | 10
The bar chart anatomy is complete and correct | 30 | 30
Program handles errors properly | 10 | 10

# Compiling and Runnig

<!-- TODO -->
##### Using g++
inside the project folder, run the code below:
```
	g++ -Wall -std=c++11 main.cpp -o bcr
```
This will generate an executable file named `bcr` inside the project folder.

##### Running
To run this project, you will need to provide a data file.

Now to execute the project, run the following template making the necessary adaptations:
```
% ./bcr
Usage: bcr [<options>] <input_data_file>
  Bar Chart Race options:
      -b  <num> Max # of bars in a single char.
                Valid range is [1,15]. Default values is 5.
      -f  <num> Animation speed in fps (frames per second).
                Valid range is [1,24]. Default value is 24.
```