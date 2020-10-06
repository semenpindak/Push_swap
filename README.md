# Push_swap

![Standard](https://img.shields.io/badge/standart-%20C11-lightgrey.svg)
![License](https://img.shields.io/badge/license-MIT-blue.svg)
![Score](https://img.shields.io/badge/school21-course%20project%20%7C%20success%20%7C%20113%2F125-brightgreen.svg)

## Table of Content

1. [About Push_swap](#about-push_swap)
2. [Compiling](#compiling)
3. [Usage](#usage)
4. [License](#license)

### About Push_swap <a name="about-Push_swap"></a>

Using 2 stacks to sort an array of integers with special commands. My push_swap uses an analogue of the timsort algorithm, taking into account the imposed restrictions on the use of special commands.

### Limitations on the number of operations:
- for `3 integers` - no more than `2-3 operations`;
- for `5 integers` - no more than `12 operations`;
- for `100 integers` - no more than `700 operations (5/5 points)`;
- for `500 integers` - no more than `5500 operations (5/5 points)`.

### Average number of operations of my algorithm:
- `630 operations` for `100 integers` - `5 points`;
- `4700 operations` for `500 integers` - `5 points`.

## Operations:
- `sa sb ss` swap the first 2 elements at the top of stack A/B/both;</p>
- `pa pb` take the first element at the top of B/A and push it at the top of A/B;</p>
- `ra rb rr` rotate all elements of stack A/B/both , the first element becomes the last one;</p>
- `rra rrb rrr` reverse rotate all elements of stack A/B/both, the last element becomes the first one.</p>

### Bonus:
`-v` debug mode with visualization;</p>
`-c` debug mode with color visualization.

## Compiling <a name="Compiling"></a>

Run `git clone --recursive https://github.com/semenpindak/Libft.git`

Run `make`, an executable called `push_swap` `checker` and should compile directly. Please submit an issue if you run into any problems.

## Usage <a name="Usage"></a>

`ARG=$(random int); ./push_swap $ARG | ./checker $ARG`

or

`ARG=$(random int); ./push_swap [-v | -c] $ARG`

<!-- <img src="screenshot/sample42.png" width="600"> -->

## License <a name="license"></a>

<!-- This project is licensed under the MIT License - see the [LICENSE](https://github.com/semenpindak/FDF/blob/master/LICENSE)
file for details. -->
