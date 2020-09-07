# Push_swap

Using 2 stacks to sort an array of integers with special commands. My push_swap uses an analogue of the timsort algorithm, taking into account the imposed restrictions on the use of special commands.

## Limitations on the number of operations:
- no more than 2-3 operations for 3 integers;
- no more than 12 operations for 5 integers;
- no more than 700 operations for 100 integers for 5/5 points;
- no more than 5300 operations for 500 integers for 5/5 points.

## Average number of operations of my algorithm:
- 630 operations for 100 integers - 5 points;
- 4700 operations for 500 integers - 5 points.

## Bonus:
-v debug mode with visualization;
-c debug mode with color visualization.

## Operations:
`sa` `sb` `ss` swap the first 2 elements at the top of stack A/B/both;
`pa` `pb` take the first element at the top of B/A and push it at the top of A/B;
`ra` `rb` `rr` rotate all elements of stack A/B/both , the first element becomes the last one;
`rra` `rrb` `rrr` reverse rotate all elements of stack A/B/both, the last element becomes the first one.

## Run:
`make `
`ARG=$(random int); ./push_swap $ARG | ./checker $ARG`
or
`ARG=$(random int); ./push_swap [-v | -c] $ARG`
