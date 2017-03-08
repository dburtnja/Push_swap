echo my = 33
ARG="7 8 9 4 5 6 1 2 3 10"; ./push_swap $ARG | wc -l
ARG="7 8 9 4 5 6 1 2 3 10"; ./push_swap $ARG | ./checker -c $ARG

echo my = 22
ARG="7 8 9 4 5 6 1 2 3"; ./push_swap $ARG | wc -l
ARG="7 8 9 4 5 6 1 2 3"; ./push_swap $ARG | ./checker -c $ARG

echo my = 22
ARG="8 9 4 6 1 2 3"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

echo my = KO
ARG="7 8 9 4 5 6 1 2 3 10 11 12"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

echo my = KO 77
ARG="2147483647 -2147483648 9 4 6 1 2 3 0 -22 36 22 -36 -1 -256"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

ARG="46 3 9 16 18 39 25 26 36 28 6 5 38 21 48 22 32 41 4 11 12 10 2 30 15 47 19 42 40 35 23 1 33 45 50 43 29 14 49 17 44 31 8 13 34 24 20 27 7 37"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

ARG=""; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -v -c $ARG
