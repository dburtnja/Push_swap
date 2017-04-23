The goal of Push_swap project is to write 2 programs in C:<br/>
• The first, named checker which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.<br/>
• The second one called push_swap which calculates and displays on the standard
output the smallest progam using Push_swap instruction language that sorts integer
arguments received.<br/>

Push_swap instruction language:<br/>
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).<br/>
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).<br/>
ss : sa and sb at the same time.<br/>
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.<br/>
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.<br/>
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.<br/>
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.<br/>
rr : ra and rb at the same time.<br/>
rra : reverse rotate a - shift down all elements of stack a by 1. The flast element
becomes the first one.<br/>
rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element
becomes the first one.<br/>
rrr : rra and rrb at the same time.<br/>

Allowed functions:<br/>
◦ write<br/>
◦ read<br/>
◦ malloc<br/>
◦ free<br/>
◦ exit<br/>

Bonus in 'checker':<br/>
• Debug option -v that can display the stack’s status after each operation<br/>
• Colour option -c<br/>
• -l display the stack's 'a' and 'b' only after last operation<br/>
• -s shows the number of instructions<br/>
• -f write all output into the file name 'stacks.txt'<br/>

Bonus in 'push_swap':<br/>
• Colour option -c<br/>
• -l display the stack's 'a' and 'b' only after last operation<br/>
• -s shows the number of instructions<br/>

*.sh - scripts to test project.

Push_swap subject:<br/>
https://cdn.intra.42.fr/pdf/pdf/944/push_swap.en.pdf
