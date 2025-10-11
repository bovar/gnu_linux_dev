set pagination off

b 14 if ((cur - m) / s >= 28) && ((cur - m) / s <= 35)
    command 1
        printf "@@@ %d %d %d %d\n", m, n, s, cur
        continue
    end
run -100 100 3 > /dev/null
quit
