for _ in range(int(input())):
    n = int(input())
    s = input()
    s = s.lower()
    i = 0
    st = set()
    while i < n and s[i] == 'm':
        st.add(s[i])
        i += 1
    while i < n and s[i] == 'e':
        st.add(s[i])
        i += 1
    while i < n and s[i] == 'o':
        st.add(s[i])
        i += 1
    while i < n and s[i] == 'w':
        st.add(s[i])
        i += 1
    if i == n and len(st) == 4:
        print("Yes")
    else:
        print("No")
