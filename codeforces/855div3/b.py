for _ in range(int(input())):
    n, k = [int(i) for i in input().split(" ")]
    s = input()
    cnt1 = [0 for i in range(26)]
    cnt2 = [0 for i in range(26)]
    for i in s:
        if i.isupper():
            cnt2[ord(i)-ord('A')] += 1
        else:
            cnt1[ord(i)-ord('a')] += 1
    ans = 0
    for i in range(26):
        x = min(cnt1[i], cnt2[i])
        cnt1[i] -= x
        cnt2[i] -= x
        ans += x
        if cnt1[i] > 1 and k > 0:
            y = min(k, cnt1[i] // 2)
            ans += y
            k -= y
        if cnt2[i] > 1 and k > 0:
            y = min(k, cnt2[i] // 2)
            ans += y
            k -= y

    print(ans)