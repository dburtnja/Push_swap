echo my = 33
ARG="7 8 9 4 5 6 1 2 3 10"; ./push_swap $ARG | wc -l
ARG="7 8 9 4 5 6 1 2 3 10"; ./push_swap $ARG | ./checker -c $ARG

echo my = 22
ARG="7 8 9 4 5 6 1 2 3"; ./push_swap $ARG | wc -l
ARG="7 8 9 4 5 6 1 2 3"; ./push_swap $ARG | ./checker -c $ARG

echo my = 16
ARG="8 9 4 6 1 2 3"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

echo my = 25
ARG="7 8 9 4 5 6 1 2 3 10 11 12"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

echo my = 62
ARG="2147483647 -2147483648 9 4 6 1 2 3 0 -22 36 22 -36 -1 -256"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

ARG="55 41 43 28 62 95 54 29 6 30 88 36 38 91 53 51 34 92 50 9 15 77 79 47 98 16 78 86 17 48 80 32 31 8 65 37 82 84 1 69 10 40 59 24 11 35 57 73 94 76"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

ARG="68 96 58 44 69 82 50 67 95 81 57 38 56 80 18 97 2 66 43 33 94 49 83 79 37 55 29 98 65 25 13 4 32 78 28 23 48 6 100 93 84 54 16 70 8 59 39 12 24 77 99 1 85 42 36 21 10 3 71 92 47 60 27 86 64 30 76 53 11 17 34 5 87 72 19 40 22 7 61 75 45 14 31 9 88 73 15 20 52 89 62 26 46 35 41 51 90 63 74 91"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG


ARG="2433541 53023659 8704744 4716594 31021964 12167774 24170715 53543826 20092931 13194661 70278411 69177028 44457873 12850925 8692731 70306348 5212395 31156824 67786409 34443516 39891512 10979299 69727818 33060549 24383133 8811227 64960261 39064008 19019488 70261102 71112805 41853739 21959684 51061573 18675642 19434628 64493540 10606799 70266273 20254605 19125296 72979780 12258334 27197671 5722128 6612021 58958375 12926489 3070294 2122636 32490651 38490827 10656128 44960879 7518913 65733934 48301226 53404518 56493251 61350217 24854967 48106267 52890136 52334805 17775628 59968294 22617647 69089938 59522823 2937178 11644650 72503725 1862937 11544544 4878265 65231414 5569740 41768157 33269880 52440613 39783561 27989736 1143037 73591782 24864037 54578642 73358675 66085263 44380342 37191729 1176845 37067072 7851368 39584065 36799113 42627414 40286292 31877560 32406551 69719875"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

ARG="15 19 10 20 6 3 8 11 16 12 14 4 7 9 18 5 17 1 13 2"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG

ARG="3 2 1 0"; ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker -c $ARG
