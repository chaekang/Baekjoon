while True:
    str = input()
    if str == ".":
        break
    
    st = []
    result = True
    
    for ch in str:
        if (ch == "(") or (ch == "["):
            st.append(ch)
        elif ch == ")":
            if not st or (st[-1] != "("):
                result = False
                break
            else:
                st.pop()
        elif ch == "]":
            if not st or (st[-1] != "["):
                result = False
                break
            else:
                st.pop()
            
    if not st and result:
        print("yes")
    else:
        print("no")