echo my = 33
ARG="7 8 9 4 5 6 1 2 3 10"; ./push_swap $ARG | wc -l
ARG="7 8 9 4 5 6 1 2 3 10"; ./push_swap $ARG | ./checker -c $ARG

echo my = 22
ARG="7 8 9 4 5 6 1 2 3"; ./push_swap $ARG | wc -l
ARG="7 8 9 4 5 6 1 2 3"; ./push_swap $ARG | ./checker $ARG

echo my = 22
ARG="8 9 4 6 1 2 3"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo my = KO
ARG="7 8 9 4 5 6 1 2 3 10 11 12"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c -v $ARG

echo my = KO 77
ARG="2147483647 -2147483648 9 4 6 1 2 3 0 -22 36 22 -36 -1 -256"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c -v $ARG

echo my = 
ARG="256 -257 9 4 6 1 2 3 0 -22 36 22 -36 -1 -256"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c -v $ARG
