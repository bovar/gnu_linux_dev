set pagination off

b 14 if cur % 5 == 0
    command 1
        printf "@@@ %d %d %d %d\n", m, n, s, cur
        continue
    end
run 1 12 > /dev/null
quit
