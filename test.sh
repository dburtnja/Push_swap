echo my = 33
ARG="7 8 9 4 5 6 1 2 3 10"; ./push_swap $ARG | wc -l
ARG="7 8 9 4 5 6 1 2 3 10"; ./push_swap $ARG | ./checker -c -v $ARG

echo my = 22
ARG="7 8 9 4 5 6 1 2 3"; ./push_swap $ARG | wc -l
ARG="7 8 9 4 5 6 1 2 3"; ./push_swap $ARG | ./checker $ARG

echo my = 22
ARG="8 9 4 6 1 2 3"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo my = KO
ARG="7 8 9 4 5 6 1 2 3 10 11 12"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

echo my = KO 77
ARG="2147483647 -2147483648 9 4 6 1 2 3 0 -22 36 22 -36 -1 -256"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

ARG="55 41 43 28 62 95 54 29 6 30 88 36 38 91 53 51 34 92 50 9 15 77 79 47 98 16 78 86 17 48 80 32 31 8 65 37 82 84 1 69 10 40 59 24 11 35 57 73 94 76"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -v -c $ARG
./push_swap $ARG

ARG="68 96 58 44 69 82 50 67 95 81 57 38 56 80 18 97 2 66 43 33 94 49 83 79 37 55 29 98 65 25 13 4 32 78 28 23 48 6 100 93 84 54 16 70 8 59 39 12 24 77 99 1 85 42 36 21 10 3 71 92 47 60 27 86 64 30 76 53 11 17 34 5 87 72 19 40 22 7 61 75 45 14 31 9 88 73 15 20 52 89 62 26 46 35 41 51 90 63 74 91"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG
